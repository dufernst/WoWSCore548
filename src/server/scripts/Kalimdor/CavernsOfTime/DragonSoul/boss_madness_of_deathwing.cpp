#include "ScriptPCH.h"
#include "Group.h"
#include "dragon_soul.h"

// send SendPlaySpellVisualKit from limbs
// 22445 + 0 before casting visual spell
// 22446 + 0 after visual spell

enum DeathwingScriptedTexts
{
    SAY_DEATHWING_AGGRO     = 0,
    SAY_DEATHWING_BOLT      = 2,
    SAY_DEATHWING_PHASE     = 1,
    SAY_IMPALE_ASPECT       = 3,
    SAY_ATTACK_ALEXSTRASZA  = 4,
    SAY_ATTACK_NOZDORMU     = 5,
    SAY_ATTACK_YSERA        = 6,
    SAY_ATTACK_KALECGOS     = 7,
};

enum AlexstraszaScriptedTexts
{
    SAY_ALEXTRASZA_END          = 0,
    SAY_ALEXSTRASZA_PLATFORM    = 1,
    SAY_ALEXSTRASZA_PHASE_2     = 2,
    SAY_ALEXSTRASZA_CATACLYSM   = 3,
};

enum NozdormuScriptedTexts
{
    SAY_NOZDORMU_PLATFORM       = 1,
    SAY_NOZDORMU_PHASE_2        = 2,
    SAY_NOZDORMU_CATACLYSM      = 3,
};

enum YseraScriptedTexts
{
    SAY_YSERA_PLATFORM          = 1,
    SAY_YSERA_PHASE_2           = 2,
    SAY_YSERA_CATACLYSM         = 3,
};

enum KalecgosScriptedTexts
{
    SAY_KALECGOS_PLATFORM       = 1,
    SAY_KALECGOS_PHASE_2        = 2,
    SAY_KALECGOS_CATACLYSM      = 3,
};

enum ThrallScriptedTexts
{
    SAY_THRALL_PHASE_2          = 0,
};

enum Spells
{
    
    // Thrall
    SPELL_ASTRAL_RECALL_1               = 108537, 
    SPELL_ASTRAL_RECALL_2               = 101063, 
    SPELL_TRIGGER_ASPECT_YELL_1         = 109708,
    SPELL_TRIGGER_ASPECT_YELL_2         = 109727,
    SPELL_FIRE_DRAGON_SOUL_ASPECTS      = 110067,
    SPELL_FIRE_DRAGON_SOUL              = 109971,
    SPELL_FIRE_DRAGON_SOUL_SCRIPT       = 110065,

    SPELL_IDLE                          = 106187, // tail tentacle has it

    SPELL_TRIGGER_ASPECT_BUFFS          = 106943, // casted by deathwing 56173
    SPELL_SHARE_HEALTH_1                = 109547, // casted by deathwing 56173 on self ?
    SPELL_SHARE_HEALTH_2                = 109548, // casted by deathwing 56173 on 57962
    SPELL_ASSAULT_ASPECTS               = 107018, // casted by deathwing 56173
    SPELL_ELEMENTIUM_BOLT               = 105651,
    SPELL_ELEMENTIUM_METEOR_SCRIPT      = 105599,
    SPELL_ELEMENTIUM_METEOR_SUMMON      = 105658,
    SPELL_ELEMENTIUM_BLAST              = 105723,
    SPELL_ELEMENTIUM_METEOR_TARGET      = 106242, // target mark
    SPELL_ELEMENTIUM_METEOR_TRANSFORM_1 = 106991, // summon from sniffs ?
    SPELL_ELEMENTIUM_METEOR_TRANSFORM_2 = 110663, 
    SPELL_ELEMENTIUM_METEOR_AURA        = 110628,
    SPELL_ELEMENTIUM_METEOR_AURA_DMG    = 110632,
    SPELL_CATACLYSM                     = 106523,
    SPELL_CATACLYSM_25                  = 110044,
    SPELL_CATACLYSM_10H                 = 110043,
    SPELL_CATACLYSM_25H                 = 110042,
    SPELL_SLUMP_1                       = 106708, // phase 2
    SPELL_SLUMP_2                       = 110062, // on death ?
    SPELL_CORRUPTED_BLOOD               = 106834,
    SPELL_CORRUPTED_BLOOD_25            = 109592,
    SPELL_CORRUPTED_BLOOD_10H           = 109593,
    SPELL_CORRUPTED_BLOOD_25H           = 109594,
    SPELL_CORRUPTED_BLOOD_STACKER       = 106843,
    SPELL_CORRUPTING_PARASITE_AOE       = 108597,
    SPELL_CORRUPTING_PARASITE_DMG       = 108601,
    SPELL_CORRUPTING_PARASITE_AURA      = 108649,
    SPELL_PARASITIC_BACKSLASH           = 108787,
    SPELL_UNSTABLE_CORRUPTION           = 108813,
    SPELL_DEATH                         = 110101,
    SPELL_BERSERK                       = 64238,

    SPELL_ACHIEVEMENT                   = 111533,

    // Limb Tentacle
    SPELL_LIMB_EMERGE_VISUAL            = 107991,
    SPELL_SUMMON_BLISTERING_TENTACLE    = 105549,
    SPELL_BURNING_BLOOD                 = 105401,
    SPELL_BURNING_BLOOD_25              = 109616,
    SPELL_BURNING_BLOOD_10H             = 109617,
    SPELL_BURNING_BLOOD_25H             = 109618,
    SPELL_TRIGGER_CONCENTRATION         = 106940,
    SPELL_AGONIZING_PAIN                = 106548,

    // Mutated Corruption
    SPELL_SUMMON_TAIL_FORCE             = 106239,
    SPELL_SUMMON_TAIL                   = 106240,
    SPELL_CRUSH_FORCE                   = 106382,
    SPELL_CRUSH_SUMMON                  = 106384,
    SPELL_CRUSH                         = 106385,
    SPELL_IMPALE                        = 106400,
    SPELL_IMPALE_DMG                    = 106444,
    SPELL_IMPALE_ASPECT_AOE             = 107026,
    SPELL_IMPALE_ASPECT                 = 107029,

    // Blistering Tentacle
    SPELL_BLISTERING_TENTACLE_VEHICLE   = 105550,
    SPELL_BLISTERING_HEAT               = 105444,
    SPELL_BLISTERING_HEAT_DMG           = 105445,

    // Hemorrhage
    SPELL_HEMORRHAGE_SUMMON_AOE         = 105853,
    SPELL_HEMORRHAGE_AURA               = 105861,
    SPELL_HEMORRHAGE_SCRIPT             = 105862,
    SPELL_HEMORRHAGE_MISSILE            = 105863,
    SPELL_HEMORRHAGE_SUMMON             = 105875,
    SPELL_REGENERATIVE_BLOOD_PERIODIC   = 105932,
    SPELL_REGENERATIVE_BLOOD_SCRIPT     = 105934,
    SPELL_REGENERATIVE_BLOOD_HEAL       = 105937,
    SPELL_REGENERATIVE_BLOOD_AURA       = 105969, // scale aura

    // Congealing Blood
    SPELL_CONGEALING_BLOOD_AOE          = 109082,
    SPELL_CONGEALING_BLOOD_SCRIPT       = 109087,
    SPELL_CONGEALING_BLOOD_MISSILE      = 109089,
    SPELL_CONGEALING_BLOOD_SUMMON       = 109091,
    SPELL_CONGEALING_BLOOD_HEAL         = 109102,

    // Elementium Terror
    SPELL_ELEMENTIUM_TERROR_SCRIPT      = 106765,
    SPELL_ELEMENTIUM_TERROR_MISSILE     = 106766,
    SPELL_ELEMENTIUM_TERROR_SUMMON      = 106767, // original name is hemorrhage

    // Impaling Tentacle
    SPELL_IMPALING_TENTACLE_SCRIPT      = 106775,
    SPELL_IMPALING_TENTACLE_MISSILE     = 106776,
    SPELL_IMPALING_TENTACLE_SUMMON      = 106777,
    SPELL_SHRAPNEL_AURA                 = 106818,
    SPELL_SHRAPNEL_AOE                  = 106789,
    SPELL_SHRAPNEL_TARGET               = 106794,
    SPELL_SHRAPNEL_DMG                  = 106791,

    // Aspects
    SPELL_ALEXSTRASZA_PRESENCE          = 105825,
    SPELL_ALEXSTRASZA_PRESENCE_AURA     = 106028,
    SPELL_ALEXSTRASZA_PRESENCE_AURA_25  = 109571,
    SPELL_ALEXSTRASZA_PRESENCE_AURA_10H = 109572,
    SPELL_ALEXSTRASZA_PRESENCE_AURA_25H = 109573,
    SPELL_CAUTERIZE_1                   = 105565, // blistering tentacle
    SPELL_CAUTERIZE_1_DMG               = 105569,
    SPELL_CAUTERIZE_2_1                 = 106860, // deathwing phase 2 5 sec
    SPELL_CAUTERIZE_2_2                 = 106888, // deathwing phase 2 10 sec
    SPELL_CAUTERIZE_2_3                 = 106889, // deathwing phase 2 15 sec
    SPELL_CAUTERIZE_2_DMG               = 106886,
    SPELL_CAUTERIZE_3                   = 108840, // parasite
    SPELL_CAUTERIZE_3_DMG               = 109045,

    SPELL_NOZDORMU_PRESENCE             = 105823,
    SPELL_NOZDORMU_PRESENCE_AURA        = 106027,
    SPELL_NOZDORMU_PRESENCE_AURA_25     = 109622,
    SPELL_NOZDORMU_PRESENCE_AURA_10H    = 109623,
    SPELL_NOZDORMU_PRESENCE_AURA_25H    = 109624,
    SPELL_TIME_ZONE_FORCE               = 106919, // first spell, there are npcs 'platform'
    SPELL_TIME_ZONE_SUMMON_TARGET       = 105793, // summon target
    SPELL_TIME_ZONE_MISSILE_1           = 105799,
    SPELL_TIME_ZONE_SUMMON_1            = 105802, // summon time zone
    SPELL_TIME_ZONE                     = 105831, // main aura on trigger
    SPELL_TIME_ZONE_AURA_1              = 105830, // aura (debuff)
    SPELL_TIME_ZONE_MISSILE_2           = 107055, // ? maybe heroic
    SPELL_TIME_ZONE_SUMMON_2            = 107057, // ? maybe heroic
    SPELL_TIME_ZONE_AURA_2              = 108646, // for parasite

    SPELL_YSERA_PRESENCE                = 106456,
    SPELL_YSERA_PRESENCE_AURA           = 106457,
    SPELL_YSERA_PRESENCE_AURA_25        = 109640,
    SPELL_YSERA_PRESENCE_AURA_10H       = 109641,
    SPELL_YSERA_PRESENCE_AURA_25H       = 109642,
    SPELL_THE_DREAMER                   = 106463,
    SPELL_ENTER_THE_DREAM               = 106464,

    SPELL_KALECGOS_PRESENCE             = 106026,
    SPELL_KALECGOS_PRESENCE_AURA        = 106029,
    SPELL_KALECGOS_PRESENCE_AURA_25     = 109606,
    SPELL_KALECGOS_PRESENCE_AURA_10H    = 109607,
    SPELL_KALECGOS_PRESENCE_AURA_25H    = 109608,
    SPELL_SPELLWEAVER                   = 106039,
    SPELL_SPELLWEAVING                  = 106040,

    SPELL_EXPOSE_WEAKNESS_1             = 106588,
    SPELL_EXPOSE_WEAKNESS_2             = 106600,
    SPELL_EXPOSE_WEAKNESS_3             = 106613,
    SPELL_EXPOSE_WEAKNESS_4             = 106624,

