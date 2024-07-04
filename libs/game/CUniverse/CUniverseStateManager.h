#pragma once

#include "CUniverseInfo.h"
#include "rstl/rc_ptr.hpp"

struct CUniverseState {
    char size[0x41B0];
};

class CUniverseStateManager {
public:
    CUniverseStateManager();

    rstl::ncrc_ptr<CUniverseInfo> mUniverseInfo;
    CUniverseState* mUniverseState;
};