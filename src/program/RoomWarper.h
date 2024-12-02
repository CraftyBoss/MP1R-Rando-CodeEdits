#pragma once

#include "CObject/CObjectId.h"
#include "CState/CStateManager.h"

class RoomWarper {
private:
    static CStateManager* sStateManager;

    static const char* sTransitionTextLabel;
public:
    enum class TransitionType {
        None,
        Text,
        Elevator
    };

    static void SetManager(CStateManager* manager) { sStateManager = manager; }

    static void SetTransitionLabel(const char* lbl) { sTransitionTextLabel = lbl; }

    static void WarpToRoom(const CObjectId& worldId, const CObjectId& areaId, TransitionType transitionType = TransitionType::None);

    static void WarpToStart();

    static void DrawWarpMenu();

    static const CObjectId& GetWorldIdFromRoom(const CObjectId& roomId);
};