    SPELL_CONCENTRATION_1               = 106641,
    SPELL_CONCENTRATION_2               = 106642,
    SPELL_CONCENTRATION_3               = 106643,
    SPELL_CONCENTRATION_4               = 106644,
    SPELL_CONCENTRATION_5               = 110071,
    SPELL_CONCENTRATION_6               = 110072,
    SPELL_CONCENTRATION_7               = 110076,
    SPELL_CONCENTRATION_8               = 110077,

    // Jump Pad
    SPELL_CARRYING_WINDS_1              = 106663, // casted by player, from 1 to 2
    SPELL_CARRYING_WINDS_SCRIPT_1       = 106666, // casted by pad on player
    SPELL_CARRYING_WINDS_2              = 106668, // from 2 to 1
    SPELL_CARRYING_WINDS_SCRIPT_2       = 106669,
    SPELL_CARRYING_WINDS_3              = 106670, // from 2 to 3
    SPELL_CARRYING_WINDS_SCRIPT_3       = 106671,
    SPELL_CARRYING_WINDS_4              = 106672, // from 3 to 2
    SPELL_CARRYING_WINDS_SCRIPT_4       = 106673,
    SPELL_CARRYING_WINDS_5              = 106674, // from 3 to 4
    SPELL_CARRYING_WINDS_SCRIPT_5       = 106675,
    SPELL_CARRYING_WINDS_6              = 106676, // from 4 to 3
    SPELL_CARRYING_WINDS_SCRIPT_6       = 106677,
    SPELL_CARRYING_WINDS_DUMMY          = 106678, // visual ?
    SPELL_CARRYING_WINDS_SPEED_10       = 106664,
    SPELL_CARRYING_WINDS_SPEED_25       = 109963,
    SPELL_CARRYING_WINDS_SPEED_10H      = 109962,
    SPELL_CARRYING_WINDS_SPEED_25H      = 109961,
};

enum Adds
{
    NPC_WING_TENTACLE       = 56168, // 1 & 4
    NPC_ARM_TENTACLE_1      = 56846, // 2
    NPC_ARM_TENTACLE_2      = 56167, // 3

    NPC_MUTATED_CORRUPTION  = 56471,
    NPC_CRUSH_TARGET        = 56581,
    NPC_BLISTERING_TENTACLE = 56188,
    NPC_REGENERAIVE_BLOOD   = 56263,
    NPC_HEMORRHAGE_TARGET   = 56359,
    NPC_ELEMENTIUM_BOLT     = 56262,
    NPC_CLAWK_MARK          = 56545,
    NPC_CORRUPTING_PARASITE = 57479,
    NPC_TIME_ZONE_TARGET    = 56332,
    NPC_TIME_ZONE           = 56311,
    NPC_IMPALING_TENTACLE   = 56724,
    NPC_ELEMENTIUM_TERROR   = 56710,
    NPC_CONGEALING_BLOOD    = 57798,

    NPC_DEATHWING_1         = 57962, // invisible ?

    NPC_COSMETIC_TENTACLE   = 57693,
    NPC_TAIL_TENTACLE       = 56844,

    NPC_JUMP_PAD            = 56699,
    NPC_PLATFORM            = 56307,
};

enum Events
{
    EVENT_SPAWN_LIMBS_1         = 1,
    EVENT_SPAWN_LIMBS_2         = 2,
    EVENT_SPAWN_LIMBS_3         = 3,
    EVENT_CHECK_PLAYERS         = 4,
    EVENT_ASSAULT_ASPECTS       = 5,
    EVENT_CRUSH                 = 6,
    EVENT_IMPALE                = 7,
    EVENT_CRUSH_1               = 8,
    EVENT_ASSAULT_ASPECTS_1     = 9,
    EVENT_HEMORRHAGE            = 10,
    EVENT_UPDATE_HEALTH         = 11,
    EVENT_START_MOVE            = 12,
    EVENT_ELEMENTIUM_BOLT       = 13,
    EVENT_CATACLYSM             = 14,
    EVENT_CORRUPTING_PARASITE   = 15,
    EVENT_UNSTABLE_CORRUPTION   = 16,
    EVENT_TIME_ZONE             = 17,
    EVENT_CAUTERIZE             = 18,
    EVENT_SELECT_VICTIM         = 19,
    EVENT_BLISTERING_TENTACLE   = 20,
    EVENT_SLUMP                 = 21,
    EVENT_ASPECT_TALK_2         = 22, // talk at the beginning of second phase
    EVENT_THRALL_TALK_2         = 23, // talk at the beginning of second phase (after aspect)
    EVENT_ELEMENTIUM_FRAGMENT   = 24,
    EVENT_ELEMENTIUM_TERROR     = 25,
    EVENT_CONGEALING_BLOOD      = 26,
    EVENT_SHRAPNEL              = 27,
    EVENT_CAUTERIZE_PARASITE    = 28,
    EVENT_CONGEALING_BLOOD_HEAL = 29,
    EVENT_DRAGON_SOUL           = 30,
    EVENT_END_BATTLE            = 31,
    EVENT_TIME_ZONE_2           = 32,
    EVENT_BERSERK               = 33,
};

enum Actions
{
    ACTION_CHECK_PLAYERS            = 1,
    ACTION_CRUSH                    = 2,
    ACTION_RESET_BATTLE             = 3,
    ACTION_ASSAULT_ASPECTS          = 4,
    ACTION_ASSAULT_ASPECTS_FIRST    = 5,
    ACTION_PARASITIC_BACKSLASH      = 6,
    ACTION_TIME_ZONE                = 7,
    ACTION_CAUTERIZE                = 8,
    ACTION_CAUTERIZE_PARASITE       = 9,
    ACTION_END_BATTLE               = 10,
    ACTION_TIME_ZONE_2              = 11,
};

enum Other
{
    DATA_ASSAULT_PLATFORM   = 1,
    DATA_DESTROY_PLATFORM   = 2,
    DATA_CURRENT_PLATFORM   = 3,
    DATA_METEOR_POINT       = 4,
    DATA_SHRAPNEL           = 5,
    DATA_BLOOD_POINT        = 6,
};

uint8 GetGround(const WorldObject* who)
{
    if (who->GetPositionX() > -11979.311523f && who->GetPositionX() < -11938.857422f &&
        who->GetPositionY() > 12236.340820f && who->GetPositionY() < 12299.116211f)
        return 1;
    else if (who->GetPositionX() > -12074.251953f && who->GetPositionX() < -12002.294922f &&
        who->GetPositionY() > 12184.281250f && who->GetPositionY() < 12256.737305f)
        return 2;
    else if (who->GetPositionX() > -12135.291992f && who->GetPositionX() < -12054.627930f &&
        who->GetPositionY() > 12129.464844f && who->GetPositionY() < 12190.023438f)
        return 3;
    else if (who->GetPositionX() > -12164.257813f && who->GetPositionX() < -12075.483398f &&
        who->GetPositionY() > 12051.344727f && who->GetPositionY() < 12107.757813f)
        return 4;

    return 0;
}

const Position mutatedcorruptionPos[4] = 
{
    {-11993.3f, 12286.3f, -2.58115f, 5.91667f}, // 1
    {-12028.8f, 12265.6f, -6.27147f, 4.13643f}, // 2
    {-12107.4f, 12201.9f, -5.32397f, 5.16617f}, // 3
    {-12160.9f, 12057.0f, 2.47362f, 0.733038f}  // 4
};

const Position limbsPos[4] = 
{
    {-11941.2f, 12248.9f, 12.1499f, 1.98968f},
    {-12005.8f, 12190.3f, -6.59399f, 2.1293f},
    {-12065.0f, 12127.2f, -3.2946f, 2.338740f},
    {-12097.8f, 12067.4f, 13.4888f, 2.21657f}
};

const Position hemorrhagePos[4] = 
{
    {-11955.948242f, 12281.756836f, 1.30f, 0.0f},
    {-12048.077148f, 12237.601563f, -6.14f, 0.0f},
    {-12113.989258f, 12166.718750f, -2.72f, 0.0f},
    {-12146.370117f, 12093.588867f, 2.31f, 0.0f}
};

const Position boltPos[5] = 
{
    {-11929.83f, 12035.63f, 35.45797f, 0.0f},
    {-11961.268555f, 12286.041992f, 1.30f, 0.0f},   // 1
    {-12055.000977f, 12239.061523f, -6.14f, 0.0f},  // 2
    {-12112.834961f, 12170.205078f, -2.72f, 0.0f},  // 3
    {-12149.885742f, 12081.416992f, 2.31f, 0.0f}    // 4
};

const Position timezonePos[5] = 
{
    {-11962.668945f, 12262.736328f, 1.30f, 0.0f},
    {-12045.594727f, 12216.872070f, -6.02f, 0.0f},
    {-12098.596680f, 12156.881836f, -2.72f, 0.0f},
    {-12113.083008f, 12081.437500f, 2.31f, 0.0f},
    {-12102.192383f, 12156.113281f, -2.72f, 0.0f}
};

//const Position blisteringPos[4] =
//{
//    {-11942.116211f, 12249.538086f, 1.37f, 0.0f},
//    {-12025.414063f, 12213.312500f, -6.14f, 0.0f},
//    {-12084.824219f, 12146.507813f, -2.72f, 0.0f},
//    {-12102.188477f, 12067.497070f, 2.31f, 0.0f},
//};

const Position impalingPos[8] = 
{
    {-12117.319336f, 12185.737305f, -2.72f, 0.0f},
    {-12115.992188f, 12177.088867f, -2.72f, 0.0f},
    {-12122.911133f, 12176.027344f, -2.72f, 0.0f},
    {-12120.683594f, 12170.037109f, -2.72f, 0.0f},
    {-12115.131836f, 12168.325195f, -2.72f, 0.0f},
    {-12120.296875f, 12165.841797f, -2.72f, 0.0f},
    {-12113.935547f, 12165.100586f, -2.72f, 0.0f},
    {-12112.777344f, 12172.588867f, -2.72f, 0.0f}
};

const Position terrorPos[2] = 
{
    {-12121.259766f, 12162.742188f, -2.74f, 0.0f},
    {-12117.771484f, 12168.811523f, -2.72f, 0.0f}
};

const Position congealingPos[2] = 
{
    {-12119.488281f, 12162.667969f, -2.72f, 0.0f},
    {-12079.577148f, 12169.696289f, -2.72f, 0.0f} // healing pos
};

const Position thrallPos[2] = 
{
    {-12128.3f, 12253.8f, 0.0451f, 0.0f}, // Thrall teleports here
    {-12061.8f, 12188.f, 10.2966f, 5.57f}
};
const Position deathwingPos = {-11903.9f, 11989.1f, -113.204f, 2.16421f};
const Position deathwing2Pos = {-12063.5f, 12198.9f, -13.04f, 2.16421f};

const Position alexstraszaPos = {-11957.3f, 12338.3f, 38.9364f, 5.06145f};
const Position nozdormuPos = {-12093.8f, 12312.0f, 43.228f, 5.42797f};
const Position yseraPos = {-12157.4f, 12212.5f, 36.0152f, 5.75959f};
const Position kalecgosPos = {-12224.8f, 12128.5f, 68.96f, 5.84685f};


const Position alexstraszaendPos = {-12077.3f, 12152.3f, -2.64092f, 6.00393f};
const Position nozdormuendPos = {-12078.4f, 12147.5f, -2.64092f, 0.174533f};
const Position yseraendPos = {-12073.8f, 12156.6f, -2.64091f, 5.55015f};
const Position kalecgosendPos = {-12069.2f, 12159.9f, -2.64091f, 5.23599f};
const Position aggraendPos = {-12066.1f, 12150.4f, -2.64091f, 3.05433f};
const Position thrallendPos = {-12067.7f, 12146.4f, -2.64091f, 3.05433f};

