#pragma once

#include <CObject/CObjectId.h>
#include <Stream/CInputStream.h>
#include <rstl/rc_ptr.hpp>

class CScriptMailboxMP1;

class CMapWorldInfoMP1 {
public:
    CMapWorldInfoMP1(void);
    CMapWorldInfoMP1(CInputStream &);

    void PutTo(COutputStream &);
    void SetDoorVisited(CGuid,bool);
    bool IsDoorVisited(CGuid) const;
    void SetAreaVisited(CObjectId,bool);
    void SetAreaMapped(CObjectId,bool);
    bool IsWorldOrAreaMapped(CObjectId) const;
    bool IsAreaRhsVisible(CObjectId) const;
    bool IsAreaVisited(CObjectId) const;
    bool IsAreaVisitedOrRhsVisible(CObjectId) const;
    bool IsWorldVisitedOrMapped(void) const;
};

class CWorldStateMP1 {
public:
    CWorldStateMP1(CObjectId);
    CWorldStateMP1(CInputStream &,uint);

    void PutTo(COutputStream &);
    CObjectId GetWorldAssetId(void);
    CScriptMailboxMP1** Mailbox(void);
    void* MapWorldInfo(void);
    rstl::rc_ptr<CScriptMailboxMP1>* GetMailbox(void) const;
    rstl::rc_ptr<CMapWorldInfoMP1>* GetMapWorldInfo(void) const;
    CObjectId GetCurrentArea(void) const;
    void SetCurrentArea(CObjectId);
    CObjectId GetDesiredAreaAssetId(void) const;
    void SetDesiredAreaAssetId(CObjectId);

    CObjectId mWorldId;
    CObjectId mAreaId;
    rstl::rc_ptr<CScriptMailboxMP1> mCScriptMailboxMP1;
    rstl::rc_ptr<CMapWorldInfoMP1> mCMapWorldInfoMP1;
    CObjectId mDesiredAreaId;
};