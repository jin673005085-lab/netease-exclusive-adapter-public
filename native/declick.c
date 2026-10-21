/* SPDX-License-Identifier: GPL-3.0-only
 * Exact-build WASAPI transition patch. The host's source queue stays unchanged.
 */
#include <stdint.h>
#include <stddef.h>

/* shortcut: sink offsets and callsite RVAs are fixed, reanalyze before supporting another Hook. */
#define U16(p,o) (*(uint16_t *)((uint8_t *)(p)+(o)))
#define U32(p,o) (*(uint32_t *)((uint8_t *)(p)+(o)))
#define PTR(p,o) (*(void **)((uint8_t *)(p)+(o)))
#define MAX_CHANNELS 8
typedef int32_t (*Stop)(void *);
typedef int32_t (*GetBuffer)(void *, uint32_t, uint8_t **);
typedef int32_t (*ReleaseBuffer)(void *, uint32_t, uint32_t);
typedef uint32_t (*Wait)(void *, uint32_t);
typedef void (*SleepMs)(uint32_t);

typedef struct {
    void *owner;
    uint32_t fade_position;
    int32_t last[MAX_CHANNELS];
} Transition;
static Transition transitions[64];

static Transition *state_for(void *sink) {
    size_t first=((uintptr_t)sink >> 4) % 64;
    for (size_t n=0;n<64;n++) {
        Transition *s=&transitions[(first+n)%64];
        void *owner=__atomic_load_n(&s->owner,__ATOMIC_ACQUIRE);
        if (owner==sink) return s;
        if (!owner && __sync_bool_compare_and_swap(&s->owner,0,sink)) {
            s->fade_position=0;
            for (unsigned c=0;c<MAX_CHANNELS;c++) s->last[c]=0;
            return s;
        }
    }
    return 0;
}

static int32_t read_pcm(const uint8_t *p,unsigned bytes) {
    uint32_t value=0;
    for (unsigned n=0;n<bytes;n++) value|=(uint32_t)p[n]<<(8*n);
    return (int32_t)(value << (32-8*bytes)) >> (32-8*bytes);
}

static void write_pcm(uint8_t *p,unsigned bytes,unsigned valid,int32_t value) {
    uint32_t raw=(uint32_t)value;
    unsigned padding=bytes*8-valid;
    if (padding) raw&=~((1u<<padding)-1);
    for (unsigned n=0;n<bytes;n++) p[n]=(uint8_t)(raw>>(8*n));
}

static int supported(void *sink) {
    unsigned channels=U16(sink,0x56), bits=U16(sink,0x246),valid=U16(sink,0x24a);
    return channels && channels<=MAX_CHANNELS && (bits==16 || bits==24 || bits==32)
        && valid && valid<=bits && U16(sink,0x244)==channels*(bits/8)
        && U32(sink,0x58)>=8000 && U32(sink,0x58)<=768000;
}

static void fade_in(void *sink,uint8_t *buffer,uint32_t flags,int prime,Transition *s) {
    if (prime) {
        s->fade_position=0;
        for (unsigned c=0;c<MAX_CHANNELS;c++) s->last[c]=0;
    }
    if (flags&2) {
        for (unsigned c=0;c<MAX_CHANNELS;c++) s->last[c]=0;
        return;
    }
    unsigned channels=U16(sink,0x56),bytes=U16(sink,0x246)/8,valid=U16(sink,0x24a);
    uint32_t fade=U32(sink,0x58)/200;
    for (uint32_t f=0;f<U32(sink,0x260);f++) {
        uint8_t *frame=buffer+(size_t)f*channels*bytes;
        int nonzero=0;
        for (unsigned c=0;c<channels;c++) nonzero|=read_pcm(frame+c*bytes,bytes)!=0;
        int ramp=s->fade_position<fade && (s->fade_position || nonzero);
        for (unsigned c=0;c<channels;c++) {
            int32_t value=read_pcm(frame+c*bytes,bytes);
            if (ramp) {
                value=(int32_t)((int64_t)value*s->fade_position/(fade-1));
                write_pcm(frame+c*bytes,bytes,valid,value);
            }
            s->last[c]=value;
        }
        if (ramp) s->fade_position++;
    }
}

__declspec(dllexport) int32_t declick_release(void *sink,uint8_t *buffer,uint32_t flags,int prime) {
    Transition *s=supported(sink) ? state_for(sink) : 0;
    if (s) fade_in(sink,buffer,flags,prime,s);
    void *render=PTR(sink,0x228);
    ReleaseBuffer release=(ReleaseBuffer)(*(void ***)render)[4];
    return release(render,U32(sink,0x260),flags);
}

static void fade_out(void *sink,Transition *s,Wait wait,SleepMs sleep_ms) {
    if (!s || !*((uint8_t *)sink+0x53) || !supported(sink)) return;
    int nonzero=0;
    for (unsigned c=0;c<U16(sink,0x56);c++) nonzero|=s->last[c]!=0;
    if (!nonzero || !PTR(sink,0x228) || !PTR(sink,0x1f8)) return;
    uint32_t frames=U32(sink,0x260),rate=U32(sink,0x58);
    if (frames<2 || frames>rate/5 || wait(PTR(sink,0x1f8),100)!=0) return;
    void *render=PTR(sink,0x228);
    GetBuffer get=(GetBuffer)(*(void ***)render)[3];
    ReleaseBuffer release=(ReleaseBuffer)(*(void ***)render)[4];
    uint8_t *buffer=0;
    if (get(render,frames,&buffer)<0 || !buffer) return;
    unsigned channels=U16(sink,0x56),bytes=U16(sink,0x246)/8,valid=U16(sink,0x24a);
    uint32_t fade=rate/200;
    if (fade>frames) fade=frames;
    for (uint32_t f=0;f<frames;f++) {
        for (unsigned c=0;c<channels;c++) {
            int32_t value=f<fade ? (int32_t)((int64_t)s->last[c]*(fade-1-f)/(fade-1)) : 0;
            write_pcm(buffer+((size_t)f*channels+c)*bytes,bytes,valid,value);
        }
    }
    if (release(render,frames,0)>=0) sleep_ms((frames*2000+rate-1)/rate+2);
}

__declspec(dllexport) int32_t declick_stop(void *sink) {
    uint8_t *base=(uint8_t *)__builtin_return_address(0)-0x15bf5;
    Wait wait=*(Wait *)(base+0x3a140);
    SleepMs sleep_ms=*(SleepMs *)(base+0x3a210);
    Transition *s=state_for(sink);
    fade_out(sink,s,wait,sleep_ms);
    void *client=PTR(sink,0x220);
    Stop stop=(Stop)(*(void ***)client)[11];
    int32_t result=stop(client);
    if (s) __atomic_store_n(&s->owner,0,__ATOMIC_RELEASE);
    return result;
}
