#include "fs.h"
#include "imgui_backend/imgui_impl_nvn.hpp"
#include "lib.hpp"
#include "logger/Logger.hpp"
#include "patches.hpp"
#include <CActors/MP1/CPlayerMP1.h>
#include <CActors/MP1/CScriptMailboxMP1.h>
#include <CGame/CGameStateManager.h>
#include <Component/MP1/CPickupMP1GOC.h>
#include <Math.hpp>

#include <cmath>
#include <helpers/StringHelper.h>
#include <rstl/key_value_vector.h>

#include "helpers.h"
#include "imgui_nvn.h"

#include "ExceptionHandler.h"

#include "CGame/CGameState.h"
#include "CGame/CGameStateManager.h"
#include "CState/CStateManager.h"

#include "RoomWarper.h"
#include "globals.h"

#include "InventoryMenu.hpp"
#include "RandoConfig.h"

#define IMGUI_ENABLED true

namespace NGuiMapFormat {
    struct SIconInstance
    {
        CVector3f mRenderPos = {};
        int mMatIdx = -1;
        int mIconAlpha = 1.0f;
    };

    struct SDoorInstance {
        char size[0x40];
    };

    struct SObjectRenderRange {
        uint mIdxFirst;
        uint mIdxSecond;
    };

    struct CMappableObjectData {
        rstl::vector<SDoorInstance> mDoorInstanceData;
        rstl::vector<SIconInstance> mIconInstanceData;
        rstl::key_value_vector<int, rstl::reserved_vector<NGuiMapFormat::SObjectRenderRange, 3>> mObjectRangesTable;
    };

    struct CGuiMapResourceData {

    };
}

struct CMappableObjectMP1
{
    CUniverseInfoMP1::SMappableObjectInfoMP1 mInfo;
    float float48;
    float float4C;
    float float50;
    char gap54[48];
    int cmappableobjectmp184;
    char gap88[56];
    int mObjectType;
    float floatC4;
    float floatC8;
    float floatCC;
    float floatD0;
    int mInstanceIdx;
    CObjectId mAreaId;
    void* qwordE8;
    void* qwordF0;
};

struct CMapAreaMP1
{
    CObjectId mAreaId;
    void* qword10;
    void* qword18;
    void* qword20;
    int mAreaIdx;
    int dword2C;
    const CTransform4f ctransform4f30;
    void* qword60;
    int dword68;
    void* qword70;
    void* qword78;
    rstl::vector<CMappableObjectMP1> mMappableObjList;

    CMapAreaMP1(void);
    //    CMapAreaMP1(CGuiMap::SAreaMapData const&);
    ~CMapAreaMP1();

    bool GetIsVisibleToAutoMapper(bool,bool) const;
    void GetBoundingBox(void);
    //    void TestCollision(CFixedLengthRay const&,bool,CVector3f &,CUnitVector3f &,float &);
};

struct CMapWorldMP1 {
    char pad[0x58];
    rstl::single_ptr<NGuiMapFormat::CMappableObjectData> mWorldMappableData;

    CMapWorldMP1(class CGuiMap const*);
    ~CMapWorldMP1();
    void AssembleMappableObjectData(void);

    bool HasMapArea(CObjectId const&) const;
    CMapAreaMP1** GetMapArea(CObjectId const&) const; // this is actually a rstl::ncrc_ptr, but our impl hasn't been finished yet.
    void GetVisibleAreas(CStateManager const&,class IWorldMP1 const&,CMapWorldInfoMP1 const&) const;
    bool IsMapAreaValid(CStateManager const&,IWorldMP1 const&,CObjectId const&,bool) const;
    void RecalculateWorldSphere(CStateManager const&,CMapWorldInfoMP1 const&,IWorldMP1 const&) const;
    void ConstrainToWorldVolume(CVector3f const&,CVector3f const&,CVector3f const&) const;
    void CopyMappableObjectData(rstl::single_ptr<NGuiMapFormat::CMappableObjectData> &) const;
};

class CGuiMap {
public:
    CGuiMap(CInputStream &);
    ~CGuiMap();

