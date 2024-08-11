#pragma once
#include <CObject/CObjectId.h>
#include <bit>

namespace RandoConfig {
    extern float eTankCapacity;
    extern float baseHealth;
    extern CObjectId startingAreaId;
    extern CObjectId startingWorldId;
    extern const char* resultsString;

    void LoadValuesFromSeed();
}
