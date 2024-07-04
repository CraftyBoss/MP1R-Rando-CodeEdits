#pragma once

#include <CActors/CEntity.h>
#include <CObject/CObjectId.h>

class CStateManager;
class CDataEnumValue;

struct CGameArea
{
    int mAreaId;
    CObjectId mAreaAssetId;
    char size[14700];

    CGameArea(CValueVersionId<uint,ushort,ushort,16u,16u> const&,CObjectId const&,uint);
    ~CGameArea();
    void SetUnloadWhenLoadComplete(bool);
    void GetUnloadWhenLoadComplete(void);
    void SetLoadWhenUnloadingComplete(bool);
    void GetLoadWhenUnloadComplete(void);
    void SetPreloadWhenUnloadingComplete(bool);
    void GetPreloadWhenUnloadComplete(void);
    void LoadAreaAsync(CStateManager &,float,int &);
    void BuildSmallLists(void);
//    void EmitStateChangedCallbacks(CStateManager &,NGameArea::EAreaStateChange);
    void NotifyBeginUnload(void);
    void UnloadAreaAsync(CStateManager &,float);
//    void GameObjectSmallList(NGameObjectList::EGameObjectSmallList);
    void ProcessAreaScriptMessages(CStateManager &);
    bool IsPreloaded(void) const;
    bool IsFullyLoadedIncludingPromotedContent(void) const;
    bool IsFullyLoaded(void) const;
    bool IsUnloaded(void) const;
    bool IsUnloading(void) const;
    bool IsLoading(void) const;
    bool IsLoadingWaitingToFinalize(void) const;
    bool IsActive(void) const;
//    void SetActiveState(CStateManager &,CGameArea::EAreaActiveState);
    void AddEntity(CStateManager &,CEntityGOC &);
    bool IsGeneratedObject(CGuid const&) const;
//    void GenerateScriptObjectSet(CStateManager &,rstl::vector<CGuid,rstl::rmemory_allocator> const&,rstl::growable_reserved_vector<CTransform4f,16,rstl::rmemory_allocator> const&,NGeneration::SGenerateOptions const&,TFunctorR<void,CStateManager &,NGeneration::SGenerateOptions const&,rstl::memory_array<CValueVersionId<uint,uint,ushort,16u,16u> const> const&> const&,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &)	.text
//    void GenerateScriptObject(CStateManager &,CGuid const&,rstl::optional_object<CTransform4f,false> const&,NGeneration::SGenerateOptions const&,rstl::growable_reserved_vector<CGameObjectComponent *,16,rstl::rmemory_allocator> &)	.text
//    void GenerateScriptObjectSet_Pooled(CStateManager &,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> const&,rstl::growable_reserved_vector<CTransform4f,16,rstl::rmemory_allocator> const&,NGeneration::SGenerateOptions const&,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator>&)	.text
//    void GenerateScriptObject_Pooled(CStateManager &,CValueVersionId<uint,uint,ushort,16u,16u>,rstl::optional_object<CTransform4f,false> const&,NGeneration::SGenerateOptions const&,rstl::growable_reserved_vector<CGameObjectComponent *,16,rstl::rmemory_allocator> &)	.text
//    void GenerateScriptObject_ResetPooledSet(CStateManager &,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> const&,NGeneration::SGenerateOptions const&)	.text
//    void SetGeneratedScriptObjectTransform(CStateManager &,CEntityGOC &,rstl::optional_object<CTransform4f,false> const&,NGeneration::SGenerateOptions const&)	.text
//    void LoadReloadSets(CStateManager &,rstl::vector<CGuid,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> const&)	.text
//    void UnloadReloadSets(CStateManager &,rstl::vector<CGuid,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> const&)	.text
//    void TurnOnPerformanceGroups(CStateManager &,rstl::vector<CGuid,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> const&)	.text
//    void TurnOffPerformanceGroups(CStateManager &,rstl::vector<CGuid,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> const&)	.text
//    void BeginLoadUnitLoad(CStateManager &,rstl::vector<CGuid,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> const&,CValueVersionId<uint,uint,ushort,16u,16u>)	.text
//    void AddLoadUnitCommand(CStateManager &,CGameArea::ECommandType,rstl::vector<CGuid,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> const&,CValueVersionId<uint,uint,ushort,16u,16u>)	.text
//    void BeginLoadUnitUnload(CStateManager &,rstl::vector<CGuid,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> const&,CValueVersionId<uint,uint,ushort,16u,16u>)	.text
    void UpdateEffectsManager(CStateManager &,float);
    void UpdateDecalManager(CStateManager &,float);
    void StartQueuedCommand(CStateManager &);
    void ProcessLoadUnitCommand(CStateManager &,float);
    void AfterUpdateHandler(CStateManager &,float);
    void GetProductionWorkStage(void);
    void GetProductionWorkStages(void);
    void GetParentAssetId(void);
    void GetLegacyPathfindingId(void);
    CGameArea* GetParentArea(CStateManager const&);
    bool IsRootOfArea(CStateManager const&,CGameArea const&) const;
    void SetNeighborRooms(rstl::vector<CObjectId,rstl::rmemory_allocator> &&);
    void GetNeighborRooms(void);
    void GetRoomType(void);
    void GetStaticCollisionBounds(void);
    void SetStaticCollisionBounds(CAABox const&);
    void AccumulateStaticCollisionBounds(CAABox const&);
    bool IsInStaticCollisionBounds(CVector3f const&) const;
    void SetAreaTransform(CTransform4f const&);
    void UpdatePathFindAreaTransform(void);
    void MoveArea(CStateManager &,CVector3f const&);
//    void AddStateNotificationCallback(TFunctorR<void,CStateManager &,CGameArea&,NGameArea::EAreaStateChange const> const&);
//    void RemoveStateNotificationCallback(TFunctorR<void,CStateManager &,CGameArea&,NGameArea::EAreaStateChange const> const&);
//    void SetPathFindArea(rstl::optional_object<TLockedToken<CPFArea>,false> &);
    void GetPairedDock(CGuid const&);
    void GetDockToRoom(CGuid const&,CGuid const&);
//    void GetNeighboringRoomControllers(CGuid const&,rstl::vector<rstl::pair<CGuid,NGameArea::ERoomType>,rstl::rmemory_allocator> &);
    void GetZoneLightProbeBounds(CStateManager const&);
//    void GetGameObjectSmallList(NGameObjectList::EGameObjectSmallList);
    void NotifySetAsCurrentArea(CStateManager &);
    void NotifyRemovedAsCurrentArea(CStateManager &);
    void GetGameObjectSmallListByIndex(uint);
    void GameObjectSmallListByIndex(uint);
    void GetGameObjectSmallLists(void);
    void RegisterEntity(CDataEnumValue const&,CEntityGOC const&);
    void DeregisterEntity(CDataEnumValue const&,CValueVersionId<uint,uint,ushort,16u,16u>);
    void GetFirstEntityUniqueIdForDataEnum(CDataEnumValue const&);
    void GetEnvironmentVarValue(CStateManager const&,CGuid const&);
    void SetEnvironmentVarValue(CStateManager &,CGuid const&,int,NScriptMsg::SOriginator const&);
    void BroadcastEnvironmentVarChanged(CStateManager &,CGuid const&,int,int,NScriptMsg::SOriginator const&);
    void AddToEnvironmentVarValue(CStateManager &,CGuid const&,int,NScriptMsg::SOriginator const&);
    void PingEnvironmentVar(CStateManager &,CGuid const&,NScriptMsg::SOriginator const&);
    void BroadcastEnvironmentVarPinged(CStateManager &,CGuid const&,NScriptMsg::SOriginator const&);
    void PingDataEnum(CStateManager &,CDataEnumValue const&,NScriptMsg::SOriginator const&);
    void BroadcastDataEnumPinged(CStateManager &,CDataEnumValue const&,NScriptMsg::SOriginator const&);
//    void ConnectEnvironmentVarChangedCallback(TFunctorR<void,CStateManager &,CGuid const&,int const,int const,NScriptMsg::SOriginator const&> const&);
//    void ConnectEnvironmentVarPingedcallback(TFunctorR<void,CStateManager &,CGuid const&,NScriptMsg::SOriginator const&> const&);
//    void ConnectDataEnumPingedcallback(TFunctorR<void,CStateManager &,CDataEnumValue const&,NScriptMsg::SOriginator const&> const&);
    void QueueScriptMsg(CScriptMsg const&);
    void ConnectOneTimePumpScriptMsgsCallback(TFunctorR<void,CStateManager &> const&);
    void ConnectAdditionalLoadRequestCallback(TFunctorR<bool,CStateManager &,float const> const&);
    void HandleAdditionalLoadRequestCallbacks(CStateManager &,float);
//    void ConnectAreaLoadedCallback(TFunctorR<void,CStateManager &> const&);
    void HandleAreaLoadedCallbacks(CStateManager &);
    void FinishAreaLoad(CStateManager &);
    void OnCancelAreaLoad(void);
    void HasPendingAreaScriptMessages(void);
    void OnCancelPreload(void);
    void CanBeginUnloadImmediately(void);
    void HaveLoadUnitsChangedSinceLastLoad(CStateManager &);
    void GetObjectCount(void);
//    void ConnectEntitiesGeneratedCallback(TFunctorR<void,CStateManager &,rstl::growable_reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,32,rstl::rmemory_allocator> const&> const&);
};