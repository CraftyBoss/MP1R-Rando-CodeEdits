#pragma once

#include "CEntity.h"
#include "misc.h"
#include <CObject/CObjectId.h>
#include <rstl/reserved_vector.h>

class CMaterialListMP1;
class CActorParametersMP1;
class CInt32POINodeMP1;
class CFrustumPlanes;
class CDamageInfoMP1;
class CWeaponModeMP1;
class CMaterialFilterMP1;
class CScriptWaterMP1;
class CEntityGOC;

class CHealthInfoMP1 {
public:
    float heatlh;
    //  inline float &GetA() const { return *GetField<float>(this, 0x0); }
    //  inline float &GetB() const { return *GetField<float>(this, 0x4); }
};

namespace NSimpleShadow {
    class SModelInfo;
}

class CActorMP1 : public CEntityMP1
{
private:
    class CModelDataMP1 *mModelData;
    void* qword28;
    void* qword30;
    void* qword38;
    int dword40;
    int pad;
    CObjectId mUnkObjId;
    int dword58;
    void* qword60;
    int dword68;
    char gap6C[52];
    class CToken *pctokenA0;
    void* qwordA8;
    void* qwordB0;
    void* qwordB8;
    char charC0;
    void* qwordC8;
    void* qwordD0;
    char gapD8[8];
    void* qwordE0;
    int dwordE8;
    int dwordEC;
    int dwordF0;
    __attribute__((packed)) __attribute__((aligned(1))) void* qwordF4;
    int dwordFC;
    int dword100;
    __attribute__((aligned(8))) char byte108;
    __attribute__((aligned(4))) char byte10C;
    int dword110;
    int dword114;
    int dword118;
    int dword11C;
    int dword120;
    char gap124[28];
    char char140;
    void* qword148;
    void* qword150;
    void* qword158;
    void* qword160;
    void* qword168;
    void* qword170;
    void* qword178;
    void* qword180;
    char char188;
    void* qword190;
    int dword198;
    int dword19C;
    int dword1A0;
    int dword1A4;
    int dword1A8;
    short word1AC;
    char byte1AE;
    char byte1AF;
    int dword1B0;
    char byte1B4;
    void* qword1B8;
    void* qword1C0;
    void* qword1C8;
    int dword1D0;
    __attribute__((packed)) __attribute__((aligned(1))) void* qword1D4;
    __attribute__((packed)) __attribute__((aligned(1))) void* qword1DC;
    int dword1E4;
public:
    enum ETrackedEmitterShouldLoop {};
    enum ETrackUnloopedEmitter {};
    enum EFluidState {};
    class EScanState {};

    CActorMP1(CEntityInfoMP1 const&,CTransform4f const&,CModelDataMP1 const&,CMaterialListMP1 const&,CActorParametersMP1 const&,CValueVersionId<uint,uint,ushort,16u,16u>);
    virtual ~CActorMP1();

    CEntityMP1& TypesMatch(int) override;
    void AcceptScriptMsg(EScriptObjectMessage,CValueVersionId<uint,uint,ushort,16u,16u>,CStateManager &) override;
    void SetActive(bool) override;
    void SetOwnerGOC(IMP1EntityBaseGOC &) override;
    void OnAreaIdChanged(CStateManager &,CValueVersionId<uint,ushort,ushort,16u,16u>) override;

    virtual void PreThink(float,CStateManager &);
    virtual void PreRender(CStateManager &,CFrustumPlanes const&);
    virtual void AddToRenderer(CFrustumPlanes const&,CStateManager const&);
    virtual void Render(CStateManager const&);
    virtual void CanRenderUnsorted(CStateManager const&) const;
    virtual void CalculateRenderBounds(void);
    virtual CHealthInfoMP1 &HealthInfo(CStateManager &);
    virtual void GetDamageVulnerability(void) const;
    virtual void GetDamageVulnerability(CValueVersionId<uint,uint,ushort,16u,16u>,CVector3f const&,CVector3f const&,CDamageInfoMP1 const&) const;
    virtual void RS14_ForceFailCanDamageTest(void) const;
    virtual void NotifyDamageEvent(CStateManager &,CValueVersionId<uint,uint,ushort,16u,16u> const&,CValueVersionId<uint,uint,ushort,16u,16u> const&,CDamageInfoMP1 const&,float,bool,CVector3f const&,CVector3f const&);
    virtual void GetTouchBounds(void) const;
    virtual void Touch(CActorMP1&,CStateManager &);
    virtual void GetOrbitPosition(CStateManager const&) const;
    virtual void GetAimPosition(CStateManager const&,float) const;
    virtual void GetHomingPosition(CStateManager const&,float) const;
    virtual void GetScanObjectIndicatorOffset(CStateManager const&) const;
    virtual void GetScanObjectIndicatorPosition(CStateManager const&) const;
    virtual void GetScanObjectCollisionPosition(CStateManager const&) const;
    virtual void GetCollisionResponseType(CStateManager &,CVector3f const&,CVector3f const&,CWeaponModeMP1 const&,int) const;
    virtual void ShouldUseCollisionActorOwnerForResponseType(void) const;
    virtual void FluidFXThink(CActorMP1::EFluidState,CScriptWaterMP1 &,CStateManager &);
    virtual void OnScanStateChange(CActorMP1::EScanState,CStateManager &);
    virtual void GetSortingBounds(CStateManager const&) const;
    virtual void GetTranslationForScanRange(CStateManager const&) const;
    virtual void MaterialFilterChanged(CStateManager &);
    virtual void DoUserAnimEvent(CStateManager &,CInt32POINodeMP1 const&,EUserEventType,float);
    virtual void MaterialListChanged(CStateManager &);
    virtual bool IsFrozen(void) const;
    virtual void GetAudioEmitterTransform(void) const;
    virtual void GetAudioEmitterRadius(void) const;
    virtual void InstallAudioEmitter(void);
    virtual void RemoveAudioEmitter(void);
    virtual void GetAudioEmitterCategory(void) const;
    virtual void EntityGOCTransformChangedCallback(CEntityGOC const&);
    virtual void Notify_GameStateNoTimerUpdates(void);
    virtual void Notify_GameStateNormal(void);
    virtual void GetDecalClassification(void) const;
    virtual void ResolveShadowSources(void);

