#pragma once

#include <CActors/CActor.h>
#include <CActors/MP1/CPlayerState.h>

class CScriptPickupMP1 : public CActorMP1
{
public:
    CPlayerStateMP1::EItemType mItem;
    int dword1EC;
    int dword1F0;
    float mPossibility;
    float float1F8;
    float float1FC;
    void* qword200;
    float float208;
    int ctoken20C;
    char gap210[12];
    void* qword21C;
    char byte224;
    char gap225[3];
    void* qword228;
    void* qword230;
    void* qword238;
    void* qword240;
    int dword248;
    float float24C;
    bool mWasGenerated;
    float float254;
    char byte258;
    char byte259;

    CScriptPickupMP1(CEntityInfoMP1 const&,CTransform4f const&,CModelDataMP1 const&,CActorParametersMP1 const&,CAABox const&,int,int,int,float,float,float,float,CObjectId,CVector3f,bool,bool);
    virtual ~CScriptPickupMP1() override;

    CEntityMP1& TypesMatch(int) override;
    void Think(float,CStateManager &) override;
    void Touch(CActorMP1 &,CStateManager &) override;
    void AcceptScriptMsg(EScriptObjectMessage,CValueVersionId<uint,uint,ushort,16u,16u>,CStateManager &) override;
    void GetOrbitPosition(CStateManager const&) const override;
    void GetTouchBounds(void) const override;

    void Stop(void);
    void MoveToOR(CVector3f const&);
    void RotateToOR(CQuaternion const&);
    void SetVelocityWR(CVector3f const&);
    void CheckItemForGalleryUnlock(CPlayerStateMP1::EItemType,CStateManager &);
    void GetBoundingBox(void);
    CPlayerStateMP1::EItemType GetItem(void) const;
    void GetPossibility(void);
    void SetWasGenerated(void);
};