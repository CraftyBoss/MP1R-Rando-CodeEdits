#pragma once

#include "types.h"
#include "Stream/CInputStream.h"

namespace NScriptLoader {
    struct SComplexPropertyLoadEntry {
        uint mTypedefHash;
        void* (*constructFunc)(void *allocator);
        ulong (*allocSizeFunc)(CInputStream& stream);
    };
}