const Position jumpPos[6] = 
{
    {-11972.8f, 12272.8f, 1.38396f, 0.0f},  // from 1 to 2
    {-12023.f, 12228.5f, -6.0689f, 0.0f},   // from 2 to 1
    {-12047.9f, 12213.9f, -5.94278f, 0.0f}, // from 2 to 3
    {-12087.5f, 12165.7f, -2.65091f, 0.0f}, // from 3 to 2
    {-12099.6f, 12152.8f, -2.65092f, 0.0f}, // from 3 to 4
    {-12118.2f, 12084.9f, 2.39029f, 0.0f}   // from 4 to 3
};

#define GOSSIP_OPTION_1 "Is this end?"

class boss_madness_of_deathwing : public CreatureScript
{
    public:
        boss_madness_of_deathwing() : CreatureScript("boss_madness_of_deathwing") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_madness_of_deathwingAI(pCreature);
        }

        struct boss_madness_of_deathwingAI : public BossAI
        {
            boss_madness_of_deathwingAI(Creature* pCreature) : BossAI(pCreature, DATA_MADNESS)
            {       
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                memset(limbsGuids, 0, sizeof(limbsGuids));
                m_current_platform = 0;
                m_destroyed_platform = 0;
                m_isFirst = true;
                m_isBerserk = false;
            }

            void AttackStart(Unit* target)
            {
                if (!target)
                    return;

                if (me->Attack(target, true))
                    DoStartNoMovement(target);
            }

            void IsSummonedBy(Unit* /*owner*/)
            {
                instance->SetBossState(DATA_MADNESS, IN_PROGRESS);
                events.ScheduleEvent(EVENT_SPAWN_LIMBS_1, 1);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_ASSAULT_PLATFORM)
                {
                    m_current_platform = (uint8)data;

                    events.ScheduleEvent(EVENT_ASSAULT_ASPECTS_1, 500);
                }
                else if (type == DATA_DESTROY_PLATFORM)
                    m_destroyed_platform |= (1 << data);
            }

            uint32 getdata(uint32 type)
            {
                if (type == DATA_DESTROY_PLATFORM)
                    return m_destroyed_platform;
                else if (type == DATA_CURRENT_PLATFORM)
                    return m_current_platform;

                return 0;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo)
            {
                if (spellInfo->Id == SPELL_AGONIZING_PAIN)
                {
                    events.CancelEvent(EVENT_CATACLYSM);
                    events.CancelEvent(EVENT_ELEMENTIUM_BOLT);
                    events.CancelEvent(EVENT_ASSAULT_ASPECTS);
                    events.CancelEvent(EVENT_ASSAULT_ASPECTS_1);

                    if (Spell* spell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                        if (spell->GetSpellInfo()->Id == SPELL_CATACLYSM ||
                            spell->GetSpellInfo()->Id == SPELL_CATACLYSM_25 ||
                            spell->GetSpellInfo()->Id == SPELL_CATACLYSM_10H ||
                            spell->GetSpellInfo()->Id == SPELL_CATACLYSM_25H)
                            me->InterruptSpell(CURRENT_GENERIC_SPELL);

                    if ((m_destroyed_platform & (1 << 1)) > 0 && 
                        (m_destroyed_platform & (1 << 2)) > 0 &&
                        (m_destroyed_platform & (1 << 3)) > 0 &&
                        (m_destroyed_platform & (1 << 4)) > 0)
                    {
                        events.ScheduleEvent(EVENT_SLUMP, 7000);
                        Talk(SAY_DEATHWING_PHASE);
                        DoCastAOE(SPELL_TRIGGER_ASPECT_BUFFS, true);
                    }
                    else
                        events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 7000);
                }
                else if (spellInfo->Id == SPELL_FIRE_DRAGON_SOUL_SCRIPT)
                {
                    me->RemoveAura(SPELL_SLUMP_2);
                    DoCast(me, SPELL_DEATH);
                    
                    //instance->DoStartMovie(75);

                    instance->DoModifyPlayerCurrencies(396, (IsHeroic() ? 140 : 120));
                    instance->DoModifyPlayerCurrencies(614, 1);
                    instance->DoModifyPlayerCurrencies(615, 1);

                    DespawnCreatures(NPC_ALEXSTRASZA_DRAGON);
                    DespawnCreatures(NPC_KALECGOS_DRAGON);
                    DespawnCreatures(NPC_YSERA_DRAGON);
                    DespawnCreatures(NPC_NOZDORMU_DRAGON);
                    DespawnCreatures(NPC_THRALL_2);

                    me->SummonCreature(NPC_ALEXSTRASZA_2, alexstraszaendPos);
                    me->SummonCreature(NPC_NOZDORMU_2, nozdormuendPos);
                    me->SummonCreature(NPC_YSERA_2, yseraendPos);
                    me->SummonCreature(NPC_KALECGOS_2, kalecgosendPos);
                    me->SummonCreature(NPC_AGGRA, thrallendPos);
                    me->SummonCreature(NPC_THRALL_3, aggraendPos);

                    switch (GetDifficulty())
                    {
                        case RAID_DIFFICULTY_10MAN_NORMAL:
                            instance->DoRespawnGameObject(instance->GetData64(DATA_ELEMENTIUM_FRAGMENT_10N), DAY);
                            break;
                        case RAID_DIFFICULTY_25MAN_NORMAL:
                            instance->DoRespawnGameObject(instance->GetData64(DATA_ELEMENTIUM_FRAGMENT_25N), DAY);
                            break;
                        case RAID_DIFFICULTY_10MAN_HEROIC:
                            instance->DoRespawnGameObject(instance->GetData64(DATA_ELEMENTIUM_FRAGMENT_10H), DAY);
                            break;
                        case RAID_DIFFICULTY_25MAN_HEROIC:
                            instance->DoRespawnGameObject(instance->GetData64(DATA_ELEMENTIUM_FRAGMENT_25H), DAY);
                            break;

						default: break;
                    }

                    me->DespawnOrUnsummon(5000);
                }
            }

            void UpdateAI( uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            if (Creature* pDeathwing = me->FindNearestCreature(NPC_DEATHWING_1, 600.0f, true))
                                pDeathwing->CastSpell(pDeathwing, SPELL_BERSERK, true);
                            m_isBerserk = true;
                            break;
                        case EVENT_SPAWN_LIMBS_1:
                            if (Creature* pLimb = me->SummonCreature(NPC_WING_TENTACLE, limbsPos[0]))
                            {
                                pLimb->SendPlaySpellVisualKit(22445, 0, 0); //might need to change this? Duration is the first zero and may need an actual number.
                                limbsGuids[0] = pLimb->GetGUID();
                                pLimb->AI()->SetData(DATA_CURRENT_PLATFORM, 1);
                            }
                            if (Creature* pLimb = me->SummonCreature(NPC_ARM_TENTACLE_1, limbsPos[1]))
                            {
                                pLimb->SendPlaySpellVisualKit(22445, 0, 0); //might need to change this? Duration is the first zero and may need an actual number.
                                limbsGuids[1] = pLimb->GetGUID();
                                pLimb->AI()->SetData(DATA_CURRENT_PLATFORM, 2);
                            }
                            if (Creature* pLimb = me->SummonCreature(NPC_ARM_TENTACLE_2, limbsPos[2]))
                            {
                                pLimb->SendPlaySpellVisualKit(22445, 0, 0); //might need to change this? Duration is the first zero and may need an actual number.
                                limbsGuids[2] = pLimb->GetGUID();
                                pLimb->AI()->SetData(DATA_CURRENT_PLATFORM, 3);
                            }
                            if (Creature* pLimb = me->SummonCreature(NPC_WING_TENTACLE, limbsPos[3]))
                            {
                                pLimb->SendPlaySpellVisualKit(22445, 0, 0); //might need to change this? Duration is the first zero and may need an actual number.
                                limbsGuids[3] = pLimb->GetGUID();
                                pLimb->AI()->SetData(DATA_CURRENT_PLATFORM, 4);
                            }
                            events.ScheduleEvent(EVENT_SPAWN_LIMBS_2, 100);
                            break;
                        case EVENT_SPAWN_LIMBS_2:
                            for (uint8 i = 0; i < 4; ++i)
                                if (Creature* pLimb = sObjectAccessor->GetCreature(*me, limbsGuids[i]))
                                    pLimb->CastSpell(pLimb, SPELL_LIMB_EMERGE_VISUAL, true);

                            events.ScheduleEvent(EVENT_SPAWN_LIMBS_3, 500);
                            break;
                        case EVENT_SPAWN_LIMBS_3:
                            for (uint8 i = 0; i < 4; ++i)
                                if (Creature* pLimb = sObjectAccessor->GetCreature(*me, limbsGuids[i]))
                                    pLimb->SendPlaySpellVisualKit(22446, 0 , 0); //might need to change this? Duration is the first zero and may need an actual number.
                            
                            events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 2000);
                            break;
                        case EVENT_ASSAULT_ASPECTS:
                            DoCastAOE(SPELL_ASSAULT_ASPECTS);
                            break;
                        case EVENT_ASSAULT_ASPECTS_1:
                        {
                            if (Creature* pTentacle = me->SummonCreature(NPC_MUTATED_CORRUPTION, mutatedcorruptionPos[m_current_platform - 1]))
                                DoZoneInCombat(pTentacle, 200.0f);

                            switch (m_current_platform)
                            {
                                case 1:
                                    if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_ALEXSTRASZA_DRAGON)))
                                        pAspect->AI()->Talk(SAY_ALEXSTRASZA_PLATFORM);

                                    Talk(SAY_ATTACK_ALEXSTRASZA);
                                    break;
                                case 2:
                                    if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_NOZDORMU_DRAGON)))
                                        pAspect->AI()->Talk(SAY_NOZDORMU_PLATFORM);

                                    Talk(SAY_ATTACK_NOZDORMU);
                                    break;
                                case 3:
                                    if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_YSERA_DRAGON)))
                                        pAspect->AI()->Talk(SAY_YSERA_PLATFORM);

                                     Talk(SAY_ATTACK_YSERA);
                                    break;
                                case 4:
                                    if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_KALECGOS_DRAGON)))
                                        pAspect->AI()->Talk(SAY_KALECGOS_PLATFORM);

                                    Talk(SAY_ATTACK_KALECGOS);
                                    break;
                            }

                            if (Creature* pLimb = this->GetLimbTentacleAtPlatform(m_current_platform))
                                pLimb->AI()->DoAction(m_isFirst ? ACTION_ASSAULT_ASPECTS_FIRST : ACTION_ASSAULT_ASPECTS);

                            if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_NOZDORMU_DRAGON)))
                                pAspect->AI()->DoAction(ACTION_TIME_ZONE);

                            events.ScheduleEvent(EVENT_ELEMENTIUM_BOLT, m_isFirst ? (40500 - 10000) : (55500 - 10000));
                            events.ScheduleEvent(EVENT_CATACLYSM, m_isFirst ? (115500 - 10000) : (130500 - 10000));

                            m_isFirst = false;
                            break;
                        }
                        case EVENT_ELEMENTIUM_BOLT:
                            DoCast(me, SPELL_ELEMENTIUM_BOLT);
                            Talk(SAY_DEATHWING_BOLT);
                            break;
                        case EVENT_CATACLYSM:
                        {
                            DoCast(me, SPELL_CATACLYSM);

                            Creature* pLimb = GetLimbTentacleAtPlatform(m_current_platform);

                            switch (m_current_platform)
                            {
                                case 1:
                                    if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_ALEXSTRASZA_DRAGON)))
                                    {
                                        pAspect->AI()->Talk(SAY_ALEXSTRASZA_CATACLYSM);
                                        if (pLimb)
                                            pAspect->CastSpell(pLimb, SPELL_EXPOSE_WEAKNESS_1);
                                    }
                                    break;
                                case 2:
                                    if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_NOZDORMU_DRAGON)))
                                    {
                                        pAspect->AI()->Talk(SAY_NOZDORMU_CATACLYSM);
                                        if (pLimb)
                                            pAspect->CastSpell(pLimb, SPELL_EXPOSE_WEAKNESS_2);
                                    }
                                    break;
                                case 3:
                                    if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_YSERA_DRAGON)))
                                    {
                                        pAspect->AI()->Talk(SAY_YSERA_CATACLYSM);
                                        if (pLimb)
                                            pAspect->CastSpell(pLimb, SPELL_EXPOSE_WEAKNESS_3);
                                    }
                                    break;
                                case 4:
                                    if (Creature* pAspect = sObjectAccessor->GetCreature(*me, instance->GetData64(DATA_KALECGOS_DRAGON)))
                                    {
                                        pAspect->AI()->Talk(SAY_KALECGOS_CATACLYSM);
                                        if (pLimb)
                                            pAspect->CastSpell(pLimb, SPELL_EXPOSE_WEAKNESS_4);
                                    }
                                    break;
                            }
                            break;
                        }
                        case EVENT_SLUMP:
                            
                            DoCast(SPELL_SLUMP_1);
                            if (Creature* pDeathwing = me->SummonCreature(NPC_DEATHWING_1, deathwing2Pos))
                            {
                                DoZoneInCombat(pDeathwing, 200.0f);
                                pDeathwing->SetMaxHealth(me->GetMaxHealth());
                                pDeathwing->SetHealth(me->GetHealth());
                                pDeathwing->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                                pDeathwing->CastSpell(pDeathwing, SPELL_CORRUPTED_BLOOD_STACKER, true);
                                pDeathwing->CastSpell(pDeathwing, SPELL_SHRAPNEL_AURA, true);
                                if (m_isBerserk)
                                    pDeathwing->CastSpell(pDeathwing, SPELL_BERSERK, true);
                            }

                            events.ScheduleEvent(EVENT_ASPECT_TALK_2, 10000);
                            break;
                        case EVENT_ASPECT_TALK_2:
                        {
                            Creature* pAspect = NULL;

                            switch (urand(0, 3))
                            {
                                case 0:
                                    if (Creature* pAspect = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ALEXSTRASZA_DRAGON)))
                                        pAspect->AI()->Talk(SAY_ALEXSTRASZA_PHASE_2);
                                    break;
                                case 1:
                                    if (Creature* pAspect = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_NOZDORMU_DRAGON)))
                                        pAspect->AI()->Talk(SAY_NOZDORMU_PHASE_2);
                                    break;
                                case 2:
                                    if (Creature* pAspect = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_YSERA_DRAGON)))
                                        pAspect->AI()->Talk(SAY_YSERA_PHASE_2);
                                    break;
                                case 3:
                                    if (Creature* pAspect = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_KALECGOS_DRAGON)))
                                        pAspect->AI()->Talk(SAY_KALECGOS_PHASE_2);
                                    break;
                            }
                            
                            events.ScheduleEvent(EVENT_THRALL_TALK_2, 6000);
                            break;
                        }
                        case EVENT_THRALL_TALK_2:

                            if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                                pThrall->AI()->Talk(SAY_THRALL_PHASE_2);

                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            uint64 limbsGuids[4];
            uint8 m_current_platform;
            uint8 m_destroyed_platform;
            bool m_isFirst;
            bool m_isBerserk;

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                   return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                     (*iter)->DespawnOrUnsummon(2000);
            }

            Creature* GetLimbTentacleAtPlatform(uint8 platform)
            {
                if (platform)
                {
                    if (Creature* pLimb = ObjectAccessor::GetCreature(*me, limbsGuids[platform - 1]))
                        if (pLimb->IsAlive())
                            return pLimb;
                }

                return NULL;
            }
        };
};

