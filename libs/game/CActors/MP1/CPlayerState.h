#pragma once

class COutputStream;
class CStateManager;

#include "../types.h"
#include <Stream/CInputStream.h>
#include <CObject/CObjectId.h>

class CPlayerStateMP1 {
public:
    // enums copied from prime decomp
    enum class EItemType : int {
        Invalid = -1,
        PowerBeam = 0,
        IceBeam = 1,
        WaveBeam = 2,
        PlasmaBeam = 3,
        Missiles = 4,
        ScanVisor = 5,
        MorphBallBombs = 6,
        PowerBombs = 7,
        Flamethrower = 8,
        ThermalVisor = 9,
        ChargeBeam = 10,
        SuperMissile = 11,
        GrappleBeam = 12,
        XRayVisor = 13,
        IceSpreader = 14,
        SpaceJumpBoots = 15,
        MorphBall = 16,
        CombatVisor = 17,
        BoostBall = 18,
        SpiderBall = 19,
        PowerSuit = 20,
        GravitySuit = 21,
        VariaSuit = 22,
        PhazonSuit = 23,
        EnergyTanks = 24,
        UnknownItem1 = 25,
        HealthRefill = 26,
        UnknownItem2 = 27,
        Wavebuster = 28,
        Truth = 29,
        Strength = 30,
        Elder = 31,
        Wild = 32,
        Lifegiver = 33,
        Warrior = 34,
        Chozo = 35,
        Nature = 36,
        Sun = 37,
        World = 38,
        Spirit = 39,
        Newborn = 40,
        Max
    };

    enum EPlayerVisorMP1 {
        kPV_Combat,
        kPV_XRay,
        kPV_Scan,
        kPV_Thermal,
    };

    enum EPlayerSuit {
        kPS_Invalid = -1,
        kPS_Power,
        kPS_Gravity,
        kPS_Varia,
        kPS_Phazon,
        kPS_FusionPower,
        kPS_FusionGravity,
        kPS_FusionVaria,
        kPS_FusionPhazon,
    };

    enum EBeamIdMP1 {
        kBI_Invalid = -1,
        kBI_Power,
        kBI_Ice,
        kBI_Wave,
        kBI_Plasma,
        kBI_Phazon,
        kBI_Phazon2 = 27,
    };

    class CPowerUp {
    private:
        int mAmount;
        int mCapacity;
    public:
        CPowerUp(int,int);
        CPowerUp(CInputStream &);
        void PutTo(COutputStream &);
    };

    CPlayerStateMP1(void);
    CPlayerStateMP1(CInputStream &,uint);
    ~CPlayerStateMP1();
    static int GetItemMax(CPlayerStateMP1::EItemType);
    void ResetFromStream(CInputStream &,uint);
    void PutTo(COutputStream &);

    void SetPowerUp(CPlayerStateMP1::EItemType,int);
    void AddPowerUp(CPlayerStateMP1::EItemType,int);
    bool HasPowerUp(CPlayerStateMP1::EItemType) const;

    float GetMaxHealth(void) const;
    void SetPickup(CPlayerStateMP1::EItemType,int);
    void IncrPickUp(CPlayerStateMP1::EItemType,int);
    void DecrPickUp(CPlayerStateMP1::EItemType,int);
    int GetItemAmount(CPlayerStateMP1::EItemType) const;
    int GetItemCapacity(CPlayerStateMP1::EItemType) const;
    uint GetPowerUp(CPlayerStateMP1::EItemType);
    void ListPowerUps(void);

    void EnableItem(CPlayerStateMP1::EItemType);
    void DisableItem(CPlayerStateMP1::EItemType);
    bool ItemEnabled(CPlayerStateMP1::EItemType) const;

    void ResetVisor(CPlayerStateMP1::EPlayerVisorMP1);
    void StartTransitionToVisor(CStateManager &,CPlayerStateMP1::EPlayerVisorMP1);
    void UpdateVisorTransition(CStateManager &,float);
    bool GetIsVisorTransitioning(void) const;
    float GetVisorTransitionFactor(void) const;
    float GetVisorTransitionTimeLeft(void) const;
    const char* GetVisorDebugName(CPlayerStateMP1::EPlayerVisorMP1);
    void HasVisor(CPlayerStateMP1::EPlayerVisorMP1);
    void Kill(CStateManager &);
    float GetBaseHealthCapacity(void);
    float GetEnergyTankCapacity(void);
    void CalculateScanPair(void);
    bool IsValidScan(CObjectId) const;
    float GetScanFraction(CObjectId);
    void SetScanFraction(CObjectId,float);
    void UpdateStaticInterference(CStateManager &,float const&);
    CPlayerStateMP1::EPlayerVisorMP1 GetActiveVisor(CStateManager const&) const;
    bool CanVisorSeeFog(CStateManager const&) const;
    CPlayerStateMP1::EPlayerSuit GetRenderSuit(void) const;
    bool IsRenderFusionSuit(void) const;
    int GetSamusSuitMPT(void) const;
    int GetSamusBeamMPT(void) const;
    int GetMaxNumPercentageItems(void) const;
    int GetCurrNumPercentageItems(void) const;
    int GetCurrItemPercentage(void) const;
    int GetMaxNumCriticalItems(void) const;
    int GetCurrNumCriticalItems(void) const;
    int GetCurrCriticalItemPercentage(void) const;
    void GiveAllPowerUps(CStateManager &);
    int GetComboMinimumFuelAmount(void) const;
    float GetComboMissileUsagePerSecond(void);
    const char* GetSuitTypeNameFromEnum(CPlayerStateMP1::EPlayerSuit);
    const char* GetTransitionSuitTypeNameFromEnum(CPlayerStateMP1::EPlayerSuit);
//    void ConnectVisorTransitionStartedCallback(TFunctorR<void,CStateManager &,CPlayerStateMP1::EPlayerVisorMP1 const,CPlayerStateMP1::EPlayerVisorMP1 const>);
};

