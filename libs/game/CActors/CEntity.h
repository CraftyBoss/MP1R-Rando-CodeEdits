#pragma once

#include "types.h"
#include "NScript/NScriptMsg.h"
#include "Types/CValueVersionId.h"

class CEntityMP1
{
private:
    class IMP1EntityBaseGOC *mEntityBase;
    int mUniqueId;
    int mAreaId;
    bool mIsValid;
public:
    CEntityMP1(class CEntityInfoMP1 const&);
    virtual ~CEntityMP1();

    virtual CEntityMP1& TypesMatch(int);
    virtual void Think(float,class CStateManager &);
    virtual void AcceptScriptMsg(class EScriptObjectMessage,CValueVersionId<uint,uint,ushort,16u,16u>,CStateManager &);
    virtual void SetActive(bool);
    virtual void SetOwnerGOC(IMP1EntityBaseGOC &);
    virtual void OnAreaIdChanged(CStateManager &,CValueVersionId<uint,ushort,ushort,16u,16u>);

    void SendScriptMsgs(class EScriptObjectState,CStateManager &,EScriptObjectMessage);
    void SendActive(CStateManager &,bool);
    void GetAreaIdForPersistence(void);
    void CheckConnectedObject_if(CStateManager const&,EScriptObjectState,EScriptObjectMessage,class CValidEntityPredicate const&);
    void GetConnectionList(void);
    void __TranslateScriptMessageToAction_SELF(EScriptObjectMessage,bool);
    void __TranslateScriptActionToMessage_SELF(NScriptMsg::EScriptAction,bool);
    void TranslateScriptStateToEvent(EScriptObjectState,bool);
    void TranslateScriptEventToState(NScriptMsg::EScriptEvent);
    void IsMP1Connection(CStateManager const&, class SConnection const&,EScriptObjectState,EScriptObjectMessage,bool);
    void IsMP1State(SConnection const&,EScriptObjectState,bool);
    void Area(void);
    void GetArea(void);
};
