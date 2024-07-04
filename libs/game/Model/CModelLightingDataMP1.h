#pragma once

#include "Math.hpp"

struct CModelLightingDataMP1 {
    static CModelLightingDataMP1 Default(void);
    static CModelLightingDataMP1 FromParams(CActorParametersMP1 const&);

    CQuaternion mQuat;
    bool unkBool1;
};