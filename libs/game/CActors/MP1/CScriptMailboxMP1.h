#pragma once

#include "rstl/vector.h"
#include "CObject/CObjectId.h"

struct SMemoryRelayMailMessageMP1 {
    CGuid mRelayGuid;
    CGuid mTargetGuid;
    CGuid mInvalidGuid;
    int mScriptAction;
    short mObjMessage;
    bool byte36;

    SMemoryRelayMailMessageMP1(CGuid const&,CGuid const&,CObjectId const&,NScriptMsg::EScriptAction,bool,EScriptObjectMessage);
    SMemoryRelayMailMessageMP1(CInputStream &,uint);
    void PutTo(COutputStream &);
};

static bool operator==(SMemoryRelayMailMessageMP1 const&,SMemoryRelayMailMessageMP1 const&);

class CScriptMailboxMP1 {
public:
    rstl::vector<SMemoryRelayMailMessageMP1> mMemoryRelayMessages;
    void* unkPtr1;
    bool unkBool1;

    CScriptMailboxMP1(void);
    CScriptMailboxMP1(CInputStream &,uint);
    ~CScriptMailboxMP1();

    void PutTo(COutputStream &);
    void SendMsgsForArea(CStateManager &,CObjectId const&);
    void AddMemoryRelayMessage(SMemoryRelayMailMessageMP1 const&);
    void RemoveMemoryRelayMessage(CGuid);
};