class npc_dragon_soul_thrall_1 : public CreatureScript
{
    public:
        npc_dragon_soul_thrall_1() : CreatureScript("npc_dragon_soul_thrall_1") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pPlayer->IsInCombat())
                return true;

            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {
                if (pInstance->IsEncounterInProgress())
                    return true;

                if (pInstance->GetBossState(DATA_SPINE) != DONE ||
                    pInstance->GetBossState(DATA_MADNESS) != NOT_STARTED)
                    return true;

                if (pInstance->instance->IsHeroic() && !pInstance->GetData(DATA_ALL_HEROIC))
                {
                    //pPlayer->GetSession()->SendNotification(LANG_DS_HEROIC_MODE);
                    return true;
                }

                pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
                
                return true;
            }
            return false;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*sender*/, uint32 action)
        {
            pPlayer->PlayerTalkClass->SendCloseGossip();

            if (pPlayer->IsInCombat())
                return true;

            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {

                if (pInstance->IsEncounterInProgress())
                    return true;

                if (pInstance->GetBossState(DATA_SPINE) != DONE ||
                    pInstance->GetBossState(DATA_MADNESS) != NOT_STARTED)
                    return true;

                if (pInstance->instance->IsHeroic() && !pInstance->GetData(DATA_ALL_HEROIC))
                {
                    //pPlayer->GetSession()->SendNotification(LANG_DS_HEROIC_MODE);
                    return true;
                }

                if (action == GOSSIP_ACTION_INFO_DEF + 1)
                {
                    pInstance->SetBossState(DATA_MADNESS, IN_PROGRESS);
                    if (Creature* pDeathwing = pCreature->SummonCreature(NPC_DEATHWING, deathwingPos))
                    {
                        pDeathwing->AI()->DoZoneInCombat(pDeathwing, 500.0f);
                        pDeathwing->AI()->Talk(SAY_DEATHWING_AGGRO);
                    }

                    pCreature->SummonCreature(NPC_ALEXSTRASZA_DRAGON, alexstraszaPos);
                    pCreature->SummonCreature(NPC_NOZDORMU_DRAGON, nozdormuPos);
                    pCreature->SummonCreature(NPC_YSERA_DRAGON, yseraPos);
                    pCreature->SummonCreature(NPC_KALECGOS_DRAGON, kalecgosPos);
                    
                    pCreature->AI()->DoAction(ACTION_CHECK_PLAYERS);

                    pCreature->CastSpell(pCreature, SPELL_ASTRAL_RECALL_1);
                }
            }
            return true;
        }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_dragon_soul_thrall_1AI(pCreature);
        }

        struct npc_dragon_soul_thrall_1AI : public ScriptedAI
        {
            npc_dragon_soul_thrall_1AI(Creature* pCreature) : ScriptedAI(pCreature)
            {             
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                pInstance = me->GetInstanceScript();
            }

            void DoAction(int32 action)
            {
                if (action == ACTION_CHECK_PLAYERS)
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
                else if (action == ACTION_RESET_BATTLE)
                    ResetBattle();
                else if (action == ACTION_END_BATTLE)
                {
                    //DoCast(me, SPELL_ASTRAL_RECALL_2, true);
                    me->NearTeleportTo(thrallPos[1].GetPositionX(), thrallPos[1].GetPositionY(), thrallPos[1].GetPositionZ(), thrallPos[1].GetOrientation());
                    events.ScheduleEvent(EVENT_END_BATTLE, 2000);

                    if (pInstance)
                    {
                        pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT, 0, 0);
                        if (Creature* pDeathwing = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_DEATHWING)))
                        {
                            pDeathwing->RemoveAura(SPELL_SLUMP_1);
                            pDeathwing->CastSpell(pDeathwing, SPELL_SLUMP_2, true);
                        }
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_CHECK_PLAYERS)
                    {
                        if (pInstance)
                        {
                            if ((pInstance->GetBossState(DATA_MADNESS) != IN_PROGRESS) || !CheckPlayers())
                            {
                                ResetBattle();
                            }
                            else
                                events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1000);
                        }
                    }
                    else if (eventId == EVENT_END_BATTLE)
                    {
                        me->UpdateObjectVisibility(true);
                        events.CancelEvent(EVENT_CHECK_PLAYERS);
                        ResetBattle(true);
                        DoCastAOE(SPELL_TRIGGER_ASPECT_YELL_1, true);
                        DoCastAOE(SPELL_FIRE_DRAGON_SOUL_ASPECTS, true);
                        events.ScheduleEvent(EVENT_DRAGON_SOUL, 1000);
                    }
                    else if (eventId == EVENT_DRAGON_SOUL)
                    {
                        DoCast(me, SPELL_FIRE_DRAGON_SOUL);
                    }
                }
            }

            void ResetBattle(bool done = false)
            {
                if (!done)
                {
                    me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                    if (pInstance)
                        pInstance->SetBossState(DATA_MADNESS, NOT_STARTED);

                    DespawnCreatures(NPC_DEATHWING);
                    DespawnCreatures(NPC_DEATHWING_1);
                    DespawnCreatures(NPC_WING_TENTACLE);
                    DespawnCreatures(NPC_ARM_TENTACLE_1);
                    DespawnCreatures(NPC_ARM_TENTACLE_2);
                    DespawnCreatures(NPC_MUTATED_CORRUPTION);
                    DespawnCreatures(NPC_BLISTERING_TENTACLE);
                    DespawnCreatures(NPC_REGENERAIVE_BLOOD);
                    DespawnCreatures(NPC_ELEMENTIUM_BOLT);
                    DespawnCreatures(NPC_TIME_ZONE);
                    DespawnCreatures(NPC_IMPALING_TENTACLE);
                    DespawnCreatures(NPC_ELEMENTIUM_TERROR);
                    DespawnCreatures(NPC_CONGEALING_BLOOD);

                    DespawnCreatures(NPC_ALEXSTRASZA_DRAGON);
                    DespawnCreatures(NPC_KALECGOS_DRAGON);
                    DespawnCreatures(NPC_YSERA_DRAGON);
                    DespawnCreatures(NPC_NOZDORMU_DRAGON);

                    me->NearTeleportTo(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ(), me->GetHomePosition().GetOrientation());
                    me->UpdateObjectVisibility(true);
                }
                else
                {
                    if (pInstance)
                        pInstance->SetBossState(DATA_MADNESS, DONE);

                    DespawnCreatures(NPC_WING_TENTACLE);
                    DespawnCreatures(NPC_ARM_TENTACLE_1);
                    DespawnCreatures(NPC_ARM_TENTACLE_2);
                    DespawnCreatures(NPC_MUTATED_CORRUPTION);
                    DespawnCreatures(NPC_BLISTERING_TENTACLE);
                    DespawnCreatures(NPC_REGENERAIVE_BLOOD);
                    DespawnCreatures(NPC_ELEMENTIUM_BOLT);
                    DespawnCreatures(NPC_TIME_ZONE);
                    DespawnCreatures(NPC_IMPALING_TENTACLE);
                    DespawnCreatures(NPC_ELEMENTIUM_TERROR);
                    DespawnCreatures(NPC_CONGEALING_BLOOD);
                }
            }

        private:

            EventMap events;
            InstanceScript* pInstance;

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                   return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                     (*iter)->DespawnOrUnsummon(2000);
            }

            bool CheckPlayers()
            {
                Player* player = NULL;
                AnyLivePlayerNoGmCheck check(me, 500.0f);
                Trinity::PlayerSearcher<AnyLivePlayerNoGmCheck> searcher(me, player, check);
                me->VisitNearbyWorldObject(500.0f, searcher);
                return (player ? true : false);
            }

            class AnyLivePlayerNoGmCheck
            {
                public:
                    AnyLivePlayerNoGmCheck(WorldObject const* obj, float range) : _obj(obj), _range(range) {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (!_obj->IsWithinDistInMap(u, _range))
                            return false;

                        if (u->IsGameMaster())
                            return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _range;
            };
        };
};

