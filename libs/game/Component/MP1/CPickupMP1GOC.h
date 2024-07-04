#pragma once

#include "Component/IMP1EntityBaseGOC.h"
#include <Script/SLdrCommon.h>

class SLdrPickupMP1 : public SGOComponentProperties
{
public:
    SLdrPickupMP1();

    SLdrVector_MP1Typedef mCollExtent;
    SLdrVector_MP1Typedef mCollOffset;
    CObjectId itemID;
    SLdrAnimSet_MP1Typedef animSet;
    CObjectId mAreaAssetId;
    SLdrVector_MP1Typedef vec3;
    SLdrMapInfo_MP1Typedef mapInfo;
    SLdrActorInformation_MP1Typedef actorInfo;

    int mItemType;
    int mItemCapacity;
    int mItemStackSize;
    float mPossibility;
    float mLifeTime;
    float mFadeInTime;
    float mStartDelay;
    bool unkBool13;
    bool unkBool14;
};


class CPickupMP1GOC : public IMP1EntityBaseGOC
{
private:
    void* qword100;
    char gap108[632];
    bool byte380;
    char gap388[56];
public:
    CPickupMP1GOC(SGOComponentInfo &);
    virtual ~CPickupMP1GOC() override;

    CGameObjectComponent* CastToPtr(CGameObjectComponent &);
    CGameObjectComponent& CastToPtr(CGameObjectComponent *);

    CGameObjectComponent const* CastToConstPtr(CGameObjectComponent const&);
    CGameObjectComponent const& CastToConstPtr(CGameObjectComponent const*);

    void AcceptScriptMsg(CStateManager &,CScriptMsg const&);
    void OnAction_Delete(CStateManager &,CScriptMsg const&);
    void OnAction_Activate_Legacy(CStateManager &,CScriptMsg const&);
    void OnAction_Deactivate_Legacy(CStateManager &,CScriptMsg const&);
    void OnAction_ToggleActive(CStateManager &,CScriptMsg const&);

    virtual void TranslateScriptMessageToAction(EScriptObjectMessage,bool) override;
    virtual void TranslateScriptActionToMessage(NScriptMsg::EScriptAction,bool) override;
    virtual void TranslateScriptStateToEvent(EScriptObjectState) override;
    virtual void TranslateScriptEventToState(NScriptMsg::EScriptEvent) override;
    virtual void CanTranslateScriptStateToEvent(EScriptObjectState) override;

    virtual void Create(CStateManager &,CGameObjectComponent::SCreateInfo const&) override;
    virtual EGOComponentType GetComponentType(void) override;
};