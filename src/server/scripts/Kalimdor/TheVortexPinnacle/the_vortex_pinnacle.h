#ifndef DEF_VORTEX_PINNACLE_H
#define DEF_VORTEX_PINNACLE_H

static const int maxEncounter = 3;
#define VPScriptName "instance_the_vortex_pinnacle"
#define VortexPinnacleScriptName "instance_the_vortex_pinnacle"
enum Data
{
    DATA_ERTAN      = 1,
    DATA_ALTAIRUS   = 2,
    DATA_ASAAD      = 3,
};


enum CreatureIds
{
    NPC_GRAND_VIZIER_ERTAN     = 43878, 
    NPC_ALTAIRUS               = 43873,
    NPC_ASAAD                  = 43875,
    // Trash mobs
    NPC_ARMORED_MISTRAL         = 45915,
    NPC_CLOUD_PRINCE            = 45917,
    NPC_EMPYREAN_ASSASSIN       = 45922,
    NPC_EXECUTOR_OF_THE_CALIPH  = 45928,
    NPC_GUST_SOLDIER            = 45477,
    NPC_HOWLING_GALE            = 45572,
    NPC_LURKING_TEMPEST         = 45704,
    NPC_MINISTER_OF_AIR         = 45930,
    NPC_TEMPLE_ADEPT            = 45935,
    NPC_YOUNG_STORM_DRAGON      = 45919,
    NPC_WILD_VORTEX             = 45912,
    NPC_SLIPSTREAM              = 45455,
    NPC_SLIPSTREAM_TWO          = 45457,
    NPC_SKYFALL                 = 52019,

    // Boss' encounter related NPCs
    NPC_SAFE_ZONE               = 42844,
    NPC_AIR_CURRENT             = 47305,
    NPC_TWISTER                 = 47342,
    NPC_GROUNDING_FIELD         = 47000,
    NPC_UNSTABLE_GROUNDING_FIELD= 46492,
    NPC_STORM_TARGET            = 46387,
    NPC_CYCLONE_SHIELD          = 46007,

    // Various NPCs
    NPC_GOLDEN_ORB              = 51157, /*Heroic Mode*/
    NPC_ITESH                   = 49943,

    NPC_WIND                    = 47305,
};


enum GameObjectIds
{
    GO_MAGIC_BRAZIER            = 207408,
};

template<class AI>
CreatureAI* GetVortexPinnacleAI(Creature* creature)
{
	if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
		if (instance->GetInstanceScript())
			if (instance->GetScriptId() == sObjectMgr->GetScriptId(VortexPinnacleScriptName))
				return new AI(creature);

	return NULL;
};

#endif
