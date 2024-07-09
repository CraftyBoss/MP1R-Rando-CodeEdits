#pragma once

#include "EGOComponentType.h"
#include "NScript/NScriptMsg.h"
#include "SGOComponentInfo.h"
#include "Types/CValueVersionId.h"
#include "rstl/rc_ptr.hpp"
#include "types.h"
#include <Math.hpp>

namespace NGeneration {
    struct SGenerationInfo {
        CObjectId mAreaAssetId;
        TUniqueId mObjId;
        bool unkBool1;
        bool unkBool2;
        int unkInt1;
    };
    class SGenerateOptions;
}

class CScriptMsg;

class CGameArea;
class CStateManager;
class CStateManagerObject;
class CValidConnectionPredicate;

class SLdrActionPayload;
class IGameObjectComponentVisitorNc;

enum ETypedefInterfaceType {};
enum EComponentInterfaceType {};

class CGameObjectComponent
{
private:
    char byte8;
    void* qword10;
    int dword18;
    class CEntityGOC *mEntityGOCPtr;
    char byte28;
    __attribute__((aligned(8))) char byte30;
    void* qword38;
public:
    struct SCreateInfo {
        enum EIsGeneratedObject {};
        enum EIsLayerActive {};
        enum EIsAreaRelativeTransform {};

        SCreateInfo(CValueVersionId<uint,uint,ushort,16u,16u>,CValueVersionId<uint,uint,ushort,16u,16u>,NGeneration::SGenerationInfo const&,CGameArea &,CGameObjectComponent::SCreateInfo::EIsGeneratedObject,CGameObjectComponent::SCreateInfo::EIsLayerActive,CGameObjectComponent::SCreateInfo::EIsAreaRelativeTransform);
        SCreateInfo(CValueVersionId<uint,uint,ushort,16u,16u>,CGameObjectComponent::SCreateInfo const&);

        TUniqueId verId1;
        TUniqueId verId2;
        NGeneration::SGenerationInfo mGenerationInfo;
        CGameArea *mGameArea;
        bool mIsGeneratedObject;
        bool mIsLayerActive;
        bool mIsAreaRelativeTransform;
    };

    struct SEntityLoadedInfo {
        SEntityLoadedInfo(void);
    };

    static void DestroyComponent(CGameObjectComponent&);

    CGameObjectComponent(SGOComponentInfo &);
    virtual ~CGameObjectComponent();

    virtual EGOComponentType GetComponentType() = 0;
    virtual void GetInterfaceType() = 0;
    virtual bool TypesMatch(int) const;
    virtual void Create(CStateManager &,CGameObjectComponent::SCreateInfo const&);
    virtual void EntityLoaded(CStateManager &,CGameObjectComponent::SEntityLoadedInfo const&);

    void ConnectAreaFunctors(CStateManager &);

    // probably private
    virtual void ConnectAreaFunctorsInternal(CStateManager &);

    virtual void AreaEntitiesLoaded(CStateManager &);
    virtual void AcceptScriptMsg(CStateManager *, const CScriptMsg *) = 0;
    virtual void OnActivationStateChange(CStateManager *, const CScriptMsg *) = 0;
    virtual void AreaMoved(CStateManager &,CVector3f const&);
    virtual void PostAreaMoved(CStateManager &,CVector3f const&);
    virtual void AreaLoadedCallback(CStateManager &);


