#include <globals.h>
#include <imgui.h>
#include <logger/Logger.hpp>
#include <program/RoomWarper.h>

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

#include "RandoConfig.h"
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

void RoomWarper::WarpToStart() {
    WarpToRoom(RandoConfig::startingWorldId, RandoConfig::startingAreaId);
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

const CObjectId& RoomWarper::GetWorldIdFromRoom(const CObjectId& roomId) {
    if(std::ranges::any_of(std::begin(sOverMasterEntries), std::end(sOverMasterEntries),          [roomId](const RegionEntry& entry) { return entry.mAreaId == roomId;})) return sOverMasterId;
    else if(std::ranges::any_of(std::begin(sRuinsWorldEntries), std::end(sRuinsWorldEntries),     [roomId](const RegionEntry& entry) { return entry.mAreaId == roomId;})) return sRuinsWorldId;
    else if(std::ranges::any_of(std::begin(sLavaMasterEntries), std::end(sLavaMasterEntries),     [roomId](const RegionEntry& entry) { return entry.mAreaId == roomId;})) return sLavaMasterId;
    else if(std::ranges::any_of(std::begin(sIceWorldEntries), std::end(sIceWorldEntries),         [roomId](const RegionEntry& entry) { return entry.mAreaId == roomId;})) return sIceWorldId;
    else if(std::ranges::any_of(std::begin(sMinesMasterEntries), std::end(sMinesMasterEntries),   [roomId](const RegionEntry& entry) { return entry.mAreaId == roomId;})) return sMinesMasterId;
    else if(std::ranges::any_of(std::begin(sCraterMasterEntries), std::end(sCraterMasterEntries), [roomId](const RegionEntry& entry) { return entry.mAreaId == roomId;})) return sCraterMasterId;
    else if(std::ranges::any_of(std::begin(sIntroMasterEntries), std::end(sIntroMasterEntries),   [roomId](const RegionEntry& entry) { return entry.mAreaId == roomId;})) return sIntroMasterId;

    EXL_ABORT(0, "Failed to find World for Room ID!");
}