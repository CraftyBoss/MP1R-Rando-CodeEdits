#pragma once

#include "CObject/CObjectId.h"
#include <CArea/CAreaInfo.h>

class CUniverseInfo {
public:
    int mAreaInfoCount;
    int int4;
    CAreaInfo *qword8;
    CObjectId mId1;
    char char20;
    char gap21[15];
    void* qword30;
    char byte38;
};
