#include <cmath>
#include <cstring>
#include <diag/assert.hpp>
#include <helpers/fsHelper.h>
#include <logger/Logger.hpp>
#include <program/RandoConfig.h>

#include "RoomWarper.h"
#include "cJSON.h"

namespace RandoConfig {
    // default values
    float eTankCapacity = 100.0f;
    float baseHealth = eTankCapacity - 1.0f;
    CObjectId startingAreaId = CObjectId("0676e13f-15cf-4bc4-a058-5e056be4cfa4");
    CObjectId startingWorldId = CObjectId();
    const char* resultsString = "Unknown Seed";

    inline void updateTankCapacity(double val) {
        if(val == (double)NAN)
            return;

        eTankCapacity = (float)val;
        baseHealth = eTankCapacity - 1.0f;

        Logger::log("Set Energy Tank Capacity to: %f\n", eTankCapacity);
        Logger::log("Set Base Health to: %f\n", baseHealth);
    }

    inline void updateStartingRoom(const char* str) {
        if(str == nullptr)
            return;

        char buffer[37] = {};
        EXL_ASSERT(strlen(str) == 36, "Starting room string is not a GUID! Value: %s", str);

        strncpy(buffer, str, sizeof(buffer));
        startingAreaId = CObjectId(buffer);
        startingWorldId = RoomWarper::GetWorldIdFromRoom(startingAreaId);

        Logger::log("Set Starting Room to: %s\n", str);
    }

    inline void updateResultsString(const char* str) {
        if(str == nullptr)
            return;

        size_t bufSize = strlen(str) + 1;
        char* buffer = (char*)malloc(bufSize);

        strncpy(buffer, str, bufSize);
        resultsString = buffer;

        Logger::log("Seed Results String: %s\n", str);
    }

    void LoadValuesFromSeed() {
        FsHelper::LoadData loadData = {
            .path = "sd:/mp1r/rando/config.json"
        };

        if(!tryLoadFileFromPath(loadData)) {
            Logger::log("Unable to load config values. Using Defaults.\n");
            return;
        }

        cJSON* configJson = cJSON_ParseWithLength((const char*)loadData.buffer, loadData.bufSize);
        if(configJson == nullptr) {
            const char* error = cJSON_GetErrorPtr();
            Logger::log("Failed to load config JSON! Error position: %s\n", error);
            FsHelper::freeLoadDataBuffer(loadData);
            return;
        }

        FsHelper::freeLoadDataBuffer(loadData);

        updateTankCapacity(cJSON_GetNumberValue(cJSON_GetObjectItem(configJson, "EnergyTankCapacity")));
//        updateStartingRoom(cJSON_GetStringValue(cJSON_GetObjectItem(configJson, "StartingArea")));
        updateResultsString(cJSON_GetStringValue(cJSON_GetObjectItem(configJson, "ResultsString")));

        cJSON_Delete(configJson);
    }
}