#pragma once

#include "../types.h"
#include "CObject/CObjectId.h"
#include "CActors/MP1/CPlayerState.h"
#include <rstl/string.h>
#include <rstl/rc_ptr.hpp>

class CUniverseInfo;
class SSaveInfo;
class CInputBitStream;
class COutputBitStream;
class CGameOptions;
class CSystemState;
class SAreaInfoContext;
class CGuid;

class CGameState {
public:
    struct SInitialState {
        SInitialState(CObjectId const&);
        SInitialState(CObjectId const&,SSaveInfo const&);
        SInitialState(CInputStream &,uint);
        void PutTo(COutputStream &);
    };

    enum EReturnTrueIfAreaInvalid {};
    enum EForcePreserveData {};

    CGameState(rstl::ncrc_ptr<CUniverseInfo> const&,CGameState::SInitialState const&);
    CGameState(CInputBitStream &,rstl::ncrc_ptr<CUniverseInfo> const&,uint,rstl::ncrc_ptr<CGameOptions> const&);
    ~CGameState();

    void InitQuickLoadBuffer(void);
    void InitializeFromStream(CInputBitStream &,uint);
    void ResetGameInstanceState(void);
    void PreSave(CObjectId const&);
    void SetSavePointName(rstl::basic_string<char,rstl::char_traits<char>,rstl::rmemory_allocator> const&);
    void PutTo(COutputBitStream &);
    void StreamInSystemState(CInputStream &,uint);
    void StreamOutSystemState(COutputStream &);
    void CopyOutSystemStateFrontEndSettings(CSystemState &);
    void ConstructAreaStatesIfRequired(SAreaInfoContext const&);
    void SetDesiredAreaId(CObjectId const&);
    rstl::string* GetSavePointName(void) const;
    CPlayerStateMP1* PlayerState(void);
    CPlayerStateMP1* GetPlayerState(void) const;
    void ComputeGameProgress(void); // unused
    void SetTotalPlayTime(double);
    void GetGameMode4CC(void);
    void IsInFrontEndArea(CGameState::EReturnTrueIfAreaInvalid);
    void WasLoadedFromSaveFile(void);
    void SetSaveSlot(int);
    void IsCinematicSkippable(CGuid const&);
    void SetCinematicSkippable(CGuid const&,bool);
    void SetCinematicForceSkippableOverride(bool);
    void StreamNewGameState(CInputStream &,rstl::ncrc_ptr<CUniverseInfo> const&,uint,rstl::ncrc_ptr<CGameOptions> const&);
    void CreateNewGameState(rstl::ncrc_ptr<CUniverseInfo> const&,CGameState::SInitialState const&);
    void ResetGameState(CGameState const&,CGameState::SInitialState const&,CGameState::EForcePreserveData);
    void ContinueWithNewInitialState(CGameState&,CGameState::SInitialState const&);
    void SetInitialState(CGameState::SInitialState const&);
    void ResetWithQuickLoadBuffer(void);

    static bool mCinematicForceSkippableOverride;
};