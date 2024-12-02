#include "patches.hpp"
#include "RandoConfig.h"
#include <Component/CGameObjectComponent.h>
#include <Types/CFourCC.h>
#include <logger/Logger.hpp>
#include <misc.h>

namespace patch = exl::patch;
namespace inst = exl::armv8::inst;
namespace reg = exl::armv8::reg;



void createAndLogChunk(CChunkDescriptor* desc, CInputStream& inputStream, const char* name) {
    new(desc) CChunkDescriptor(inputStream);

    char buffer[5] = {};
    CFourCC::ToString(buffer, desc->id);
    Logger::log("%s Descriptor: %s\n", name, buffer);
}

void createScriptLoaderChunkDesc(CChunkDescriptor* desc, CInputStream& inputStream) {
    createAndLogChunk(desc, inputStream, "Script Loader Chunk");
}

void createScriptLayerChunkDesc(CChunkDescriptor* desc, CInputStream& inputStream) {
    createAndLogChunk(desc, inputStream, "Script Layer Chunk");
}

void createChunkDesc(CChunkDescriptor* desc, CInputStream& inputStream) {
    createAndLogChunk(desc, inputStream, "Chunk");
}

void CreateFormDesc(CFormDescriptor* desc, CInputStream& inputStream) {
    new(desc) CFormDescriptor(inputStream);

    Logger::log("Form Descriptor Info:\n");
    char buffer[5] = {};
    CFourCC::ToString(buffer, desc->type);
    Logger::log("\tType: %s\n", buffer);

    Logger::log("\tSize: %lu\n", desc->size);

    CFourCC::ToString(buffer, desc->id);
    Logger::log("\tID: %s\n", buffer);

    Logger::log("\tReader Version: %u\n", desc->readerVersion);
    Logger::log("\tWriter Version: %u\n", desc->writerVersion);
}

void CreateGuid(CGuid* guid, CInputStream& inputStream) {
    new(guid) CGuid(inputStream);
    Logger::log("Got GUID: %s\n", guid->AsString().data());
}

void runCodePatches() {
    // removes call to check if item in gallery can be unlocked
    patch::CodePatcher p(0xEA135C);
    p.WriteInst(inst::Nop());

    // removes call to CMaterialExec::DrawMesh (we call it ourselves in an inline hook)
    p.Seek(0xB55DA4); p.WriteInst(inst::Nop());

    p.Seek(0xE64C5C);
    p.WriteInst(inst::MovRegister(reg::X20, reg::X13));

//    p.Seek(0x4726C4);
//    p.BranchLinkInst((void*)CreateGuid);

    // changes an unused material index located in a static array used when initializing an SIconInstance for CMappableObjectData
    patch::RandomAccessPatcher rop;
    u64 startOffset = 0x1D27454;
    rop.Write(startOffset + (9 * 0x4), 9);

//    p.Seek(0xDA1368);
//    p.WriteInst(inst::Nop());

//    p.Seek(0x3D7528);
//    p.BranchLinkInst((void*)CreateFormDesc);

//    p.Seek(0x477E48);
//    p.BranchLinkInst((void*)createScriptLayerChunkDesc);
//
//    p.Seek(0x4783B0);
//    p.BranchLinkInst((void*)createScriptLayerChunkDesc);
//
//    p.Seek(0x4AB81C);
//    p.BranchLinkInst((void*)createScriptLoaderChunkDesc);
//
//    p.Seek(0x4788D0);
//    p.BranchLinkInst((void*)CreateFormDesc);
//
//    p.Seek(0x477E54);
//    p.BranchLinkInst((void*)CreateGuid);

    // force ScriptPlayerHint to return early during AcceptScriptMsg
//    p.Seek(0xD0BB4C);
//    p.WriteInst(inst::Ret());
//
//    p.Seek(0xEA0190);
//    p.WriteInst(inst::Nop());
}