    void GetEntityUniqueId(void);
    void ConnectionListOwnedCopy(void);
    void LinkListOwnedCopy(void);
    void GetGenerationInfo(void);
    void OnAction_ActivateGameObject(CStateManager &,CScriptMsg const&);
    void OnAction_DeactivateGameObject(CStateManager &,CScriptMsg const&);
    void OnAction_ActivateComponent(CStateManager &,CScriptMsg const&);
    void OnAction_DeactivateComponent(CStateManager &,CScriptMsg const&);
    void QueueScriptMsgs(NScriptMsg::EScriptEvent,CStateManager const&);
    void QueueScriptMsgs(NScriptMsg::EScriptEvent,CStateManager const&,NScriptMsg::SOriginator const&);
    void QueueScriptMsgs(NScriptMsg::EScriptEvent,CStateManager const&,NScriptMsg::SOriginator const&,rstl::rc_ptr<SLdrActionPayload const> const&);
    void QueueScriptMsgs(NScriptMsg::EScriptEvent,CStateManager const&,rstl::rc_ptr<SLdrActionPayload const> const&);
    void QueueScriptMessagesForConnection(CStateManager const&,SConnection const&,rstl::rc_ptr<SLdrActionPayload const> const&,NScriptMsg::SOriginator const&);
    void QueueScriptMsg(CScriptMsg const&);
    void QueueScriptMsgToSelf(NScriptMsg::EScriptAction,rstl::rc_ptr<SLdrActionPayload const> const&);
    void QueueScriptMsgToGameObject(NScriptMsg::EScriptAction,rstl::rc_ptr<SLdrActionPayload const> const&);
    void GetConnectionRange(NScriptMsg::EScriptEvent,ETypedefInterfaceType);
    void FindConnectedObject(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction);
    void ConnectedObjectRange(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction,CValidConnectionPredicate const*);
    void FindConnectedObject_if(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction,CValidConnectionPredicate const&);
    void FindConnectedObjects(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void BuildConnectedUniqueObjectCount(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction);
    void FindConnectedObjects_if(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction,CValidConnectionPredicate const&,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void FindLinkedObject(CStateManagerObject const&,NScriptMsg::EScriptLink);
    void LinkedObjectRange(CStateManagerObject const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const*);
    void FindLinkedObject_if(CStateManagerObject const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const&);
    void FindOneLinkedObject(CStateManagerObject const&,NScriptMsg::EScriptLink);
    void FindOneLinkedObject_if(CStateManagerObject const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const&);
    void FindLinkedObjects(CStateManagerObject const&,NScriptMsg::EScriptLink,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void BuildLinkedUniqueObjectCount(CStateManagerObject const&,NScriptMsg::EScriptLink);
    void FindLinkedObjects(CStateManagerObject const&,NScriptMsg::EScriptLink,rstl::growable_reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,32,rstl::rmemory_allocator> &);
    void FindLinkedObjects_if(CStateManagerObject const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const&,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void FindLinkedObjects_if(CStateManagerObject const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const&,rstl::growable_reserved_vector<CValueVersionId<uint,uint,ushort,16u,16u>,32,rstl::rmemory_allocator> &);
    void FindLinkedRepresentativeObjects(CStateManager const&,NScriptMsg::EScriptLink,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void FindLinkedRepresentativeObjects_if(CStateManager const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const&,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void FindLinkedComponent(CStateManagerObject const&,NScriptMsg::EScriptLink,EComponentInterfaceType);
    void LinkedComponentRange(CStateManagerObject const&,NScriptMsg::EScriptLink,EComponentInterfaceType,CValidConnectionPredicate const*);
    void FindLinkedComponent_if(CStateManagerObject const&,NScriptMsg::EScriptLink,EComponentInterfaceType,CValidConnectionPredicate const&);
    void FindLinkedComponentPrioritized_if(CStateManagerObject const&,NScriptMsg::EScriptLink,rstl::vector<EComponentInterfaceType,rstl::rmemory_allocator> const&,CValidConnectionPredicate const&);
    void FindOneLinkedComponent(CStateManagerObject const&,NScriptMsg::EScriptLink,EComponentInterfaceType);
    void FindOneLinkedComponent_if(CStateManagerObject const&,NScriptMsg::EScriptLink,EComponentInterfaceType,CValidConnectionPredicate const&);
    void FindLinkedComponents(CStateManagerObject const&,NScriptMsg::EScriptLink,EComponentInterfaceType,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void FindLinkedComponents_if(CStateManagerObject const&,NScriptMsg::EScriptLink,EComponentInterfaceType,CValidConnectionPredicate const&,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void FindLinkedComponentsPrioritized(CStateManagerObject const&,NScriptMsg::EScriptLink,rstl::vector<EComponentInterfaceType,rstl::rmemory_allocator> const&,rstl::vector<CValueVersionId<uint,uint,ushort,16u,16u>,rstl::rmemory_allocator> &);
    void VisitLinkedComponents(CStateManager &,NScriptMsg::EScriptLink,EComponentInterfaceType,IGameObjectComponentVisitorNc &);
    void HasConnectedEvent(NScriptMsg::EScriptEvent);
    void HasConnectedObject(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction);
    void HasConnectedObject_if(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction,CValidConnectionPredicate const&);
    void HasLinkedObject(CStateManagerObject const&,NScriptMsg::EScriptLink);
    void HasLinkedObject_if(CStateManagerObject const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const&);
    void HasLink(NScriptMsg::EScriptLink);
    void BuildLinkedEditorIdCount(NScriptMsg::EScriptLink);
    void LinkedObjectRangeWithData(CStateManagerObject const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const*);
    void LinkedRepresentativeObjectRange(CStateManager const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const*);
    void LinkedRepresentativeObjectRangeWithData(CStateManager const&,NScriptMsg::EScriptLink,CValidConnectionPredicate const*);
    void LinkedComponentRangeWithData(CStateManagerObject const&,NScriptMsg::EScriptLink,EComponentInterfaceType,CValidConnectionPredicate const*);
    void ConnectedObjectRangeWithData(CStateManagerObject const&,NScriptMsg::EScriptEvent,NScriptMsg::EScriptAction,CValidConnectionPredicate const*);
    void LinkedComponentPrioritizedRange(CStateManagerObject const&,NScriptMsg::EScriptLink,rstl::vector<EComponentInterfaceType,rstl::rmemory_allocator> const&);
    void LinkedComponentPrioritizedRangeWithData(CStateManagerObject const&,NScriptMsg::EScriptLink,rstl::vector<EComponentInterfaceType,rstl::rmemory_allocator> const&);
    void IncrementUniqueIdVersion(CStateManagerObject &);
    virtual void ResetForGeneration(CStateManager &,NGeneration::SGenerateOptions const&);

    bool IsActive(void) const;
    CEntityGOC* GetEntityGOC(void) const; // return this->mEntityGOCPtr;
};
