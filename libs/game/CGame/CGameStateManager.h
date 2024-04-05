#pragma once

#include "rstl/auto_ptr.h"
#include <rstl/rc_ptr.hpp>

class CUniverseInfo;
class CGameState;

class CGameStateManager {
public:
    CGameStateManager(rstl::ncrc_ptr<CUniverseInfo> const&);
    ~CGameStateManager();
    void AssignNewGameState(rstl::auto_ptr<CGameState> &);

    rstl::auto_ptr<CGameState> mGameState;
};