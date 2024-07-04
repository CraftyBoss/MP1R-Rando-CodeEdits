#pragma once

#include "CActors/CEntity.h"
#include "Types/TFunctorR.h"
#include <CActors/CActor.h>
#include <CActors/MP1/CPlayerMP1.h>
#include <CActors/MP1/CPlayerState.h>
#include <CActors/MP1/CScriptMailboxMP1.h>
#include <rstl/reserved_vector.h>
#include <rstl/single_ptr.h>

class CStateManager;

class CSinglePathMazeMP1;
class CStateManagerUpdateAccess;
class CPlane;
class CParticleGen;
class CParticleGen;
class CGameProjectileMP1;
class CIncludeExcludeCollisionFilterMP1;
class CDamageVulnerabilityMP1;
class CCollisionResponseData;
class CRayCastResultMP1;
class CFixedLengthRay;

struct SConnectionTarget;

enum EGameObjectListMP1 {};
enum EListenNoiseType {};

namespace NSceneRenderSort {
    enum ESortType {};
}

namespace rstl {
    template <typename T, bool DefaultValue = false>
    class optional_object;
}

class CStateManagerGameLogicMP1 {
public:
    enum EGameState { kGS_Running, kGS_SoftPaused, kGS_Paused };
    enum EPauseScreen {};
    enum EBossType {};
    enum EPlayerDeadAlphaType {};