class npc_madness_of_deathwing_mutated_corruption : public CreatureScript
{
    public:
        npc_madness_of_deathwing_mutated_corruption() : CreatureScript("npc_madness_of_deathwing_mutated_corruption") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_mutated_corruptionAI(pCreature);
        }

        struct npc_madness_of_deathwing_mutated_corruptionAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_mutated_corruptionAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {     
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                pInstance = me->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void DoAction(int32 action)
            {
                if (action == ACTION_CRUSH)
                    events.ScheduleEvent(EVENT_CRUSH_1, 500);
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_CRUSH, urand(10000, 15000));
                events.ScheduleEvent(EVENT_IMPALE, 12000);
                events.ScheduleEvent(EVENT_SELECT_VICTIM, 5000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CRUSH:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                me->SetFacingToObject(pTarget);
                                DoCast(pTarget, SPELL_CRUSH);
                            }
                            events.ScheduleEvent(EVENT_CRUSH, 8000);
                            break;
                        case EVENT_IMPALE:
                        {
                            Unit* pTarget = me->GetVictim();

                            if (!me->IsWithinMeleeRange(pTarget))
                            {
                                Unit* pNearest = SelectTarget(SELECT_TARGET_NEAREST, 0, 0.0f, true);
                                if (pNearest)
                                    pTarget = pNearest;
                            }

                            DoCast(pTarget, SPELL_IMPALE);
                            events.ScheduleEvent(EVENT_IMPALE, 35000);
                            break;
                        }
                        case EVENT_SELECT_VICTIM:
                        {
                            Unit* pNearest = NULL;
							if (!me->GetVictim() || !me->IsWithinMeleeRange(me->GetVictim()))
                            {
                                pNearest = SelectTarget(SELECT_TARGET_NEAREST, 0, 0.0f, true);
                            
                                // Cast Impale Aspect
                                if (!pNearest || !me->IsWithinMeleeRange(pNearest))
                                {
                                    if (pInstance)
                                    {
                                        if (Creature* pDeathwing = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_DEATHWING)))
                                        {
                                            Unit* pAspect = NULL;
                                            uint8 platform = pDeathwing->AI()->GetData(DATA_CURRENT_PLATFORM);
                                            
                                            switch (platform)
                                            {
                                                case 1: 
                                                    pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_ALEXSTRASZA_DRAGON));
                                                    break;
                                                case 2: 
                                                    pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_NOZDORMU_DRAGON));
                                                    break;
                                                case 3: 
                                                    pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_YSERA_DRAGON));
                                                    break;
                                                case 4: 
                                                    pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_KALECGOS_DRAGON));
                                                    break;
                                            }

                                            if (pAspect)
                                            {
                                                pDeathwing->AI()->Talk(SAY_IMPALE_ASPECT);
                                                DoCast(pAspect, SPELL_IMPALE_ASPECT);
                                            }
                                        }
                                    }
                                }
                                else
                                    me->Attack(pNearest, true);
                            }

                            events.ScheduleEvent(EVENT_SELECT_VICTIM, 2000);
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
        };
};

class npc_madness_of_deathwing_crush_target : public CreatureScript
{
    public:
        npc_madness_of_deathwing_crush_target() : CreatureScript("npc_madness_of_deathwing_crush_target") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_crush_targetAI(pCreature);
        }

        struct npc_madness_of_deathwing_crush_targetAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_crush_targetAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            { 
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*owner*/)
            {
                if (Creature* pCorruption = me->FindNearestCreature(NPC_MUTATED_CORRUPTION, 80.0f))
                {
                    pCorruption->SetFacingToObject(me);
                    pCorruption->CastSpell(me, SPELL_CRUSH);
               }
            }
        };
};

class npc_madness_of_deathwing_limb_tentacle : public CreatureScript
{
    public:
        npc_madness_of_deathwing_limb_tentacle() : CreatureScript("npc_madness_of_deathwing_limb_tentacle") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_limb_tentacleAI(pCreature);
        }

        struct npc_madness_of_deathwing_limb_tentacleAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_limb_tentacleAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {    
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->SetReactState(REACT_PASSIVE);

                phase = 0;
                tentacles = 0;
                m_current_platform = 0;

                pInstance = me->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
                phase = 0;
                tentacles = 0;
                m_current_platform = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                phase = 0;
                tentacles = 0;
                m_current_platform = 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_CURRENT_PLATFORM)
                    m_current_platform = data;
            }

            void JustSummoned(Creature* summon)
            {
                DoZoneInCombat(summon);

                if (summon->GetEntry() == NPC_BLISTERING_TENTACLE)
                    tentacles++;
                else if (summon->GetEntry() == NPC_HEMORRHAGE_TARGET)
                    summon->CastSpell(summon, SPELL_HEMORRHAGE_AURA, true);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                if (summon->GetEntry() == NPC_BLISTERING_TENTACLE)
                    tentacles--;
            }

            void DoAction(int32 action)
            {
                if (action == ACTION_ASSAULT_ASPECTS_FIRST)
                {
                    events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 100);
                    events.ScheduleEvent(EVENT_UPDATE_HEALTH, 2000);
                    events.ScheduleEvent(EVENT_HEMORRHAGE, IsHeroic() ? (55500 - 10000) : (85500 - 10000));
                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 12000 - 10000);
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 72000 - 10000);
                    }
                }
                else if (action == ACTION_ASSAULT_ASPECTS)
                {
                    events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 100);
                    events.ScheduleEvent(EVENT_UPDATE_HEALTH, 2000);
                    events.ScheduleEvent(EVENT_HEMORRHAGE, IsHeroic() ? (70500 - 10000) : (100500 - 10000));
                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 22000 - 10000);
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 82000 - 10000);
                    }
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                events.Reset();

                if (pInstance && m_current_platform)
                {
                    if (Creature* pDeathwing = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_DEATHWING)))
                        pDeathwing->AI()->SetData(DATA_DESTROY_PLATFORM, m_current_platform);

                    switch (m_current_platform)
                    {
                        case 1:
                            if (Creature* pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_ALEXSTRASZA_DRAGON)))
                                DoCast(pAspect, SPELL_TRIGGER_CONCENTRATION, true);
                            break;
                        case 2:
                            if (Creature* pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_NOZDORMU_DRAGON)))
                                DoCast(pAspect, SPELL_TRIGGER_CONCENTRATION, true);
                            break;
                        case 3:
                            if (Creature* pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_YSERA_DRAGON)))
                                DoCast(pAspect, SPELL_TRIGGER_CONCENTRATION, true);
                            break;
                        case 4:
                            if (Creature* pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_KALECGOS_DRAGON)))
                                DoCast(pAspect, SPELL_TRIGGER_CONCENTRATION, true);
                            break;
                    }
                }

                DoCastAOE(SPELL_AGONIZING_PAIN, true);

                DespawnCreatures(NPC_BLISTERING_TENTACLE);

                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if ((me->GetHealthPct() <= 70 && phase == 0) ||
                    (me->GetHealthPct() <= 35 && phase == 1))
                {
                    phase++;

                    if (tentacles < 5)
                    {
                        uint8 need_tentacles = 5 - tentacles;
                        for (uint8 i = 0; i < need_tentacles; ++i)
                            DoCast(me, SPELL_SUMMON_BLISTERING_TENTACLE, true);
                            //me->SummonCreature(NPC_BLISTERING_TENTACLE, blisteringPos[m_current_platform]);

                        if (pInstance)
                            if (Creature* pAspect = sObjectAccessor->GetCreature(*me, pInstance->GetData64(DATA_ALEXSTRASZA_DRAGON)))
                                pAspect->AI()->DoAction(ACTION_CAUTERIZE);
                            
                    }
                    return;
                }

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ASSAULT_ASPECTS:
                            DoCast(me, SPELL_BURNING_BLOOD, true);
                            break;
                        case EVENT_HEMORRHAGE:
                            if (m_current_platform > 0)
                                me->SummonCreature(NPC_HEMORRHAGE_TARGET, hemorrhagePos[m_current_platform - 1], TEMPSUMMON_TIMED_DESPAWN, 10000);
                            break;
                        case EVENT_UPDATE_HEALTH:
                            if (Aura* aur = me->GetAura(RAID_MODE(SPELL_BURNING_BLOOD, SPELL_BURNING_BLOOD_25, SPELL_BURNING_BLOOD_10H, SPELL_BURNING_BLOOD_25H)))
                            {
                                uint8 newstack = 100 - me->GetHealthPct();
                                if (newstack > 100) newstack = 100;
                                if (newstack < 1) newstack = 1;
                                if (aur->GetStackAmount() != newstack)
                                    aur->SetStackAmount(newstack);
                            }
                            events.ScheduleEvent(EVENT_UPDATE_HEALTH, 3000);
                            break;
                        case EVENT_CORRUPTING_PARASITE:
                            me->CastCustomSpell(SPELL_CORRUPTING_PARASITE_AOE, SPELLVALUE_MAX_TARGETS, 1, NULL, true);
                            break;
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            uint8 phase;
            uint8 tentacles;
            uint8 m_current_platform;

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                   return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                     (*iter)->DespawnOrUnsummon(2000);
            }
        };
};

class npc_madness_of_deathwing_blistering_tentacle : public CreatureScript
{
    public:
        npc_madness_of_deathwing_blistering_tentacle() : CreatureScript("npc_madness_of_deathwing_blistering_tentacle") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_blistering_tentacleAI(pCreature);
        }

        struct npc_madness_of_deathwing_blistering_tentacleAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_blistering_tentacleAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->SetReactState(REACT_PASSIVE);

                me->SetCanFly(true);
                me->SetDisableGravity(true);
            }

            void IsSummonedBy(Unit* owner)
            {
                me->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 50.0f);
                
                if (owner->GetEntry() == NPC_WING_TENTACLE ||
                    owner->GetEntry() == NPC_ARM_TENTACLE_1 ||
                    owner->GetEntry() == NPC_ARM_TENTACLE_2)
                {
                    DoCast(owner, SPELL_BLISTERING_TENTACLE_VEHICLE, true);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                me->DespawnOrUnsummon(500);
            }
        };
};

class npc_madness_of_deathwing_regenerative_blood : public CreatureScript
{
    public:
        npc_madness_of_deathwing_regenerative_blood() : CreatureScript("npc_madness_of_deathwing_regenerative_blood") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_regenerative_bloodAI(pCreature);
        }

        struct npc_madness_of_deathwing_regenerative_bloodAI : public ScriptedAI
        {
            npc_madness_of_deathwing_regenerative_bloodAI(Creature* pCreature) : ScriptedAI(pCreature)
            {          
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
                platform = GetGround(me);
            }

            void Reset()
            {
                events.Reset();
                me->setPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 10);
                me->SetPower(POWER_ENERGY, 0);
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                events.ScheduleEvent(EVENT_START_MOVE, 1000);
            }

            void AttackStart(Unit* who)
            {
                if (!who)
                    return;

                if (platform && platform != GetGround(who))
                {
                    me->Attack(who, false);
                }
                else
                {
                    if (me->Attack(who, true))
                        me->GetMotionMaster()->MoveChase(who);
                }
            }
            
            void JustDied(Unit* /*who*/)
            {   
                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_MOVE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_UPDATE_HEALTH:
                        {
                            int32 val = me->GetPower(POWER_ENERGY);
                            val++;
                            if (val > 9)
                            {
                                me->SetPower(POWER_ENERGY, 0);
                                DoCast(me, SPELL_REGENERATIVE_BLOOD_HEAL, true);
                            }
                            else
                                me->SetPower(POWER_ENERGY, val);

                            events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            uint8 platform;
        };
};

