#pragma once

#include "rstl/rc_ptr.hpp"
#include "misc.h"
#include "Math.hpp"

struct CModelDataMP1 {
    CModelDataMP1(IMP1EntityBaseGOC &,CStaticResMPT const&,CModelLightingDataMP1 const&);
    CModelDataMP1(IMP1EntityBaseGOC &,CStaticResMPT const&,CModelLightingDataMP1 const&,CAnimatedUvDataMP1 const&);
    CModelDataMP1(void);
    CModelDataMP1(CStateManager const&,rstl::ncrc_ptr<CSceneProxy> const&,CAnimResMPT const&,CAnimDataMP1::ETransformMode,CModelLightingDataMP1 const&);
    CModelDataMP1(CStateManager const&,IMP1EntityBaseGOC &,CAnimResMPT const&,CAnimDataMP1::ETransformMode,CModelLightingDataMP1 const&);
    CModelDataMP1(CModelDataMP1 const&);
    CModelDataMP1(CModelDataMP1&&);

    CScale3f mModelScale;
    int pad1;
    bool byte10;
    struct CAnimDataMP1 *mAnimData;
    bool byte20;
    float float24;
    float float28;
    float float2C;
    float float30;
    rstl::rc_ptr<class CModelSceneNodeProxyMP1> mModelNode;
    rstl::rc_ptr<class CSceneNodeProxy> mSceneNodeProxy2;
    rstl::rc_ptr<CSceneNodeProxy> mSceneNodeProxy3;
    CValueVersionId<uint,ushort,ushort,16u,16u> mAreaUniqueId;
    uint8_t mGroupId;
    float float70;
    float float74;
    CObjectId mModelId;
    CAABox mBoundBox;
    bool mHasBoundBox;
    NGame::SObjectInfo *mObjInfo;
    CModelLightingDataMP1 mLightingData;
};