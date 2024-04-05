#pragma once

class CInputStream;
class COutputStream;

#include "../types.h"
#include "CState/CStateManager.h"

class CPlayerStateMP1 {
public:
    // enums copied from prime decomp
    enum EItemType {
        kIT_Invalid = -1,
        kIT_PowerBeam = 0,
        kIT_IceBeam = 1,
        kIT_WaveBeam = 2,
        kIT_PlasmaBeam = 3,
        kIT_Missiles = 4,
        kIT_ScanVisor = 5,
        kIT_MorphBallBombs = 6,
        kIT_PowerBombs = 7,
        kIT_Flamethrower = 8,
        kIT_ThermalVisor = 9,
        kIT_ChargeBeam = 10,
        kIT_SuperMissile = 11,
        kIT_GrappleBeam = 12,
        kIT_XRayVisor = 13,
        kIT_IceSpreader = 14,
        kIT_SpaceJumpBoots = 15,
        kIT_MorphBall = 16,
        kIT_CombatVisor = 17,
        kIT_BoostBall = 18,
        kIT_SpiderBall = 19,
        kIT_PowerSuit = 20,
        kIT_GravitySuit = 21,
        kIT_VariaSuit = 22,
        kIT_PhazonSuit = 23,
        kIT_EnergyTanks = 24,
        kIT_UnknownItem1 = 25,
        kIT_HealthRefill = 26,
        kIT_UnknownItem2 = 27,
        kIT_Wavebuster = 28,
        kIT_Truth = 29,
        kIT_Strength = 30,
        kIT_Elder = 31,
        kIT_Wild = 32,
        kIT_Lifegiver = 33,
        kIT_Warrior = 34,
        kIT_Chozo = 35,
        kIT_Nature = 36,
        kIT_Sun = 37,
        kIT_World = 38,
        kIT_Spirit = 39,
        kIT_Newborn = 40,

        kIT_Max
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

    struct CPowerUp {
        CPowerUp(int,int);
        CPowerUp(CInputStream &);
        void PutTo(COutputStream &);
    };

    CPlayerStateMP1(void);
    CPlayerStateMP1(CInputStream &,uint);
    ~CPlayerStateMP1();
    int GetItemMax(CPlayerStateMP1::EItemType);
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
    case CPlayerStateMP1::kIT_Invalid:
        return "Invalid";
    case CPlayerStateMP1::kIT_PowerBeam:
        return "PowerBeam";
    case CPlayerStateMP1::kIT_IceBeam:
        return "IceBeam";
    case CPlayerStateMP1::kIT_WaveBeam:
        return "WaveBeam";
    case CPlayerStateMP1::kIT_PlasmaBeam:
        return "PlasmaBeam";
    case CPlayerStateMP1::kIT_Missiles:
        return "Missiles";
    case CPlayerStateMP1::kIT_ScanVisor:
        return "ScanVisor";
    case CPlayerStateMP1::kIT_MorphBallBombs:
        return "MorphBallBombs";
    case CPlayerStateMP1::kIT_PowerBombs:
        return "PowerBombs";
    case CPlayerStateMP1::kIT_Flamethrower:
        return "Flamethrower";
    case CPlayerStateMP1::kIT_ThermalVisor:
        return "ThermalVisor";
    case CPlayerStateMP1::kIT_ChargeBeam:
        return "ChargeBeam";
    case CPlayerStateMP1::kIT_SuperMissile:
        return "SuperMissile";
    case CPlayerStateMP1::kIT_GrappleBeam:
        return "GrappleBeam";
    case CPlayerStateMP1::kIT_XRayVisor:
        return "XRayVisor";
    case CPlayerStateMP1::kIT_IceSpreader:
        return "IceSpreader";
    case CPlayerStateMP1::kIT_SpaceJumpBoots:
        return "SpaceJumpBoots";
    case CPlayerStateMP1::kIT_MorphBall:
        return "MorphBall";
    case CPlayerStateMP1::kIT_CombatVisor:
        return "CombatVisor";
    case CPlayerStateMP1::kIT_BoostBall:
        return "BoostBall";
    case CPlayerStateMP1::kIT_SpiderBall:
        return "SpiderBall";
    case CPlayerStateMP1::kIT_PowerSuit:
        return "PowerSuit";
    case CPlayerStateMP1::kIT_GravitySuit:
        return "GravitySuit";
    case CPlayerStateMP1::kIT_VariaSuit:
        return "VariaSuit";
    case CPlayerStateMP1::kIT_PhazonSuit:
        return "PhazonSuit";
    case CPlayerStateMP1::kIT_EnergyTanks:
        return "EnergyTanks";
    case CPlayerStateMP1::kIT_UnknownItem1:
        return "UnknownItem1";
    case CPlayerStateMP1::kIT_HealthRefill:
        return "HealthRefill";
    case CPlayerStateMP1::kIT_UnknownItem2:
        return "UnknownItem2";
    case CPlayerStateMP1::kIT_Wavebuster:
        return "Wavebuster";
    case CPlayerStateMP1::kIT_Truth:
        return "Truth";
    case CPlayerStateMP1::kIT_Strength:
        return "Strength";
    case CPlayerStateMP1::kIT_Elder:
        return "Elder";
    case CPlayerStateMP1::kIT_Wild:
        return "Wild";
    case CPlayerStateMP1::kIT_Lifegiver:
        return "Lifegiver";
    case CPlayerStateMP1::kIT_Warrior:
        return "Warrior";
    case CPlayerStateMP1::kIT_Chozo:
        return "Chozo";
    case CPlayerStateMP1::kIT_Nature:
        return "Nature";
    case CPlayerStateMP1::kIT_Sun:
        return "Sun";
    case CPlayerStateMP1::kIT_World:
        return "World";
    case CPlayerStateMP1::kIT_Spirit:
        return "Spirit";
    case CPlayerStateMP1::kIT_Newborn:
        return "Newborn";
    case CPlayerStateMP1::kIT_Max:
        return "Max";
    default:
        return "Unknown";
    }
}