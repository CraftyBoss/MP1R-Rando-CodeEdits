#pragma once

#include "types.h"

#include <ExceptionHandler.h>
#include <cxxabi.h>

// misc helpers

inline char* demangle(const char* symbol);

void logFuncPtrSymbol(u64 addr);
