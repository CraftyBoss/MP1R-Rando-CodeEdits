#include "fs.h"
#include "imgui_backend/imgui_impl_nvn.hpp"
#include "lib.hpp"
#include "logger/Logger.hpp"
#include "patches.hpp"
#include <CActors/MP1/CPlayerMP1.h>
#include <CActors/MP1/CScriptPickupMP1.h>
#include <CGame/CGameStateManager.h>
#include <Component/CGameObjectComponent.h>
#include <Component/MP1/CPickupMP1GOC.h>
#include <Math.hpp>
#include <cmath>

#include "helpers/InputHelper.h"
#include "imgui_nvn.h"

#include "ExceptionHandler.h"

#include "CGame/CGameState.h"

#define IMGUI_ENABLED true

rstl::auto_ptr<CGameState> gGameState;
CGameStateManager *gGameStateManager = nullptr;
CStateManager *gStateManager = nullptr;

CTransform4f lastKnownTransform = CTransform4f::Identity();
CVector3f lastKnownVelocity{};
CAxisAngle lastKnownAngularVelocity{};

void drawDebugWindow() {
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::Begin("Game Debug Window");

    if(ImGui::CollapsingHeader("General Game Toggles")) {
        ImGui::Checkbox("Toggle Skippable Cutscene Override", &CGameState::mCinematicForceSkippableOverride);

        if(!gGameState.null() && gStateManager) {

            rstl::string *savePointName = gGameState->GetSavePointName();

            ImGui::Text("Save Point Name: %s", savePointName->data());

            CGameAreaManager* areaManager = gStateManager->mGameAreaManager;

            if(areaManager && areaManager->mCurArea) {
                ImGui::Text("Current Area Asset ID: %s\n", areaManager->mCurArea->mAreaAssetId.AsString().data());
                ImGui::Text("Current Area ID: %d\n", areaManager->mCurArea->mAreaId);
            }
        }
    }

    ImGui::Text("Player Pos: %f %f %f", lastKnownTransform.x, lastKnownTransform.y, lastKnownTransform.z);

    ImGui::End();
}

bool isNearValue(float in, float value, float range = 0.1f) {
    return in >= (value - range) && in <= (value + range);
}

struct CEntityInfoMP1;
struct CActorParametersMP1;
struct CAnimResMPT;
struct CStaticResMPT;
struct CAnimatedUvDataMP1;

struct CAnimDataMP1 {
    static const char* skSkeletonRoot; // "Skeleton_Root"
    static const char* skRelativeRoot; // "root.anchorBlend"
    static const char* skLegacyRelativeRoot; // "character.anchorBlend"

    enum ETransformMode {};
};

namespace NGame {
    struct SObjectInfo;
}

struct CModelLightingDataMP1 {
    static CModelLightingDataMP1 Default(void);
    static CModelLightingDataMP1 FromParams(CActorParametersMP1 const&);

    CQuaternion mQuat;
    bool unkBool1;
};

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

HOOK_DEFINE_TRAMPOLINE(CreatePickupHook) {
    static void Callback(CScriptPickupMP1 *thiz, CEntityInfoMP1 const& entityInfo, CTransform4f const& transform, CModelDataMP1& modelData,
                         CActorParametersMP1 const& actorParams, CAABox const& bBox, int int1, int int2, int int3, float float1, float float2, float float3,
                         float float4, CObjectId objectId, CVector3f pos, bool bool1, bool bool2) {

        Logger::log("Pickup Model ID: %llu %llu\n", modelData.mModelId.low,  modelData.mModelId.high);

        Logger::log("Lighting Data Quat: %f %f %f %f\n", modelData.mLightingData.mQuat.x, modelData.mLightingData.mQuat.y, modelData.mLightingData.mQuat.z, modelData.mLightingData.mQuat.w);
        modelData.mLightingData.unkBool1 = true;

        Orig(thiz, entityInfo, transform, modelData, actorParams, bBox, int1, int2, int3, float1, float2, float3, float4, objectId, pos, bool1, bool2);

        Logger::log("Created Pickup Script with Item Type: %d (%s)\n", thiz->mItem, getItemName(thiz->mItem));

        // Pickup near spawn
        // -327.727448 -30.442602 -298.809204
        // custom pos
        // -326.283325 -21.843369 -333.332367

        Logger::log("Entity Position: %f %f %f\n", transform.x, transform.y, transform.z);

        if(isNearValue(transform.x, -327.727448f) && isNearValue(transform.y, -30.442602f) && isNearValue(transform.z, -298.809204f)) {
            auto& trans = thiz->GetTransform();

            Logger::log("Moving Starting room pickup.\n");
            trans.x = -326.283325f;
            trans.y = -21.843369f;
            trans.z = -333.332367f;

            thiz->SetTransform(trans);
        }
    }
};

