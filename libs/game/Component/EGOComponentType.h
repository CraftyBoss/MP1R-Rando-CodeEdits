#pragma once

#include "types.h"

enum EGOComponentType : uint
{
    Invalid = 0x0,
    EntityProperties = 0x749749F1,
    FakePlayerControls = 0x4EC5FA3A,
    StaticCollision = 0x57153AA4,
    RenderWorld = 0x41956904,
    ActorCollision = 0xB4361E7B,
    LightStatic = 0x2BE8BC19,
    LightDynamic = 0x9EE5541D,
    Effect = 0xCD098F70,
    Relay = 0x8FE0BFC9,
    Counter = 0xA7DB53C1,
    Timer = 0x9E8A4940,
    ControllerAction = 0xD616EE8B,
    Waypoint = 0xD898656D,
    PathControl = 0xF0240D23,
    CameraHint = 0x4FE57689,
    TouchableTrigger = 0x97E65DDD,
    Touch = 0x1A4117AB,
    TriggerLogic = 0xC49D730E,
    CustomInterpolation = 0x1349E5AC,
    CameraTarget = 0xC1F64515,
    Generator = 0xDE522669,
    SplineMotion = 0x2C4F2D31,
    DynamicActorCollision = 0x21C57D2B,
    Render = 0xDF31EC16,
    TakeDamage = 0xBDE4AB05,
    AnimationMountRider = 0x5453C979,
    TimerSequence = 0x46FAD23,
    ApplyDamage = 0x3175DF36,
    RelayRandom = 0x65E2349B,
    RelayConditional = 0xABBCFC6A,
    SpawnPoint = 0xEA30E0B1,
    ActorKeyframe = 0x1FB9AF22,
    ObjectFollow = 0x10EA9EC8,
    Pickup = 0x481EA5AF,
    CameraManager = 0xBC9A60AE,
    ColorModifier = 0xB85D6790,
    Explosion = 0x21C14B0,
    ReloadSetLoader = 0x16702F15,
    Checkpoint = 0x660FC7C1,
    PlayerRespawn = 0x8C2CCFAC,
    ImpulseDriver = 0xC0281AE7,
    Health = 0x6E89BE7,
    Respawn = 0x9373FEC0,
    ActorInteraction = 0xC7B43DA6,
    CameraTargetPlayer = 0x78D8893A,
    PoiObject = 0xCE22001E,
    Sound = 0xFDD83489,
    PerformanceGroupController = 0xCCAD4BD9,
    TouchSet = 0x502506D6,
    LiquidVolume = 0xE1E1C49C,
    NearVisible = 0x6C5D597D,
    LiquidInhabitant = 0x3449A5DF,
    CharacterPrimitivesCollision = 0x591D8F55,
    TriggerForce = 0xBD4CFA2F,
    GroupSpawn = 0x2131C235,
    AnimationGridController = 0x2751EBF2,
    TimerAnimationGridParamProvider = 0x18B96D29,
    CameraShaker = 0x343A47F7,
    PlayerActor = 0x7E6063C8,
    Tippy = 0x91F22DCF,
    CinematicCameraShot = 0x89F426F2,
    ConveyorModifier = 0x1EB2749F,
    FogVolume = 0x73AECD92,
    Retronome = 0x845E492A,
    WaterRenderVolume = 0x23C5DFF4,
    CinematicSkipHandler = 0x55F80CCE,
    InventoryItem = 0xF34EDD1F,
    EndGame = 0x18C0AD0F,
    UVTransform = 0x6302BBB3,
    MusicData = 0x25899782,
    MusicStateController = 0x1AC8C8FD,
    MusicSystemTransport = 0x47A60DC3,
    AdapterManager = 0x5CF17BFE,
    RelayAutoFire = 0x7F6D1CBA,
    GraphicalTransition = 0xD745DC42,
    RetronomeDriver = 0xFA3899C,
    CausticVolume = 0xA7D1C922,
    Playlist = 0xBA796FEF,
    VoiceEffect = 0x24D9D323,
    DSP = 0xF7602744,
    RoomSettings = 0x160E9AF9,
    DynamicActorControl = 0x5746A908,
    TimeKeyframe = 0xF442A668,
    RelayProbabilityGameMode = 0xB6040870,
    SimpleShadow = 0x212BCDF5,
    AudioBusController = 0x655C5175,
    PlayerKeyframe = 0xF6751A5D,
    SurfaceControl = 0xBE7FC29,
    SimpleSound = 0xB6EC1A51,
    LightGroupProxy = 0xD2CAC9A5,
    LevelDarkener = 0xBD040603,
    RenderGroup = 0xA72A9926,
    SkinSwap = 0x3ABCFF68,
    StreamedMovie = 0xBFF963D2,
    BloomEffect = 0x7DCAF170,
    ProjectedSimpleShadowReceiver = 0x1243C3E3,
    LoadUnitController = 0x4C53A836,
    DynamicLoadManager = 0xEE0D6FD4,
    AudioBusMixer = 0x62913993,
    FSMManager = 0x8832EA4D,
    RoomController = 0x83CC17AA,
    PathFind = 0xD0368513,
    OrbitTarget = 0xCEAFD99C,
    NavigationMesh = 0x49BD721E,
    NavigationMeshHint = 0x4490513E,
    NavigationOffMeshLink = 0x85298BEA,
    Tonemap = 0xDDEA916D,
    ScreenSpaceAO = 0x8061E045,
    TextPane = 0x38ACAAF1,
    InventoryTextPane = 0x79738030,
    ContextInteraction = 0x59CFBBD7,
    DetectionPlane = 0x69091B92,
    CameraFilter = 0xB0C9B2F9,
    AnimatedMeter = 0xAD2098FA,
    ModCon = 0x451740EB,
    GlobalStateMonitor = 0xECD265D2,
    RelayMemory = 0x91C301A5,
    EnvironmentVarModifier = 0xF05BC9C3,
    Terrain = 0x2BA4912D,
    ControllerAnalogShapeAction = 0x998FFC9,
    UICamera = 0xB35B0375,
    Drivable = 0x244019EB,
    Occlusion = 0xF6A30345,
    AnimatedSprite = 0xD8726471,
    PlayerEventListener = 0xF06BBE92,
    EnvironmentVarQuery = 0x4C183EBB,
    ControllerAnalogMovement = 0xC6F6F28C,
    TriggerInhabitant = 0x91F73D69,
    CameraTargetCreature = 0x9E806C4,
    UIButton = 0x13DAAAC,
    ControllerAnalogInputDriver = 0xB7332353,
    GradientAmbient = 0x87EFBCF0,
    CameraSystemHint = 0x59372FE6,
    CollisionProbe = 0xA3B90913,
    HUDSuppressor = 0xA02CF18F,
    UIProxy = 0xC80DDC,
    GameFlowRelay = 0x70292D3D,
    SettingsMenuManager = 0x91666769,
    AnalogDriver = 0xDEC78ECB,
    EnvironmentVarSender = 0xC26ABE1A,
    EnvironmentVarListener = 0x2F0C8179,
    ControlCommandDisabler = 0x29B7E32A,
    ControlCommandSpoofer = 0xF0D1BCC7,
    AiTarget = 0x9E20D0AF,
    UIRelay = 0x2376DE64,
    TriggerProgressionVolume = 0x780E031E,
    Projectile = 0xB692D28B,
    FrontEndManager = 0x8F472283,
    RelayFrameDelay = 0x455285E2,
    GameFlowHub = 0x46B12081,
    NavigationAreaLink = 0x676A5AC4,
    DamageResponderVulnerability = 0x736DD919,
    GameFlowProxy = 0x10BE69F9,
    ObjectSelector = 0xED02DE02,
    AIGeneratorSelector = 0x55960D16,
    AIGenerator = 0xAC073DF4,
    Label = 0x78ADD45F,
    RelayAttackTypePayload = 0xF20F2698,
    Faction = 0xAFD50F72,
    ParticleVolume = 0x3FCF5A88,
    PeriodicAdditiveAnimationDriver = 0xB793D90A,
    AnimVisibilityStateGroupManager = 0xD34AB306,
    PlayerDeathFall = 0xCBA2FC47,
    SaveSlot = 0x8B306E38,
    CameraAdditiveFOV = 0x8666855A,
    TriggerDeathFall = 0xFD46F49E,
    RelayOriginatorFilter = 0x5959DB91,
    ObjectTeleport = 0xE1C825C9,
    PlayerTeleport = 0x238467F5,
    CameraPredictivePitchHint = 0x514043DD,
    PlayerInventoryEffects = 0xC338FD04,
    CameraPredictiveYawHint = 0x322F85E1,
    ToneData = 0x67598BE,
    UIMenu = 0x7EDF6B2,
    UIWidget = 0x3CFFFC01,
    RhythmMatcher = 0x3DFD89F7,
    ToneSelectorSequence = 0x8F4A3A35,
    ToneSelectorScriptDriven = 0xD0E99272,
    CinematicActor = 0xD298FC35,
    SlideShow = 0x7A6ED813,
    BoostPad = 0x854924D1,
    SetInventory = 0x7A38CC26,
    ToneSelectorHint = 0x4ADC88B7,
    PathGenerator = 0xB3B55602,
    UIListView = 0x5445F685,
    MIDINoteAdaptor = 0x84BB17FA,
    NavigationMeshDynamicObstruction = 0x3536E079,
    CameraPointOfInterest = 0xC16B7565,
    AITeleportProxy = 0x41AD2545,
    Cinematic = 0xC9EEBC83,
    AABoxMagnet = 0xD09FBBE7,
    FlowPath = 0xF9F62FD4,
    MIDISequence = 0x18E10190,
    MIDIRetronome = 0x76AAC155,
    ToneSelectorMIDI = 0x49D039CD,
    Dock = 0xA10BAA67,
    NavigationMeshDock = 0xF190A097,
    GibManager = 0x6221A411,
    ScreenShot = 0xD3E0D14,
    MIDIMatcher = 0x2249DE78,
    ControllerMotionDriver = 0xAE579212,
    SetAnimVisibilityState = 0xD2BCB71A,
    RenderClipPlane = 0x21A978D3,
    IncandescenceModulator = 0x1955E30C,
    UISlider = 0x5F0FA37C,
    SampleBankHint = 0xCF9E2373,
    AudioSamplerProxy = 0xFC397B56,
    SubtitleSequence = 0x57AB06B5,
    PhaseToEvents = 0x921362,
    SplineMotionPhaseResponder = 0xC6C04116,
    ActorKeyframePhaseResponder = 0x35FA03A6,
    SimpleSoundPhaseResponder = 0xF3BC4EE8,
    MIDINoteEmitter = 0x4CA2E586,
    Boolean = 0x5DD288E,
    LogicGate = 0x9340932C,
    RenderDecal = 0xD7B10EFD,
    PatternMatcher = 0xDF279C9B,
    MIDIControllerMessageEmitter = 0x9D97D9C1,
    SoundVolumeModifier = 0xC03CD39D,
    Reactivator = 0xF75ADD4D,
    SampleBankData = 0x8BE6648A,
    ActionControlPoint = 0xE795D2B1,
    MusicStateTransitionData = 0xA86001C4,
    Footprint = 0x74BD547A,
    SamplerVoiceBankData = 0x61EF47C6,
    PlayerSpawnTeleporter = 0x916F072F,
    AudioSampleBank = 0x17982019,
    AudioSampler = 0xDC777C06,
    HardwareProxy = 0xEA6D58E8,
    RoomPreloader = 0xB2DA6936,
    BroadcastSpatialListener = 0xEF9ABE4,
    BroadcastSpatial = 0x9AAFCB03,
    AudioBusDriver = 0xD515E89D,
    AudioBusDriverInteractor = 0x2C9918AE,
    CombatStateProxy = 0x1A4BC6BD,
    MIDITransmitter = 0xE6A64862,
    MIDIReceiver = 0x4F10BECB,
    MIDIResponderSampler = 0xF12E9C71,
    RuleSetManager = 0x3325A532,
    MIDIResponderArpeggiator = 0xD9C9A3F5,
    MIDIResponderChordMaker = 0xBA249E78,
    TemplateManager = 0xD645278A,
    MIDIResponderPatternMatcher = 0x11F81321,
    AddActorEntityFlag = 0xD813A35A,
    ColorSampler = 0x12931CE3,
    PickupManager = 0x57DC20F,
    SoundPitchModifier = 0xD3FD952C,
    ActorVertexAnimationPlayList = 0x75560CE3,
    ActorVertexAnimationPhaseResponder = 0x412E0D82,
    BGMHint = 0x5CB0DE9C,
    LightShafts = 0x37E758DA,
    Choreographer = 0x8CE59F27,
    RelayChoreography = 0xD7C7E6F9,
    AudioSamplerPhaseResponder = 0xD54B0DCC,
    PhaseLooper = 0x8CE6E4F6,
    CameraLetterBox = 0x945E0902,
    ReflectionProbe = 0x27807E39,
    HeatDistortionHint = 0xD008829F,
    CameraProxy = 0x5E3F39EE,
    LavaFlowSurface = 0xF75EA7EF,
    FogShape = 0x92561A4A,
    DockDoor = 0xAE371A20,
    GenericSplineControl = 0xCC8F9FF2,
    ControlSplineMappingsDefinition = 0x682591,
    Scannable = 0x157533DD,
    PhaseRelay = 0xC04D4753,
    Skybox = 0x5112A065,
    ControlSchemesDefinition = 0x637E29A,
    ControlSchemeAccessor = 0x60E107E0,
    AudioObstruction = 0xECE8E32E,
    BroadcastGlobal = 0xA482E214,
    BroadcastGlobalListener = 0x3E9F6170,
    CreatureBase = 0x986AD9EA,
    PickupDropper = 0x720A3AC5,
    AnimationController = 0xBCA078F7,
    FSMController = 0x8F6C4769,
    CollisionLogic = 0x4368E960,
    PhysicsDriver = 0xA3B4FD2,
    CreatureMovement = 0xA60A6693,
    CreatureHealth = 0x81519976,
    RegisterEntity = 0xCB54E84D,
    ProxyRegisteredEntity = 0x6654CA01,
    CharacterPrimitives = 0x6548CFCC,
    Steering = 0x2C9D30B,
    WorldTransition = 0x564DEE0F,
    CreatureRules = 0x4A8D8E14,
    CreatureTargeting = 0x2095A979,
    TerrainAlignment = 0x2D0F036C,
    CreatureLeashBehavior = 0xE9B9F6EE,
    CreatureChangePostureBehavior = 0x97422C3F,
    CreatureTurnBehavior = 0x8BB84EB1,
    CreatureNavigateBehavior = 0x228A335D,
    CreaturePatrolBehavior = 0xFC76D74C,
    CreatureDeployActionBehavior = 0x949E5BBE,
    CreatureWanderBehavior = 0x24EB1A32,
    CreatureSpawnBehavior = 0xC1C02476,
    CreatureRangedCombatBehavior = 0x834CF41D,
    CreatureMeleeCombatBehavior = 0x45924F80,
    CreatureHitReactionBehavior = 0xCDB24FAD,
    CreatureHecklerBehavior = 0x2E8A5117,
    CreatureDespawnBehavior = 0x52BFD9AD,
    CreatureFallBehavior = 0x1B1EBDD,
    CreatureActionBroadcaster = 0xA3FE9467,
    CreatureAttackPathBehavior = 0xF3133CDF,
    CreatureScriptedAnimationBehavior = 0xABE969D,
    CreatureAmbushBehavior = 0x6B3CDB28,
    CreatureEvadeBehavior = 0xC062FD1A,
    CameraTargetProxy = 0x2BC6608A,
    VolumetricFog = 0x1B9CD84F,
    CreatureFlinch = 0x874AA246,
    VolumetricFogRegion = 0xAFFE9CF9,
    ResetObject = 0x7DB10F4C,
    Scoring = 0x7D3512D7,
    ScorableTarget = 0x3254E042,
    DynamicControlScriptedRealDefinition = 0x40F9629D,
    InventoryInitializer = 0x24D8FDD0,
    GameOptionsDefinition = 0xB28E4996,
    GameOptionsAccessor = 0xA190EAA2,
    CreatureWaitAtPositionBehavior = 0xA38743D1,
    CreatureContextInteractionBehavior = 0x81718106,
    CreatureContextInteraction = 0x931B692F,
    BoolToRealMap = 0xDE3024E9,
    EnumToRealMap = 0x69504ACB,
    IntToRealMap = 0x8C9B8856,
    RealToRealMap = 0xECFFB88F,
    CoverPoint = 0xC0366DC7,
    CreatureCoverCombatBehavior = 0x9E73EB5D,
    CreatureArmor = 0x1F969D66,
    RealNumberFunction = 0x2CDAF986,
    RealNumber = 0xD855B36E,
    RealNumberComparison = 0xBC121D69,
    DebugMenuItemsDefinition = 0x5A82703D,
    CreatureFleeBehavior = 0x2AB5EF6F,
    TimeDilation = 0x3EC5D79A,
    CreatureFireDamage = 0x5904644C,
    CreatureHeadTracking = 0xDB0310B9,
    OriginatorProxy = 0x9E219714,
    FleePoint = 0xC55DC4E,
    Enumeration = 0x528C1159,
    CreatureAiming = 0x87CF06DF,
    ProjectileIntersectionHint = 0xFDA2465A,
    CreatureIceDamage = 0x86692789,
    AIPostOwner = 0x71A1C997,
    WanderPoint = 0xE262F4AF,
    LineOfSight = 0xB1A9ECED,
    CreatureThunderDamage = 0xD73EBB11,
    CreatureProjectileLauncher = 0xDE991E1E,
    ChainLightning = 0x6027B2CE,
    CreatureSecondaryAnimation = 0x16169AEA,
    CreatureSecondaryActions = 0xD1BBF0E7,
    AudioPluginEffect = 0x57312ED0,
    AnimationRateModifier = 0x97947F1E,
    CollisionWithWorld = 0x27568F71,
    CreatureScriptedJumpBehavior = 0x51422A18,
    ScriptedJumpData = 0x331613D1,
    SniperPoint = 0xBC5EB9D5,
    CreatureSniperBehavior = 0xD8A9F583,
    GenericAimTarget = 0xFA73D359,
    ControlCommandMappingPhysical = 0x65823457,
    ControlCommandMappingNode = 0xECDCE2E3,
    ControlCommandMappingsDefinition = 0x7CDFBC83,
    ReverbFieldNode = 0x712755E8,
    InputMacroPlayer = 0x6467B289,
    InputMacroRecorder = 0x83EB0628,
    ControlCommandMappingOne = 0x98AACF09,
    ControlCommandMappingZero = 0x48C1CEF7,
    ControlCommandMappingScriptedReal = 0xE33F78B,
    ControlCommandMappingAdd = 0x66AD5099,
    ControlCommandMappingDebugMenuBoolean = 0xDAEE1AAD,
    ControlCommandMappingDebugMenuInt = 0xCC5AE725,
    ControlCommandMappingDebugMenuRealEvaluator = 0xAB505EAB,
    ControlCommandMappingDebugMenuRealMultiplier = 0x8B123910,
    ControlCommandMappingMultiply = 0xEE0426D8,
    ControlCommandMappingAnd = 0xAC392770,
    ControlCommandMappingNot = 0xDB4AB61D,
    ControlCommandMappingOr = 0x81EC3BB6,
    ControlCommandMappingSpline = 0x94147BD8,
    ControlCommandMappingNegate = 0x571F8FD2,
    ControlCommandMappingNegativeOne = 0x7B8DB9C7,
    HealthPhases = 0xE7C5BA34,
    AiTargetManager = 0x88E7782,
    RumbleEffectsDefinition = 0x12D9053F,
    RumbleSensoryDefinition = 0x1F0AFAB0,
    RumbleEmitter = 0x224F782C,
    FactionManager = 0x3BBBE401,
    CreatureTurnProcedural = 0x7FCBC2AD,
    RealNumberPhaseResponder = 0x3713FD4F,
    CreatureActionPatternBehavior = 0xA619D230,
    PathMovement = 0x1A828893,
    CreatureProneBehavior = 0xD36B0797,
    PathMovementMagnetizationPoint = 0x9C7DF587,
    DistanceCompare = 0x46033F8D,
    CreatureTargetable = 0xEFED81F1,
    WindWaker = 0x53744D89,
    AnimationEventListener = 0xC3CCC605,
    CreaturePositioning = 0xD5DCB013,
    TriggerDamage = 0xA9584C89,
    CreaturePositioningManager = 0x5BA03233,
    AttackManager = 0x3DA7DA05,
    AttackManagerTest = 0x6ACAA7DA,
    FSMHotSwapper = 0x2CE325,
    ScriptedAnimationData = 0x80B94FCD,
    HeightfieldSurfaceDescription = 0x3A080954,
    AnchorPoint = 0x44ED3D2,
    CreatureScriptedActionBehavior = 0xFC7D9A11,
    CreatureSplineFollowBehavior = 0xFB26FD7D,
    LavaRenderVolume = 0xA7EE9C33,
    CreatureGrabTarget = 0xF33FD0C8,
    BossMeterState = 0xD4AC7206,
    PlayerSpawnPoint_InputMacroRelay = 0xCE2470CB,
    AudioEmitter = 0xEEA718B9,
    NavigationMeshIncludeExcludeHint = 0x20C7601E,
    AnimationVariableReal = 0x1F8CA08E,
    CounterPhaseResponder = 0x47E7EE64,
    AutoExposureHint = 0x98694074,
    ShockWave = 0xCD85A847,
    ColorGrade = 0x6B091E44,
    VolumetricFogHint = 0x84FB5798,
    PointOfInterest = 0xAFB53A8C,
    ColorGradeHint = 0xA36CD908,
    EffectVariableDriver = 0xFD5075F3,
    TimerProgression = 0xEF5E0348,
    ProjectedShadowBlob = 0x414D77FF,
    CreatureCollisionAvoidance = 0x444959AD,
    SoundFilterModifier = 0x512A3EE4,
    DistanceCompareGroup = 0x9F61CD7F,
    PhaseCombinator = 0xB9FAC2DF,
    CollisionAvoidanceManager = 0x536567,
    BloomEffectHint = 0xF66B9100,
    AngleCompare = 0xDAE5D368,
    AudioOcclusionVolume = 0xC3049839,
    AnimationUserEventRouter = 0x917FD37D,
    AnimatedMeterPhaseResponder = 0xE493532F,
    Backlight = 0x190D20D7,
    NavigationPathPoint = 0xCE69684B,
    NavigationPathPointOffMeshLink = 0x37B90174,
    ChromaticAberration = 0x2B854B47,
    SoundLevelMeterPhaseDriver = 0x99DC9C6E,
    AudioPluginEffectCrossfadePhaseResponder = 0x8E881C85,
    LightHint = 0x56CF02A6,
    AudioObstructionOcclusionOverride = 0x135C010E,
    BroadcastAudioEvent = 0x62FC6E51,
    BroadcastAudioEventListener = 0x458501CF,
    GameVariableAccess = 0xEA33D242,
    PerformanceHint = 0x6F5A20BE,
    AudioBusPhaseResponder = 0x62C5D8C7,
    CounterAdapter = 0x4812E080,
    TimerStopwatch = 0xD81587E0,
    HealthDisplay = 0x7E394FF2,
    HealthDisplaySource = 0xAD67F77F,
    SurfaceGenerator = 0x4EEBAAD3,
    BlackboardBoolean = 0xA41FC3A9,
    BlackboardRealNumber = 0x13D0F71D,
    BlackboardPhaseRelay = 0x25E4D42F,
    BlackboardBooleanWriter = 0xC8A56ECC,
    BlackboardPhaseRelayWriter = 0xBFB2C3AE,
    BlackboardRealNumberWriter = 0x12A1D49F,
    FSMMessage = 0x7C9B685C,
    CreatureHurlBehavior = 0xCF272BD6,
    AudioPluginEffectCrossfadeSend = 0xC5BFD655,
    TimerSequencePhaseResponder = 0xA623AFA1,
    AmbientParticleEffect = 0xCBE2042D,
    RealValueRelay = 0x63DD6841,
    RealNumberDriver = 0xD81EF16F,
    Beam = 0x392DCDF1,
    SnapToPath = 0x1D4532DB,
    ScriptedMotion = 0xF78649C8,
    DamageRelay = 0x75C4E493,
    POIRoomController = 0x5B5FB670,
    ScreenCoverageTrigger = 0x12C9E761,
    VolumetricFogRegionTransition = 0xDF95AC1A,
    AudioOutputEffects = 0xF6559CEA,
    AnimationPlaybackRate = 0xEB5B364D,
    Condition = 0x76025BB8,
    ScriptedMotionPhaseResponder = 0x50B4F3D7,
    PlayerRoomTeleporter = 0x7FAE7590,
    CreaturePositionLogic_WaypointScripting = 0x2A7E80CC,
    Credits = 0xA60583CC,
    ActorMP1 = 0xB6200BE6,
    ColorModulateMP1 = 0xA856F484,
    CounterMP1 = 0x32AEF7DD,
    DebugActorMP1 = 0x59BC6B3B,
    WaypointMP1 = 0x8E4C86EC,
    PlayerMP1 = 0x99EA4919,
    SpawnPointMP1 = 0x79F02E11,
    EnergyProjectileMP1 = 0x7003C6AA,
    ControllerActionMP1 = 0x42A7692D,
    PlasmaProjectileMP1 = 0xF5CE0E14,
    BombMP1 = 0xE9F08E02,
    PowerBombMP1 = 0xD62862CA,
    NewFlameThrowerMP1 = 0x2CA49DE4,
    WaveBusterMP1 = 0x7191E814,
    ExplosionMP1 = 0x50E62AE4,
    ShockWaveMP1 = 0x2CB074D1,
    FlameThrowerMP1 = 0x618B3777,
    IceAttackProjectileMP1 = 0xB130AB71,
    DamageEffectMP1 = 0xDAF49AD2,
    CollisionActorMP1 = 0x7059AA54,
    ScriptRelayMP1 = 0x1B78F9A4,
    TimerMP1 = 0x25C6D2A3,
    TriggerMP1 = 0xF526FC2A,
    SwitchMP1 = 0xC0E28B3D,
    AiJumpPointMP1 = 0xEFA09DB4,
    RumbleEffectMP1 = 0xA7C1E08D,
    ActorKeyframeMP1 = 0x3CE6630A,
    SteamMP1 = 0xFC64463E,
    BallTriggerMP1 = 0x50F2F67A,
    FirstPersonCameraMP1 = 0x1FAB791D,
    BallCameraMP1 = 0x76A6385F,
    FreeCameraMP1 = 0x4E9F22E,
    InterpolationCameraMP1 = 0xE44D80F3,
    SpecialFunctionMP1 = 0x71337F4F,
    AmbientAIMP1 = 0xA497918D,
    ActorRotateMP1 = 0x3391E02B,
    MemoryRelayMP1 = 0x1205609A,
    PlatformMP1 = 0xA12967FB,
    EffectMP1 = 0xB421CDCB,
    HUDMemoMP1 = 0x77E59F98,
    DamageableTriggerMP1 = 0xDCB49607,
    WaterMP1 = 0x12DB855D,
    CameraMP1 = 0x2EAEC98,
    VisorFlareMP1 = 0x8BEDB563,
    DebrisExtendedMP1 = 0x6665F6DF,
    DebrisMP1 = 0xE7A0171,
    WorldTeleporterTooMP1 = 0x2FA104FF,
    PlayerActorMP1 = 0xDB389155,
    CameraWaypointMP1 = 0xF649EEC3,
    AreaAttributesMP1 = 0x48F8341D,
    PointOfInterestMP1 = 0xD5C1882,
    CameraBlurKeyframeMP1 = 0xCC92B31B,
    CameraFilterKeyframeMP1 = 0x750702EA,
    StreamedAudioMP1 = 0x7E1F2807,
    SoundMP1 = 0x46787DDD,
    MidiMP1 = 0x3BAB18A0,
    VisorGooMP1 = 0xCB5682C4,
    CameraShakerOldMP1 = 0x9B0F9C29,
    CameraShakerNewMP1 = 0x99DFC912,
    RandomRelayMP1 = 0xDF4FCCA3,
    NotSTD_DockMP1 = 0x3168FE6,
    PickupMP1 = 0x36386A69,
    GrapplePointMP1 = 0xEB82E3B,
    ContraptionMP1 = 0xB5CD58CD,
    DoorMP1 = 0x564A1641,
    RoomAcousticsMP1 = 0xCD695064,
    PlayerHintMP1 = 0x23F1E994,
    GunTurretMP1 = 0x1704C1F0,
    CameraHintTriggerMP1 = 0x4CA870EF,
    GeneratorMP1 = 0x8EE5D87E,
    WallCrawlerSwarmMP1 = 0x16B8B319,
    DistanceFogMP1 = 0x2131945E,
    CameraHintMP1 = 0xAD191C7E,
    EnvFxDensityControllerMP1 = 0x3C832EC7,
    ElectroMagneticPulseMP1 = 0x7D070EF0,
    CameraPitchVolumeMP1 = 0x176F6F27,
    PickupGeneratorMP1 = 0x4CA59EB7,
    MazeNodeMP1 = 0x47E5D68B,
    PathCameraMP1 = 0xC6E2DE1F,
    CoverPointMP1 = 0x2B3AD4B6,
    RadialDamageMP1 = 0x93C5B36D,
    PhazonPoolMP1 = 0xACC3CE1E,
    SpiderBallAttractionSurfaceMP1 = 0xD4CD5E63,
    SpiderBallWaypointMP1 = 0xC7668E15,
    TargetingPointMP1 = 0x48AE7CA9,
    IntroBossMP1 = 0x65EE9092,
    RippleMP1 = 0x3AB7170D,
    TeamAiMgrMP1 = 0xC30C5758,
    ThermalHeatFaderMP1 = 0x33D9FFA6,
    SpindleCameraMP1 = 0x36B8D0D0,
    SpankWeedMP1 = 0x705B28FC,
    ShadowProjectorMP1 = 0x17DB2246,
    WorldLightFaderMP1 = 0x7A4BC122,
    ThardusMP1 = 0xEAA40B01,
    AThardusRockProjectileMP1 = 0x2249224E,
    AtomicAlphaMP1 = 0x61653ED2,
    AtomicBetaMP1 = 0x87412090,
    GeemerMP1 = 0xB99D2B06,
    OculusMP1 = 0x9EAF010,
    PufferMP1 = 0xADA0EC66,
    BouncyGrenadeMP1 = 0xF800EFF9,
    RidleyMP1 = 0x4F9D71EC,
    BabygothMP1 = 0x254D4D49,
    TryclopsMP1 = 0x1498BA74,
    BloodFlowerMP1 = 0x4DEB1E3A,
    FlyingPirateMP1 = 0x6CFA6902,
    BurrowerMP1 = 0x1C3D435D,
    ChozoGhostMP1 = 0x84B92D36,
    DroneMP1 = 0x50B7576D,
    SpacePirateMP1 = 0xEB1F342,
    ElitePirateMP1 = 0xF4326A02,
    OmegaPirateMP1 = 0x7F2845C7,
    PuddleSporeMP1 = 0x242C3C90,
    EyeBallMP1 = 0xC963CC17,
    FireFleaMP1 = 0x52EBC2A7,
    FlaahgraMP1 = 0x3C669ACB,
    FlaahgraTentacleMP1 = 0x30A6B6DE,
    FlaahgraProjectileMP1Runtime = 0xFFFBA0C,
    FlaahgraPlantsMP1Runtime = 0xD2806770,
    FlaahgraRendererMP1Runtime = 0xDB9430C7,
    ParasiteMP1 = 0xBE462B0E,
    FlickerBatMP1 = 0x1A03F50A,
    GarBeetleMP1 = 0xE8CA3EA0,
    IceSheegothMP1 = 0xCBE62855,
    WarWaspMP1 = 0xB6E36FD4,
    JellyZapMP1 = 0xFE939195,
    MagdoliteMP1 = 0xB0C4378E,
    MetareeMP1 = 0x1230FA75,
    MetroidBetaMP1 = 0x55032CDA,
    SeedlingMP1 = 0xB6B2691,
    TargetableProjectileMP1 = 0xBCF96C94,
    RipperMP1 = 0xB5D157DB,
    SnakeWeedSwarmMP1 = 0xAC1C4AAD,
    MetroidMP1 = 0x7FC7DEBC,
    PuddleToadGammaMP1 = 0x719EE8C2,
    FishCloudModifierMP1 = 0x41BC06DD,
    MetroidPrimeRelayMP1 = 0x622F6B23,
    GrapplePointMP1Runtime = 0x5048D44F,
    ControlledPlatformMP1Runtime = 0xD909C936,
    FishCloudMP1 = 0x4E8A3CE2,
    PhazonHealingNoduleMP1 = 0xA68D2EB5,
    MetroidPrimeMP1 = 0xAE757B71,
    ProxyPlayerMP1 = 0x5797D3C7,
    MetroidPrimeStage2MP1 = 0x980EF312,
    VisorFlareMP1Runtime = 0x9B592020,
    DroneLaserMP1Runtime = 0xD39988C0,
    DeathCameraEffectMP1Runtime = 0xDCF9614B,
    ElitePirateGrenadeLauncherMP1Runtime = 0x27116D98,
    PoisonProjectileMP1 = 0x7CF4C8C0,
    MissileTargetMP1 = 0x1E3517FC,
    DestroyableRockMP1Runtime = 0x42020DA4,
    RoomOcclusionOverrideMP1 = 0x6EA08BAD,
    ElectricBeamProjectileMP1Runtime = 0x82980E58,
    CameraOverrideMP1 = 0xE5740BFD,
    AnimatedCameraMP1 = 0xCB3B5BEA,
    ARepulsorMP1 = 0x85E5E721,
    PlayerStateChangeMP1 = 0x90905F24,
    AEnergyBallMP1 = 0xAE09E5E2,
    AScriptBeamMP1 = 0x515541D,
    SustainedPlayerDamageMP1Runtime = 0xEB70CD36,
    HUDManagerMP1 = 0x104A7116,
    ScriptHUDBillboardEffectMP1 = 0x7383D6B5,
    RumbleEventResponderMP1 = 0x333F83D4,
    CinematicStateProxyMP1 = 0x14D107FE,
    HUDBillboardFreezeEffectTestMP1 = 0x63B6ECDC,
    ScriptedOcclusionVolumeMP1 = 0xC1FAC87D,
    MaterialVariableDriverMP1 = 0x8A12A2F9,
    EffectProxyMP1 = 0xE12AAE70,
    CinematicMP1 = 0xF06785E1,
    PhazonDriverMP1 = 0x73A6D8F1,
    AmbientParticleEffectPrimitiveShapeProviderMP1 = 0x55A188F6,
    XRayHintMP1 = 0x98EEA4CA,
    CameraWaterStateProxyMP1 = 0x6A7A53B0,
    WaterTransitionMP1 = 0xDF22BD66,
    AreaOcclusionModifierMP1 = 0x8B8689D,
    BakedLightingPriorityModifierMP1 = 0x9FEAB9B3,
    AutoExposureHintMP1 = 0x451C85B6,
    ActorIceDarkenerMP1 = 0x427C6C50,
    FrontEndManagerMPT = 0x72F2A8FE,
    SaveSlotMPT = 0x983B318F,
};