    void CurrentVersion(void);
    void CopyRenderResourceData(rstl::single_ptr<NGuiMapFormat::CGuiMapResourceData,rstl::single_ptr_details::default_traits> &) const;
};

class IWorldMP1 {
public:
    virtual ~IWorldMP1() = default;
    virtual CObjectId *IGetWorldAssetId() = 0;
    virtual void IGetStringTableEntry() = 0;
    virtual CMapWorldMP1 *IGetMapWorld() = 0;
    virtual CMapWorldMP1 *IMapWorld() = 0;
    virtual bool IHasMapWorld() = 0;
    virtual void ICheckWorldComplete(const CStateManager *) = 0;
    virtual CGuiMap* IGetGuiMapPtr() = 0;
};

struct CAutoMapControllerMP1 {
    char pad[0x28];
    int mWorldIdx;
    IWorldMP1 *mFocusWorld;
    IWorldMP1 *mCurrPlayerWorld;
    bool mWorldChanged;
    char size[0x270-0x40];

    IWorldMP1* DummyWorld(int);
};

struct CAutoMapperMP1 {
    char size[0x428];
    CAutoMapControllerMP1 mMapController;
};

struct SGuiMapRenderData {
    u8 mRenderDataBitfield; // 2nd bit = mIsReloadArea
    char pad[0x30F];
    rstl::single_ptr<NGuiMapFormat::CGuiMapResourceData> mResourceData;
    rstl::single_ptr<NGuiMapFormat::CMappableObjectData> mMappableObjData;
    void* field_320;
    void* field_328;
};

struct CGuiMapContextSceneNodeProxy {
    char inheritedData[0x68];
    SGuiMapRenderData mRenderData;

    SGuiMapRenderData* Data();
};

class CGraphicsDeviceContext;
class CGraphicsVertexBufferToken;
class CMaterialInstance;
enum EPrimitive {};
enum EMaterialTechnique {};
class CMaterialExec {
public:
    static void DrawMesh(CGraphicsDeviceContext &,CGraphicsVertexBufferToken const&,CMaterialInstance const&,EPrimitive,uint,uint,EMaterialTechnique);
};

struct CMaterialInstanceData;
struct CGuiMapRenderManager {
    char gap0[0xB0];
    CMaterialInstanceData* mIconMatList;
    char gapB8[0x40];
    CMaterialInstanceData* mHintIconMat;
    char gapF8[0x560];
    CVector3f mHintIconScalar;
};

struct CCreditsGOC {
    char pad[0x204];
    float mScrollSpeed;
};
constexpr float CREDITS_SPEED = 5.0f;

rstl::auto_ptr<CGameState> gGameState;
CGameStateManager *gGameStateManager = nullptr;
CStateManager *gStateManager = nullptr;

CTransform4f lastKnownTransform = CTransform4f::Identity();
CVector3f lastKnownVelocity{};
CAxisAngle lastKnownAngularVelocity{};

bool isMemoryRelayActive(CObjectId relayGuid, CObjectId worldId) {
    if(relayGuid == *CObjectId::Invalid() || worldId == *CObjectId::Invalid()) {
        Logger::log("Relay ID value: %s World Id value: %s\n", relayGuid.AsString().data(), worldId.AsString().data());
        return false;
    }

    auto worldState = gpGameState->StateForWorld(worldId);
    if(!worldState) {
        Logger::log("World state was null!\n");
        return false;
    }

    auto mailbox = *worldState->Mailbox();
    if(!mailbox) {
        Logger::log("Mailbox was null!\n");
        return false;
    }

    auto& msgs = mailbox->mMemoryRelayMessages;

    for (int i = 0; i < msgs.size(); ++i) {
        if(msgs.at(i).mRelayGuid == relayGuid)
            return true;
    }
    return false;
}

