#pragma once

#include "CObject/CObjectId.h"
#include "Math.hpp"

#include <rstl/vector.h>
#include <rstl/string.h>

class CAreaInfo {
public:
    CGuid mId;
    rstl::string mAreaLabel;
    int dword28;
    int dword2C;
    CGuid mId2;
    CAABox mBoundBox;
    rstl::vector<char> mSpecificMeta;
    CGuid mId3;
    int dword78;
    char byte7C;
    int dword80;
    char char84;
    char gap85[387];
    void* qword208;
    void* qword210;
    void* qword218;
};
