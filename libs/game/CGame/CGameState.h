#pragma once

#include "../types.h"
#include "CActors/MP1/CPlayerState.h"
#include "CGameInstanceState.h"
#include "CObject/CObjectId.h"
#include <CUniverse/CUniverseStateManager.h>
#include <World/CWorldStateMP1.h>
#include <Types/CFourCC.h>
#include <rstl/rc_ptr.hpp>
#include <rstl/string.h>

class CUniverseInfo;
class SSaveInfo;
class CInputBitStream;
class COutputBitStream;
class CGameOptions;

class CSystemState {
public:
    CSystemState() = default;
    CSystemState(CInputBitStream&);

    int GetCurrentSaveGameSlot() const;
    void SetCurrentSaveGameSlot(int slot);

    int mCurrentSaveSlot = 0;
};
class SAreaInfoContext;
class CGuid;

class CGameState {
public:
    struct SInitialState {
        SInitialState(CObjectId const&);
        SInitialState(CObjectId const&,SSaveInfo const&);
        SInitialState(CInputStream &,uint);
        void PutTo(COutputStream &);

        CObjectId mAreaId;
        CFourCC mSaveMagic;
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
    void SetInitialState(CGameState::SInitialState const&);
    void ResetWithQuickLoadBuffer(void);

    static void ContinueWithNewInitialState(CGameState&,CGameState::SInitialState const&);

    static bool mCinematicForceSkippableOverride;

    int mQuickLoadBufferSize;
    char mQuickLoadBuffer[0xFFA81];
    int mDevVersion;
    CGameState::SInitialState mInitialArea;
    CGameState::SInitialState mDesiredArea;
    void* qwordFFAB4;
    void* qwordFFABC;
    int dwordFFAC4;
    rstl::string mSavePointName;
    CGameInstanceState *mGameInstState;
    CUniverseStateManager mStateManager;
    class CPlayerState *mPlayerState;
    double mTotalPlayTime;
    int dwordFFB10;
    CSystemState mSystemState;
    char gapFFB18[16];
    void* qwordFFB28;
    void* qwordFFB30;
    char byteFFB38;
};


class CSystemStateMP1;

class CGameStateMP1 {
public:
    ~CGameStateMP1();
    CGameStateMP1(void);
    CGameStateMP1(CInputStream &,uint);
    void ResetFromStream(CInputStream &,uint);
    void InitializeWithUniverseInfo(CGameState const&);
    void SetCurrentWorldId(CObjectId);
    void PutTo(COutputStream &);
    void StreamInSystemState(CInputStream &,uint);
    void StreamOutSystemState(COutputStream &);
    void StreamInStateForGameCompletion(CInputStream &);
    void StreamOutStateForGameCompletion(COutputStream &);
    void CopyInSystemStateFrontEndSettings(CSystemStateMP1 const&);

    CWorldStateMP1* StateForWorld(CObjectId);

    CWorldStateMP1* CurrentWorldState(void);
    const CWorldStateMP1* GetCurrentWorldState(void) const;

    CPlayerStateMP1* PlayerState(void);
    const CPlayerStateMP1* GetPlayerState(void) const;

    void SetGameCompleted(bool);
    void GetDamageMultiplier(void);
    void GetWeaponMultiplier(void);
    void IsIntroLevel(void);

    CObjectId mLevelGuid;
    CObjectId mGuessedGuid;
    CPlayerStateMP1 *mPlayerState;
    void* qword28;
    void* qword30;
    int dword38;
    char byte3C;
    char gap3D[3];
    int cgamestatemp140;
    char gap44[604];
    int cgamestatemp12A0;
    char gap2A4[20];
    void* qword2B8;
    short word2C0;
    char byte2C2;
    char gap2C3;
    void* qword2C4;
    int dword2CC;
    char byte2D0;
};