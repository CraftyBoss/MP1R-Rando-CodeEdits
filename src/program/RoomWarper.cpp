#include <globals.h>
#include <imgui.h>
#include <logger/Logger.hpp>
#include <program/RoomWarper.h>

CObjectId sOverMasterId = CObjectId("73f2640c-cfb2-407b-a786-47a263ef0001"); // Tallon Overworld
CObjectId sRuinsWorldId = CObjectId("914061a2-c17a-4826-94f5-be4faf90cae7"); // Chozo Ruins
CObjectId sLavaMasterId = CObjectId("f5712eed-dde1-47bf-8670-d0664954861a"); // Magmoor Caverns
CObjectId sIceWorldId = CObjectId("81b62adb-88f3-46f0-a43c-b8ccdfc354df"); // Phendrana Drifts
CObjectId sMinesMasterId = CObjectId("d3e02263-def7-4a66-bef4-26a45e8c59a8"); // Phazon Mines
CObjectId sCraterMasterId = CObjectId("73318837-09ac-4dbb-bc66-d26950259b27"); // Impact Crater
CObjectId sIntroMasterId = CObjectId("4b5e8635-0f43-4ffb-9427-2e62186e517d"); // Space Pirate Frigate

namespace {
    struct RegionEntry {
        const char* mEnglishName = nullptr;
        CObjectId mAreaId;
    };

    template<unsigned int N>
    void drawAreaEntries(const char* englishName, CObjectId& regionId, const RegionEntry(&entries)[N]) {
        if(ImGui::BeginMenu(englishName)) {
            ImGui::MenuItem("Warp to room", NULL, false, false);
            for (auto& entry : entries) {
                if(ImGui::MenuItem(entry.mEnglishName)) {
                    RoomWarper::WarpToRoom(regionId, entry.mAreaId);
                }

            }
            ImGui::EndMenu();
        }
    }
}

#include "RegionEntries.h"

CStateManager* RoomWarper::sStateManager = nullptr;

void RoomWarper::WarpToRoom(const CObjectId& worldId, const CObjectId& areaId) {
    if(sStateManager == nullptr) {
        Logger::log("State Manager is not Set! Cannot Warp.\n");
        return;
    }

    gpGameState->SetCurrentWorldId(worldId);
    gpGameState->CurrentWorldState()->SetDesiredAreaAssetId(areaId);

    CGameState::ContinueWithNewInitialState(sStateManager->GameState(), CGameState::SInitialState(areaId));

    sStateManager->GameInstanceState().QuitGame(NGameInstanceState::kQR_Warp);
}

void RoomWarper::DrawWarpMenu() {
    drawAreaEntries("Tallon Overworld", sOverMasterId, sOverMasterEntries);
    drawAreaEntries("Chozo Ruins", sRuinsWorldId, sRuinsWorldEntries);
    drawAreaEntries("Magmoor Caverns", sLavaMasterId, sLavaMasterEntries);
    drawAreaEntries("Phendrana Drifts", sIceWorldId, sIceWorldEntries);
    drawAreaEntries("Phazon Mines", sMinesMasterId, sMinesMasterEntries);
    drawAreaEntries("Impact Crater", sCraterMasterId, sCraterMasterEntries);
    drawAreaEntries("Space Pirate Frigate", sIntroMasterId, sIntroMasterEntries);
}