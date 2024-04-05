#pragma once

#include "types.h"
#include <Script/SLdrCommon.h>
#include <rstl/auto_ptr.h>
#include <rstl/rc_ptr.hpp>
#include "Types/CValueVersionId.h"

class SScriptStringPoolCache;
class SScriptLink;
class SConnection;
class SGOComponentInstanceData;

#pragma pack(push, 1)
class SGOComponentProperties {
public:
    SLdrVector_MP1Typedef vec1;
    SLdrVector_MP1Typedef vec2;
    CObjectId itemID;
    SLdrAnimSet_MP1Typedef animSet;
    CObjectId mAreaAssetId;
    SLdrVector_MP1Typedef vec3;
    SLdrMapInfo_MP1Typedef mapInfo;
    SLdrActorInformation_MP1Typedef actorInfo;

    virtual ~SGOComponentProperties();
    virtual void Load(CInputStream *a2, class CScriptLoadContext *a3);
};
#pragma pack(pop)

struct SGOComponentInfo {
    enum EActiveOnConstruction {};

    SGOComponentInfo(CValueVersionId<uint,uint,ushort,16u,16u>,CGuid const&,CObjectId const&,SGOComponentInfo::EActiveOnConstruction,rstl::vector<SConnection,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> &&,rstl::vector<SScriptLink,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> &&,rstl::auto_ptr<SGOComponentProperties const> const&);
    SGOComponentInfo(CValueVersionId<uint,uint,ushort,16u,16u>,CObjectId const&,SGOComponentInfo::EActiveOnConstruction,rstl::auto_ptr<SGOComponentInstanceData> &&,rstl::auto_ptr<SGOComponentProperties const> const&);
    SGOComponentInfo(rstl::ncrc_ptr<rstl::owned_memory_arena_allocator> const&,SScriptStringPoolCache const*,CValueVersionId<uint,uint,ushort,16u,16u>,CObjectId const&,SGOComponentInfo::EActiveOnConstruction,rstl::auto_ptr<SGOComponentInstanceData> &&,rstl::auto_ptr<SGOComponentProperties const> const&);

    void* field_0;
    void* field_8;
    void* field_10;
    int field_18;
    CObjectId objId;
    bool mIsActiveOnConstruction;
    char gap_2D[3];
    bool field_30;
    void* field_38;
    rstl::auto_ptr<SGOComponentProperties const> mComponentProperties;
};