class npc_madness_of_deathwing_elementium_bolt : public CreatureScript
{
    public:
        npc_madness_of_deathwing_elementium_bolt() : CreatureScript("npc_madness_of_deathwing_elementium_bolt") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_elementium_boltAI(pCreature);
        }

        struct npc_madness_of_deathwing_elementium_boltAI : public ScriptedAI
        {
            npc_madness_of_deathwing_elementium_boltAI(Creature* pCreature) : ScriptedAI(pCreature)
            {          
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->setActive(true);
                me->SetSpeed(MOVE_FLIGHT, 4.5f, true);
                me->SetSpeed(MOVE_WALK, 50.f, true);
                me->SetSpeed(MOVE_RUN, 50.f, true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
                platform = 0;
                isSlow = false;
            }

            void IsSummonedBy(Unit* owner)
            {
                if (!owner || !owner->ToCreature())
                    return;

                platform = owner->ToCreature()->AI()->GetData(DATA_CURRENT_PLATFORM);
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo)
            {
                if (!platform)
                    return;

                if (spellInfo->Id == SPELL_ELEMENTIUM_METEOR_SCRIPT)
                {
                    // not offlike !!!
                    //if (Creature* pTrigger = me->SummonCreature(NPC_CLAWK_MARK, boltPos[platform], TEMPSUMMON_TIMED_DESPAWN, 25000))
                    //    pTrigger->AddAura(SPELL_ELEMENTIUM_METEOR_TARGET, pTrigger);
                    if (Creature* pTrigger = me->SummonCreature(NPC_PLATFORM, boltPos[platform], TEMPSUMMON_TIMED_DESPAWN, 25000))
                        pTrigger->AddAura(SPELL_ELEMENTIUM_METEOR_TARGET, pTrigger);

                    me->GetMotionMaster()->MovePoint(DATA_METEOR_POINT, boltPos[platform]);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE)
                    if (id == DATA_METEOR_POINT)
                    {
                        DoCastAOE(SPELL_ELEMENTIUM_BLAST, true);
                        //DoCast(me, SPELL_ELEMENTIUM_METEOR_TRANSFORM_2, true);
                        DoCast(me, SPELL_ELEMENTIUM_METEOR_AURA, true);
                        me->SetFloatValue(UNIT_FIELD_BOUNDING_RADIUS, 0.39f);
                        me->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 1.0f);
                        me->SetDisplayId(15435);
                    }
            }

            void JustDied(Unit* /*who*/)
            {
                me->DespawnOrUnsummon(1000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!isSlow && me->FindNearestCreature(NPC_TIME_ZONE, 15.0f, true))
                {
                    isSlow = true;
                    me->SetSpeed(MOVE_FLIGHT, 0.225f, true);
                    me->SetSpeed(MOVE_WALK, 2.5f, true);
                    me->SetSpeed(MOVE_RUN, 2.5f, true);
                }
                else if (isSlow && !me->FindNearestCreature(NPC_TIME_ZONE, 15.0f, true))
                {
                    me->SetSpeed(MOVE_FLIGHT, 4.5f, true);
                    me->SetSpeed(MOVE_WALK, 50.f, true);
                    me->SetSpeed(MOVE_RUN, 50.f, true);
                }
            }

        private:
            InstanceScript* pInstance;
            uint8 platform;
            bool isSlow;
        };
};

class npc_madness_of_deathwing_corrupting_parasite : public CreatureScript
{
    public:
        npc_madness_of_deathwing_corrupting_parasite() : CreatureScript("npc_madness_of_deathwing_corrupting_parasite") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_corrupting_parasiteAI(pCreature);
        }

        struct npc_madness_of_deathwing_corrupting_parasiteAI : public ScriptedAI
        {
            npc_madness_of_deathwing_corrupting_parasiteAI(Creature* pCreature) : ScriptedAI(pCreature)
            {          
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();

                m_unstable = false;
            }

            void Reset()
            {
                events.Reset();
            }

            void DoAction(int32 action)
            {
                if (action == ACTION_PARASITIC_BACKSLASH && !m_unstable)
                {
                    m_unstable = true;
                    me->ApplyPercentModFloatValue(OBJECT_FIELD_SCALE, -70.0f, false);
                    events.ScheduleEvent(EVENT_UNSTABLE_CORRUPTION, 1000);

                    if (pInstance)
                        if (Creature* pAspect = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_ALEXSTRASZA_DRAGON)))
                            pAspect->AI()->DoAction(ACTION_CAUTERIZE_PARASITE);
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_UNSTABLE_CORRUPTION)
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        DoCastAOE(SPELL_UNSTABLE_CORRUPTION);
                    }
                }
            }

            void JustDied(Unit* /*who*/)
            {
                me->DespawnOrUnsummon(1000);
            }

        private:
            EventMap events;
            InstanceScript* pInstance;
            bool m_unstable;
        };
};

class npc_madness_of_deathwing_deathwing : public CreatureScript
{
    public:
        npc_madness_of_deathwing_deathwing() : CreatureScript("npc_madness_of_deathwing_deathwing") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_deathwingAI(pCreature);
        }

        struct npc_madness_of_deathwing_deathwingAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_deathwingAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {           
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();

                isDead = false;
                phase = 0;
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                if ((me->GetHealthPct() <= 15.0f && phase == 0) || (me->GetHealthPct() <= 10.0f && phase == 1) || (me->GetHealthPct() <= 5.0f && phase == 2))
                {
                    phase++;
                    if (IsHeroic())
                        for (uint8 i = 0; i < 8; ++i)
                            me->CastSpell(congealingPos[0].GetPositionX(), congealingPos[0].GetPositionY(), congealingPos[0].GetPositionZ(), SPELL_CONGEALING_BLOOD_MISSILE, true);
                }
                

                if (!isDead)
                    if (me->GetHealth() <= damage)
                    {
                        isDead = true;
                        if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                            pThrall->AI()->DoAction(ACTION_END_BATTLE);
                        me->DespawnOrUnsummon(500);
                    }
            }

            void HealReceived(Unit* /*who*/, uint32& /*heal*/)
            {
                if (me->GetHealthPct() >= 15.0f && phase > 0)
                    phase = 0;
                else if (me->GetHealthPct() >= 10.0f && phase > 1)
                    phase = 1;
                else if (me->GetHealthPct() >= 5.0f && phase > 2)
                    phase = 2;
            }

            void JustSummoned(Creature* summon)
            {
                DoZoneInCombat(summon);
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_ELEMENTIUM_FRAGMENT, 10500);
                events.ScheduleEvent(EVENT_ELEMENTIUM_TERROR, 35500);
                events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);

                phase = 0;
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPDATE_HEALTH:
                            if (AuraEffect* aurEff = me->GetAuraEffect(RAID_MODE(SPELL_CORRUPTED_BLOOD, SPELL_CORRUPTED_BLOOD_25, SPELL_CORRUPTED_BLOOD_10H, SPELL_CORRUPTED_BLOOD_25H), EFFECT_1))
                            {
                                int32 newamount = 100 * (phase + 1) + 30;
                                aurEff->SetAmount(newamount);                                
                            }
                            events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1500);
                            break;
                        case EVENT_ELEMENTIUM_FRAGMENT:
                        {
                            DoCast(me, SPELL_IMPALING_TENTACLE_SCRIPT, true);
                            uint8 num = RAID_MODE(3, 8);
                            for (uint8 i = 0; i < num; ++i)
                            {
                                uint8 pos = urand(0, 7);
                                me->CastSpell(impalingPos[pos].GetPositionX(), impalingPos[pos].GetPositionY(), impalingPos[pos].GetPositionZ(), SPELL_IMPALING_TENTACLE_MISSILE, true);
                            }

                            events.ScheduleEvent(EVENT_ELEMENTIUM_FRAGMENT, 90000);
                            break;
                        }
                        case EVENT_ELEMENTIUM_TERROR:
                        {
                            DoCast(me, SPELL_ELEMENTIUM_TERROR_SCRIPT, true);
                            for (uint8 i = 0; i < 2; ++i)
                            {
                                uint8 pos = urand(0, 1);
                                me->CastSpell(terrorPos[pos].GetPositionX(), terrorPos[pos].GetPositionY(), terrorPos[pos].GetPositionZ(), SPELL_ELEMENTIUM_TERROR_MISSILE, true);
                            }

                            events.ScheduleEvent(EVENT_ELEMENTIUM_TERROR, 90000);
                            break;
                        }
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            bool isDead;
            uint8 phase;
        };
};

class npc_madness_of_deathwing_impaling_tentacle : public CreatureScript
{
    public:
        npc_madness_of_deathwing_impaling_tentacle() : CreatureScript("npc_madness_of_deathwing_impaling_tentacle") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_impaling_tentacleAI(pCreature);
        }

        struct npc_madness_of_deathwing_impaling_tentacleAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_impaling_tentacleAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->SetReactState(REACT_PASSIVE);

                targetGuid = 0;
            }

            void Reset()
            {
                events.Reset();
            }

            void JustDied(Unit* /*killer*/)
            {
                me->DespawnOrUnsummon(2000);
            }

            void SetGUID(uint64 guid, int32 type)
            {
                if (type == DATA_SHRAPNEL)
                {
                    if (guid != 0)
                    {
                        targetGuid = guid;
                        events.ScheduleEvent(EVENT_SHRAPNEL, 200);
                    }
                }
            }
            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHRAPNEL:
                            if (Unit* pTarget = ObjectAccessor::GetUnit(*me, targetGuid))
                            {
                                DoCast(pTarget, SPELL_SHRAPNEL_TARGET, true);
                                DoCast(pTarget, SPELL_SHRAPNEL_DMG);
                            }
                            break;
                    }
                }
            }

        private:
            EventMap events;
            uint64 targetGuid;
        };
};

class npc_madness_of_deathwing_elementium_terror : public CreatureScript
{
    public:
        npc_madness_of_deathwing_elementium_terror() : CreatureScript("npc_madness_of_deathwing_elementium_terror") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_elementium_terrorAI(pCreature);
        }

        struct npc_madness_of_deathwing_elementium_terrorAI : public ScriptedAI
        {
            npc_madness_of_deathwing_elementium_terrorAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                events.Reset();
            }

            void JustDied(Unit* /*killer*/)
            {
                me->DespawnOrUnsummon(2000);
            }

            void IsSummonedBy(Unit* owner)
            {
                events.ScheduleEvent(EVENT_START_MOVE, 1000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_MOVE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };
};

class npc_madness_of_deathwing_congealing_blood : public CreatureScript
{
    public:
        npc_madness_of_deathwing_congealing_blood() : CreatureScript("npc_madness_of_deathwing_congealing_blood") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_congealing_bloodAI(pCreature);
        }

        struct npc_madness_of_deathwing_congealing_bloodAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_congealing_bloodAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {             
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                
                me->SetReactState(REACT_PASSIVE);

                me->SetSpeed(MOVE_RUN, 1.0f);

                pInstance = me->GetInstanceScript();
            }

            void IsSummonedBy(Unit* /*owner*/)
            {
                events.ScheduleEvent(EVENT_START_MOVE, 1000);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->DespawnOrUnsummon(1000);
            }

            void MovementInform(uint32 type, uint32 data)
            {
                if (type == POINT_MOTION_TYPE)
                    if (data == DATA_BLOOD_POINT)
                        events.ScheduleEvent(EVENT_CONGEALING_BLOOD_HEAL, 1);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_MOVE:
                            me->GetMotionMaster()->MovePoint(DATA_BLOOD_POINT, congealingPos[1]);
                            break;
                        case EVENT_CONGEALING_BLOOD_HEAL:
                            DoCast(me, SPELL_CONGEALING_BLOOD_HEAL, true);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
        };
};