void drawDebugWindow() {
    if(!InputHelper::isInputToggled())
        return;

    ImGui::SetNextWindowPos(ImVec2(390, 0), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(500, 300), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
    ImGui::Begin("Debug Info");

    if(ImGui::CollapsingHeader("General Game Info")) {
        ImGui::Text("Current Level Guid: %s", gpGameState->mLevelGuid.AsString().data());
        ImGui::Text("Current Area Guid: %s", gpGameState->CurrentWorldState()->GetCurrentArea().AsString().data());
    }

    if(ImGui::CollapsingHeader("Current World Relay Messages")) {
        if(gpGameState) {
            auto worldState = gpGameState->CurrentWorldState();

            if(worldState) {
                auto mailbox = *worldState->Mailbox();
                if(mailbox) {
                    auto& msgs = mailbox->mMemoryRelayMessages;
                    ImGui::Text("Message Count: %d", msgs.size());
                    ImGui::Text("Message Capacity: %d", msgs.capacity());

                    for (int i = 0; i < msgs.size(); ++i) {
                        ImGui::Text("Entry[%d]: Guid %s", i, msgs.at(i).mRelayGuid.AsString().data());
                    }
                }else
                    ImGui::Text("Mailbox is null.");
            }else
                ImGui::Text("World state is null.");
        }else
            ImGui::Text("Game state is null.");
    }

    if(ImGui::BeginMenu("Warp Menu")) {
        RoomWarper::DrawWarpMenu();
        ImGui::EndMenu();
    }

    if(ImGui::Button("Warp to Credits")) {
        RoomWarper::WarpToRoom(gpGameState->mLevelGuid, CObjectId("CE44A797-C442-4128-8372-694626A83722"));
    }

    ImGui::Text("Left Stick X: %f", InputHelper::getLeftStickX());
    ImGui::Text("Left Stick Y: %f", InputHelper::getLeftStickY());

//    GUI::drawInventoryMenu();

    ImGui::End();
}

HOOK_DEFINE_TRAMPOLINE(GetGameStateHook) {
    static void Callback(CGameStateManager *thisPtr, rstl::auto_ptr<CGameState> &newState) {
        gGameState = newState;
        gGameStateManager = thisPtr;
        Orig(thisPtr, newState);
    }
};

HOOK_DEFINE_TRAMPOLINE(GetStateManagerHook) {
    static void Callback(CStateManager *thisPtr) {
        gStateManager = thisPtr;
        RoomWarper::SetManager(gStateManager);
        Orig(thisPtr);
    }
};

// noclip code from mp1r-practice-mod by Pwootage
HOOK_DEFINE_TRAMPOLINE(CPlayerMP1_ProcessInput) {
    static void Callback(CPlayerMP1 *thiz, const CFinalInput &input, CStateManager &stateManager) {
        if(InputHelper::isInputToggled()) {
            if (InputHelper::isHoldZR()) {
                float multiplier = 0.3f;
                if (InputHelper::isHoldZL()) {
                    multiplier = 0.9f;
                }
                CVector3f movement = CVector3f(
                    -InputHelper::getLeftStickX() * multiplier,
                    InputHelper::getRightStickY() * multiplier,
                    InputHelper::getLeftStickY() * multiplier
                );
                CTransform4f transform = thiz->GetTransform();
                movement = transform.Rotate(movement);
                lastKnownTransform.x = lastKnownTransform.x + movement.x;
                lastKnownTransform.y = lastKnownTransform.y + movement.y;
                lastKnownTransform.z = lastKnownTransform.z + movement.z;

                auto rot = CRelAngle(InputHelper::getRightStickX() * -0.05f);
                CTransform4f rotT = CTransform4f::Identity();
                rotT.RotateLocalY(rot);
                lastKnownTransform = lastKnownTransform * rotT;
            }

            thiz->SetTransform(lastKnownTransform);
            thiz->SetVelocityWR(stateManager, lastKnownVelocity);
            thiz->SetAngularVelocityWR(stateManager, lastKnownAngularVelocity);
        }

        Orig(thiz, input, stateManager);

        lastKnownTransform = thiz->GetTransform();
        lastKnownVelocity = *thiz->GetVelocityWR(stateManager);
        lastKnownAngularVelocity = *thiz->GetAngularVelocityWR(stateManager);
    }
};

// original implementation by UltiNaruto, modified to work in exlaunch
HOOK_DEFINE_INLINE(CheckForVariaHook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        CPlayerStateMP1* pState = (CPlayerStateMP1*)ctx->X[0];
        ctx->W[8] = pState->GetItemCapacity(CPlayerStateMP1::EItemType::VariaSuit);
    }
};

