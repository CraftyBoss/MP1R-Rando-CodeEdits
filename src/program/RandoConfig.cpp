#include <helpers/fsHelper.h>
#include <logger/Logger.hpp>
#include <program/RandoConfig.h>

#include "cJSON.h"

namespace RandoConfig {
    // default values
    float eTankCapacity = 100.0f;
    float baseHealth = eTankCapacity - 1.0f;

    inline void updateTankCapacity(float val) {
        eTankCapacity = val;
        baseHealth = eTankCapacity - 1.0f;

        Logger::log("Set Energy Tank Capacity to: %f\n", eTankCapacity);
        Logger::log("Set Base Health to: %f\n", baseHealth);
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

        auto capacityObj = cJSON_GetObjectItem(configJson, "EnergyTankCapacity");
        if(cJSON_IsNumber(capacityObj)) {
            double capacityInt = cJSON_GetNumberValue(capacityObj);
            updateTankCapacity((float)capacityInt);
        }

        cJSON_Delete(configJson);
    }
}