    CStateManagerGameLogicMP1(void);
    ~CStateManagerGameLogicMP1();
    void GameObjectCreated(CStateManager &,CEntityGOC &);
    void RendererDrawCallback(void const*,void const*,int);
    void Initialize(CStateManager &);
    void GameObjectDeleted(CStateManager &,CEntityGOC &);
    void InitializeState(CStateManager &,CObjectId,CObjectId,CObjectId);
    void GameMainLoop(CStateManager &,CStateManagerUpdateAccess &,float);
    void DoDebugDumps(void);
    void UpdateGameState(void);
    void UpdateRedundantHintSystem(CStateManager &,float);
    void DoPreThinkLogic(CStateManager &,float);
    void UpdateSortedLists(CStateManager &);
    void ProcessPlayerInput(CStateManager &);
    void DoTouchLogic(CStateManager &,CStateManagerUpdateAccess &);
    void DoThinkLogic(CStateManager &,CStateManagerUpdateAccess &,float);
    void UpdateXRay(float);
    void UpdateThermal(CStateManager &,float);
    void ObjectById(CValueVersionId<uint,uint,ushort,16u,16u>);
    void DoPostThinkLogic(CStateManager &,float);
    void UpdateXRayHints(CStateManager &,float);
    void DoUpdateDisplayManager(CStateManager &,CStateManagerUpdateAccess &,float);
    void DoPostCameraMove(CStateManager &,CStateManagerUpdateAccess &,float);
    void EnterMessageScreen(uint,float,bool,CObjectId const&);
    void UpdateEscapeSequenceTimer(CStateManager &,float);
    void UpdateEnvFx(CStateManager &,float);
    void UpdateScreenFxRandom(CStateManager &,float);
    void UpdateStreamAudio(float);
    void ProcessInput(CStateManager &,CFinalInput const&);
    void UpdateRenderState(CStateManager &);
    void WorldExists(void);
    void GetVisAreaId(CStateManager &);
    void PreRender(CStateManager &);
    void DrawWorld(CStateManager &);
    void IncrementRenderFrameCount(void);
    void OnUnloadAreasForShutdown(CStateManager &);
    void Shutdown(CStateManager &);
    void AreaLoaded(CStateManager &,CValueVersionId<uint,ushort,ushort,16u,16u>);
    void OnAllInitialAreasLoaded(CStateManager &);
    void UpdateRoomAcoustics(CValueVersionId<uint,ushort,ushort,16u,16u>);
    void GameObjectSmallList(EGameObjectListMP1);
    void DeliverScriptMsg(CEntityMP1 *,CValueVersionId<uint,uint,ushort,16u,16u>,EScriptObjectMessage);
    bool IsPlayerAlive(CStateManager const&);
    CPlayerStateMP1* GetPlayerState(void) const;
    void GetWorldTransitionAreaId(uint);
    void GameRenderer(void);
    void GetGameRenderer(void);
    void GetDecalManagerMP1(void);
    void CreateRenderCommandStates(void);
    void GetRenderFrameCount(void);
    void PushRenderCommandStates(void);
    void GetCurrentAreaId(void);
    void GetCurrentAreaAssetId(void);
    void SetCurrentAreaId(CObjectId,CValueVersionId<uint,ushort,ushort,16u,16u>);
    void MarkAreaVisited(CObjectId);
    void MapWorldInfo(void);
    void GetMapWorldInfo(void);
    void GetObjectByEntityGOC(CEntityGOC const&);
    void ObjectByEntityGOC(CEntityGOC &);
    void GetObjectByEntityGOCEvenOutOfLookup(CEntityGOC const&);
    void ObjectByEntityGOCEvenOutOfLookup(CEntityGOC &);
    void GetObjectById(CValueVersionId<uint,uint,ushort,16u,16u>);
    void GetObjectByIdEvenOutOfLookup(CValueVersionId<uint,uint,ushort,16u,16u>);
    void ObjectByIdEvenOutOfLookup(CValueVersionId<uint,uint,ushort,16u,16u>);
    void RenderCommandState(void);
    void GetRenderCommandState(void);
    void GuiRenderCommandState(void);
    void GetGuiRenderCommandState(void);
    void GetIdForScript(SConnectionTarget const&);
    void GetIdForScript(CGuid);
    void GetEditorIdForUniqueId(CValueVersionId<uint,uint,ushort,16u,16u>);
    void GetUpdateCount(void);
    bool IsRandomAvailable(void);
    void SetRandomAvailable(bool);
    void GetSinglePathMaze(void);
    void SinglePathMaze(void);
    void SetSinglePathMaze(rstl::single_ptr<CSinglePathMazeMP1> &&);
    void SetGameState(CStateManagerGameLogicMP1::EGameState);
    CScriptMailboxMP1* ScriptMailbox(void);
    CScriptMailboxMP1* GetScriptMailbox(void) const;
    void BuildNearList(rstl::reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,1024> &,CAABox const&,CMaterialFilterMP1 const&,CActorMP1 const*);
    void CalculateObjectBounds(CActorMP1 const&);
    void UpdateActorInSortedLists(CActorMP1 &);
    void UpdateObjectInLists(CEntityMP1 &);
    void BuildColliderList(rstl::reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,1024> &,CActorMP1 const&,CAABox const&);
    void BuildNearList(rstl::reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,1024> &,CVector3f const&,CVector3f const&,float,CMaterialFilterMP1 const&,CActorMP1 const*);
    void CanCreateProjectile(CValueVersionId<uint,uint,ushort,16u,16u>,EWeaponType,int);
    void AddWeaponId(CValueVersionId<uint,uint,ushort,16u,16u>,EWeaponType);
    void RemoveWeaponId(CValueVersionId<uint,uint,ushort,16u,16u>,EWeaponType);
    void GetWeaponIdCount(CValueVersionId<uint,uint,ushort,16u,16u>,EWeaponType);
    void DrawSpaceWarp(CStateManager const&,CVector3f const&,float,bool);
    void TouchPlayerActor(CStateManager &);
    void DisplayPlayerCoord(void);
    void ResetEscapeSequenceTimer(float);
    void SpecialSkipCinematic(void);
    void AddDrawableActor(CActorMP1 const&,CVector3f const&,CAABox const&,float,NGameWater::EWaterSortType);
    void AddDrawableActorParticle(CActorMP1 const&,CVector3f const&,CAABox const&,float,NSceneRenderSort::ESortType);
    void AddPlaneObject(CActorMP1 const&,CPlane const&,CAABox const&);
    void AddParticleGen(CParticleGen const&,float);
    void AddParticleGenExplicit(CParticleGen const&,CVector3f const&,CAABox const&,float);
    void AddProjectile(CGameProjectileMP1 const&);
    void SendScriptMsg(CValueVersionId<uint,uint,ushort,16u,16u>,CGuid,EScriptObjectMessage,EScriptObjectState);
    void DeliverScriptMsg(CValueVersionId<uint,uint,ushort,16u,16u>,CValueVersionId<uint,uint,ushort,16u,16u>,EScriptObjectMessage);
    void SetDesiredPauseScreen(CStateManagerGameLogicMP1::EPauseScreen);
    void CanEnterMapScreen(void);
    void SetEnergyBarActorInfo(CValueVersionId<uint,uint,ushort,16u,16u>,float,CStateManagerGameLogicMP1::EBossType,bool);
    void GetEnergyBarActorStringId(void);
    void SetBillboardParams(rstl::basic_string<char,rstl::char_traits<char>,rstl::rmemory_allocator> const&,CVector2i const&,CVector2i const&);
    void ClearBillboardParams(void);
    void GetGameObjectSmallList(EGameObjectListMP1);
    void GetPlayerDeadAlpha(CStateManagerGameLogicMP1::EPlayerDeadAlphaType);
    void AddObjectToSmallLists(CEntityMP1 &);
    void RemoveObjectFromSmallLists(CEntityMP1 &);
    void DeleteObjectRequest(CValueVersionId<uint,uint,ushort,16u,16u>);
    void DeleteObjectRequest(CEntityMP1 &);
    void RayWorldIntersection(CValueVersionId<uint,uint,ushort,16u,16u> &,CVector3f const&,CVector3f const&,float,CIncludeExcludeCollisionFilterMP1 const&,rstl::reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,1024> const&);
    void RayStaticIntersection(CVector3f const&,CVector3f const&,float,CIncludeExcludeCollisionFilterMP1 const&);
    void LineOfSightTest(CVector3f const&,CVector3f const&,rstl::reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,1024> const&,CIncludeExcludeCollisionFilterMP1 const&,CActorMP1 const*);
    void LineOfSightTestInternal(CVector3f const&,CVector3f const&,CIncludeExcludeCollisionFilterMP1 const&,rstl::reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,1024> const&,CActorMP1 const*);
    void LineOfSightTest(CVector3f const&,CVector3f const&,CMaterialFilterMP1 const&,CActorMP1 const*);
    void SetEntityAreaId(CEntityMP1 &,CValueVersionId<uint,ushort,ushort,16u,16u>);
    void CreateStandardGameObjects(CStateManager &);
    void SetupViewForDraw(CStateManager const&,CAABox2i const&);
    void DrawDebugStuff(void);
    void RenderCamerasAndAreaLights(void);
    void DrawE3DeathEffect(void);
    void DrawAdditionalFilters(void);
    void ApplyDamageDirectly(CStateManager &,CValueVersionId<uint,uint,ushort,16u,16u>,CValueVersionId<uint,uint,ushort,16u,16u>,CValueVersionId<uint,uint,ushort,16u,16u>,CDamageInfoMP1 const&,float);
    void ApplyLocalDamage(CVector3f const&,CVector3f const&,CActorMP1 &,float,CDamageInfoMP1 const&,CValueVersionId<uint,uint,ushort,16u,16u>,bool);
    void ApplyKnockBack(CStateManager &,CActorMP1 &,CDamageInfoMP1 const&,CDamageVulnerabilityMP1 const&,CVector3f const&,float);
    void ApplyDamage(CStateManager &,CValueVersionId<uint,uint,ushort,16u,16u>,CValueVersionId<uint,uint,ushort,16u,16u>,CValueVersionId<uint,uint,ushort,16u,16u>,CDamageInfoMP1 const&,CMaterialFilterMP1 const&,CVector3f const&,rstl::optional_object<CVector3f,false> const&,bool);
    void ProcessRadiusDamage(CStateManager &,CActorMP1 const&,CActorMP1&,CValueVersionId<uint,uint,ushort,16u,16u>,CDamageInfoMP1 const&,CMaterialFilterMP1 const&);
    void ApplyDamageToWorld(CStateManager &,CValueVersionId<uint,uint,ushort,16u,16u>,CActorMP1 const&,CVector3f const&,CDamageInfoMP1 const&,CMaterialFilterMP1 const&);
    void TestBombHittingWater(CActorMP1 const&,CVector3f const&,CActorMP1&);
    void CanDamage(CVector3f const&,CActorMP1 const&,rstl::reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,1024> &);
    void ApplyRadiusDamage(CStateManager &,CActorMP1 const&,CVector3f const&,CValueVersionId<uint,uint,ushort,16u,16u>,CActorMP1&,CDamageInfoMP1 const&);
    void InformListeners(CVector3f const&,EListenNoiseType);
    void AreaGameLogic(CValueVersionId<uint,ushort,ushort,16u,16u> const&);
    void DoCollisionResponse(CStateManager &,CCollisionResponseData const&,CRayCastResultMP1 const&,CValueVersionId<uint,uint,ushort,16u,16u>,CDamageInfoMP1 const&,bool,bool);
    void GetAreaGameLogic(CValueVersionId<uint,ushort,ushort,16u,16u> const&);
    void SetMessageAfterScreenCounter(uint,uint,float,CObjectId const&);
    void AdjustFogVolumeHeight(float);
    bool IsAreaFullyLoaded(CValueVersionId<uint,ushort,ushort,16u,16u> const&);
    void GetAreaGameLogic(CObjectId const&);
    void GetAreaIdFromWe2AssetId(CStateManager const&,CObjectId);
    void CanDamageStaticTest(CFixedLengthRay const&,CIncludeExcludeCollisionFilterMP1 const&);
    void ApplyPlayerKnockBackForce(CStateManager &,CPlayerMP1 &,CVector3f const&,float,float);
    bool IsAi(CEntityMP1 const*);
    void ShouldUpdateAi(CStateManager &,IMP1EntityBaseGOC const&);
    void ConnectPostThink(TFunctorR<void,float const,CStateManager &> const&);
    void GetPlayerPhysicsActor(void);
    void PlayerPhysicsActor(void);
    void GetPlayerActor(void);
    void PlayerActor(void);
    void RecursiveDrawTree(CValueVersionId<uint,uint,ushort,16u,16u>);
    void RenderLast(CValueVersionId<uint,uint,ushort,16u,16u> const&);
    void RenderFirstSorted(CValueVersionId<uint,uint,ushort,16u,16u> const&);
    void RenderLastAfterCameraFilters(CValueVersionId<uint,uint,ushort,16u,16u> const&);
    static CPlayerStateMP1* PlayerState(void);
    bool IsHudMessageActive(void);
    void GetGameLogicType(void);
    bool IsFullyInitialized(void);
    void RequiresLegacyGraveyard(void);
    bool IsPaused(void);
};