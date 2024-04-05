#pragma once

#include "CObject/CObjectId.h"
#include "rstl/string.h"

namespace NGameWater {
    enum EWaterSortType : u8 {};
}

struct SLdrVector_MP1Typedef {
    float x;
    float y;
    float z;
};

struct SLdrAnimSet_MP1Typedef {
    CObjectId mObjId;
    rstl::string mString1;
    rstl::string mString2;
};

struct SLdrMapInfo_MP1Typedef {
    CObjectId mObjId;
    int unkInt1;
    int unkInt2;
};

struct SLdrLighting_MP1Typedef {
    char size[0x5C];
};

struct SLdrScannable_MP1Typedef {
    char size[0x14];
};

struct SLdrVisor_MP1Typedef {
    int unkInt1;
    bool unkBool1;
    bool unkBool2;
    bool unkBool3;
};

struct __attribute__((aligned(2))) SLdrActorInformation_MP1Typedef {
    CObjectId objId1;
    CObjectId objId2;
    CObjectId objId3;
    CObjectId objId4;
    CObjectId objId5;
    SLdrLighting_MP1Typedef lightInfo;
    SLdrScannable_MP1Typedef scanInfo;
    SLdrVisor_MP1Typedef visorInfo;
    float unkFloat1;
    float unkFloat2;
    float fadeInTime;
    float fadeOutTime;
    float thermalMag;
    NGameWater::EWaterSortType waterSortType;
    bool unkBool2;
    bool globalTimeProvider;
    bool unkBool4;
    bool unkBool5;
    bool unkBool6;
    bool unkBool7;
    bool unkBool8;
    bool unkBool9;
    bool unkBool10;
    bool unkBool11;
};