    void SetRenderActive(bool);
    void GetParticipatesInTouch(void);
    void GetUseInSortedLists(void);
    void UpdateAnimation(float,CStateManager &,bool);
    void UpdateSoundEmitterPositions(void);
    void Character(void);
    void AnimationData(void);
    void StopLoopedSounds(void);
    void StopTrackedEmitterSound(void);
    void GetTrackedEmitterSoundId(void);
    void PlayTrackedEmitterSound(CStateManager &,CObjectId,CActorMP1::ETrackedEmitterShouldLoop);
    void ProcessSoundEvent(CObjectId,int,float,int,float,float,uchar,uchar,CVector3f const&,CVector3f const&,int,CStateManager &,CActorMP1::ETrackUnloopedEmitter);
    void RequestPlayTrackedEmitterSound(CStateManager &,CObjectId,CActorMP1::ETrackedEmitterShouldLoop,char const*);
    void RequestStopTrackedEmitterSound(CStateManager &,CObjectId,char const*);
    void PauseLoopedSounds(void);
    void UnpauseLoopedSounds(void);
    void SetPreRenderViaVisorEffectsManager(bool);
    void GetPreRenderViaVisorEffectsManager(void);
    void SetDrawShadow(bool);
    void GetAverageAnimVelocity(int);
    void HasAnimation(void);
    void GetAnimationData(void);
    void CalculateParticleRenderBounds(void);
    void HasModelData(void);
    CTransform4f& GetTransform(void) const;
    void SetModelData(CModelDataMP1 const&,CStateManager &);
    void SetPreRenderClipped(bool);
    void PreRenderShadow(CStateManager &,CFrustumPlanes const&);
    void AddParticleEffectsToRenderer(CStateManager const&);
    void EnsureRendered(CStateManager const&);
    void EnsureRendered(CStateManager const&,CVector3f const&,CAABox const&);
    void IsModelOpaque(CStateManager const&);
    void RenderModelData(CStateManager const&);
    void RenderParticleEffects(CStateManager const&);
    void GetYaw(void);
    void GetPitch(void);
    void GetRoll(void);
    void SetUseInSortedLists(bool);
    void GetCallTouch(void);
    void SetCallTouch(bool);
    void AddMaterial(EMaterialTypesMP1,CStateManager &);
    void AddMaterial(EMaterialTypesMP1,EMaterialTypesMP1,CStateManager &);
    void AddMaterial(EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,CStateManager &);
    void AddMaterial(EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,CStateManager &);
    void AddMaterial(EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,CStateManager &);
    void RemoveMaterial(EMaterialTypesMP1,CStateManager &);
    void RemoveMaterial(EMaterialTypesMP1,EMaterialTypesMP1,CStateManager &);
    void RemoveMaterial(EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,CStateManager &);
    void RemoveMaterial(EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,CStateManager &);
    void RemoveMaterial(EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,EMaterialTypesMP1,CStateManager &);
    void SetMaterialList(CStateManager &,CMaterialListMP1 const&);
    void SetSkinnedModel(CObjectId const&);
    void SetIceDarkeningFactor(float);
    void GetMaterialFilter(void);
    void SetMaterialFilter(CStateManager &,CMaterialFilterMP1 const&);
    void GetGroupId(void);
    void AddPreventRenderRequest(void);
    void RemovePreventRenderRequest(void);
    void ApplyCinematicRoot(void);
    CTransform4f SetTransform(const CTransform4f& transform);
    void SetInFluid(bool,CValueVersionId<uint,uint,ushort,16u,16u>);
    void GetScannableObjectInfo(void);
    void MoveScannableObjectInfoToActor(CActorMP1*,CStateManager &);
    void IsScannable(void);
    void SetMuted(bool);
    void SetVolume(uchar);
    void SetSoundEventPitchBend(int);
    void ClearSoundEventPitchBend(void);
    void GetTrackedEmitterHandle(void);
    void GetLocatorTransform(int);
    void GetLocatorTransform(CInt32POINodeMP1 const&);
    void GetLocatorTransform(rstl::basic_string<char,rstl::char_traits<char>,rstl::rmemory_allocator> const&);
    void GetScaledLocatorTransform(int);
    void GetScaledLocatorTransform(rstl::basic_string<char,rstl::char_traits<char>,rstl::rmemory_allocator> const&);
    void SetTranslation(CVector3f const&);
    void SetScale(CVector3f const&);
    void CreateShadowIfNeeded(void);
    void CanPrerenderUnsortedParts(void);
    void GetAudioEmitterId(void);
    void RenderDebugLocators(CStateManager const&);
    void GetTransformWithScale(void);
    void GetScale(void);
    void GetCharacter(void);
    void SetCalculateRenderBoundsWithoutRender(bool);
    void UpdateBoundsUsedForShadow(rstl::reserved_vector<NSimpleShadow::SModelInfo,2> const&);
};
