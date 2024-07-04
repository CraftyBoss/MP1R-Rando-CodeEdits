#pragma once

#include "Stream/CInputStream.h"
#include "CObject/CObjectId.h"
#include "CGame/CGameState.h"
#include "Math.hpp"

enum EMappableObjectType
{
    BlueDoor = 0x0,
    ShieldDoor = 0x1,
    IceDoor = 0x2,
    WaveDoor = 0x3,
    PlasmaDoor = 0x4,
    BigDoor1 = 0x5,
    BigDoor2 = 0x6,
    IceDoorCeiling = 0x7,
    IceDoorFloor = 0x8,
    WaveDoorCeiling = 0x9,
    WaveDoorFloor = 0xA,
    PlasmaDoorCeiling = 0xB,
    PlasmaDoorFloor = 0xC,
    IceDoorFloor2 = 0xD,
    WaveDoorFloor2 = 0xE,
    PlasmaDoorFloor2 = 0xF,

    DownArrowYellow = 0x1B,
    UpArrowYellow = 0x1C,
    DownArrowGreen = 0x1D,
    UpArrowGreen = 0x1E,
    DownArrowRed = 0x1F,
    UpArrowRed = 0x20,
    TransportLift = 0x21,
    SaveStation = 0x22,
    MissileStation = 0x25,

    // custom
    PickupDot = 0x24
};

enum EVisMode
{
    Always = 0x0,
    MapStationOrVisit = 0x1,
    Visit = 0x2,
    Never = 0x3,
    MapStationOrVisit2 = 0x4,
};

class CUniverseInfoMP1 {
private:
public:
    class CAreaInfoMP1 {
    public:
        CAreaInfoMP1(void);
        CAreaInfoMP1(CInputStream &);
    };

    struct SWorldInfoMP1 {
        void GetWorldName(void);
        void GetAbbreviatedWorldName(void);
    };

    struct SMappableObjectInfoMP1 {
        CGuid mId;
        EMappableObjectType mObjectType;
        EVisMode mVisMode;
        CTransform4f mTransform;

        SMappableObjectInfoMP1(CInputStream &);
    };

    CUniverseInfoMP1(void);
    ~CUniverseInfoMP1();
    void CheckLoadComplete(void);
    bool DoesWorldExist(CObjectId);
    SWorldInfoMP1* GetWorldInfo(CObjectId);
    void GetRedundantHintSet(void);
    void Initialize(CGameState const&);
//    void ReadAreaInfoMP1(rstl::vector<uchar,rstl::tracked_allocator<(IAllocator::ECategory)37,(IAllocator::EHint)0,8ul>> const&);
    SMappableObjectInfoMP1* GetMappableObjects(CObjectId);
};