class npc_dragon_soul_alexstrasza_dragon : public CreatureScript
{
    public:
        npc_dragon_soul_alexstrasza_dragon() : CreatureScript("npc_dragon_soul_alexstrasza_dragon") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_dragon_soul_alexstrasza_dragonAI(pCreature);
        }

        struct npc_dragon_soul_alexstrasza_dragonAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_alexstrasza_dragonAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {             
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();

                isActive = true;
            }

            void EnterEvadeMode()
            {
                return;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo)
            {
                switch (spellInfo->Id)
                {   
                    case SPELL_TRIGGER_CONCENTRATION:
                        isActive = false;
                        events.Reset();
                        me->RemoveAura(SPELL_ALEXSTRASZA_PRESENCE);
                        me->InterruptNonMeleeSpells(true);
                        DoCast(SPELL_CONCENTRATION_1);                     
                        break;
                    case SPELL_TRIGGER_ASPECT_BUFFS:
                        isActive = true;
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_ALEXSTRASZA_PRESENCE, true);
                        break;
                    case SPELL_TRIGGER_ASPECT_YELL_1:
                        Talk(SAY_ALEXTRASZA_END);
                        break;
                    case SPELL_FIRE_DRAGON_SOUL_ASPECTS:
                        isActive = false;
                        events.Reset();
                        me->RemoveAura(SPELL_ALEXSTRASZA_PRESENCE);
                        DoCast(me, SPELL_CONCENTRATION_5);
                        break;
                }
            }

            void DoAction(int32 action)
            {
                if (isActive && action == ACTION_CAUTERIZE)
                    events.ScheduleEvent(EVENT_CAUTERIZE, 2000);
                else if (isActive && action == ACTION_CAUTERIZE_PARASITE)
                    events.ScheduleEvent(EVENT_CAUTERIZE_PARASITE, 1000);

            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                    pThrall->AI()->DoAction(ACTION_RESET_BATTLE);
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAUTERIZE:
                            DoCast(me, SPELL_CAUTERIZE_1, true);
                            break;
                        case EVENT_CAUTERIZE_PARASITE:
                            DoCast(me, SPELL_CAUTERIZE_3, true);
                            break;
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            bool isActive;
        };
};

class npc_dragon_soul_nozdormu_dragon : public CreatureScript
{
    public:
        npc_dragon_soul_nozdormu_dragon() : CreatureScript("npc_dragon_soul_nozdormu_dragon") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_dragon_soul_nozdormu_dragonAI(pCreature);
        }

        struct npc_dragon_soul_nozdormu_dragonAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_nozdormu_dragonAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature), summons(me)
            {             
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();

                isActive = true;
            }

            void EnterEvadeMode()
            {
                return;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo)
            {
                switch (spellInfo->Id)
                {   
                    case SPELL_TRIGGER_CONCENTRATION:
                        isActive = false;
                        events.Reset();
                        me->RemoveAura(SPELL_NOZDORMU_PRESENCE);
                        me->InterruptNonMeleeSpells(true);
                        DoCast(SPELL_CONCENTRATION_2);                    
                        break;
                    case SPELL_TRIGGER_ASPECT_BUFFS:
                        isActive = true;
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_NOZDORMU_PRESENCE, true);
                        DoAction(ACTION_TIME_ZONE_2);
                        break;
                    case SPELL_FIRE_DRAGON_SOUL_ASPECTS:
                        isActive = false;
                        events.Reset();
                        me->InterruptNonMeleeSpells(true);
                        summons.DespawnEntry(NPC_TIME_ZONE);
                        me->RemoveAura(SPELL_NOZDORMU_PRESENCE);
                        DoCast(me, SPELL_CONCENTRATION_6);
                        break;
                }
            }

            void DoAction(int32 action)
            {
                if (isActive && action == ACTION_TIME_ZONE)
                {
                    summons.DespawnEntry(NPC_TIME_ZONE);
                    events.ScheduleEvent(EVENT_TIME_ZONE, urand(2000, 6000));
                }
                else if (action == ACTION_TIME_ZONE_2)
                {
                    summons.DespawnEntry(NPC_TIME_ZONE);
                    events.ScheduleEvent(EVENT_TIME_ZONE_2, urand(5000, 6000));
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                    pThrall->AI()->DoAction(ACTION_RESET_BATTLE);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TIME_ZONE:
                            if (pInstance)
                            {
                                if (Creature* pDeathwing = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_DEATHWING)))
                                {
                                    uint8 platform = pDeathwing->AI()->GetData(DATA_CURRENT_PLATFORM);
                                    if (platform < 1)
                                        break;

                                    me->CastSpell(timezonePos[platform - 1].GetPositionX(), timezonePos[platform - 1].GetPositionY(), timezonePos[platform - 1].GetPositionZ(), SPELL_TIME_ZONE_MISSILE_1, true);
                                }
                            }
                            break;
                        case EVENT_TIME_ZONE_2:
                            me->CastSpell(timezonePos[4].GetPositionX(), timezonePos[4].GetPositionY(), timezonePos[4].GetPositionZ(), SPELL_TIME_ZONE_MISSILE_2, true);
                            events.ScheduleEvent(EVENT_TIME_ZONE_2, 30000);
                            break;
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            SummonList summons;
            bool isActive;
        };
};

class npc_dragon_soul_ysera_dragon : public CreatureScript
{
    public:
        npc_dragon_soul_ysera_dragon() : CreatureScript("npc_dragon_soul_ysera_dragon") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_dragon_soul_ysera_dragonAI(pCreature);
        }

        struct npc_dragon_soul_ysera_dragonAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_ysera_dragonAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {             
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
            }

            void EnterEvadeMode()
            {
                return;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo)
            {
                switch (spellInfo->Id)
                {   
                    case SPELL_TRIGGER_CONCENTRATION:
                        me->RemoveAura(SPELL_YSERA_PRESENCE);
                        me->RemoveAura(SPELL_THE_DREAMER);
                        me->InterruptNonMeleeSpells(true);
                        DoCast(SPELL_CONCENTRATION_3);                    
                        break;
                    case SPELL_TRIGGER_ASPECT_BUFFS:
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_YSERA_PRESENCE, true);
                        DoCast(me, SPELL_THE_DREAMER, true);
                        break;
                    case SPELL_FIRE_DRAGON_SOUL_ASPECTS:
                        me->RemoveAura(SPELL_YSERA_PRESENCE);
                        me->RemoveAura(SPELL_THE_DREAMER);
                        DoCast(me, SPELL_CONCENTRATION_7);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                    pThrall->AI()->DoAction(ACTION_RESET_BATTLE);
            }

        private:
            InstanceScript* pInstance;
        };
};

class npc_dragon_soul_kalecgos_dragon : public CreatureScript
{
    public:
        npc_dragon_soul_kalecgos_dragon() : CreatureScript("npc_dragon_soul_kalecgos_dragon") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_dragon_soul_kalecgos_dragonAI(pCreature);
        }

        struct npc_dragon_soul_kalecgos_dragonAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_kalecgos_dragonAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {             
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
            }

            void EnterEvadeMode()
            {
                return;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo)
            {
                switch (spellInfo->Id)
                {   
                    case SPELL_TRIGGER_CONCENTRATION:
                        me->RemoveAura(SPELL_KALECGOS_PRESENCE);
                        me->RemoveAura(SPELL_SPELLWEAVER);
                        me->InterruptNonMeleeSpells(true);
                        DoCast(SPELL_CONCENTRATION_4);                     
                        break;
                    case SPELL_TRIGGER_ASPECT_BUFFS:
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_KALECGOS_PRESENCE, true);
                        DoCast(me, SPELL_SPELLWEAVER, true);
                        break;
                    case SPELL_FIRE_DRAGON_SOUL_ASPECTS:
                        me->RemoveAura(SPELL_KALECGOS_PRESENCE);
                        me->RemoveAura(SPELL_SPELLWEAVER);
                        DoCast(me, SPELL_CONCENTRATION_8);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                    pThrall->AI()->DoAction(ACTION_RESET_BATTLE);
            }

        private:
            InstanceScript* pInstance;
        };
};

class npc_madness_of_deathwing_jump_pad : public CreatureScript
{
    public:
        npc_madness_of_deathwing_jump_pad() : CreatureScript("npc_madness_of_deathwing_jump_pad") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_madness_of_deathwing_jump_padAI(pCreature);
        }

        struct npc_madness_of_deathwing_jump_padAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_jump_padAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                checkTimer = 500;
                pos = 0;
                spellId = 0;
                spellIdEx1 = 0;
                spellIdEx2 = 0;
            }

            void Reset()
            {
                for (uint8 i = 0; i < 6; ++i)
                {
                    if (me->GetExactDist(&jumpPos[i]) < 5.0f)
                    {
                        pos = i + 1;
                        switch (pos)
                        {
                            case 1:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_1;
                                spellIdEx1 = SPELL_CARRYING_WINDS_1;
                                spellIdEx2 = SPELL_CARRYING_WINDS_2;
                                break;
                            case 2:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_2;
                                spellIdEx1 = SPELL_CARRYING_WINDS_2;
                                spellIdEx2 = SPELL_CARRYING_WINDS_1;
                                break;
                            case 3:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_3;
                                spellIdEx1 = SPELL_CARRYING_WINDS_3;
                                spellIdEx2 = SPELL_CARRYING_WINDS_4;
                                break;
                            case 4:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_4;
                                spellIdEx1 = SPELL_CARRYING_WINDS_4;
                                spellIdEx2 = SPELL_CARRYING_WINDS_3;
                                break;
                            case 5:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_5;
                                spellIdEx1 = SPELL_CARRYING_WINDS_5;
                                spellIdEx2 = SPELL_CARRYING_WINDS_6;
                                break;
                            case 6:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_6;
                                spellIdEx1 = SPELL_CARRYING_WINDS_6;
                                spellIdEx2 = SPELL_CARRYING_WINDS_5;
                                break;
                        }
                        break;
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!spellId)
                    return;

                if (checkTimer <= diff)
                {
                    std::list<Player*> players;
                    PlayerCheck check(me, spellIdEx1, spellIdEx2);
                    Trinity::PlayerListSearcher<PlayerCheck> searcher(me, players, check);
                    me->VisitNearbyObject(32.0f, searcher);
                    if (!players.empty())
                        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++ itr)
                            DoCast((*itr), spellId, true);

                    checkTimer = 300;
                }
                else
                    checkTimer -= diff;
            }

        private:
            uint32 checkTimer;
            uint8 pos;
            uint32 spellId;
            uint32 spellIdEx1;
            uint32 spellIdEx2;

            class PlayerCheck
            {
                public:
                    PlayerCheck(WorldObject const* obj, uint32 spellEx1, uint32 spellEx2) : _obj(obj), _spellEx1(spellEx2), _spellEx2(spellEx2) {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (!u->IsFalling() || _obj->GetPositionZ() < (u->GetPositionZ() + 3.0f))
                            return false;

                        if (!_obj->IsWithinDistInMap(u, 32.0f))
                            return false;

                        if (u->HasAura(_spellEx1) || u->HasAura(_spellEx2))
                            return false;

                        if (Creature* pPad = u->FindNearestCreature(NPC_JUMP_PAD, 32.0f, true))
                            if (pPad->GetGUID() != _obj->GetGUID())
                                return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    uint32 _spellEx1, _spellEx2;
            };
        };
};

