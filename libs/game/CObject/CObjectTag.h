#pragma once

#include "types.h"
#include "CObjectId.h"
#include "misc.h"

struct CObjectTag {
    static CObjectTag& Invalid(void);
    static const char* Type2Text(uint);
    static uint Text2Type(const char*);
    static const char* Id2Text(void *,ulong,CObjectId const&);

    CObjectTag(CInputStream &);
    void PutTo(COutputStream &);

    void NormType(uint);
    void ValidateType(uint);
    void GetType(IAllocator::SDebugInfo const&);
    void Type(IAllocator::SDebugInfo &);
    void GetId(IAllocator::SDebugInfo const&);
    void Id(IAllocator::SDebugInfo &);

    uint mType;
    __attribute__((packed)) CGuid cguid4;
    __attribute__((packed)) CObjectId mObjId;
    void* qword28;
};