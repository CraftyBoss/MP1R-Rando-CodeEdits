#pragma once

#include "types.h"

namespace IAllocator {
    enum EHint {};
}

class CInputStream {
public:
    struct SBufferAndSize {
        void* buf;
        ulong size;
    };
    enum EException {};
    enum EFileEndianMode {};
    enum EReadAdvance {};

    CInputStream(ulong,IAllocator::EHint);
    CInputStream(void *,ulong,bool);
    CInputStream(void const*,ulong);
    CInputStream(CInputStream::SBufferAndSize const&,bool);

    virtual ~CInputStream();
    virtual void Read(void *,ulong) = 0;
    virtual void Peek(void *,ulong) = 0;
    virtual void SkipBytes(ulong) = 0;

    void ThrowException(CInputStream::EException,char const*);
    void GetOtherEndian(CInputStream::EFileEndianMode);
    void ValidateEndian(void);

    void Get(void *,ulong,CInputStream::EReadAdvance);
    void SkipAhead(ulong);
    void ReadBytes(void *,ulong);
    void GetExceptionString(void);
    void ReadToAlignment(uint);

//private:
    void InternalReadNext(void);
    void GrabAnotherBlock(void);

    ulong mBlockOffset;
    ulong mBlockLen;
    ulong mStreamSize;
    void *mDataBuffer;
    bool mIsOwned;
    bool byte29;
    bool byte2A;
    ulong mReadPosition;
    int dword38; // might be bitWord/bitOffset from orig, not exactly sure though
};