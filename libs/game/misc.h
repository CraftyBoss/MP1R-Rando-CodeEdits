#pragma once

#include <Types/CFourCC.h>

struct CEntityInfoMP1;
struct CActorParametersMP1;
struct CAnimResMPT;
struct CStaticResMPT;
struct CAnimatedUvDataMP1;

enum EMaterialTypesMP1 {};
enum EUserEventType {};

enum EWeaponType {
    kWT_None = -1,
    kWT_Power = 0,
    kWT_Ice = 1,
    kWT_Wave = 2,
    kWT_Plasma = 3,
    kWT_Bomb = 4,
    kWT_PowerBomb = 5,
    kWT_Missile = 6,
    kWT_BoostBall = 7,
    kWT_Phazon = 8,
    kWT_AI = 9,
    kWT_PoisonWater = 10,
    kWT_Lava = 11,
    kWT_Heat = 12,
    kWT_Unused1 = 13,
    kWT_OrangePhazon = 14,
    kWT_Max = 15
};

namespace IAllocator {
    struct SDebugInfo;
}

struct CFormDescriptor {
    CFormDescriptor(CInputStream &);

    CFourCC type;
    ulong size;
    ulong unk1;
    CFourCC id;
    uint readerVersion;
    uint writerVersion;
};

struct CChunkDescriptor {
    CChunkDescriptor(CInputStream &);

    CFourCC id;
    ulong size;
    uint unk;
    ulong skip;
};