#pragma once

#include "CObject/CObjectId.h"
#include "CState/CStateManager.h"

class RoomWarper {
private:
    static CStateManager* sStateManager;
public:
    static void SetManager(CStateManager* manager) { sStateManager = manager; }

    static void WarpToRoom(const CObjectId& worldId, const CObjectId& areaId);

    static void WarpToStart();

    static void DrawWarpMenu();

    static const CObjectId& GetWorldIdFromRoom(const CObjectId& roomId);
};

