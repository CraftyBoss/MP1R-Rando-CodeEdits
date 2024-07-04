#include <helpers/symHelpers.h>

#include <ExceptionHandler.h>
#include <cxxabi.h>
#include <logger/Logger.hpp>

inline char* demangle(const char* symbol) {
    int status = 0;
    return abi::__cxa_demangle(symbol, nullptr, nullptr, &status);
}

void logFuncPtrSymbol(u64 addr) {
    char symbol[0x100] = {};
    u64 symAddr;
    if(addr != 0)
        symAddr = nn::diag::GetSymbolName(symbol, 0x100, addr);
    else
        symAddr = 0;

    if(!isIllegalSymbolAddress(symAddr, addr)) {
        char* demangled = demangle(symbol);
        Logger::log("%s", demangled);
        free(demangled);
    }else {
        Logger::log("%02X", addr);
    }
}