inline const char* getItemName(CPlayerStateMP1::EItemType type) {
    switch (type) {
    case CPlayerStateMP1::EItemType::Invalid:
        return "Invalid";
    case CPlayerStateMP1::EItemType::PowerBeam:
        return "PowerBeam";
    case CPlayerStateMP1::EItemType::IceBeam:
        return "IceBeam";
    case CPlayerStateMP1::EItemType::WaveBeam:
        return "WaveBeam";
    case CPlayerStateMP1::EItemType::PlasmaBeam:
        return "PlasmaBeam";
    case CPlayerStateMP1::EItemType::Missiles:
        return "Missiles";
    case CPlayerStateMP1::EItemType::ScanVisor:
        return "ScanVisor";
    case CPlayerStateMP1::EItemType::MorphBallBombs:
        return "MorphBallBombs";
    case CPlayerStateMP1::EItemType::PowerBombs:
        return "PowerBombs";
    case CPlayerStateMP1::EItemType::Flamethrower:
        return "Flamethrower";
    case CPlayerStateMP1::EItemType::ThermalVisor:
        return "ThermalVisor";
    case CPlayerStateMP1::EItemType::ChargeBeam:
        return "ChargeBeam";
    case CPlayerStateMP1::EItemType::SuperMissile:
        return "SuperMissile";
    case CPlayerStateMP1::EItemType::GrappleBeam:
        return "GrappleBeam";
    case CPlayerStateMP1::EItemType::XRayVisor:
        return "XRayVisor";
    case CPlayerStateMP1::EItemType::IceSpreader:
        return "IceSpreader";
    case CPlayerStateMP1::EItemType::SpaceJumpBoots:
        return "SpaceJumpBoots";
    case CPlayerStateMP1::EItemType::MorphBall:
        return "MorphBall";
    case CPlayerStateMP1::EItemType::CombatVisor:
        return "CombatVisor";
    case CPlayerStateMP1::EItemType::BoostBall:
        return "BoostBall";
    case CPlayerStateMP1::EItemType::SpiderBall:
        return "SpiderBall";
    case CPlayerStateMP1::EItemType::PowerSuit:
        return "PowerSuit";
    case CPlayerStateMP1::EItemType::GravitySuit:
        return "GravitySuit";
    case CPlayerStateMP1::EItemType::VariaSuit:
        return "VariaSuit";
    case CPlayerStateMP1::EItemType::PhazonSuit:
        return "PhazonSuit";
    case CPlayerStateMP1::EItemType::EnergyTanks:
        return "EnergyTanks";
    case CPlayerStateMP1::EItemType::UnknownItem1:
        return "UnknownItem1";
    case CPlayerStateMP1::EItemType::HealthRefill:
        return "HealthRefill";
    case CPlayerStateMP1::EItemType::UnknownItem2:
        return "UnknownItem2";
    case CPlayerStateMP1::EItemType::Wavebuster:
        return "Wavebuster";
    case CPlayerStateMP1::EItemType::Truth:
        return "Truth";
    case CPlayerStateMP1::EItemType::Strength:
        return "Strength";
    case CPlayerStateMP1::EItemType::Elder:
        return "Elder";
    case CPlayerStateMP1::EItemType::Wild:
        return "Wild";
    case CPlayerStateMP1::EItemType::Lifegiver:
        return "Lifegiver";
    case CPlayerStateMP1::EItemType::Warrior:
        return "Warrior";
    case CPlayerStateMP1::EItemType::Chozo:
        return "Chozo";
    case CPlayerStateMP1::EItemType::Nature:
        return "Nature";
    case CPlayerStateMP1::EItemType::Sun:
        return "Sun";
    case CPlayerStateMP1::EItemType::World:
        return "World";
    case CPlayerStateMP1::EItemType::Spirit:
        return "Spirit";
    case CPlayerStateMP1::EItemType::Newborn:
        return "Newborn";
    case CPlayerStateMP1::EItemType::Max:
        return "Max";
    default:
        return "Unknown";
    }
}