HOOK_DEFINE_TRAMPOLINE(LoadPickupHook) {
    static CPickupMP1GOC* Callback(CInputStream *paramStream, SGOComponentInfo& info) {
        // modify pickup type here
        auto properties = (SLdrPickupMP1*)info.mComponentProperties.get();
//
//        if(properties->mItemType != CPlayerStateMP1::EItemType::kIT_Missiles) {
//            Orig(paramStream, info);
//            return;
//        }

        Logger::log("Loading Pickup GameObject with Item Type: %d (%s)\n", properties->mItemType, getItemName((CPlayerStateMP1::EItemType)properties->mItemType));
//
//        Logger::log("\tvec1: %f %f %f\n", properties->vec1.x, properties->vec1.y, properties->vec1.z);
//        Logger::log("\tvec2: %f %f %f\n", properties->vec2.x, properties->vec2.y, properties->vec2.z);
//        Logger::log("\tvec3: %f %f %f\n", properties->vec3.x, properties->vec3.y, properties->vec3.z);

//        Logger::log("\tMap Info ObjID: %s\n", properties->mapInfo.mObjId.AsString().data());
//        Logger::log("\tMap Info unkInt1: %d\n", properties->mapInfo.unkInt1);
//        Logger::log("\tMap Info unkInt2: %d\n", properties->mapInfo.unkInt2);


        properties->mAreaAssetId = *CObjectId::Invalid();

        properties->animSet.mObjId = *CObjectId::FromString(rstl::string_l("38e0274f-bcc5-410f-9b80-961479454634"));
        properties->animSet.mString2 = rstl::string_l("powerbomb2_ready");

        Logger::log("\tItem Asset ID Low: %llu\n", properties->itemID.low);
        Logger::log("\tItem Asset ID High: %llu\n", properties->itemID.high);

        Logger::log("\tArea Asset ID: %s\n", properties->mAreaAssetId.AsString().data());

        Logger::log("\tAnim Set Asset ID: %s\n", properties->animSet.mObjId.AsString().data());
        Logger::log("\tAnim Set String1: %s\n", properties->animSet.mString1.data());
        Logger::log("\tAnim Set String2: %s\n", properties->animSet.mString2.data());

//        Logger::log("\tactorInfo.objId1: %s\n", properties->actorInfo.objId1.AsString().data());
//        Logger::log("\tactorInfo.objId2: %s\n", properties->actorInfo.objId2.AsString().data());
//        Logger::log("\tactorInfo.objId3: %s\n", properties->actorInfo.objId3.AsString().data());
//        Logger::log("\tactorInfo.objId4: %s\n", properties->actorInfo.objId4.AsString().data());
//        Logger::log("\tactorInfo.objId5: %s\n", properties->actorInfo.objId5.AsString().data());

//        Logger::log("\tunkInt2: %d\n",properties->unkInt2);
//        Logger::log("\tunkInt3: %d\n",properties->unkInt3);
//        Logger::log("\tunkFloat1: %f\n", properties->unkFloat1);
//        Logger::log("\tunkFloat2: %f\n", properties->unkFloat2);
//        Logger::log("\tunkFloat3: %f\n", properties->unkFloat3);
//        Logger::log("\tunkBool9: %s (%d)\n",BTOC(properties->unkBool9), properties->unkBool9);
//        Logger::log("\tunkBool10: %s (%d)\n",BTOC(properties->unkBool10), properties->unkBool10);
//        Logger::log("\tunkBool11: %s (%d)\n",BTOC(properties->unkBool11), properties->unkBool11);
//        Logger::log("\tunkBool12: %s (%d)\n",BTOC(properties->unkBool12), properties->unkBool12);
//        Logger::log("\tunkBool13: %s (%d)\n",BTOC(properties->unkBool13), properties->unkBool13);
//        Logger::log("\tunkBool14: %s (%d)\n",BTOC(properties->unkBool14), properties->unkBool14);

        properties->mItemType = CPlayerStateMP1::EItemType::kIT_EnergyTanks;

        auto* gObj = Orig(paramStream, info);

        return gObj;
    }
};

