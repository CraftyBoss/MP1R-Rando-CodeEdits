#pragma once

#include "CObject/CObjectId.h"

struct CScriptLoadUnitResourceData {
    CGuid mLoadUnitGuid;
    CGuid unkGuid;

    short unkShort;
    int gap;

    int mGuidListCount;
    int mGuidListSize;
    CObjectId *mGuidList;

    int mLayerGuidListCount;
    int mLayerGuidListSize;
    CGuid *mLayerGuidList;

    void* mLoadUnitLogic;
    void* qword50;
};