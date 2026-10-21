#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../native/declick.c"

static uint8_t hardware[3840*8*4];
static int waits,sleeps,releases,fail_get,fail_release;
static uint32_t wait_result;
static uint32_t delayed_ms;
static int32_t mock_get(void *self,uint32_t frames,uint8_t **buffer) {
    (void)self;(void)frames;
    *buffer=hardware;
    return fail_get ? (int32_t)0x88890004 : 0;
}
static int32_t mock_release(void *self,uint32_t frames,uint32_t flags) {
    (void)self;(void)frames;(void)flags;
    releases++;
    return fail_release ? (int32_t)0x88890004 : 0;
}
static uint32_t mock_wait(void *event,uint32_t timeout) {
    assert(event==(void *)1 && timeout==100);
    waits++;
    return wait_result;
}
static void mock_sleep(uint32_t ms) {sleeps++;delayed_ms=ms;}

static void reset_mocks(void) {
    waits=sleeps=releases=fail_get=fail_release=0;
    wait_result=0;
    delayed_ms=0;
}

static void check_format(unsigned bits,unsigned valid,int32_t level,uint32_t rate) {
    uint8_t sink[0x340]={0};
    void *vtable[5]={0,0,0,(void *)mock_get,(void *)mock_release};
    void **render=vtable;
    unsigned bytes=bits/8,channels=2;
    uint32_t frames=rate/50,fade=rate/200;
    U16(sink,0x56)=channels;U32(sink,0x58)=rate;
    U16(sink,0x246)=bits;U16(sink,0x24a)=valid;
    U16(sink,0x244)=channels*bytes;U32(sink,0x260)=frames;
    PTR(sink,0x228)=&render;PTR(sink,0x1f8)=(void *)1;
    sink[0x53]=1;
    Transition state={0};
    uint8_t pcm[3840*2*4],original[3840*2*4];
    memset(pcm,0,sizeof(pcm));
    fade_in(sink,pcm,0,1,&state);
    assert(state.fade_position==0); /* Initial silence must not use up the ramp. */
    for (uint32_t f=0;f<frames;f++) {
        write_pcm(pcm+(f*2)*bytes,bytes,valid,level);
        write_pcm(pcm+(f*2+1)*bytes,bytes,valid,-level);
    }
    memcpy(original,pcm,frames*2*bytes);
    fade_in(sink,pcm,0,0,&state);
    assert(read_pcm(pcm,bytes)==0 && read_pcm(pcm+bytes,bytes)==0);
    assert(read_pcm(pcm+(fade-1)*2*bytes,bytes)==level);
    assert(read_pcm(pcm+((fade-1)*2+1)*bytes,bytes)==-level);
    assert(memcmp(pcm+fade*2*bytes,original+fade*2*bytes,(frames-fade)*2*bytes)==0);
    for (uint32_t f=1;f<fade;f++) {
        assert(read_pcm(pcm+f*2*bytes,bytes)>=read_pcm(pcm+(f-1)*2*bytes,bytes));
        assert(read_pcm(pcm+(f*2+1)*bytes,bytes)<=0);
    }
    memcpy(pcm,original,frames*2*bytes);
    fade_in(sink,pcm,0,0,&state);
    assert(memcmp(pcm,original,frames*2*bytes)==0); /* Steady playback stays bit-identical. */
    reset_mocks();
    fade_out(sink,&state,mock_wait,mock_sleep);
    assert(waits==1 && releases==1 && sleeps==1 && delayed_ms==42);
    assert(read_pcm(hardware,bytes)==level);
    assert(read_pcm(hardware+bytes,bytes)==-level);
    for (uint32_t f=fade-1;f<frames;f++)
        for (unsigned c=0;c<2;c++) assert(read_pcm(hardware+(f*2+c)*bytes,bytes)==0);
    reset_mocks();wait_result=258;
    fade_out(sink,&state,mock_wait,mock_sleep);
    assert(waits==1 && releases==0 && sleeps==0);
    reset_mocks();fail_get=1;
    fade_out(sink,&state,mock_wait,mock_sleep);
    assert(releases==0 && sleeps==0);
    reset_mocks();fail_release=1;
    fade_out(sink,&state,mock_wait,mock_sleep);
    assert(releases==1 && sleeps==0);
    reset_mocks();sink[0x53]=0;
    fade_out(sink,&state,mock_wait,mock_sleep);
    assert(waits==0 && releases==0);
    fade_in(sink,pcm,2,0,&state);
    assert(state.last[0]==0 && state.last[1]==0);
}

int main(void) {
    for (unsigned r=0;r<3;r++) {
        uint32_t rate=r==0 ? 44100 : r==1 ? 48000 : 192000;
        check_format(16,16,20000,rate);
        check_format(24,24,6000000,rate);
        check_format(32,24,0x60000000,rate);
        check_format(32,32,0x60000000,rate);
    }
    puts("PASS: 12 PCM/rate combinations; stereo ramps; unchanged steady playback; silent, stopped and device-error guards.");
    return 0;
}