// CScriptLayer::ParseGeneratedData(ushort,CInputStream &,ulong,rstl::key_value_vector<CGuid,CScriptLayer::SDataInfo,rstl::less<CGuid>,rstl::shared_owned_memory_allocator<rstl::rmemory_allocator>> &)
HOOK_DEFINE_TRAMPOLINE(GetGeneratedObjCount) {
    static void Callback(ushort count, void* inputStream, ulong unk, void* kvpVec, void* allocator) {
        Logger::log("Generated Obj Count: %d\n", count);

        Orig(count, inputStream, unk, kvpVec, allocator);
    }
};

// NScriptLoader::ComputeSizeForComponentProperties(rstl::memory_description,CInputStream &,ulong)
HOOK_DEFINE_TRAMPOLINE(GetScriptLoaderCompCount) {
    static void Callback(void* thiz, void* memDesc, CInputStream& inputStream, ulong count) {
        Logger::log("SDEN Count: %d\n", count);

        Orig(thiz, memDesc, inputStream, count);
    }
};

HOOK_DEFINE_TRAMPOLINE(OpenFileHook) {
    static nn::Result Callback(nn::fs::FileHandle* handleOut, char const* path, int mode) {
        Logger::log("Opening File at Path: %s", path);
        nn::Result result = Orig(handleOut, path, mode);
        Logger::log(" Handle: %ld\n", handleOut->_internal);

        return result;
    }
};

HOOK_DEFINE_TRAMPOLINE(WriteFileHook) {
    static nn::Result Callback(nn::fs::FileHandle handle, s64 position, void const* buffer, u64 size, nn::fs::WriteOption const& option) {
        Logger::log("Writing File with handle: %ld\n", handle._internal);

        exceptionHandlerNoInfo(true);

        return Orig(handle, position, buffer, size, option);
    }
};

// series of hooks that will allow a custom SIconInstance to use the Hint material
// these 3 are all located within CGuiMapRenderManager::RenderIcons
HOOK_DEFINE_INLINE(SwapMaterial1Hook) { // Replaces X1 for the second CMaterialInstance::Append call
    EXPORT_SYM static void Callback(exl::hook::InlineCtx* ctx) {
        auto renderManagerPtr = (CGuiMapRenderManager*)ctx->X[21];
        auto mHintIconMat = renderManagerPtr->mHintIconMat;
        auto* icoData = (NGuiMapFormat::SIconInstance*)ctx->X[22];

        if(icoData->mMatIdx > 8) {
            if(mHintIconMat) {
                ctx->X[1] = (u64)mHintIconMat;
            }else {
                EXL_ABORT(0, "Hint Icon Material was null!");
            }
        }
    }
};

HOOK_DEFINE_INLINE(SwapMaterial2Hook) { // Replaces X0 for the first CMaterialInstanceData::BindVec4Data call
    EXPORT_SYM static void Callback(exl::hook::InlineCtx * ctx) {
        auto renderManagerPtr = (CGuiMapRenderManager*)ctx->X[21];
        auto mHintIconMat = renderManagerPtr->mHintIconMat;
        auto* icoData = (NGuiMapFormat::SIconInstance*)ctx->X[22];

        if(icoData->mMatIdx > 8) {
            if(mHintIconMat) {
                ctx->X[0] = (u64)mHintIconMat;
            }else {
                EXL_ABORT(0, "Hint Icon Material was null!");
            }
        }
    }
};

HOOK_DEFINE_INLINE(SwapMaterial3Hook) { // Replaces X0 and X2 for the second CMaterialInstanceData::BindVec4Data call
    EXPORT_SYM static void Callback(exl::hook::InlineCtx* ctx) {
        auto renderManagerPtr = (CGuiMapRenderManager*)ctx->X[21];
        auto mHintIconMat = renderManagerPtr->mHintIconMat;
        auto* icoData = (NGuiMapFormat::SIconInstance*)ctx->X[22];

        if(icoData->mMatIdx > 8) {
            if(mHintIconMat) {
                ctx->X[0] = (u64)mHintIconMat;
                ctx->X[2] = (u64)&renderManagerPtr->mHintIconScalar;
            }else {
                EXL_ABORT(0, "Hint Icon Material was null!");
            }
        }
    }
};