class spell_madness_of_deathwing_assault_aspects : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_assault_aspects() : SpellScriptLoader("spell_madness_of_deathwing_assault_aspects") { }

        class spell_madness_of_deathwing_assault_aspects_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_assault_aspects_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                uint8 players[4];
                memset(players, 0, sizeof(players));

                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if (WorldObject* object = (*itr))
                    {
                        uint8 ground =  GetGround(object);
                        if (ground > 0)
                            players[ground - 1]++;
                    }

                uint8 found = 0;
                uint8 max_val = 0;

                uint8 destroyed = 0;
                if (Creature* pDeathwing = GetCaster()->ToCreature())
                {
                    destroyed = pDeathwing->AI()->GetData(DATA_DESTROY_PLATFORM);

                    if (destroyed == 30)
                        return;

                    for (uint8 i = 0; i < 4; ++i)
                        if (players[i] > max_val && (destroyed & (1 << (i + 1))) == 0)
                        {
                            max_val = players[i];
                            found = i + 1;
                        }

                    if (found == 0)
                        for (uint8 i = 0; i < 4; ++i)
                            if ((destroyed & (1 << (i + 1))) == 0)
                            {
                                found = i + 1;
                                break;
                            }

                    if (found > 0)
                        pDeathwing->AI()->SetData(DATA_ASSAULT_PLATFORM, found);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_madness_of_deathwing_assault_aspects_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_assault_aspects_SpellScript();
        }
};

class spell_madness_of_deathwing_crush_force : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_crush_force() : SpellScriptLoader("spell_madness_of_deathwing_crush_force") { }

        class spell_madness_of_deathwing_crush_force_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_crush_force_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResizeList(targets, 1);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_madness_of_deathwing_crush_force_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_crush_force_SpellScript();
        }
};

class spell_madness_of_deathwing_hemorrhage_script : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_hemorrhage_script() : SpellScriptLoader("spell_madness_of_deathwing_hemorrhage_script") { }

        class spell_madness_of_deathwing_hemorrhage_script_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_hemorrhage_script_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetHitUnit()->CastSpell(GetCaster(), SPELL_HEMORRHAGE_MISSILE, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_madness_of_deathwing_hemorrhage_script_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_hemorrhage_script_SpellScript();
        }
};

class spell_madness_of_deathwing_elementium_meteor_summon : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_elementium_meteor_summon() : SpellScriptLoader("spell_madness_of_deathwing_elementium_meteor_summon") { }

        class spell_madness_of_deathwing_elementium_meteor_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_elementium_meteor_summon_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                WorldLocation summonPos = *GetExplTargetDest();
                summonPos.Relocate(boltPos[0]);
                SetExplTargetDest(summonPos);
                GetHitDest()->Relocate(boltPos[0]);
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_madness_of_deathwing_elementium_meteor_summon_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_elementium_meteor_summon_SpellScript();
        }
};

class spell_madness_of_deathwing_elementium_blast : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_elementium_blast() : SpellScriptLoader("spell_madness_of_deathwing_elementium_blast") { }

        class spell_madness_of_deathwing_elementium_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_elementium_blast_SpellScript);

            void HandleDamage()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                float distance = GetCaster()->GetExactDist2d(GetHitUnit());
                SetHitDamage(int32(GetHitDamage() / (distance / 3.2f)));
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_madness_of_deathwing_elementium_blast_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_elementium_blast_SpellScript();
        }
};

class spell_madness_of_deathwing_corrupting_parasite_aoe : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_corrupting_parasite_aoe() : SpellScriptLoader("spell_madness_of_deathwing_corrupting_parasite_aoe") { }

        class spell_madness_of_deathwing_corrupting_parasite_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_corrupting_parasite_aoe_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                Unit* pTarget = GetHitUnit();

                GetCaster()->CastSpell(GetHitUnit(), SPELL_CORRUPTING_PARASITE_AURA, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_CORRUPTING_PARASITE_DMG, true);
                if (Creature* pParasite = GetCaster()->SummonCreature(NPC_CORRUPTING_PARASITE, *pTarget))
                {
                    pParasite->AI()->DoZoneInCombat();
                    pParasite->EnterVehicle(GetHitUnit(), -1); //had a true on the end.
                    pParasite->ApplyPercentModFloatValue(OBJECT_FIELD_SCALE, -70.0f, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_madness_of_deathwing_corrupting_parasite_aoe_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_corrupting_parasite_aoe_SpellScript();
        }
};

class spell_madness_of_deathwing_corrupting_parasite_aura : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_corrupting_parasite_aura() : SpellScriptLoader("spell_madness_of_deathwing_corrupting_parasite_aura") { }

        class spell_madness_of_deathwing_corrupting_parasite_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_madness_of_deathwing_corrupting_parasite_aura_AuraScript);

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                    owner->CastSpell((Unit*)NULL, SPELL_PARASITIC_BACKSLASH, true);
                    if (Creature* pParasite = owner->FindNearestCreature(NPC_CORRUPTING_PARASITE, 10.0f))
                        pParasite->AI()->DoAction(ACTION_PARASITIC_BACKSLASH);
                }
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_madness_of_deathwing_corrupting_parasite_aura_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_madness_of_deathwing_corrupting_parasite_aura_AuraScript();
        }
};

class spell_madness_of_deathwing_agonizing_pain : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_agonizing_pain() : SpellScriptLoader("spell_madness_of_deathwing_agonizing_pain") { }

        class spell_madness_of_deathwing_agonizing_pain_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_agonizing_pain_SpellScript);

            void HandleDamage()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                int32 damage = GetHitUnit()->CountPctFromMaxHealth(20);

                SetHitDamage(damage);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_madness_of_deathwing_agonizing_pain_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_agonizing_pain_SpellScript();
        }
};

class spell_madness_of_deathwing_impale_aspect : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_impale_aspect() : SpellScriptLoader("spell_madness_of_deathwing_impale_aspect") { }

        class spell_madness_of_deathwing_impale_aspect_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_impale_aspect_SpellScript);

            void HandleDamage()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                int32 damage = GetHitUnit()->CountPctFromMaxHealth(26);

                SetHitDamage(damage);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_madness_of_deathwing_impale_aspect_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_impale_aspect_SpellScript();
        }
};

class spell_madness_of_deathwing_shrapnel_aoe : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_shrapnel_aoe() : SpellScriptLoader("spell_madness_of_deathwing_shrapnel_aoe") { }

        class spell_madness_of_deathwing_shrapnel_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_shrapnel_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                fragments.clear();

                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if ((*itr)->GetEntry() == NPC_IMPALING_TENTACLE)                   
                        fragments.push_back((*itr)->GetGUID());
            }

            void FilterPlayers(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                Unit* pCaster = GetCaster();

                if (fragments.empty())
                    return;

                if (targets.empty())
                    return;

                targets.remove_if(PlayersCheck());

                Trinity::Containers::RandomResizeList(targets, fragments.size());

                for (std::list<uint64>::const_iterator itr = fragments.begin(); itr != fragments.end(); ++itr)
                {
                    if (targets.empty())
                        break;

                    if (Creature* pFragment = ObjectAccessor::GetCreature(*pCaster, (*itr)))
                    {
                        std::list<WorldObject*>::iterator itr_player = targets.begin();
                        pFragment->AI()->SetGUID((*itr_player)->GetGUID(), DATA_SHRAPNEL);
                        targets.erase(itr_player);
                    }
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_madness_of_deathwing_shrapnel_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_madness_of_deathwing_shrapnel_aoe_SpellScript::FilterPlayers, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }

        private:
            std::list<uint64> fragments;

            class PlayersCheck
            {
                public:
                    PlayersCheck() {}
                    bool operator()(WorldObject* unit)
                    {
                        if (unit->GetTypeId() != TYPEID_PLAYER)
                            return true;
                        return false;
                    }
            };
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_shrapnel_aoe_SpellScript();
        }
};

class spell_madness_of_deathwing_unstable_corruption : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_unstable_corruption() : SpellScriptLoader("spell_madness_of_deathwing_unstable_corruption") { }

        class spell_madness_of_deathwing_unstable_corruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_unstable_corruption_SpellScript);

            void HandleDamage()
            {
                if (!GetCaster())
                    return;

                int32 damage = 0.1f * GetCaster()->GetHealth();

                SetHitDamage(damage);
            }

            void HandleCast()
            {
                if (!GetCaster())
                    return;

                if (Creature* pParasite = GetCaster()->ToCreature())
                    pParasite->DespawnOrUnsummon(2000);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_madness_of_deathwing_unstable_corruption_SpellScript::HandleDamage);
                AfterCast += SpellCastFn(spell_madness_of_deathwing_unstable_corruption_SpellScript::HandleCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_unstable_corruption_SpellScript();
        }
};

class spell_madness_of_deathwing_carrying_winds_script : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_carrying_winds_script(const char* name, uint8 pos) : SpellScriptLoader(name), _pos(pos) { }

        class spell_madness_of_deathwing_carrying_winds_script_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_carrying_winds_script_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                uint32 spellId = SPELL_CARRYING_WINDS_1;
                switch (_pos)
                {
                    case 1: spellId = SPELL_CARRYING_WINDS_1; break;
                    case 2: spellId = SPELL_CARRYING_WINDS_2; break;
                    case 3: spellId = SPELL_CARRYING_WINDS_3; break;
                    case 4: spellId = SPELL_CARRYING_WINDS_4; break;
                    case 5: spellId = SPELL_CARRYING_WINDS_5; break;
                    case 6: spellId = SPELL_CARRYING_WINDS_6; break;
                    default: break;
                }

                uint8 otherPos = (_pos % 2) == 1 ? _pos : _pos - 2;
                GetHitUnit()->CastSpell(jumpPos[otherPos].GetPositionX(), jumpPos[otherPos].GetPositionY(), jumpPos[otherPos].GetPositionZ(), spellId, true);
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CARRYING_WINDS_SPEED_10, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_madness_of_deathwing_carrying_winds_script_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

        public:
            spell_madness_of_deathwing_carrying_winds_script_SpellScript(uint8 pos) : SpellScript(), _pos(pos) {} 

        private:
            uint8 _pos;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_madness_of_deathwing_carrying_winds_script_SpellScript(_pos);
        }

    private:
        uint8 _pos;
};

class achievement_chromatic_champion : public AchievementCriteriaScript
{
    public:
        achievement_chromatic_champion() : AchievementCriteriaScript("achievement_chromatic_champion") { }

        bool OnCheck(Player* source, Unit* target)
        {
            return false;
        }
};

void AddSC_madness_of_deathwing()
{
    new boss_madness_of_deathwing();
    new npc_dragon_soul_thrall_1();
    new npc_madness_of_deathwing_mutated_corruption();
    new npc_madness_of_deathwing_crush_target();
    new npc_madness_of_deathwing_limb_tentacle();
    new npc_madness_of_deathwing_blistering_tentacle();
    new npc_madness_of_deathwing_regenerative_blood();
    new npc_madness_of_deathwing_elementium_bolt();
    new npc_madness_of_deathwing_corrupting_parasite();
    new npc_madness_of_deathwing_deathwing();
    new npc_madness_of_deathwing_impaling_tentacle();
    new npc_madness_of_deathwing_elementium_terror();
    new npc_madness_of_deathwing_congealing_blood();
    new npc_dragon_soul_alexstrasza_dragon();
    new npc_dragon_soul_nozdormu_dragon();
    new npc_dragon_soul_ysera_dragon();
    new npc_dragon_soul_kalecgos_dragon();
    new npc_madness_of_deathwing_jump_pad();
    new spell_madness_of_deathwing_assault_aspects();
    new spell_madness_of_deathwing_crush_force();
    new spell_madness_of_deathwing_hemorrhage_script();
    new spell_madness_of_deathwing_elementium_meteor_summon();
    new spell_madness_of_deathwing_elementium_blast();
    new spell_madness_of_deathwing_corrupting_parasite_aoe();
    new spell_madness_of_deathwing_corrupting_parasite_aura();
    new spell_madness_of_deathwing_agonizing_pain();
    new spell_madness_of_deathwing_impale_aspect();
    new spell_madness_of_deathwing_shrapnel_aoe();
    new spell_madness_of_deathwing_unstable_corruption();
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_1", 1);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_2", 2);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_3", 3);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_4", 4);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_5", 5);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_6", 6);
    new achievement_chromatic_champion();
}
