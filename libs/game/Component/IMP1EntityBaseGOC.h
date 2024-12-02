#pragma once

#include "CGameObjectComponent.h"
#include "NScript/NScriptMsg.h"

class IMP1EntityBaseGOC : public CGameObjectComponent
{
private:
    CEntityGOC* mEntityGOC;
    bool byte48;
    void* qword50;
    void* qword58;
    void* qword60;
    void* qword68;
    void* qword70;
    void* qword78;
    void* qword80;
    void* qword88;
    void* qword90;
    void* qword98;
    void* qwordA0;
    void* qwordA8;
    void* qwordB0;
    void* qwordB8;
    void* qwordC0;
    void* qwordC8;
    void* qwordD0;
    void* qwordD8;
    void* qwordE0;
    void* qwordE8;
    void* qwordF0;
    void* qwordF8;
public:
    virtual bool TypesMatch(int) const override;
    virtual void GetInterfaceType(void) override;

    IMP1EntityBaseGOC(SGOComponentInfo &);
    virtual ~IMP1EntityBaseGOC() override;

    CEntityGOC* EntityMP1(void);
    CEntityGOC* GetEntityMP1(void);
    CEntityGOC* SetEntityMP1(class CEntityMP1 *);

    virtual void EntityLoaded(CStateManager &,CGameObjectComponent::SEntityLoadedInfo const&) override;
    virtual void AreaEntitiesLoaded(CStateManager &) override;

    void OnActivationStateChange(CStateManager &,CScriptMsg const&);
    void TranslateAndAcceptScriptMessage(CScriptMsg const&,CStateManager &);
    void TranslateAndSendScriptMessages(EScriptObjectState,CStateManager &, EScriptObjectMessage);
    void TranslateAndSendScriptMessagesForConnection(class SConnection const&,CStateManager &,EScriptObjectMessage);

    virtual void TranslateScriptMessageToAction(EScriptObjectMessage,bool);
    virtual void TranslateScriptActionToMessage(NScriptMsg::EScriptAction,bool);
    virtual void TranslateScriptStateToEvent(EScriptObjectState);
    virtual void TranslateScriptEventToState(NScriptMsg::EScriptEvent);
    virtual void CanTranslateScriptStateToEvent(EScriptObjectState);

    void PrePhysicsUpdate(CStateManager &,float);
    void PostPhysicsUpdate(CStateManager &,float);
    void TransformChanged(CEntityGOC const&);
};