HOOK_DEFINE_INLINE(DisableIconDrawHook) {
    EXPORT_SYM static void Callback(exl::hook::InlineCtx* ctx) {
        CGraphicsDeviceContext* arg0 = (CGraphicsDeviceContext*)ctx->X[0];
        CGraphicsVertexBufferToken* arg1 = (CGraphicsVertexBufferToken*)ctx->X[1];
        CMaterialInstance* arg2 = (CMaterialInstance*)ctx->X[2];
        NGuiMapFormat::SIconInstance* icoData = (NGuiMapFormat::SIconInstance*)ctx->X[22];

//        Logger::log("Icon Material Idx: %d", icoData->mMatIdx);
        if(icoData->mMatIdx <= 9) {
//            Logger::log(" Drawing.\n");
            CMaterialExec::DrawMesh(*arg0, *arg1, *arg2, static_cast<EPrimitive>(ctx->W[3]), ctx->W[4], ctx->W[5], static_cast<EMaterialTechnique>(ctx->W[6]));
        }
//        else {
//            Logger::log(" Not Drawing.\n");
//        }
    }
};

// Fix mIconIdx from being out of bounds for the CToken used for the donor mat
HOOK_DEFINE_INLINE(FixIconIdxHook) {
    EXPORT_SYM static void Callback(exl::hook::InlineCtx* ctx) {
        int mIconIdx = ctx->X[8];

        if(mIconIdx > 8) {
            ctx->X[8] = 1;
        }
    }
};

EXPORT_SYM void updateCtxRenderData(CGuiMap* renderMap, const CMapWorldMP1& world, CGuiMapContextSceneNodeProxy& ctxProxy) {
    if(!renderMap) {
        Logger::log("CGuiMap ptr was null! unable to set resource data.");
        return;
    }
    auto* renderData = ctxProxy.Data();

    Logger::log("Updating Context Data.\n");
    world.CopyMappableObjectData(renderData->mMappableObjData);
    renderMap->CopyRenderResourceData(renderData->mResourceData);
    renderData->mRenderDataBitfield |= 2;
}

HOOK_DEFINE_TRAMPOLINE(UpdatePickupDotDataHook) {
    EXPORT_SYM static void Callback(CAutoMapControllerMP1 *thiz, const CObjectId& areaId, const CMapWorldMP1& world, const CMapWorldInfoMP1& worldInfo, CGuiMapContextSceneNodeProxy& ctxProxy) {
        if(thiz == nullptr || thiz->mFocusWorld == nullptr) {
            Orig(thiz, areaId, world, worldInfo, ctxProxy);
            return;
        }

        CObjectId worldId = *(thiz->mFocusWorld->IGetWorldAssetId());
        CMapAreaMP1* mapArea = *world.GetMapArea(areaId);

        bool isNeedUpdateCtx = false;
        for (int i = 0; i < mapArea->mMappableObjList.size(); ++i) {
            auto& mappableObj = mapArea->mMappableObjList.at(i);

            if(mappableObj.mInfo.mObjectType != EMappableObjectType::PickupDot)
                continue;

            // get render data for obj
            auto& mappableObjData = world.mWorldMappableData;

            if(mappableObjData.null()) {
                Logger::log("Mappable Object Data is null!\n");
                continue;
            }

            auto& icoInstData = mappableObjData->mIconInstanceData.at(mappableObj.mInstanceIdx);

            bool isHideIcon = isMemoryRelayActive(CObjectId(mappableObj.mInfo.mId), worldId);
            int targetIdx = isHideIcon ? 11 : 9;

            if(icoInstData.mMatIdx == targetIdx)
                continue;

            icoInstData.mMatIdx = targetIdx;
            Logger::log("%s Icon at Idx: %d\n", isHideIcon ? "Hiding" : "Displaying", mappableObj.mInstanceIdx);
            isNeedUpdateCtx = true;
        }

        if(isNeedUpdateCtx) {
            IWorldMP1* mapRenderWorld;
            if(worldId == gpGameState->mLevelGuid)
                mapRenderWorld = thiz->mCurrPlayerWorld;
            else
                mapRenderWorld = thiz->DummyWorld(thiz->mWorldIdx);

            CGuiMap* renderMap = mapRenderWorld ? mapRenderWorld->IGetGuiMapPtr() : nullptr;

            updateCtxRenderData(renderMap, world, ctxProxy);
        }

        Orig(thiz, areaId, world, worldInfo, ctxProxy);
    }
};