inline const char* getComponentName(EGOComponentType type) {
    switch (type) {
    case EGOComponentType::Invalid:
        return "Invalid";
    case EGOComponentType::EntityProperties:
        return "EntityProperties";
    case EGOComponentType::FakePlayerControls:
        return "FakePlayerControls";
    case EGOComponentType::StaticCollision:
        return "StaticCollision";
    case EGOComponentType::RenderWorld:
        return "RenderWorld";
    case EGOComponentType::ActorCollision:
        return "ActorCollision";
    case EGOComponentType::LightStatic:
        return "LightStatic";
    case EGOComponentType::LightDynamic:
        return "LightDynamic";
    case EGOComponentType::Effect:
        return "Effect";
    case EGOComponentType::Relay:
        return "Relay";
    case EGOComponentType::Counter:
        return "Counter";
    case EGOComponentType::Timer:
        return "Timer";
    case EGOComponentType::ControllerAction:
        return "ControllerAction";
    case EGOComponentType::Waypoint:
        return "Waypoint";
    case EGOComponentType::PathControl:
        return "PathControl";
    case EGOComponentType::CameraHint:
        return "CameraHint";
    case EGOComponentType::TouchableTrigger:
        return "TouchableTrigger";
    case EGOComponentType::Touch:
        return "Touch";
    case EGOComponentType::TriggerLogic:
        return "TriggerLogic";
    case EGOComponentType::CustomInterpolation:
        return "CustomInterpolation";
    case EGOComponentType::CameraTarget:
        return "CameraTarget";
    case EGOComponentType::Generator:
        return "Generator";
    case EGOComponentType::SplineMotion:
        return "SplineMotion";
    case EGOComponentType::DynamicActorCollision:
        return "DynamicActorCollision";
    case EGOComponentType::Render:
        return "Render";
    case EGOComponentType::TakeDamage:
        return "TakeDamage";
    case EGOComponentType::AnimationMountRider:
        return "AnimationMountRider";
    case EGOComponentType::TimerSequence:
        return "TimerSequence";
    case EGOComponentType::ApplyDamage:
        return "ApplyDamage";
    case EGOComponentType::RelayRandom:
        return "RelayRandom";
    case EGOComponentType::RelayConditional:
        return "RelayConditional";
    case EGOComponentType::SpawnPoint:
        return "SpawnPoint";
    case EGOComponentType::ActorKeyframe:
        return "ActorKeyframe";
    case EGOComponentType::ObjectFollow:
        return "ObjectFollow";
    case EGOComponentType::Pickup:
        return "Pickup";
    case EGOComponentType::CameraManager:
        return "CameraManager";
    case EGOComponentType::ColorModifier:
        return "ColorModifier";
    case EGOComponentType::Explosion:
        return "Explosion";
    case EGOComponentType::ReloadSetLoader:
        return "ReloadSetLoader";
    case EGOComponentType::Checkpoint:
        return "Checkpoint";
    case EGOComponentType::PlayerRespawn:
        return "PlayerRespawn";
    case EGOComponentType::ImpulseDriver:
        return "ImpulseDriver";
    case EGOComponentType::Health:
        return "Health";
    case EGOComponentType::Respawn:
        return "Respawn";
    case EGOComponentType::ActorInteraction:
        return "ActorInteraction";
    case EGOComponentType::CameraTargetPlayer:
        return "CameraTargetPlayer";
    case EGOComponentType::PoiObject:
        return "PoiObject";
    case EGOComponentType::Sound:
        return "Sound";
    case EGOComponentType::PerformanceGroupController:
        return "PerformanceGroupController";
    case EGOComponentType::TouchSet:
        return "TouchSet";
    case EGOComponentType::LiquidVolume:
        return "LiquidVolume";
    case EGOComponentType::NearVisible:
        return "NearVisible";
    case EGOComponentType::LiquidInhabitant:
        return "LiquidInhabitant";
    case EGOComponentType::CharacterPrimitivesCollision:
        return "CharacterPrimitivesCollision";
    case EGOComponentType::TriggerForce:
        return "TriggerForce";
    case EGOComponentType::GroupSpawn:
        return "GroupSpawn";
    case EGOComponentType::AnimationGridController:
        return "AnimationGridController";
    case EGOComponentType::TimerAnimationGridParamProvider:
        return "TimerAnimationGridParamProvider";
    case EGOComponentType::CameraShaker:
        return "CameraShaker";
    case EGOComponentType::PlayerActor:
        return "PlayerActor";
    case EGOComponentType::Tippy:
        return "Tippy";
    case EGOComponentType::CinematicCameraShot:
        return "CinematicCameraShot";
    case EGOComponentType::ConveyorModifier:
        return "ConveyorModifier";
    case EGOComponentType::FogVolume:
        return "FogVolume";
    case EGOComponentType::Retronome:
        return "Retronome";
    case EGOComponentType::WaterRenderVolume:
        return "WaterRenderVolume";
    case EGOComponentType::CinematicSkipHandler:
        return "CinematicSkipHandler";
    case EGOComponentType::InventoryItem:
        return "InventoryItem";
    case EGOComponentType::EndGame:
        return "EndGame";
    case EGOComponentType::UVTransform:
        return "UVTransform";
    case EGOComponentType::MusicData:
        return "MusicData";
    case EGOComponentType::MusicStateController:
        return "MusicStateController";
    case EGOComponentType::MusicSystemTransport:
        return "MusicSystemTransport";
    case EGOComponentType::AdapterManager:
        return "AdapterManager";
    case EGOComponentType::RelayAutoFire:
        return "RelayAutoFire";
    case EGOComponentType::GraphicalTransition:
        return "GraphicalTransition";
    case EGOComponentType::RetronomeDriver:
        return "RetronomeDriver";
    case EGOComponentType::CausticVolume:
        return "CausticVolume";
    case EGOComponentType::Playlist:
        return "Playlist";
    case EGOComponentType::VoiceEffect:
        return "VoiceEffect";
    case EGOComponentType::DSP:
        return "DSP";
    case EGOComponentType::RoomSettings:
        return "RoomSettings";
    case EGOComponentType::DynamicActorControl:
        return "DynamicActorControl";
    case EGOComponentType::TimeKeyframe:
        return "TimeKeyframe";
    case EGOComponentType::RelayProbabilityGameMode:
        return "RelayProbabilityGameMode";
    case EGOComponentType::SimpleShadow:
        return "SimpleShadow";
    case EGOComponentType::AudioBusController:
        return "AudioBusController";
    case EGOComponentType::PlayerKeyframe:
        return "PlayerKeyframe";
    case EGOComponentType::SurfaceControl:
        return "SurfaceControl";
    case EGOComponentType::SimpleSound:
        return "SimpleSound";
    case EGOComponentType::LightGroupProxy:
        return "LightGroupProxy";
    case EGOComponentType::LevelDarkener:
        return "LevelDarkener";
    case EGOComponentType::RenderGroup:
        return "RenderGroup";
    case EGOComponentType::SkinSwap:
        return "SkinSwap";
    case EGOComponentType::StreamedMovie:
        return "StreamedMovie";
    case EGOComponentType::BloomEffect:
        return "BloomEffect";
    case EGOComponentType::ProjectedSimpleShadowReceiver:
        return "ProjectedSimpleShadowReceiver";
    case EGOComponentType::LoadUnitController:
        return "LoadUnitController";
    case EGOComponentType::DynamicLoadManager:
        return "DynamicLoadManager";
    case EGOComponentType::AudioBusMixer:
        return "AudioBusMixer";
    case EGOComponentType::FSMManager:
        return "FSMManager";
    case EGOComponentType::RoomController:
        return "RoomController";
    case EGOComponentType::PathFind:
        return "PathFind";
    case EGOComponentType::OrbitTarget:
        return "OrbitTarget";
    case EGOComponentType::NavigationMesh:
        return "NavigationMesh";
    case EGOComponentType::NavigationMeshHint:
        return "NavigationMeshHint";
    case EGOComponentType::NavigationOffMeshLink:
        return "NavigationOffMeshLink";
    case EGOComponentType::Tonemap:
        return "Tonemap";
    case EGOComponentType::ScreenSpaceAO:
        return "ScreenSpaceAO";
    case EGOComponentType::TextPane:
        return "TextPane";
    case EGOComponentType::InventoryTextPane:
        return "InventoryTextPane";
    case EGOComponentType::ContextInteraction:
        return "ContextInteraction";
    case EGOComponentType::DetectionPlane:
        return "DetectionPlane";
    case EGOComponentType::CameraFilter:
        return "CameraFilter";
    case EGOComponentType::AnimatedMeter:
        return "AnimatedMeter";
    case EGOComponentType::ModCon:
        return "ModCon";
    case EGOComponentType::GlobalStateMonitor:
        return "GlobalStateMonitor";
    case EGOComponentType::RelayMemory:
        return "RelayMemory";
    case EGOComponentType::EnvironmentVarModifier:
        return "EnvironmentVarModifier";
    case EGOComponentType::Terrain:
        return "Terrain";
    case EGOComponentType::ControllerAnalogShapeAction:
        return "ControllerAnalogShapeAction";
    case EGOComponentType::UICamera:
        return "UICamera";
    case EGOComponentType::Drivable:
        return "Drivable";
    case EGOComponentType::Occlusion:
        return "Occlusion";
    case EGOComponentType::AnimatedSprite:
        return "AnimatedSprite";
    case EGOComponentType::PlayerEventListener:
        return "PlayerEventListener";
    case EGOComponentType::EnvironmentVarQuery:
        return "EnvironmentVarQuery";
    case EGOComponentType::ControllerAnalogMovement:
        return "ControllerAnalogMovement";
    case EGOComponentType::TriggerInhabitant:
        return "TriggerInhabitant";
    case EGOComponentType::CameraTargetCreature:
        return "CameraTargetCreature";
    case EGOComponentType::UIButton:
        return "UIButton";
    case EGOComponentType::ControllerAnalogInputDriver:
        return "ControllerAnalogInputDriver";
    case EGOComponentType::GradientAmbient:
        return "GradientAmbient";
    case EGOComponentType::CameraSystemHint:
        return "CameraSystemHint";
    case EGOComponentType::CollisionProbe:
        return "CollisionProbe";
    case EGOComponentType::HUDSuppressor:
        return "HUDSuppressor";
    case EGOComponentType::UIProxy:
        return "UIProxy";
    case EGOComponentType::GameFlowRelay:
        return "GameFlowRelay";
    case EGOComponentType::SettingsMenuManager:
        return "SettingsMenuManager";
    case EGOComponentType::AnalogDriver:
        return "AnalogDriver";
    case EGOComponentType::EnvironmentVarSender:
        return "EnvironmentVarSender";
    case EGOComponentType::EnvironmentVarListener:
        return "EnvironmentVarListener";
    case EGOComponentType::ControlCommandDisabler:
        return "ControlCommandDisabler";
    case EGOComponentType::ControlCommandSpoofer:
        return "ControlCommandSpoofer";
    case EGOComponentType::AiTarget:
        return "AiTarget";
    case EGOComponentType::UIRelay:
        return "UIRelay";
    case EGOComponentType::TriggerProgressionVolume:
        return "TriggerProgressionVolume";
    case EGOComponentType::Projectile:
        return "Projectile";
    case EGOComponentType::FrontEndManager:
        return "FrontEndManager";
    case EGOComponentType::RelayFrameDelay:
        return "RelayFrameDelay";
    case EGOComponentType::GameFlowHub:
        return "GameFlowHub";
    case EGOComponentType::NavigationAreaLink:
        return "NavigationAreaLink";
    case EGOComponentType::DamageResponderVulnerability:
        return "DamageResponderVulnerability";
    case EGOComponentType::GameFlowProxy:
        return "GameFlowProxy";
    case EGOComponentType::ObjectSelector:
        return "ObjectSelector";
    case EGOComponentType::AIGeneratorSelector:
        return "AIGeneratorSelector";
    case EGOComponentType::AIGenerator:
        return "AIGenerator";
    case EGOComponentType::Label:
        return "Label";
    case EGOComponentType::RelayAttackTypePayload:
        return "RelayAttackTypePayload";
    case EGOComponentType::Faction:
        return "Faction";
    case EGOComponentType::ParticleVolume:
        return "ParticleVolume";
    case EGOComponentType::PeriodicAdditiveAnimationDriver:
        return "PeriodicAdditiveAnimationDriver";
    case EGOComponentType::AnimVisibilityStateGroupManager:
        return "AnimVisibilityStateGroupManager";
    case EGOComponentType::PlayerDeathFall:
        return "PlayerDeathFall";
    case EGOComponentType::SaveSlot:
        return "SaveSlot";
    case EGOComponentType::CameraAdditiveFOV:
        return "CameraAdditiveFOV";
    case EGOComponentType::TriggerDeathFall:
        return "TriggerDeathFall";
    case EGOComponentType::RelayOriginatorFilter:
        return "RelayOriginatorFilter";
    case EGOComponentType::ObjectTeleport:
        return "ObjectTeleport";
    case EGOComponentType::PlayerTeleport:
        return "PlayerTeleport";
    case EGOComponentType::CameraPredictivePitchHint:
        return "CameraPredictivePitchHint";
    case EGOComponentType::PlayerInventoryEffects:
        return "PlayerInventoryEffects";
    case EGOComponentType::CameraPredictiveYawHint:
        return "CameraPredictiveYawHint";
    case EGOComponentType::ToneData:
        return "ToneData";
    case EGOComponentType::UIMenu:
        return "UIMenu";
    case EGOComponentType::UIWidget:
        return "UIWidget";
    case EGOComponentType::RhythmMatcher:
        return "RhythmMatcher";
    case EGOComponentType::ToneSelectorSequence:
        return "ToneSelectorSequence";
    case EGOComponentType::ToneSelectorScriptDriven:
        return "ToneSelectorScriptDriven";
    case EGOComponentType::CinematicActor:
        return "CinematicActor";
    case EGOComponentType::SlideShow:
        return "SlideShow";
    case EGOComponentType::BoostPad:
        return "BoostPad";
    case EGOComponentType::SetInventory:
        return "SetInventory";
    case EGOComponentType::ToneSelectorHint:
        return "ToneSelectorHint";
    case EGOComponentType::PathGenerator:
        return "PathGenerator";
    case EGOComponentType::UIListView:
        return "UIListView";
    case EGOComponentType::MIDINoteAdaptor:
        return "MIDINoteAdaptor";
    case EGOComponentType::NavigationMeshDynamicObstruction:
        return "NavigationMeshDynamicObstruction";
    case EGOComponentType::CameraPointOfInterest:
        return "CameraPointOfInterest";
    case EGOComponentType::AITeleportProxy:
        return "AITeleportProxy";
    case EGOComponentType::Cinematic:
        return "Cinematic";
    case EGOComponentType::AABoxMagnet:
        return "AABoxMagnet";
    case EGOComponentType::FlowPath:
        return "FlowPath";
    case EGOComponentType::MIDISequence:
        return "MIDISequence";
    case EGOComponentType::MIDIRetronome:
        return "MIDIRetronome";
    case EGOComponentType::ToneSelectorMIDI:
        return "ToneSelectorMIDI";
    case EGOComponentType::Dock:
        return "Dock";
    case EGOComponentType::NavigationMeshDock:
        return "NavigationMeshDock";
    case EGOComponentType::GibManager:
        return "GibManager";
    case EGOComponentType::ScreenShot:
        return "ScreenShot";
    case EGOComponentType::MIDIMatcher:
        return "MIDIMatcher";
    case EGOComponentType::ControllerMotionDriver:
        return "ControllerMotionDriver";
    case EGOComponentType::SetAnimVisibilityState:
        return "SetAnimVisibilityState";
    case EGOComponentType::RenderClipPlane:
        return "RenderClipPlane";
    case EGOComponentType::IncandescenceModulator:
        return "IncandescenceModulator";
    case EGOComponentType::UISlider:
        return "UISlider";
    case EGOComponentType::SampleBankHint:
        return "SampleBankHint";
    case EGOComponentType::AudioSamplerProxy:
        return "AudioSamplerProxy";
    case EGOComponentType::SubtitleSequence:
        return "SubtitleSequence";
    case EGOComponentType::PhaseToEvents:
        return "PhaseToEvents";
    case EGOComponentType::SplineMotionPhaseResponder:
        return "SplineMotionPhaseResponder";
    case EGOComponentType::ActorKeyframePhaseResponder:
        return "ActorKeyframePhaseResponder";
    case EGOComponentType::SimpleSoundPhaseResponder:
        return "SimpleSoundPhaseResponder";
    case EGOComponentType::MIDINoteEmitter:
        return "MIDINoteEmitter";
    case EGOComponentType::Boolean:
        return "Boolean";
    case EGOComponentType::LogicGate:
        return "LogicGate";
    case EGOComponentType::RenderDecal:
        return "RenderDecal";
    case EGOComponentType::PatternMatcher:
        return "PatternMatcher";
    case EGOComponentType::MIDIControllerMessageEmitter:
        return "MIDIControllerMessageEmitter";
    case EGOComponentType::SoundVolumeModifier:
        return "SoundVolumeModifier";
    case EGOComponentType::Reactivator:
        return "Reactivator";
    case EGOComponentType::SampleBankData:
        return "SampleBankData";
    case EGOComponentType::ActionControlPoint:
        return "ActionControlPoint";
    case EGOComponentType::MusicStateTransitionData:
        return "MusicStateTransitionData";
    case EGOComponentType::Footprint:
        return "Footprint";
    case EGOComponentType::SamplerVoiceBankData:
        return "SamplerVoiceBankData";
    case EGOComponentType::PlayerSpawnTeleporter:
        return "PlayerSpawnTeleporter";
    case EGOComponentType::AudioSampleBank:
        return "AudioSampleBank";
    case EGOComponentType::AudioSampler:
        return "AudioSampler";
    case EGOComponentType::HardwareProxy:
        return "HardwareProxy";
    case EGOComponentType::RoomPreloader:
        return "RoomPreloader";
    case EGOComponentType::BroadcastSpatialListener:
        return "BroadcastSpatialListener";
    case EGOComponentType::BroadcastSpatial:
        return "BroadcastSpatial";
    case EGOComponentType::AudioBusDriver:
        return "AudioBusDriver";
    case EGOComponentType::AudioBusDriverInteractor:
        return "AudioBusDriverInteractor";
    case EGOComponentType::CombatStateProxy:
        return "CombatStateProxy";
    case EGOComponentType::MIDITransmitter:
        return "MIDITransmitter";
    case EGOComponentType::MIDIReceiver:
        return "MIDIReceiver";
    case EGOComponentType::MIDIResponderSampler:
        return "MIDIResponderSampler";
    case EGOComponentType::RuleSetManager:
        return "RuleSetManager";
    case EGOComponentType::MIDIResponderArpeggiator:
        return "MIDIResponderArpeggiator";
    case EGOComponentType::MIDIResponderChordMaker:
        return "MIDIResponderChordMaker";
    case EGOComponentType::TemplateManager:
        return "TemplateManager";
    case EGOComponentType::MIDIResponderPatternMatcher:
        return "MIDIResponderPatternMatcher";
    case EGOComponentType::AddActorEntityFlag:
        return "AddActorEntityFlag";
    case EGOComponentType::ColorSampler:
        return "ColorSampler";
    case EGOComponentType::PickupManager:
        return "PickupManager";
    case EGOComponentType::SoundPitchModifier:
        return "SoundPitchModifier";
    case EGOComponentType::ActorVertexAnimationPlayList:
        return "ActorVertexAnimationPlayList";
    case EGOComponentType::ActorVertexAnimationPhaseResponder:
        return "ActorVertexAnimationPhaseResponder";
    case EGOComponentType::BGMHint:
        return "BGMHint";
    case EGOComponentType::LightShafts:
        return "LightShafts";
    case EGOComponentType::Choreographer:
        return "Choreographer";
    case EGOComponentType::RelayChoreography:
        return "RelayChoreography";
    case EGOComponentType::AudioSamplerPhaseResponder:
        return "AudioSamplerPhaseResponder";
    case EGOComponentType::PhaseLooper:
        return "PhaseLooper";
    case EGOComponentType::CameraLetterBox:
        return "CameraLetterBox";
    case EGOComponentType::ReflectionProbe:
        return "ReflectionProbe";
    case EGOComponentType::HeatDistortionHint:
        return "HeatDistortionHint";
    case EGOComponentType::CameraProxy:
        return "CameraProxy";
    case EGOComponentType::LavaFlowSurface:
        return "LavaFlowSurface";
    case EGOComponentType::FogShape:
        return "FogShape";
    case EGOComponentType::DockDoor:
        return "DockDoor";
    case EGOComponentType::GenericSplineControl:
        return "GenericSplineControl";
    case EGOComponentType::ControlSplineMappingsDefinition:
        return "ControlSplineMappingsDefinition";
    case EGOComponentType::Scannable:
        return "Scannable";
    case EGOComponentType::PhaseRelay:
        return "PhaseRelay";
    case EGOComponentType::Skybox:
        return "Skybox";
    case EGOComponentType::ControlSchemesDefinition:
        return "ControlSchemesDefinition";
    case EGOComponentType::ControlSchemeAccessor:
        return "ControlSchemeAccessor";
    case EGOComponentType::AudioObstruction:
        return "AudioObstruction";
    case EGOComponentType::BroadcastGlobal:
        return "BroadcastGlobal";
    case EGOComponentType::BroadcastGlobalListener:
        return "BroadcastGlobalListener";
    case EGOComponentType::CreatureBase:
        return "CreatureBase";
    case EGOComponentType::PickupDropper:
        return "PickupDropper";
    case EGOComponentType::AnimationController:
        return "AnimationController";
    case EGOComponentType::FSMController:
        return "FSMController";
    case EGOComponentType::CollisionLogic:
        return "CollisionLogic";
    case EGOComponentType::PhysicsDriver:
        return "PhysicsDriver";
    case EGOComponentType::CreatureMovement:
        return "CreatureMovement";
    case EGOComponentType::CreatureHealth:
        return "CreatureHealth";
    case EGOComponentType::RegisterEntity:
        return "RegisterEntity";
    case EGOComponentType::ProxyRegisteredEntity:
        return "ProxyRegisteredEntity";
    case EGOComponentType::CharacterPrimitives:
        return "CharacterPrimitives";
    case EGOComponentType::Steering:
        return "Steering";
    case EGOComponentType::WorldTransition:
        return "WorldTransition";
    case EGOComponentType::CreatureRules:
        return "CreatureRules";
    case EGOComponentType::CreatureTargeting:
        return "CreatureTargeting";
    case EGOComponentType::TerrainAlignment:
        return "TerrainAlignment";
    case EGOComponentType::CreatureLeashBehavior:
        return "CreatureLeashBehavior";
    case EGOComponentType::CreatureChangePostureBehavior:
        return "CreatureChangePostureBehavior";
    case EGOComponentType::CreatureTurnBehavior:
        return "CreatureTurnBehavior";
    case EGOComponentType::CreatureNavigateBehavior:
        return "CreatureNavigateBehavior";
    case EGOComponentType::CreaturePatrolBehavior:
        return "CreaturePatrolBehavior";
    case EGOComponentType::CreatureDeployActionBehavior:
        return "CreatureDeployActionBehavior";
    case EGOComponentType::CreatureWanderBehavior:
        return "CreatureWanderBehavior";
    case EGOComponentType::CreatureSpawnBehavior:
        return "CreatureSpawnBehavior";
    case EGOComponentType::CreatureRangedCombatBehavior:
        return "CreatureRangedCombatBehavior";
    case EGOComponentType::CreatureMeleeCombatBehavior:
        return "CreatureMeleeCombatBehavior";
    case EGOComponentType::CreatureHitReactionBehavior:
        return "CreatureHitReactionBehavior";
    case EGOComponentType::CreatureHecklerBehavior:
        return "CreatureHecklerBehavior";
    case EGOComponentType::CreatureDespawnBehavior:
        return "CreatureDespawnBehavior";
    case EGOComponentType::CreatureFallBehavior:
        return "CreatureFallBehavior";
    case EGOComponentType::CreatureActionBroadcaster:
        return "CreatureActionBroadcaster";
    case EGOComponentType::CreatureAttackPathBehavior:
        return "CreatureAttackPathBehavior";
    case EGOComponentType::CreatureScriptedAnimationBehavior:
        return "CreatureScriptedAnimationBehavior";
    case EGOComponentType::CreatureAmbushBehavior:
        return "CreatureAmbushBehavior";
    case EGOComponentType::CreatureEvadeBehavior:
        return "CreatureEvadeBehavior";
    case EGOComponentType::CameraTargetProxy:
        return "CameraTargetProxy";
    case EGOComponentType::VolumetricFog:
        return "VolumetricFog";
    case EGOComponentType::CreatureFlinch:
        return "CreatureFlinch";
    case EGOComponentType::VolumetricFogRegion:
        return "VolumetricFogRegion";
    case EGOComponentType::ResetObject:
        return "ResetObject";
    case EGOComponentType::Scoring:
        return "Scoring";
    case EGOComponentType::ScorableTarget:
        return "ScorableTarget";
    case EGOComponentType::DynamicControlScriptedRealDefinition:
        return "DynamicControlScriptedRealDefinition";
    case EGOComponentType::InventoryInitializer:
        return "InventoryInitializer";
    case EGOComponentType::GameOptionsDefinition:
        return "GameOptionsDefinition";
    case EGOComponentType::GameOptionsAccessor:
        return "GameOptionsAccessor";
    case EGOComponentType::CreatureWaitAtPositionBehavior:
        return "CreatureWaitAtPositionBehavior";
    case EGOComponentType::CreatureContextInteractionBehavior:
        return "CreatureContextInteractionBehavior";
    case EGOComponentType::CreatureContextInteraction:
        return "CreatureContextInteraction";
    case EGOComponentType::BoolToRealMap:
        return "BoolToRealMap";
    case EGOComponentType::EnumToRealMap:
        return "EnumToRealMap";
    case EGOComponentType::IntToRealMap:
        return "IntToRealMap";
    case EGOComponentType::RealToRealMap:
        return "RealToRealMap";
    case EGOComponentType::CoverPoint:
        return "CoverPoint";
    case EGOComponentType::CreatureCoverCombatBehavior:
        return "CreatureCoverCombatBehavior";
    case EGOComponentType::CreatureArmor:
        return "CreatureArmor";
    case EGOComponentType::RealNumberFunction:
        return "RealNumberFunction";
    case EGOComponentType::RealNumber:
        return "RealNumber";
    case EGOComponentType::RealNumberComparison:
        return "RealNumberComparison";
    case EGOComponentType::DebugMenuItemsDefinition:
        return "DebugMenuItemsDefinition";
    case EGOComponentType::CreatureFleeBehavior:
        return "CreatureFleeBehavior";
    case EGOComponentType::TimeDilation:
        return "TimeDilation";
    case EGOComponentType::CreatureFireDamage:
        return "CreatureFireDamage";
    case EGOComponentType::CreatureHeadTracking:
        return "CreatureHeadTracking";
    case EGOComponentType::OriginatorProxy:
        return "OriginatorProxy";
    case EGOComponentType::FleePoint:
        return "FleePoint";
    case EGOComponentType::Enumeration:
        return "Enumeration";
    case EGOComponentType::CreatureAiming:
        return "CreatureAiming";
    case EGOComponentType::ProjectileIntersectionHint:
        return "ProjectileIntersectionHint";
    case EGOComponentType::CreatureIceDamage:
        return "CreatureIceDamage";
    case EGOComponentType::AIPostOwner:
        return "AIPostOwner";
    case EGOComponentType::WanderPoint:
        return "WanderPoint";
    case EGOComponentType::LineOfSight:
        return "LineOfSight";
    case EGOComponentType::CreatureThunderDamage:
        return "CreatureThunderDamage";
    case EGOComponentType::CreatureProjectileLauncher:
        return "CreatureProjectileLauncher";
    case EGOComponentType::ChainLightning:
        return "ChainLightning";
    case EGOComponentType::CreatureSecondaryAnimation:
        return "CreatureSecondaryAnimation";
    case EGOComponentType::CreatureSecondaryActions:
        return "CreatureSecondaryActions";
    case EGOComponentType::AudioPluginEffect:
        return "AudioPluginEffect";
    case EGOComponentType::AnimationRateModifier:
        return "AnimationRateModifier";
    case EGOComponentType::CollisionWithWorld:
        return "CollisionWithWorld";
    case EGOComponentType::CreatureScriptedJumpBehavior:
        return "CreatureScriptedJumpBehavior";
    case EGOComponentType::ScriptedJumpData:
        return "ScriptedJumpData";
    case EGOComponentType::SniperPoint:
        return "SniperPoint";
    case EGOComponentType::CreatureSniperBehavior:
        return "CreatureSniperBehavior";
    case EGOComponentType::GenericAimTarget:
        return "GenericAimTarget";
    case EGOComponentType::ControlCommandMappingPhysical:
        return "ControlCommandMappingPhysical";
    case EGOComponentType::ControlCommandMappingNode:
        return "ControlCommandMappingNode";
    case EGOComponentType::ControlCommandMappingsDefinition:
        return "ControlCommandMappingsDefinition";
    case EGOComponentType::ReverbFieldNode:
        return "ReverbFieldNode";
    case EGOComponentType::InputMacroPlayer:
        return "InputMacroPlayer";
    case EGOComponentType::InputMacroRecorder:
        return "InputMacroRecorder";
    case EGOComponentType::ControlCommandMappingOne:
        return "ControlCommandMappingOne";
    case EGOComponentType::ControlCommandMappingZero:
        return "ControlCommandMappingZero";
    case EGOComponentType::ControlCommandMappingScriptedReal:
        return "ControlCommandMappingScriptedReal";
    case EGOComponentType::ControlCommandMappingAdd:
        return "ControlCommandMappingAdd";
    case EGOComponentType::ControlCommandMappingDebugMenuBoolean:
        return "ControlCommandMappingDebugMenuBoolean";
    case EGOComponentType::ControlCommandMappingDebugMenuInt:
        return "ControlCommandMappingDebugMenuInt";
    case EGOComponentType::ControlCommandMappingDebugMenuRealEvaluator:
        return "ControlCommandMappingDebugMenuRealEvaluator";
    case EGOComponentType::ControlCommandMappingDebugMenuRealMultiplier:
        return "ControlCommandMappingDebugMenuRealMultiplier";
    case EGOComponentType::ControlCommandMappingMultiply:
        return "ControlCommandMappingMultiply";
    case EGOComponentType::ControlCommandMappingAnd:
        return "ControlCommandMappingAnd";
    case EGOComponentType::ControlCommandMappingNot:
        return "ControlCommandMappingNot";
    case EGOComponentType::ControlCommandMappingOr:
        return "ControlCommandMappingOr";
    case EGOComponentType::ControlCommandMappingSpline:
        return "ControlCommandMappingSpline";
    case EGOComponentType::ControlCommandMappingNegate:
        return "ControlCommandMappingNegate";
    case EGOComponentType::ControlCommandMappingNegativeOne:
        return "ControlCommandMappingNegativeOne";
    case EGOComponentType::HealthPhases:
        return "HealthPhases";
    case EGOComponentType::AiTargetManager:
        return "AiTargetManager";
    case EGOComponentType::RumbleEffectsDefinition:
        return "RumbleEffectsDefinition";
    case EGOComponentType::RumbleSensoryDefinition:
        return "RumbleSensoryDefinition";
    case EGOComponentType::RumbleEmitter:
        return "RumbleEmitter";
    case EGOComponentType::FactionManager:
        return "FactionManager";
    case EGOComponentType::CreatureTurnProcedural:
        return "CreatureTurnProcedural";
    case EGOComponentType::RealNumberPhaseResponder:
        return "RealNumberPhaseResponder";
    case EGOComponentType::CreatureActionPatternBehavior:
        return "CreatureActionPatternBehavior";
    case EGOComponentType::PathMovement:
        return "PathMovement";
    case EGOComponentType::CreatureProneBehavior:
        return "CreatureProneBehavior";
    case EGOComponentType::PathMovementMagnetizationPoint:
        return "PathMovementMagnetizationPoint";
    case EGOComponentType::DistanceCompare:
        return "DistanceCompare";
    case EGOComponentType::CreatureTargetable:
        return "CreatureTargetable";
    case EGOComponentType::WindWaker:
        return "WindWaker";
    case EGOComponentType::AnimationEventListener:
        return "AnimationEventListener";
    case EGOComponentType::CreaturePositioning:
        return "CreaturePositioning";
    case EGOComponentType::TriggerDamage:
        return "TriggerDamage";
    case EGOComponentType::CreaturePositioningManager:
        return "CreaturePositioningManager";
    case EGOComponentType::AttackManager:
        return "AttackManager";
    case EGOComponentType::AttackManagerTest:
        return "AttackManagerTest";
    case EGOComponentType::FSMHotSwapper:
        return "FSMHotSwapper";
    case EGOComponentType::ScriptedAnimationData:
        return "ScriptedAnimationData";
    case EGOComponentType::HeightfieldSurfaceDescription:
        return "HeightfieldSurfaceDescription";
    case EGOComponentType::AnchorPoint:
        return "AnchorPoint";
    case EGOComponentType::CreatureScriptedActionBehavior:
        return "CreatureScriptedActionBehavior";
    case EGOComponentType::CreatureSplineFollowBehavior:
        return "CreatureSplineFollowBehavior";
    case EGOComponentType::LavaRenderVolume:
        return "LavaRenderVolume";
    case EGOComponentType::CreatureGrabTarget:
        return "CreatureGrabTarget";
    case EGOComponentType::BossMeterState:
        return "BossMeterState";
    case EGOComponentType::PlayerSpawnPoint_InputMacroRelay:
        return "PlayerSpawnPoint_InputMacroRelay";
    case EGOComponentType::AudioEmitter:
        return "AudioEmitter";
    case EGOComponentType::NavigationMeshIncludeExcludeHint:
        return "NavigationMeshIncludeExcludeHint";
    case EGOComponentType::AnimationVariableReal:
        return "AnimationVariableReal";
    case EGOComponentType::CounterPhaseResponder:
        return "CounterPhaseResponder";
    case EGOComponentType::AutoExposureHint:
        return "AutoExposureHint";
    case EGOComponentType::ShockWave:
        return "ShockWave";
    case EGOComponentType::ColorGrade:
        return "ColorGrade";
    case EGOComponentType::VolumetricFogHint:
        return "VolumetricFogHint";
    case EGOComponentType::PointOfInterest:
        return "PointOfInterest";
    case EGOComponentType::ColorGradeHint:
        return "ColorGradeHint";
    case EGOComponentType::EffectVariableDriver:
        return "EffectVariableDriver";
    case EGOComponentType::TimerProgression:
        return "TimerProgression";
    case EGOComponentType::ProjectedShadowBlob:
        return "ProjectedShadowBlob";
    case EGOComponentType::CreatureCollisionAvoidance:
        return "CreatureCollisionAvoidance";
    case EGOComponentType::SoundFilterModifier:
        return "SoundFilterModifier";
    case EGOComponentType::DistanceCompareGroup:
        return "DistanceCompareGroup";
    case EGOComponentType::PhaseCombinator:
        return "PhaseCombinator";
    case EGOComponentType::CollisionAvoidanceManager:
        return "CollisionAvoidanceManager";
    case EGOComponentType::BloomEffectHint:
        return "BloomEffectHint";
    case EGOComponentType::AngleCompare:
        return "AngleCompare";
    case EGOComponentType::AudioOcclusionVolume:
        return "AudioOcclusionVolume";
    case EGOComponentType::AnimationUserEventRouter:
        return "AnimationUserEventRouter";
    case EGOComponentType::AnimatedMeterPhaseResponder:
        return "AnimatedMeterPhaseResponder";
    case EGOComponentType::Backlight:
        return "Backlight";
    case EGOComponentType::NavigationPathPoint:
        return "NavigationPathPoint";
    case EGOComponentType::NavigationPathPointOffMeshLink:
        return "NavigationPathPointOffMeshLink";
    case EGOComponentType::ChromaticAberration:
        return "ChromaticAberration";
    case EGOComponentType::SoundLevelMeterPhaseDriver:
        return "SoundLevelMeterPhaseDriver";
    case EGOComponentType::AudioPluginEffectCrossfadePhaseResponder:
        return "AudioPluginEffectCrossfadePhaseResponder";
    case EGOComponentType::LightHint:
        return "LightHint";
    case EGOComponentType::AudioObstructionOcclusionOverride:
        return "AudioObstructionOcclusionOverride";
    case EGOComponentType::BroadcastAudioEvent:
        return "BroadcastAudioEvent";
    case EGOComponentType::BroadcastAudioEventListener:
        return "BroadcastAudioEventListener";
    case EGOComponentType::GameVariableAccess:
        return "GameVariableAccess";
    case EGOComponentType::PerformanceHint:
        return "PerformanceHint";
    case EGOComponentType::AudioBusPhaseResponder:
        return "AudioBusPhaseResponder";
    case EGOComponentType::CounterAdapter:
        return "CounterAdapter";
    case EGOComponentType::TimerStopwatch:
        return "TimerStopwatch";
    case EGOComponentType::HealthDisplay:
        return "HealthDisplay";
    case EGOComponentType::HealthDisplaySource:
        return "HealthDisplaySource";
    case EGOComponentType::SurfaceGenerator:
        return "SurfaceGenerator";
    case EGOComponentType::BlackboardBoolean:
        return "BlackboardBoolean";
    case EGOComponentType::BlackboardRealNumber:
        return "BlackboardRealNumber";
    case EGOComponentType::BlackboardPhaseRelay:
        return "BlackboardPhaseRelay";
    case EGOComponentType::BlackboardBooleanWriter:
        return "BlackboardBooleanWriter";
    case EGOComponentType::BlackboardPhaseRelayWriter:
        return "BlackboardPhaseRelayWriter";
    case EGOComponentType::BlackboardRealNumberWriter:
        return "BlackboardRealNumberWriter";
    case EGOComponentType::FSMMessage:
        return "FSMMessage";
    case EGOComponentType::CreatureHurlBehavior:
        return "CreatureHurlBehavior";
    case EGOComponentType::AudioPluginEffectCrossfadeSend:
        return "AudioPluginEffectCrossfadeSend";
    case EGOComponentType::TimerSequencePhaseResponder:
        return "TimerSequencePhaseResponder";
    case EGOComponentType::AmbientParticleEffect:
        return "AmbientParticleEffect";
    case EGOComponentType::RealValueRelay:
        return "RealValueRelay";
    case EGOComponentType::RealNumberDriver:
        return "RealNumberDriver";
    case EGOComponentType::Beam:
        return "Beam";
    case EGOComponentType::SnapToPath:
        return "SnapToPath";
    case EGOComponentType::ScriptedMotion:
        return "ScriptedMotion";
    case EGOComponentType::DamageRelay:
        return "DamageRelay";
    case EGOComponentType::POIRoomController:
        return "POIRoomController";
    case EGOComponentType::ScreenCoverageTrigger:
        return "ScreenCoverageTrigger";
    case EGOComponentType::VolumetricFogRegionTransition:
        return "VolumetricFogRegionTransition";
    case EGOComponentType::AudioOutputEffects:
        return "AudioOutputEffects";
    case EGOComponentType::AnimationPlaybackRate:
        return "AnimationPlaybackRate";
    case EGOComponentType::Condition:
        return "Condition";
    case EGOComponentType::ScriptedMotionPhaseResponder:
        return "ScriptedMotionPhaseResponder";
    case EGOComponentType::PlayerRoomTeleporter:
        return "PlayerRoomTeleporter";
    case EGOComponentType::CreaturePositionLogic_WaypointScripting:
        return "CreaturePositionLogic_WaypointScripting";
    case EGOComponentType::Credits:
        return "Credits";
    case EGOComponentType::ActorMP1:
        return "ActorMP1";
    case EGOComponentType::ColorModulateMP1:
        return "ColorModulateMP1";
    case EGOComponentType::CounterMP1:
        return "CounterMP1";
    case EGOComponentType::DebugActorMP1:
        return "DebugActorMP1";
    case EGOComponentType::WaypointMP1:
        return "WaypointMP1";
    case EGOComponentType::PlayerMP1:
        return "PlayerMP1";
    case EGOComponentType::SpawnPointMP1:
        return "SpawnPointMP1";
    case EGOComponentType::EnergyProjectileMP1:
        return "EnergyProjectileMP1";
    case EGOComponentType::ControllerActionMP1:
        return "ControllerActionMP1";
    case EGOComponentType::PlasmaProjectileMP1:
        return "PlasmaProjectileMP1";
    case EGOComponentType::BombMP1:
        return "BombMP1";
    case EGOComponentType::PowerBombMP1:
        return "PowerBombMP1";
    case EGOComponentType::NewFlameThrowerMP1:
        return "NewFlameThrowerMP1";
    case EGOComponentType::WaveBusterMP1:
        return "WaveBusterMP1";
    case EGOComponentType::ExplosionMP1:
        return "ExplosionMP1";
    case EGOComponentType::ShockWaveMP1:
        return "ShockWaveMP1";
    case EGOComponentType::FlameThrowerMP1:
        return "FlameThrowerMP1";
    case EGOComponentType::IceAttackProjectileMP1:
        return "IceAttackProjectileMP1";
    case EGOComponentType::DamageEffectMP1:
        return "DamageEffectMP1";
    case EGOComponentType::CollisionActorMP1:
        return "CollisionActorMP1";
    case EGOComponentType::ScriptRelayMP1:
        return "ScriptRelayMP1";
    case EGOComponentType::TimerMP1:
        return "TimerMP1";
    case EGOComponentType::TriggerMP1:
        return "TriggerMP1";
    case EGOComponentType::SwitchMP1:
        return "SwitchMP1";
    case EGOComponentType::AiJumpPointMP1:
        return "AiJumpPointMP1";
    case EGOComponentType::RumbleEffectMP1:
        return "RumbleEffectMP1";
    case EGOComponentType::ActorKeyframeMP1:
        return "ActorKeyframeMP1";
    case EGOComponentType::SteamMP1:
        return "SteamMP1";
    case EGOComponentType::BallTriggerMP1:
        return "BallTriggerMP1";
    case EGOComponentType::FirstPersonCameraMP1:
        return "FirstPersonCameraMP1";
    case EGOComponentType::BallCameraMP1:
        return "BallCameraMP1";
    case EGOComponentType::FreeCameraMP1:
        return "FreeCameraMP1";
    case EGOComponentType::InterpolationCameraMP1:
        return "InterpolationCameraMP1";
    case EGOComponentType::SpecialFunctionMP1:
        return "SpecialFunctionMP1";
    case EGOComponentType::AmbientAIMP1:
        return "AmbientAIMP1";
    case EGOComponentType::ActorRotateMP1:
        return "ActorRotateMP1";
    case EGOComponentType::MemoryRelayMP1:
        return "MemoryRelayMP1";
    case EGOComponentType::PlatformMP1:
        return "PlatformMP1";
    case EGOComponentType::EffectMP1:
        return "EffectMP1";
    case EGOComponentType::HUDMemoMP1:
        return "HUDMemoMP1";
    case EGOComponentType::DamageableTriggerMP1:
        return "DamageableTriggerMP1";
    case EGOComponentType::WaterMP1:
        return "WaterMP1";
    case EGOComponentType::CameraMP1:
        return "CameraMP1";
    case EGOComponentType::VisorFlareMP1:
        return "VisorFlareMP1";
    case EGOComponentType::DebrisExtendedMP1:
        return "DebrisExtendedMP1";
    case EGOComponentType::DebrisMP1:
        return "DebrisMP1";
    case EGOComponentType::WorldTeleporterTooMP1:
        return "WorldTeleporterTooMP1";
    case EGOComponentType::PlayerActorMP1:
        return "PlayerActorMP1";
    case EGOComponentType::CameraWaypointMP1:
        return "CameraWaypointMP1";
    case EGOComponentType::AreaAttributesMP1:
        return "AreaAttributesMP1";
    case EGOComponentType::PointOfInterestMP1:
        return "PointOfInterestMP1";
    case EGOComponentType::CameraBlurKeyframeMP1:
        return "CameraBlurKeyframeMP1";
    case EGOComponentType::CameraFilterKeyframeMP1:
        return "CameraFilterKeyframeMP1";
    case EGOComponentType::StreamedAudioMP1:
        return "StreamedAudioMP1";
    case EGOComponentType::SoundMP1:
        return "SoundMP1";
    case EGOComponentType::MidiMP1:
        return "MidiMP1";
    case EGOComponentType::VisorGooMP1:
        return "VisorGooMP1";
    case EGOComponentType::CameraShakerOldMP1:
        return "CameraShakerOldMP1";
    case EGOComponentType::CameraShakerNewMP1:
        return "CameraShakerNewMP1";
    case EGOComponentType::RandomRelayMP1:
        return "RandomRelayMP1";
    case EGOComponentType::NotSTD_DockMP1:
        return "NotSTD_DockMP1";
    case EGOComponentType::PickupMP1:
        return "PickupMP1";
    case EGOComponentType::GrapplePointMP1:
        return "GrapplePointMP1";
    case EGOComponentType::ContraptionMP1:
        return "ContraptionMP1";
    case EGOComponentType::DoorMP1:
        return "DoorMP1";
    case EGOComponentType::RoomAcousticsMP1:
        return "RoomAcousticsMP1";
    case EGOComponentType::PlayerHintMP1:
        return "PlayerHintMP1";
    case EGOComponentType::GunTurretMP1:
        return "GunTurretMP1";
    case EGOComponentType::CameraHintTriggerMP1:
        return "CameraHintTriggerMP1";
    case EGOComponentType::GeneratorMP1:
        return "GeneratorMP1";
    case EGOComponentType::WallCrawlerSwarmMP1:
        return "WallCrawlerSwarmMP1";
    case EGOComponentType::DistanceFogMP1:
        return "DistanceFogMP1";
    case EGOComponentType::CameraHintMP1:
        return "CameraHintMP1";
    case EGOComponentType::EnvFxDensityControllerMP1:
        return "EnvFxDensityControllerMP1";
    case EGOComponentType::ElectroMagneticPulseMP1:
        return "ElectroMagneticPulseMP1";
    case EGOComponentType::CameraPitchVolumeMP1:
        return "CameraPitchVolumeMP1";
    case EGOComponentType::PickupGeneratorMP1:
        return "PickupGeneratorMP1";
    case EGOComponentType::MazeNodeMP1:
        return "MazeNodeMP1";
    case EGOComponentType::PathCameraMP1:
        return "PathCameraMP1";
    case EGOComponentType::CoverPointMP1:
        return "CoverPointMP1";
    case EGOComponentType::RadialDamageMP1:
        return "RadialDamageMP1";
    case EGOComponentType::PhazonPoolMP1:
        return "PhazonPoolMP1";
    case EGOComponentType::SpiderBallAttractionSurfaceMP1:
        return "SpiderBallAttractionSurfaceMP1";
    case EGOComponentType::SpiderBallWaypointMP1:
        return "SpiderBallWaypointMP1";
    case EGOComponentType::TargetingPointMP1:
        return "TargetingPointMP1";
    case EGOComponentType::IntroBossMP1:
        return "IntroBossMP1";
    case EGOComponentType::RippleMP1:
        return "RippleMP1";
    case EGOComponentType::TeamAiMgrMP1:
        return "TeamAiMgrMP1";
    case EGOComponentType::ThermalHeatFaderMP1:
        return "ThermalHeatFaderMP1";
    case EGOComponentType::SpindleCameraMP1:
        return "SpindleCameraMP1";
    case EGOComponentType::SpankWeedMP1:
        return "SpankWeedMP1";
    case EGOComponentType::ShadowProjectorMP1:
        return "ShadowProjectorMP1";
    case EGOComponentType::WorldLightFaderMP1:
        return "WorldLightFaderMP1";
    case EGOComponentType::ThardusMP1:
        return "ThardusMP1";
    case EGOComponentType::AThardusRockProjectileMP1:
        return "AThardusRockProjectileMP1";
    case EGOComponentType::AtomicAlphaMP1:
        return "AtomicAlphaMP1";
    case EGOComponentType::AtomicBetaMP1:
        return "AtomicBetaMP1";
    case EGOComponentType::GeemerMP1:
        return "GeemerMP1";
    case EGOComponentType::OculusMP1:
        return "OculusMP1";
    case EGOComponentType::PufferMP1:
        return "PufferMP1";
    case EGOComponentType::BouncyGrenadeMP1:
        return "BouncyGrenadeMP1";
    case EGOComponentType::RidleyMP1:
        return "RidleyMP1";
    case EGOComponentType::BabygothMP1:
        return "BabygothMP1";
    case EGOComponentType::TryclopsMP1:
        return "TryclopsMP1";
    case EGOComponentType::BloodFlowerMP1:
        return "BloodFlowerMP1";
    case EGOComponentType::FlyingPirateMP1:
        return "FlyingPirateMP1";
    case EGOComponentType::BurrowerMP1:
        return "BurrowerMP1";
    case EGOComponentType::ChozoGhostMP1:
        return "ChozoGhostMP1";
    case EGOComponentType::DroneMP1:
        return "DroneMP1";
    case EGOComponentType::SpacePirateMP1:
        return "SpacePirateMP1";
    case EGOComponentType::ElitePirateMP1:
        return "ElitePirateMP1";
    case EGOComponentType::OmegaPirateMP1:
        return "OmegaPirateMP1";
    case EGOComponentType::PuddleSporeMP1:
        return "PuddleSporeMP1";
    case EGOComponentType::EyeBallMP1:
        return "EyeBallMP1";
    case EGOComponentType::FireFleaMP1:
        return "FireFleaMP1";
    case EGOComponentType::FlaahgraMP1:
        return "FlaahgraMP1";
    case EGOComponentType::FlaahgraTentacleMP1:
        return "FlaahgraTentacleMP1";
    case EGOComponentType::FlaahgraProjectileMP1Runtime:
        return "FlaahgraProjectileMP1Runtime";
    case EGOComponentType::FlaahgraPlantsMP1Runtime:
        return "FlaahgraPlantsMP1Runtime";
    case EGOComponentType::FlaahgraRendererMP1Runtime:
        return "FlaahgraRendererMP1Runtime";
    case EGOComponentType::ParasiteMP1:
        return "ParasiteMP1";
    case EGOComponentType::FlickerBatMP1:
        return "FlickerBatMP1";
    case EGOComponentType::GarBeetleMP1:
        return "GarBeetleMP1";
    case EGOComponentType::IceSheegothMP1:
        return "IceSheegothMP1";
    case EGOComponentType::WarWaspMP1:
        return "WarWaspMP1";
    case EGOComponentType::JellyZapMP1:
        return "JellyZapMP1";
    case EGOComponentType::MagdoliteMP1:
        return "MagdoliteMP1";
    case EGOComponentType::MetareeMP1:
        return "MetareeMP1";
    case EGOComponentType::MetroidBetaMP1:
        return "MetroidBetaMP1";
    case EGOComponentType::SeedlingMP1:
        return "SeedlingMP1";
    case EGOComponentType::TargetableProjectileMP1:
        return "TargetableProjectileMP1";
    case EGOComponentType::RipperMP1:
        return "RipperMP1";
    case EGOComponentType::SnakeWeedSwarmMP1:
        return "SnakeWeedSwarmMP1";
    case EGOComponentType::MetroidMP1:
        return "MetroidMP1";
    case EGOComponentType::PuddleToadGammaMP1:
        return "PuddleToadGammaMP1";
    case EGOComponentType::FishCloudModifierMP1:
        return "FishCloudModifierMP1";
    case EGOComponentType::MetroidPrimeRelayMP1:
        return "MetroidPrimeRelayMP1";
    case EGOComponentType::GrapplePointMP1Runtime:
        return "GrapplePointMP1Runtime";
    case EGOComponentType::ControlledPlatformMP1Runtime:
        return "ControlledPlatformMP1Runtime";
    case EGOComponentType::FishCloudMP1:
        return "FishCloudMP1";
    case EGOComponentType::PhazonHealingNoduleMP1:
        return "PhazonHealingNoduleMP1";
    case EGOComponentType::MetroidPrimeMP1:
        return "MetroidPrimeMP1";
    case EGOComponentType::ProxyPlayerMP1:
        return "ProxyPlayerMP1";
    case EGOComponentType::MetroidPrimeStage2MP1:
        return "MetroidPrimeStage2MP1";
    case EGOComponentType::VisorFlareMP1Runtime:
        return "VisorFlareMP1Runtime";
    case EGOComponentType::DroneLaserMP1Runtime:
        return "DroneLaserMP1Runtime";
    case EGOComponentType::DeathCameraEffectMP1Runtime:
        return "DeathCameraEffectMP1Runtime";
    case EGOComponentType::ElitePirateGrenadeLauncherMP1Runtime:
        return "ElitePirateGrenadeLauncherMP1Runtime";
    case EGOComponentType::PoisonProjectileMP1:
        return "PoisonProjectileMP1";
    case EGOComponentType::MissileTargetMP1:
        return "MissileTargetMP1";
    case EGOComponentType::DestroyableRockMP1Runtime:
        return "DestroyableRockMP1Runtime";
    case EGOComponentType::RoomOcclusionOverrideMP1:
        return "RoomOcclusionOverrideMP1";
    case EGOComponentType::ElectricBeamProjectileMP1Runtime:
        return "ElectricBeamProjectileMP1Runtime";
    case EGOComponentType::CameraOverrideMP1:
        return "CameraOverrideMP1";
    case EGOComponentType::AnimatedCameraMP1:
        return "AnimatedCameraMP1";
    case EGOComponentType::ARepulsorMP1:
        return "ARepulsorMP1";
    case EGOComponentType::PlayerStateChangeMP1:
        return "PlayerStateChangeMP1";
    case EGOComponentType::AEnergyBallMP1:
        return "AEnergyBallMP1";
    case EGOComponentType::AScriptBeamMP1:
        return "AScriptBeamMP1";
    case EGOComponentType::SustainedPlayerDamageMP1Runtime:
        return "SustainedPlayerDamageMP1Runtime";
    case EGOComponentType::HUDManagerMP1:
        return "HUDManagerMP1";
    case EGOComponentType::ScriptHUDBillboardEffectMP1:
        return "ScriptHUDBillboardEffectMP1";
    case EGOComponentType::RumbleEventResponderMP1:
        return "RumbleEventResponderMP1";
    case EGOComponentType::CinematicStateProxyMP1:
        return "CinematicStateProxyMP1";
    case EGOComponentType::HUDBillboardFreezeEffectTestMP1:
        return "HUDBillboardFreezeEffectTestMP1";
    case EGOComponentType::ScriptedOcclusionVolumeMP1:
        return "ScriptedOcclusionVolumeMP1";
    case EGOComponentType::MaterialVariableDriverMP1:
        return "MaterialVariableDriverMP1";
    case EGOComponentType::EffectProxyMP1:
        return "EffectProxyMP1";
    case EGOComponentType::CinematicMP1:
        return "CinematicMP1";
    case EGOComponentType::PhazonDriverMP1:
        return "PhazonDriverMP1";
    case EGOComponentType::AmbientParticleEffectPrimitiveShapeProviderMP1:
        return "AmbientParticleEffectPrimitiveShapeProviderMP1";
    case EGOComponentType::XRayHintMP1:
        return "XRayHintMP1";
    case EGOComponentType::CameraWaterStateProxyMP1:
        return "CameraWaterStateProxyMP1";
    case EGOComponentType::WaterTransitionMP1:
        return "WaterTransitionMP1";
    case EGOComponentType::AreaOcclusionModifierMP1:
        return "AreaOcclusionModifierMP1";
    case EGOComponentType::BakedLightingPriorityModifierMP1:
        return "BakedLightingPriorityModifierMP1";
    case EGOComponentType::AutoExposureHintMP1:
        return "AutoExposureHintMP1";
    case EGOComponentType::ActorIceDarkenerMP1:
        return "ActorIceDarkenerMP1";
    case EGOComponentType::FrontEndManagerMPT:
        return "FrontEndManagerMPT";
    case EGOComponentType::SaveSlotMPT:
        return "SaveSlotMPT";
    default:
        return "Unknown";
    }
}
