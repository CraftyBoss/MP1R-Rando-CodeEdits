#pragma once

#include "NScript/NScriptMsg.h"
#include "Types/CValueVersionId.h"
#include "types.h"
#include <Component/CGameObjectComponent.h>
#include <Math.hpp>

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
    virtual void AcceptScriptMsg(EScriptObjectMessage,CValueVersionId<uint,uint,ushort,16u,16u>,CStateManager &);
    virtual void SetActive(bool);
    virtual void SetOwnerGOC(IMP1EntityBaseGOC &);
    virtual void OnAreaIdChanged(CStateManager &,CValueVersionId<uint,ushort,ushort,16u,16u>);

    void SendScriptMsgs(EScriptObjectState,CStateManager &,EScriptObjectMessage);
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

    inline IMP1EntityBaseGOC* GetEntityBaseGOC() {return mEntityBase; }
    inline const IMP1EntityBaseGOC* GetEntityBaseGOC() const {return mEntityBase; }
    inline int GetUniqueId() const {return mUniqueId; }
};

class CEntityGOC : public CGameObjectComponent {
//private:
public:
    CTransform4f *mTransform;
    void* qword48;
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
    char gapA0[8];
    char *pcharA8;
    int mComponentIdTableMax;
    int mComponentCount;
    int *mComponentIdTable;
    void* qwordC0;
    char gapC8[8];
    char *pcharD0;
    int intD8;
    int intDC;
    char *pcharE0;
    void* qwordE8;
    char gapF0[8];
    char *pcharF8;
    int int100;
    int int104;
    char *pchar108;
    short word110;
    char gap112[6];
    CGameArea *mGameArea;
    int int120;
    int int124;
    int int128;
    char gap12C[12];
    void* qword138;
    void* qword140;
    void* qword148;
    void* qword150;
    void* qword158;
    void* qword160;
    void* qword168;
    void* qword170;
    void* qword178;
    void* qword180;
    void* qword188;
    void* qword190;
    int dword198;
    char gap19C[36];
    void* qword1C0;
    char gap1C8[56];
    void* qword200;
    void* qword208;
    void* qword210;
    void* qword218;
    void* qword220;
    void* qword228;
    void* qword230;
    void* qword238;
    char byte240;
    char gap241[7];
    void* qword248;
    void* qword250;
    void* qword258;
    void* qword260;
    void* qword268;
    void* qword270;
    void* qword278;
    int dword280;
    char gap284[60];
    void* qword2C0;
    void* qword2C8;
    int dword2D0;
    short word2D4;
    __attribute__((aligned(4))) int dword2D8;
public:

};