HOOK_DEFINE_INLINE(VerifyRenderDataUpdateHook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        Logger::log("Re-initializing NGuiMapFormat::CGuiMapRenderData in CGuiMapRenderManager::Update.\n");
    }
};

HOOK_DEFINE_INLINE(CheckWillUpdateHook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        u8 isReloadFlag = ctx->W[8];

        Logger::log("Is Reload flag: %d\n", isReloadFlag);

        if(isReloadFlag & 2) {
            bool isHaveObjData = ((void*)ctx->X[22]) != nullptr;
            bool isHaveResourceData = ((void*)ctx->X[1]) != nullptr;
            Logger::log("Is Have Mappable Object Data: %s\n", BTOC(isHaveObjData));
            Logger::log("Is Have Resource Data: %s\n", BTOC(isHaveResourceData));
        }
    }
};

// Fixes the 3 calls to CAutoMapControllerMP1::UpdateAreaRenderState to have a reference to this, instead of being optimized out
HOOK_DEFINE_INLINE(FixMapControllerRegister1Hook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[0] = ctx->X[20];
    }
};

HOOK_DEFINE_INLINE(FixMapControllerRegister2Hook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[0] = ctx->X[20];
    }
};

HOOK_DEFINE_INLINE(FixMapControllerRegister3Hook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[0] = ctx->X[20];
    }
};

HOOK_DEFINE_INLINE(OverrideCreditsSpeedHook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        auto thiz = (CCreditsGOC*)ctx->X[19];
        float yInput = InputHelper::getLeftStickY();
        thiz->mScrollSpeed = fabs((double)yInput) > 0.001f ? (-yInput * CREDITS_SPEED) : 1.0f;
    }
};
// CGameState::ResetGameState(CGameState const&,CGameState::SInitialState const&,CGameState::EForcePreserveData)	.text
HOOK_DEFINE_INLINE(ChangeInitialAreaHook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        auto initState = (CGameState::SInitialState*)ctx->X[2];

        if(initState->mSaveMagic.value != -1) {
            if(initState->mAreaId == CObjectId("a8444ff6-e4a4-4183-bfec-73d6d6407fa5")) {
                Logger::log("Setting Initial Area ID to Landing Site.\n");
                initState->mAreaId = CObjectId("0676e13f-15cf-4bc4-a058-5e056be4cfa4");
            }
        }
    }
};

HOOK_DEFINE_TRAMPOLINE(GetTextTeleportValueHook) {
    static void Callback(rstl::string& label, CObjectId* objId) {
        if(StringHelper::isEqualString(label.data(), "[CEDB5BA7]_000")) {
            Logger::log("Replacing Intro Text with world start text.\n");
            label = rstl::string_l("[398D1DEC]_000");
            Logger::log("Done.\n");
        }

        Orig(label, objId);
    }
};

HOOK_DEFINE_REPLACE(GetTankCapacityHook) {
    static float Callback() {
        return RandoConfig::eTankCapacity;
    }
};

HOOK_DEFINE_REPLACE(GetBaseHealthHook) {
    static float Callback() {
        return RandoConfig::baseHealth;
    }
};

HOOK_DEFINE_REPLACE(GetMaxHealthHook) {
    static float Callback(CPlayerStateMP1* thiz) {
        return (((float)thiz->GetItemAmount(CPlayerStateMP1::EItemType::EnergyTanks)) * RandoConfig::eTankCapacity) + RandoConfig::baseHealth;
    }
};

