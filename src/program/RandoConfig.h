#pragma once
#include <bit>

namespace RandoConfig {
    constexpr float eTankCapacity = 50.0f;
    constexpr float baseHealth = eTankCapacity - 1.0f;

    // TODO: this
    void LoadValuesFromSeed();
}
