#include "patches.hpp"
#include <Component/CGameObjectComponent.h>
#include <logger/Logger.hpp>

namespace patch = exl::patch;
namespace inst = exl::armv8::inst;
namespace reg = exl::armv8::reg;

void runCodePatches() {
//    patch::CodePatcher p(0x46A394);
//    p.BranchLinkInst((void*)createComponentHook);
//    p.WriteInst(inst::Nop());
//
//    p.Seek(0xEA0190);
//    p.WriteInst(inst::Nop());
}