HOOK_DEFINE_INLINE(ChangeTankCapacityHook1) { static void Callback(exl::hook::InlineCtx* ctx) { ctx->W[8] = std::bit_cast<int>(RandoConfig::eTankCapacity); } };
HOOK_DEFINE_INLINE(ChangeBaseHealthHook1) { static void Callback(exl::hook::InlineCtx* ctx) { ctx->W[8] =   std::bit_cast<int>(RandoConfig::baseHealth); } };
HOOK_DEFINE_INLINE(ChangeTankCapacityHook2) { static void Callback(exl::hook::InlineCtx* ctx) { ctx->W[8] = std::bit_cast<int>(RandoConfig::eTankCapacity); } };
HOOK_DEFINE_INLINE(ChangeBaseHealthHook2) { static void Callback(exl::hook::InlineCtx* ctx) { ctx->W[8] =   std::bit_cast<int>(RandoConfig::baseHealth); } };
HOOK_DEFINE_INLINE(ChangeTankCapacityHook3) { static void Callback(exl::hook::InlineCtx* ctx) { ctx->W[8] = std::bit_cast<int>(RandoConfig::eTankCapacity); } };
HOOK_DEFINE_INLINE(ChangeBaseHealthHook3) { static void Callback(exl::hook::InlineCtx* ctx) { ctx->W[8] =   std::bit_cast<int>(RandoConfig::baseHealth); } };
HOOK_DEFINE_INLINE(ChangeTankCapacityHook4) { static void Callback(exl::hook::InlineCtx* ctx) { ctx->W[8] = std::bit_cast<int>(RandoConfig::eTankCapacity); } };
HOOK_DEFINE_INLINE(ChangeBaseHealthHook4) { static void Callback(exl::hook::InlineCtx* ctx) { ctx->W[8] =   std::bit_cast<int>(RandoConfig::baseHealth); } };

// reimplements CPlayerMP1::IsEnergyLow to use RandoConfig values
HOOK_DEFINE_REPLACE(LowHealthCheckHook) {
    static bool Callback(CPlayerMP1* thiz, CStateManager& mgr) {
        auto& healthInfo = thiz->HealthInfo(mgr);
        auto* playerState = CStateManagerGameLogicMP1::PlayerState();
        float curHealth = fmaxf(CMath::CeilingF(healthInfo.mHealth), 0.0f);

        float lowHealthThreshold = playerState->GetItemCapacity(CPlayerStateMP1::EItemType::EnergyTanks) <= 3 ? 0.10f * (3 * RandoConfig::eTankCapacity) : RandoConfig::baseHealth;

        return curHealth <= lowHealthThreshold;
    }
};

HOOK_DEFINE_TRAMPOLINE(GameMainLoopHook) {
    static void Callback(void* thiz) {
        if(R_FAILED(nn::fs::MountSdCardForDebug("sd"))) {
            Logger::log("Failed to mount SD Card! Skipping Config load.\n");
        }else {
            RandoConfig::LoadValuesFromSeed();
        }

        Orig(thiz);
    }
};