HOOK_DEFINE_INLINE(CreateComponentHook) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        auto* thiz = (CGameObjectComponent*)ctx->X[0];
        auto& stateManager = (CStateManager&)ctx->X[1];
        auto& createInfo = (CGameObjectComponent::SCreateInfo&)ctx->X[2];

        Logger::log("Creating Component: %04x (%s)\n", createInfo.verId1.value, getComponentName((EGOComponentType)createInfo.verId1.value));
        thiz->Create(stateManager, createInfo);
    }
};

HOOK_DEFINE_TRAMPOLINE(GetGameStateHook) {
    static void Callback(CGameStateManager *thisPtr, rstl::auto_ptr<CGameState> &newState) {
        //        Logger::log("Setting New Game State Ptr.\n");
        gGameState = newState;
        gGameStateManager = thisPtr;

        Orig(thisPtr, newState);
    }
};

HOOK_DEFINE_TRAMPOLINE(GetStateManagerHook) {
    static void Callback(CStateManager *thisPtr) {
//        Logger::log("Setting State Manager ptr.\n");
        gStateManager = thisPtr;
        Orig(thisPtr);
    }
};

HOOK_DEFINE_TRAMPOLINE(CPlayerMP1_ProcessInput) {
    static void Callback(CPlayerMP1 *thiz, const CFinalInput &input, CStateManager &stateManager) {
        auto *gameState = stateManager.GameState();

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

extern "C" void exl_main(void *x0, void *x1) {
    /* Setup hooking enviroment. */
    exl::hook::Initialize();

    nn::os::SetUserExceptionHandler(exception_handler, nullptr, 0, nullptr);

    R_ABORT_UNLESS(Logger::instance().init(LOGGER_IP, 3080).value);

    runCodePatches();

    GetGameStateHook::InstallAtSymbol("_ZN17CGameStateManager18AssignNewGameStateERN4rstl8auto_ptrI10CGameStateEE");
    GetStateManagerHook::InstallAtSymbol("_ZN13CStateManager15InitializeStateEv");

    // rando patches
    CreatePickupHook::InstallAtSymbol("_ZN16CScriptPickupMP1C1ERK14CEntityInfoMP1RK12CTransform4fRK13CModelDataMP1RK19CActorParametersMP1RK6CAABoxiiiffff9CObjectId9CVector3fbb");
//    LoadPickupHook::InstallAtSymbol("_Z16LoadPickupMP1GOCR12CInputStreamR16SGOComponentInfo");
    //    SetItemTypeInlineHook::InstallAtOffset(0xEA0034);
    CreateComponentHook::InstallAtOffset(0x46A394);

    // practice mod patches
    CPlayerMP1_ProcessInput::InstallAtSymbol("_ZN10CPlayerMP112ProcessInputERK11CFinalInputR13CStateManager");

    // ImGui Hooks
#if IMGUI_ENABLED
    nvnImGui::InstallHooks();

    nvnImGui::addDrawFunc(drawDebugWindow);
#endif

}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}