extern "C" void exl_main(void *x0, void *x1) {
    /* Setup hooking enviroment. */
    exl::hook::Initialize();

    nn::os::SetUserExceptionHandler(exception_handler, nullptr, 0, nullptr);

    R_ABORT_UNLESS(Logger::instance().init(LOGGER_IP, 3080).value);

    runCodePatches();

    GetGameStateHook::InstallAtSymbol("_ZN17CGameStateManager18AssignNewGameStateERN4rstl8auto_ptrI10CGameStateEE");
    GetStateManagerHook::InstallAtSymbol("_ZN13CStateManager15InitializeStateEv");

    // initialization hook
    GameMainLoopHook::InstallAtSymbol("_ZN17CGameArchitecture3RunEv");

    // practice mod patches
    CPlayerMP1_ProcessInput::InstallAtSymbol("_ZN10CPlayerMP112ProcessInputERK11CFinalInputR13CStateManager");

    // rando patches
    CheckForVariaHook::InstallAtOffset(0xD95F54);

    // patches for item hint locations on map
    SwapMaterial1Hook::InstallAtOffset(0xB55D30);
    SwapMaterial2Hook::InstallAtOffset(0xB55D5C);
    SwapMaterial3Hook::InstallAtOffset(0xB55D84);
    FixIconIdxHook::InstallAtOffset(0xB55CA8);

    UpdatePickupDotDataHook::InstallAtSymbol("_ZNK21CAutoMapControllerMP121UpdateAreaRenderStateERK9CObjectIdRK12CMapWorldMP1RK16CMapWorldInfoMP1R28CGuiMapContextSceneNodeProxy");
    DisableIconDrawHook::InstallAtOffset(0xB55DA4);
    FixMapControllerRegister1Hook::InstallAtOffset(0xE5FCCC);
    FixMapControllerRegister2Hook::InstallAtOffset(0xE5FD58);
    FixMapControllerRegister3Hook::InstallAtOffset(0xE5FDE0);

    // credits changes
    OverrideCreditsSpeedHook::InstallAtOffset(0x577CC8);

    // intro skip changes
    ChangeInitialAreaHook::InstallAtOffset(0x40A75C);
    GetTextTeleportValueHook::InstallAtSymbol("_ZN21CWorldTransitionIOWin18EnableTextTeleportERKN4rstl12basic_stringIcNS0_11char_traitsIcEENS0_17rmemory_allocatorEEERK9CObjectId");

    // health system changes
    GetTankCapacityHook::InstallAtSymbol("_ZN15CPlayerStateMP121GetEnergyTankCapacityEv");
    GetBaseHealthHook::InstallAtSymbol("_ZN15CPlayerStateMP121GetBaseHealthCapacityEv");
    GetMaxHealthHook::InstallAtSymbol("_ZNK15CPlayerStateMP112GetMaxHealthEv");
    LowHealthCheckHook::InstallAtSymbol("_ZNK10CPlayerMP111IsEnergyLowERK13CStateManager");
    ChangeTankCapacityHook1::InstallAtOffset(0xC88FE4);
    ChangeBaseHealthHook1::InstallAtOffset(0xC88FFC);
    ChangeTankCapacityHook2::InstallAtOffset(0xC88FA4);
    ChangeBaseHealthHook2::InstallAtOffset(0xC88FB8);
    ChangeTankCapacityHook3::InstallAtOffset(0xC890C8);
    ChangeBaseHealthHook3::InstallAtOffset(0xC890E0);
    ChangeTankCapacityHook4::InstallAtOffset(0xC89088);
    ChangeBaseHealthHook4::InstallAtOffset(0xC8909C);
    LowHealthCheckHook::InstallAtOffset(0xC69FFC);

    CGameState::mCinematicForceSkippableOverride = true;

//    VerifyRenderDataUpdateHook::InstallAtOffset(0xB50434);
//    CheckWillUpdateHook::InstallAtOffset(0xB50420);

//    GetGeneratedObjCount::InstallAtSymbol("_ZN12CScriptLayer18ParseGeneratedDataEtR12CInputStreammRN4rstl16key_value_vectorI5CGuidNS_9SDataInfoENS2_4lessIS4_EENS2_29shared_owned_memory_allocatorINS2_17rmemory_allocatorEEEEE");
//    GetScriptLoaderCompCount::InstallAtSymbol("_ZN13NScriptLoader33ComputeSizeForComponentPropertiesEN4rstl18memory_descriptionER12CInputStreamm");

    // ImGui Hooks
#if IMGUI_ENABLED
    nvnImGui::InstallHooks();

    nvnImGui::addDrawFunc(drawDebugWindow);

//    nvnImGui::addDrawFunc([]() {
//        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
//        ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
//        ImGui::Begin("PlayerPos", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
//                                                       ImGuiWindowFlags_NoSavedSettings |
//                                                       ImGuiWindowFlags_NoFocusOnAppearing);
//        ImGui::Text("Player Pos: %f %f %f", lastKnownTransform.x, lastKnownTransform.y, lastKnownTransform.z);
//        ImGui::End();
//    });


#endif
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}