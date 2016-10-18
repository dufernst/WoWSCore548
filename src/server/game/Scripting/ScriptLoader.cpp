/*
* Copyright (C) 2011-2015 Project SkyFire <http://www.projectskyfire.org/>
* Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2015 MaNGOS <http://getmangos.com/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ScriptLoader.h"

//examples
void AddSC_example_creature();
void AddSC_example_escort();
void AddSC_example_gossip_codebox();
void AddSC_example_misc();
void AddSC_example_commandscript();

// spells
void AddSC_deathknight_spell_scripts();
void AddSC_druid_spell_scripts();
void AddSC_generic_spell_scripts();
void AddSC_hunter_spell_scripts();
void AddSC_mage_spell_scripts();
void AddSC_monk_spell_scripts();
void AddSC_mastery_spell_scripts();
void AddSC_paladin_spell_scripts();
void AddSC_priest_spell_scripts();
void AddSC_rogue_spell_scripts();
void AddSC_shaman_spell_scripts();
void AddSC_warlock_spell_scripts();
void AddSC_warrior_spell_scripts();
void AddSC_quest_spell_scripts();
void AddSC_example_spell_scripts();
void AddSC_item_spell_scripts();
void AddSC_holiday_spell_scripts();

void AddSC_SmartSCripts();

//Commands
void AddSC_account_commandscript();
void AddSC_achievement_commandscript();
void AddSC_ban_commandscript();
void AddSC_bf_commandscript();
void AddSC_cast_commandscript();
void AddSC_character_commandscript();
void AddSC_cheat_commandscript();
void AddSC_debug_commandscript();
void AddSC_deserter_commandscript();
void AddSC_disable_commandscript();
void AddSC_event_commandscript();
void AddSC_gm_commandscript();
void AddSC_go_commandscript();
void AddSC_gobject_commandscript();
void AddSC_group_commandscript();
void AddSC_guild_commandscript();
void AddSC_honor_commandscript();
void AddSC_instance_commandscript();
void AddSC_learn_commandscript();
void AddSC_lfg_commandscript();
void AddSC_list_commandscript();
void AddSC_lookup_commandscript();
void AddSC_message_commandscript();
void AddSC_misc_commandscript();
void AddSC_mmaps_commandscript();
void AddSC_modify_commandscript();
void AddSC_npc_commandscript();
void AddSC_pet_commandscript();
void AddSC_quest_commandscript();
void AddSC_rbac_commandscript();
void AddSC_reload_commandscript();
void AddSC_reset_commandscript();
void AddSC_send_commandscript();
void AddSC_server_commandscript();
void AddSC_tele_commandscript();
void AddSC_ticket_commandscript();
void AddSC_titles_commandscript();
void AddSC_wp_commandscript();

#ifdef SCRIPTS
//world
void AddSC_areatrigger_scripts();
void AddSC_emerald_dragons();
void AddSC_generic_creature();
void AddSC_go_scripts();
void AddSC_guards();
void AddSC_item_scripts();
void AddSC_npc_professions();
void AddSC_npc_innkeeper();
void AddSC_npcs_special();
void AddSC_npc_taxi();
void AddSC_achievement_scripts();
void AddSC_player_scripts();

//eastern kingdoms

//Alterac Valley
void AddSC_alterac_valley();                 
void AddSC_boss_balinda();
void AddSC_boss_drekthar();
void AddSC_boss_galvangar();
void AddSC_boss_vanndar();

//Baradin Hold
void AddSC_boss_alizabal();                  
void AddSC_boss_occuthar();
void AddSC_boss_pit_lord_argaloth();
void AddSC_instance_baradin_hold();

//Blackrock Depths
void AddSC_blackrock_depths();               
void AddSC_boss_ambassador_flamelash();
void AddSC_boss_anubshiah();
void AddSC_boss_draganthaurissan();
void AddSC_boss_general_angerforge();
void AddSC_boss_gorosh_the_dervish();
void AddSC_boss_grizzle();
void AddSC_boss_high_interrogator_gerstahn();
void AddSC_boss_magmus();
void AddSC_boss_moira_bronzebeard();
void AddSC_boss_tomb_of_seven();
void AddSC_instance_blackrock_depths();

//Blackrock Spire
void AddSC_boss_drakkisath();                
void AddSC_boss_halycon();
void AddSC_boss_highlordomokk();
void AddSC_boss_mothersmolderweb();
void AddSC_boss_overlordwyrmthalak();
void AddSC_boss_shadowvosh();
void AddSC_boss_thebeast();
void AddSC_boss_warmastervoone();
void AddSC_boss_quatermasterzigris();
void AddSC_boss_pyroguard_emberseer();
void AddSC_boss_gyth();
void AddSC_boss_rend_blackhand();
void AddSC_boss_gizrul_the_slavener();
void AddSC_boss_urok_doomhowl();
void AddSC_boss_lord_valthalak();
void AddSC_instance_blackrock_spire();

//Blackwing lair
void AddSC_boss_razorgore();                 
void AddSC_boss_vaelastrasz();
void AddSC_boss_broodlord();
void AddSC_boss_firemaw();
void AddSC_boss_ebonroc();
void AddSC_boss_flamegor();
void AddSC_boss_chromaggus();
void AddSC_boss_nefarian();
void AddSC_instance_blackwing_lair();

//Deadmines
void AddSC_deadmines();                     
void AddSC_instance_deadmines();
void AddSC_boss_admiral_ripsnarl();
void AddSC_boss_captain_cookie();
void AddSC_boss_foereaper5000();
void AddSC_boss_glubtok();
void AddSC_boss_helix_gearbreaker();
void AddSC_boss_vanessa_vancleef();

//Gnomeregan
void AddSC_gnomeregan();                    
void AddSC_instance_gnomeregan();

//Karazhan
void AddSC_boss_attumen();                   
void AddSC_boss_curator();
void AddSC_boss_maiden_of_virtue();
void AddSC_boss_shade_of_aran();
void AddSC_boss_malchezaar();
void AddSC_boss_terestian_illhoof();
void AddSC_boss_moroes();
void AddSC_bosses_opera();
void AddSC_boss_netherspite();
void AddSC_instance_karazhan();
void AddSC_karazhan();
void AddSC_boss_nightbane();

// Magister's Terrace
void AddSC_boss_felblood_kaelthas();         
void AddSC_boss_selin_fireheart();
void AddSC_boss_vexallus();
void AddSC_boss_priestess_delrissa();
void AddSC_instance_magisters_terrace();
void AddSC_magisters_terrace();

//Molten core
void AddSC_boss_lucifron();                  
void AddSC_boss_magmadar();
void AddSC_boss_gehennas();
void AddSC_boss_garr();
void AddSC_boss_baron_geddon();
void AddSC_boss_shazzrah();
void AddSC_boss_golemagg();
void AddSC_boss_sulfuron();
void AddSC_boss_majordomo();
void AddSC_boss_ragnaros();
void AddSC_instance_molten_core();

//Ragefire Chasm
void AddSC_instance_ragefire_chasm();        

//Scarlet Enclave
void AddSC_the_scarlet_enclave();            
void AddSC_the_scarlet_enclave_c1();
void AddSC_the_scarlet_enclave_c2();
void AddSC_the_scarlet_enclave_c5();

//Shadowfang keep
void AddSC_shadowfang_keep();                
void AddSC_instance_shadowfang_keep();
void AddSC_boss_baron_ashbury();
void AddSC_boss_baron_silverlaine();
void AddSC_boss_commander_springvale();
void AddSC_boss_lord_godfrey();
void AddSC_boss_lord_valden();

//Stratholme
void AddSC_boss_magistrate_barthilas();      
void AddSC_boss_maleki_the_pallid();
void AddSC_boss_nerubenkan();
void AddSC_boss_cannon_master_willey();
void AddSC_boss_baroness_anastari();
void AddSC_boss_ramstein_the_gorger();
void AddSC_boss_timmy_the_cruel();
void AddSC_boss_postmaster_malown();
void AddSC_boss_baron_rivendare();
void AddSC_boss_dathrohan_balnazzar();
void AddSC_boss_order_of_silver_hand();
void AddSC_instance_stratholme();
void AddSC_stratholme();

// Sunken Temple
void AddSC_sunken_temple();                  
void AddSC_instance_sunken_temple();

//Sunwell Plateau
void AddSC_instance_sunwell_plateau();       
void AddSC_boss_kalecgos();
void AddSC_boss_brutallus();
void AddSC_boss_felmyst();
void AddSC_boss_eredar_twins();
void AddSC_boss_muru();
void AddSC_boss_kiljaeden();
void AddSC_sunwell_plateau();

//Uldaman
void AddSC_boss_archaedas();                 
void AddSC_boss_ironaya();
void AddSC_uldaman();
void AddSC_instance_uldaman();

//The Stockade
void AddSC_instance_the_stockade();          

//Zul'Aman(CATA DUNGEON)
void AddSC_boss_akilzon();                   
void AddSC_boss_halazzi();
void AddSC_boss_hex_lord_malacrass();
void AddSC_boss_janalai();
void AddSC_boss_nalorakk();
void AddSC_boss_daakara();
void AddSC_instance_zulaman();
void AddSC_zulaman();

// Zul'Gurub(CATA DUNGEON)
void AddSC_boss_grilek();                  
void AddSC_boss_hazzarah();
void AddSC_boss_jindo_the_godbreaker();
void AddSC_boss_kilnara();
void AddSC_boss_mandokir();
void AddSC_boss_renataki();
void AddSC_boss_venoxis();
void AddSC_boss_wushoolay();
void AddSC_boss_zanzil();
void AddSC_instance_zulgurub();

//Bastion of Twilight (CATA RAID)
void AddSC_bastion_of_twilight();
void AddSC_boss_chogall();
void AddSC_boss_ascendant_council();
void AddSC_boss_halfus_wyrmbreaker();
void AddSC_boss_sinestra();
void AddSC_boss_theralion_and_valiona();
void AddSC_instance_bastion_of_twilight();


//Blackwing Descent(CATA RAID)
void AddSC_blackwing_descent();
void AddSC_boss_atramedes();
void AddSC_boss_chimaeron();
void AddSC_boss_magmaw();
void AddSC_boss_maloriak();
void AddSC_boss_omnotron_defence_system();
void AddSC_instance_blackwing_descent();

//Grim Batol (CATA DUNGEON)
void AddSC_boss_drahga_shadowburner();
void AddSC_boss_erudax();
void AddSC_boss_forgemaster_throngus();
void AddSC_boss_general_umbriss();
void AddSC_grim_batol();
void AddSC_instance_grim_batol();

//The Throne of Tides (CATA DUNGEON)
void AddSC_boss_commander_ulthok();
void AddSC_boss_lady_nazjar();
void AddSC_boss_erunak_stonespeaker();
void AddSC_boss_ozumat();
void AddSC_instance_throne_of_the_tides();
void AddSC_throne_of_the_tides();




//Eastern Kingdoms Zones
void AddSC_alterac_mountains();
void AddSC_arathi_highlands();
void AddSC_blasted_lands();
void AddSC_burning_steppes();
void AddSC_duskwood();
void AddSC_eastern_plaguelands();
void AddSC_eversong_woods();
void AddSC_ghostlands();
void AddSC_hinterlands();
void AddSC_ironforge();
void AddSC_isle_of_queldanas();
void AddSC_loch_modan();
void AddSC_redridge_mountains();
void AddSC_silverpine_forest();
void AddSC_stormwind_city();
void AddSC_stranglethorn_vale();
void AddSC_swamp_of_sorrows();
void AddSC_tirisfal_glades();
void AddSC_undercity();
void AddSC_western_plaguelands();
void AddSC_westfall();
void AddSC_wetlands();
void AddSC_dun_morogh();
void AddSC_elwyn_forest();
void AddSC_silvermoon_city();

//kalimdor

//Blackfathom Depths
void AddSC_blackfathom_deeps();              
void AddSC_boss_gelihast();
void AddSC_boss_kelris();
void AddSC_boss_aku_mai();
void AddSC_instance_blackfathom_deeps();

//Battle for Mt. Hyjal(BC RAID)
void AddSC_hyjal();                          
void AddSC_boss_archimonde();
void AddSC_instance_mount_hyjal();
void AddSC_hyjal_trash();
void AddSC_boss_rage_winterchill();
void AddSC_boss_anetheron();
void AddSC_boss_kazrogal();
void AddSC_boss_azgalor();

//Old Hillsbrad
void AddSC_boss_captain_skarloc();           
void AddSC_boss_epoch_hunter();
void AddSC_boss_lieutenant_drake();
void AddSC_instance_old_hillsbrad();
void AddSC_old_hillsbrad();

//The Black Morass
void AddSC_boss_aeonus();                    
void AddSC_boss_chrono_lord_deja();
void AddSC_boss_temporus();
void AddSC_the_black_morass();
void AddSC_instance_the_black_morass();

//Culling Of Stratholme
void AddSC_boss_epoch();                     
void AddSC_boss_infinite_corruptor();
void AddSC_boss_salramm();
void AddSC_boss_mal_ganis();
void AddSC_boss_meathook();
void AddSC_culling_of_stratholme();
void AddSC_instance_culling_of_stratholme();

//Dire Maul
void AddSC_instance_dire_maul();             

//Maraudon
void AddSC_boss_celebras_the_cursed();      
void AddSC_boss_landslide();
void AddSC_boss_noxxion();
void AddSC_boss_ptheradras();
void AddSC_instance_maraudon();

//Onyxia's Lair
void AddSC_boss_onyxia();                   
void AddSC_instance_onyxias_lair();

//Razorfen Downs
void AddSC_boss_amnennar_the_coldbringer(); 
void AddSC_razorfen_downs();
void AddSC_instance_razorfen_downs();

//Razorfen Kraul
void AddSC_razorfen_kraul();                 
void AddSC_instance_razorfen_kraul();

//Ruins of ahn'qiraj
void AddSC_boss_kurinnaxx();                 
void AddSC_boss_rajaxx();
void AddSC_boss_moam();
void AddSC_boss_buru();
void AddSC_boss_ayamiss();
void AddSC_boss_ossirian();
void AddSC_instance_ruins_of_ahnqiraj();

//Temple of ahn'qiraj
void AddSC_boss_cthun();                    
void AddSC_boss_viscidus();
void AddSC_boss_fankriss();
void AddSC_boss_huhuran();
void AddSC_bug_trio();
void AddSC_boss_sartura();
void AddSC_boss_skeram();
void AddSC_boss_twinemperors();
void AddSC_boss_ouro();
void AddSC_npc_anubisath_sentinel();
void AddSC_instance_temple_of_ahnqiraj();

//Wailing caverns
void AddSC_wailing_caverns();                
void AddSC_instance_wailing_caverns();

//Zul'Farrak
void AddSC_boss_zum_rah();                   
void AddSC_zulfarrak();
void AddSC_instance_zulfarrak();
void AddSC_instance_halls_of_origination();
void AddSC_boss_temple_guardian_anhuur();
void AddSC_boss_earthrager_ptah();
void AddSC_boss_anraphet();
void AddSC_instance_firelands();
void AddSC_boss_alysrazor();


//Dragon Soul (CATA RAID)
void AddSC_instance_dragon_soul();
void AddSC_dragon_soul();
void AddSC_boss_morchok();
void AddSC_boss_yorsahj_the_unsleeping();
void AddSC_boss_warlord_zonozz();
void AddSC_boss_hagara_the_stormbinder();
void AddSC_boss_ultraxion();
void AddSC_boss_warmaster_blackhorn();
void AddSC_spine_of_deathwing();
void AddSC_madness_of_deathwing();


// Firelands(CATA RAID)
void AddSC_instance_firelands(); 
void AddSC_firelands();
void AddSC_boss_shannox();
void AddSC_boss_bethtilac();
void AddSC_boss_alysrazor();
void AddSC_boss_lord_rhyolith();
void AddSC_boss_baleroc();
void AddSC_boss_majordomo_staghelm();
void AddSC_boss_ragnaros_firelands();



// End Time (CATA DUNGEON)
void AddSC_instance_end_time(); 
void AddSC_end_time();
void AddSC_end_time_teleport();
void AddSC_boss_echo_of_tyrande();
void AddSC_boss_echo_of_sylvanas();
void AddSC_boss_echo_of_baine();
void AddSC_boss_echo_of_jaina();
void AddSC_boss_murozond();


// Well of Eternity (CATA DUNGEON)
void AddSC_instance_well_of_eternity(); 
void AddSC_well_of_eternity();
void AddSC_well_of_eternity_teleport();
void AddSC_boss_perotharn();
void AddSC_boss_queen_azshara();
void AddSC_boss_mannoroth();


// Hour of Twilight (CATA DUNGEON)
void AddSC_instance_hour_of_twilight(); 
void AddSC_hour_of_twilight();
void AddSC_boss_arcurion();
void AddSC_boss_asira_dawnslayer();
void AddSC_boss_archbishop_benedictus();


// Halls of Origination
void AddSC_instance_halls_of_origination();
void AddSC_halls_of_origination();
void AddSC_boss_temple_guardian_anhuur();
void AddSC_boss_earthrager_ptah();
void AddSC_boss_anraphet();
void AddSC_boss_ammunae();
void AddSC_boss_isiset();
void AddSC_boss_setesh();
void AddSC_boss_rajh();


// Lost City of the Tol'Vir
void AddSC_instance_lost_city_of_the_tolvir(); 
void AddSC_lost_city_of_the_tolvir();
void AddSC_boss_general_husam();
void AddSC_boss_lockmaw_augh();
void AddSC_boss_high_prophet_barim();
void AddSC_boss_siamat();

// The Vortex Pinnacle
void AddSC_instance_the_vortex_pinnacle(); 
void AddSC_the_vortex_pinnacle();
void AddSC_boss_grand_vizier_ertan();
void AddSC_boss_altairus();
void AddSC_boss_asaad();


// Throne of the Four Wind (CATA RAID)
void AddSC_instance_throne_of_the_four_winds(); 
void AddSC_throne_of_the_four_winds();
void AddSC_boss_conclave_of_wind();
void AddSC_boss_alakir();

//Kalimdor Zones
void AddSC_ashenvale();
void AddSC_azshara();
void AddSC_azuremyst_isle();
void AddSC_bloodmyst_isle();
void AddSC_darkshore();
void AddSC_desolace();
void AddSC_durotar();
void AddSC_dustwallow_marsh();
void AddSC_felwood();
void AddSC_feralas();
void AddSC_moonglade();
void AddSC_mulgore();
void AddSC_orgrimmar();
void AddSC_silithus();
void AddSC_stonetalon_mountains();
void AddSC_tanaris();
void AddSC_teldrassil();
void AddSC_the_barrens();
void AddSC_thousand_needles();
void AddSC_thunder_bluff();
void AddSC_ungoro_crater();
void AddSC_winterspring();

// Northrend

void AddSC_boss_slad_ran();
void AddSC_boss_moorabi();
void AddSC_boss_drakkari_colossus();
void AddSC_boss_gal_darah();
void AddSC_boss_eck();
void AddSC_instance_gundrak();


//Azjol-Nerub
void AddSC_boss_krik_thir();
void AddSC_boss_hadronox();
void AddSC_boss_anub_arak();
void AddSC_instance_azjol_nerub();


//Ahn'kahet
void AddSC_boss_elder_nadox();
void AddSC_boss_taldaram();
void AddSC_boss_amanitar();
void AddSC_boss_jedoga_shadowseeker();
void AddSC_boss_volazj();
void AddSC_instance_ahnkahet();


// Drak'Tharon Keep
void AddSC_boss_trollgore();
void AddSC_boss_novos();
void AddSC_boss_king_dred();
void AddSC_boss_tharon_ja();
void AddSC_instance_drak_tharon_keep();


//Trial of the Champion
void AddSC_boss_argent_challenge();      
void AddSC_boss_black_knight();
void AddSC_boss_grand_champions();
void AddSC_instance_trial_of_the_champion();
void AddSC_trial_of_the_champion();

//Trial of the Crusader
void AddSC_boss_anubarak_trial();        
void AddSC_boss_faction_champions();
void AddSC_boss_jaraxxus();
void AddSC_boss_northrend_beasts();
void AddSC_boss_twin_valkyr();
void AddSC_trial_of_the_crusader();
void AddSC_instance_trial_of_the_crusader();

//Naxxramas
void AddSC_boss_anubrekhan();            
void AddSC_boss_maexxna();
void AddSC_boss_patchwerk();
void AddSC_boss_grobbulus();
void AddSC_boss_razuvious();
void AddSC_boss_kelthuzad();
void AddSC_boss_loatheb();
void AddSC_boss_noth();
void AddSC_boss_gluth();
void AddSC_boss_sapphiron();
void AddSC_boss_four_horsemen();
void AddSC_boss_faerlina();
void AddSC_boss_heigan();
void AddSC_boss_gothik();
void AddSC_boss_thaddius();
void AddSC_instance_naxxramas();

//The Nexus(dungeon)
void AddSC_boss_magus_telestra();        
void AddSC_boss_anomalus();
void AddSC_boss_ormorok();
void AddSC_boss_keristrasza();
void AddSC_instance_nexus();

//The Oculus
void AddSC_boss_drakos();                
void AddSC_boss_urom();
void AddSC_boss_varos();
void AddSC_boss_eregos();
void AddSC_instance_oculus();
void AddSC_oculus();

//The Eye of Eternity(WOTLK RAID)
void AddSC_boss_malygos();             
void AddSC_instance_eye_of_eternity();

//Obsidian Sanctum
void AddSC_boss_sartharion();            
void AddSC_instance_obsidian_sanctum();

//Halls of Lightning
void AddSC_boss_bjarngrim();             
void AddSC_boss_loken();
void AddSC_boss_ionar();
void AddSC_boss_volkhan();
void AddSC_instance_halls_of_lightning();

//Halls of Stone
void AddSC_boss_maiden_of_grief();       
void AddSC_boss_krystallus();
void AddSC_boss_sjonnir();
void AddSC_instance_halls_of_stone();
void AddSC_halls_of_stone();

//Ulduar
void AddSC_boss_auriaya();               
void AddSC_boss_flame_leviathan();
void AddSC_boss_ignis();
void AddSC_boss_razorscale();
void AddSC_boss_xt002();
void AddSC_boss_kologarn();
void AddSC_boss_assembly_of_iron();
void AddSC_boss_general_vezax();
void AddSC_ulduar_teleporter();
void AddSC_boss_mimiron();
void AddSC_boss_hodir();
void AddSC_boss_freya();
void AddSC_boss_yogg_saron();
void AddSC_boss_algalon_the_observer();
void AddSC_instance_ulduar();

//Utgarde Keep
void AddSC_boss_keleseth();
void AddSC_boss_skarvald_dalronn();
void AddSC_boss_ingvar_the_plunderer();
void AddSC_instance_utgarde_keep();
void AddSC_utgarde_keep();

//Utgarde Pinnacle
void AddSC_boss_svala();
void AddSC_boss_palehoof();
void AddSC_boss_skadi();
void AddSC_boss_ymiron();
void AddSC_instance_utgarde_pinnacle();

// Vault of Archavon
void AddSC_boss_archavon();
void AddSC_boss_emalon();
void AddSC_boss_koralon();
void AddSC_boss_toravon();
void AddSC_instance_vault_of_archavon();

//Violet Hold
void AddSC_boss_cyanigosa();            
void AddSC_boss_erekem();
void AddSC_boss_ichoron();
void AddSC_boss_lavanthor();
void AddSC_boss_moragg();
void AddSC_boss_xevozz();
void AddSC_boss_zuramat();
void AddSC_instance_violet_hold();
void AddSC_violet_hold();

//Forge of Souls
void AddSC_instance_forge_of_souls();   
void AddSC_forge_of_souls();
void AddSC_boss_bronjahm();
void AddSC_boss_devourer_of_souls();

//Pit of Saron
void AddSC_instance_pit_of_saron();     
void AddSC_pit_of_saron();
void AddSC_boss_garfrost();
void AddSC_boss_ick();
void AddSC_boss_tyrannus();

// Halls of Reflection
void AddSC_instance_halls_of_reflection();   
void AddSC_halls_of_reflection();
void AddSC_boss_falric();
void AddSC_boss_marwyn();

// Icecrown Citadel
void AddSC_boss_lord_marrowgar();      
void AddSC_boss_lady_deathwhisper();
void AddSC_boss_deathbringer_saurfang();
void AddSC_boss_festergut();
void AddSC_boss_rotface();
void AddSC_boss_professor_putricide();
void AddSC_boss_blood_prince_council();
void AddSC_boss_blood_queen_lana_thel();
void AddSC_boss_valithria_dreamwalker();
void AddSC_boss_sindragosa();
void AddSC_boss_the_lich_king();
void AddSC_icecrown_citadel_teleport();
void AddSC_instance_icecrown_citadel();
void AddSC_icecrown_citadel();

// Ruby Sanctum
void AddSC_instance_ruby_sanctum();      
void AddSC_ruby_sanctum();
void AddSC_boss_baltharus_the_warborn();
void AddSC_boss_saviana_ragefire();
void AddSC_boss_general_zarithrian();
void AddSC_boss_halion();


//Northrend Zones
void AddSC_dalaran();
void AddSC_borean_tundra();
void AddSC_dragonblight();
void AddSC_grizzly_hills();
void AddSC_howling_fjord();
void AddSC_icecrown();
void AddSC_sholazar_basin();
void AddSC_storm_peaks();
void AddSC_wintergrasp();
void AddSC_zuldrak();
void AddSC_crystalsong_forest();
void AddSC_isle_of_conquest();

// Outland

//Auchenai Crypts
void AddSC_boss_shirrak_the_dead_watcher();
void AddSC_boss_exarch_maladaar();
void AddSC_instance_auchenai_crypts();

//Mana Tombs
void AddSC_boss_pandemonius();
void AddSC_boss_nexusprince_shaffar();
void AddSC_instance_mana_tombs();

//Sekketh Halls
void AddSC_boss_darkweaver_syth();
void AddSC_boss_talon_king_ikiss();
void AddSC_boss_anzu();
void AddSC_instance_sethekk_halls();

//Shadow Labyrinth
void AddSC_boss_ambassador_hellmaw();
void AddSC_boss_blackheart_the_inciter();
void AddSC_boss_grandmaster_vorpil();
void AddSC_boss_murmur();
void AddSC_instance_shadow_labyrinth();


//Black Temple
void AddSC_black_temple();                   
void AddSC_boss_illidan();
void AddSC_boss_shade_of_akama();
void AddSC_boss_supremus();
void AddSC_boss_gurtogg_bloodboil();
void AddSC_boss_mother_shahraz();
void AddSC_boss_reliquary_of_souls();
void AddSC_boss_teron_gorefiend();
void AddSC_boss_najentus();
void AddSC_boss_illidari_council();
void AddSC_instance_black_temple();

//Serpent Shrine Cavern(BC RAID)
void AddSC_boss_fathomlord_karathress();     
void AddSC_boss_hydross_the_unstable();
void AddSC_boss_lady_vashj();
void AddSC_boss_leotheras_the_blind();
void AddSC_boss_morogrim_tidewalker();
void AddSC_instance_serpentshrine_cavern();
void AddSC_boss_the_lurker_below();

//Steam Vault
void AddSC_boss_hydromancer_thespia();       
void AddSC_boss_mekgineer_steamrigger();
void AddSC_boss_warlord_kalithresh();
void AddSC_instance_steam_vault();

//The Slave Pens
void AddSC_instance_the_slave_pens();      

//The Underbog
void AddSC_boss_hungarfen();                
void AddSC_boss_the_black_stalker();
void AddSC_instance_the_underbog();

//Gruul's Lair(BC RAID)
void AddSC_boss_gruul();                    
void AddSC_boss_high_king_maulgar();
void AddSC_instance_gruuls_lair();

//Blood Furnace
void AddSC_boss_broggok();                   
void AddSC_boss_kelidan_the_breaker();
void AddSC_boss_the_maker();
void AddSC_instance_blood_furnace();

//Magtheridon's Lair(BC RAID)
void AddSC_boss_magtheridon();               
void AddSC_instance_magtheridons_lair();

//Shattered Halls
void AddSC_boss_grand_warlock_nethekurse();  
void AddSC_boss_warbringer_omrogg();
void AddSC_boss_warchief_kargath_bladefist();
void AddSC_instance_shattered_halls();

//Hellfire Ramparts
void AddSC_boss_watchkeeper_gargolmar();    
void AddSC_boss_omor_the_unscarred();
void AddSC_boss_vazruden_the_herald();
void AddSC_instance_ramparts();

//The Arcatraz
void AddSC_arcatraz();                       
void AddSC_boss_harbinger_skyriss();
void AddSC_instance_arcatraz();

//The Botanica
void AddSC_boss_high_botanist_freywinn();    
void AddSC_boss_laj();
void AddSC_boss_warp_splinter();
void AddSC_boss_thorngrin_the_tender();
void AddSC_boss_commander_sarannis();
void AddSC_instance_the_botanica();

//The Eye(BC RAID)
void AddSC_boss_alar();                      
void AddSC_boss_kaelthas();
void AddSC_boss_void_reaver();
void AddSC_boss_high_astromancer_solarian();
void AddSC_instance_the_eye();
void AddSC_the_eye();

//The Mechanar
void AddSC_boss_gatewatcher_iron_hand();     
void AddSC_boss_gatewatcher_gyrokill();
void AddSC_boss_nethermancer_sepethrea();
void AddSC_boss_pathaleon_the_calculator();
void AddSC_boss_mechano_lord_capacitus();
void AddSC_instance_mechanar();


//Outlands Zones
void AddSC_blades_edge_mountains();
void AddSC_boss_doomlordkazzak();
void AddSC_boss_doomwalker();
void AddSC_hellfire_peninsula();
void AddSC_nagrand();
void AddSC_netherstorm();
void AddSC_shadowmoon_valley();
void AddSC_shattrath_city();
void AddSC_terokkar_forest();
void AddSC_zangarmarsh();

// Maelstrom

//The Stone Core
void AddSC_boss_corborus();
void AddSC_boss_high_priestess_azil();
void AddSC_boss_ozruk();
void AddSC_boss_slabhide();
void AddSC_instance_the_stonecore();
void AddSC_the_stonecore();

//Maelstrom Zones
void AddSC_kezan();
void AddSC_lost_isle();

// Events
void AddSC_event_childrens_week();

// Pandaria World Bosses
void AddSC_boss_ordos();
void AddSC_boss_nalak_the_storm_lord();
void AddSC_boss_oondasta();
void AddSC_boss_sha_of_anger();
void AddSC_boss_galion();
// Pandaria Zones
void AddSC_jade_forest();
void AddSC_krasarang_wilds();
void AddSC_kun_lai_summit();
void AddSC_the_veiled_stair();
void AddSC_townlong_steppes();
void AddSC_vale_of_eternal_blossoms();
void AddSC_valley_of_the_four_winds();
void AddSC_WanderingIsland_East();
void AddSC_WanderingIsland_North();
void AddSC_WanderingIsland_South();
void AddSC_WanderingIsland_West();
// Timeless Isle
void AddSC_zone_timeless_isle();
void AddSC_timeless_isle();
void AddSC_worldboss_chiji();
// Pandaria Raids :: Throne of Thunder
void AddSC_instance_ThroneOfThunder();
void AddSC_boss_Council();
void AddSC_boss_DarkAnimus();
void AddSC_boss_Durumu();
void AddSC_boss_Horridon();
void AddSC_boss_IronQon();
void AddSC_boss_JiKun();
void AddSC_boss_Jinrokh();
void AddSC_boss_LeiShen();
void AddSC_boss_Megaera();
void AddSC_boss_Primordius();
void AddSC_boss_Raden();
void AddSC_boss_Tortos();
void AddSC_boss_TwinConsorts();
// Pandaria Raids :: Terrace of the Endless Spring
void AddSC_instance_terrace_of_the_endless_spring();
void AddSC_boss_lei_shi();
void AddSC_boss_tsulong();
void AddSC_boss_sha_of_fear();
void AddSC_boss_protectors_of_the_endless();
// Pandaria Raids :: Siege of Orgrimmar
void AddSC_instance_SiegeOfOrgrimmar();
void AddSC_boss_Galakras();
void AddSC_boss_GarroshHellscream();
void AddSC_boss_GeneralNazgrim();
void AddSC_boss_IronJuggernaut();
void AddSC_boss_Immerseus();
void AddSC_boss_KorKron();
void AddSC_boss_Malkorok();
void AddSC_boss_Norushen();
void AddSC_boss_ParagonsOfTheKlaxxi();
void AddSC_boss_ShaOfPride();
void AddSC_boss_SiegecrafterBlackfuse();
void AddSC_boss_SpoilsOfPandaria();
void AddSC_boss_TheFallenProtectors();
void AddSC_boss_Thok();
// Pandaria Raids :: Mogushan Vault
void AddSC_mogu_shan_vault();
void AddSC_instance_mogu_shan_vault();
void AddSC_boss_feng();
void AddSC_boss_elegon();
void AddSC_boss_garajal();
void AddSC_boss_spirit_kings();
void AddSC_boss_stone_guard();
void AddSC_boss_will_of_emperor();
// Pandaria Raids :: Heart of Fear
void AddSC_instance_heart_of_fear();
void AddSC_boss_ambershaper_unsok();
void AddSC_boss_blade_lord_tayak();
void AddSC_boss_garalon();
void AddSC_boss_grand_empress_shekzeer();
void AddSC_boss_imperial_vizier_zorlok();
void AddSC_boss_wind_lord_meljarak();
// Pandaria Dungeons:: Gate of the Setting Sun
void AddSC_instance_gate_setting_sun();
void AddSC_boss_commander_rimok();
void AddSC_boss_raigonn();
void AddSC_boss_saboteur_kiptilak();
void AddSC_boss_striker_gadok();
// Pandaria Dungeons:: Mogushan Palace
void AddSC_instance_mogu_shan_palace();
void AddSC_boss_xin_the_weaponmaster();
void AddSC_boss_gekkan();
void AddSC_boss_trial_of_king();
// Pandaria Dungeons:: Scarlet Halls
void AddSC_instance_scarlet_halls();
void AddSC_boss_houndmaster_braun();
void AddSC_boss_flameweaver_koegler();
void AddSC_boss_armsmaster_harlan();
// Pandaria Dungeons:: Scarlet Monastery
void AddSC_boss_thalnos_the_souldrender();
void AddSC_boss_high_inquisitor_whitemane();
void AddSC_boss_brother_korloff();
// Pandaria Dungeons:: Scholomance
void AddSC_boss_rattlegore();
void AddSC_boss_lilian_voss();
void AddSC_boss_jandice_barov();
void AddSC_boss_instructor_chillheart();
void AddSC_boss_darkmaster_gandling();
// Pandaria Dungeons:: Shado'pan Monastery
void AddSC_instance_shadopan_monastery();
void AddSC_boss_taran_zhu();
void AddSC_boss_sha_of_violence();
void AddSC_boss_gu_cloudstrike();
void AddSC_boss_master_snowdrift();
// Pandaria Dungeons:: Siege of Niuzao Temple
void AddSC_instance_siege_of_niuzao_temple();
void AddSC_boss_wing_leader_neronok();
void AddSC_boss_vizier_jinbak();
void AddSC_boss_general_pavalak();
void AddSC_boss_commander_vojak();
// Pandaria Dungeons:: Stormstout Brewery
void AddSC_instance_stormstout_brewery();
void AddSC_boss_yan_zhu();
void AddSC_boss_ook_ook();
void AddSC_boss_hoptallus();
// Pandaria Dungeons:: Temple of the Jade Serpent
void AddSC_instance_temple_of_jade_serpent();
void AddSC_boss_wise_mari();
void AddSC_boss_lorewalker_stonestep();
void AddSC_boss_liu_flameheat();
void AddSC_boss_sha_of_doubt();


// Pets
void AddSC_deathknight_pet_scripts();
void AddSC_generic_pet_scripts();
void AddSC_hunter_pet_scripts();
void AddSC_mage_pet_scripts();
void AddSC_monk_pet_scripts();
void AddSC_priest_pet_scripts();
void AddSC_shaman_pet_scripts();
void AddSC_warlock_pet_scripts();
void AddSC_paladin_pet_scripts();

// battlegrounds

// outdoor pvp
void AddSC_outdoorpvp_hp();
void AddSC_outdoorpvp_na();
void AddSC_outdoorpvp_si();
void AddSC_outdoorpvp_tf();
void AddSC_outdoorpvp_zm();

// player
void AddSC_chat_log();

#endif

void AddScripts()
{
	AddExampleScripts();
	AddSpellScripts();
	AddSC_SmartSCripts();
	AddCommandScripts();
#ifdef SCRIPTS
	AddWorldScripts();
	AddEasternKingdomsScripts();
	AddKalimdorScripts();
	AddOutlandScripts();
	AddNorthrendScripts();
	AddMaelstromScripts();
	AddEventScripts();
	AddPandariaScripts();
	AddPetScripts();
	AddBattlegroundScripts();
	AddOutdoorPvPScripts();
	AddCustomScripts();
#endif
}

void AddExampleScripts()
{
	AddSC_example_creature();
	AddSC_example_escort();
	AddSC_example_gossip_codebox();
	AddSC_example_misc();
	AddSC_example_commandscript();
}

void AddSpellScripts()
{
	AddSC_deathknight_spell_scripts();
	AddSC_druid_spell_scripts();
	AddSC_generic_spell_scripts();
	AddSC_hunter_spell_scripts();
	AddSC_mage_spell_scripts();
	AddSC_monk_spell_scripts();
	AddSC_mastery_spell_scripts();
	AddSC_paladin_spell_scripts();
	AddSC_priest_spell_scripts();
	AddSC_rogue_spell_scripts();
	AddSC_shaman_spell_scripts();
	AddSC_warlock_spell_scripts();
	AddSC_warrior_spell_scripts();
	AddSC_quest_spell_scripts();
	AddSC_item_spell_scripts();
	AddSC_example_spell_scripts();
	AddSC_holiday_spell_scripts();
}

void AddCommandScripts()
{
	AddSC_account_commandscript();
	AddSC_achievement_commandscript();
	AddSC_ban_commandscript();
	AddSC_bf_commandscript();
	AddSC_cast_commandscript();
	AddSC_character_commandscript();
	AddSC_cheat_commandscript();
	AddSC_debug_commandscript();
	AddSC_deserter_commandscript();
	AddSC_disable_commandscript();
	AddSC_event_commandscript();
	AddSC_gm_commandscript();
	AddSC_go_commandscript();
	AddSC_gobject_commandscript();
	AddSC_group_commandscript();
	AddSC_guild_commandscript();
	AddSC_honor_commandscript();
	AddSC_instance_commandscript();
	AddSC_learn_commandscript();
	AddSC_lookup_commandscript();
	AddSC_lfg_commandscript();
	AddSC_list_commandscript();
	AddSC_message_commandscript();
	AddSC_misc_commandscript();
	AddSC_mmaps_commandscript();
	AddSC_modify_commandscript();
	AddSC_npc_commandscript();
	AddSC_quest_commandscript();
	AddSC_pet_commandscript();
	AddSC_rbac_commandscript();
	AddSC_reload_commandscript();
	AddSC_reset_commandscript();
	AddSC_send_commandscript();
	AddSC_server_commandscript();
	AddSC_tele_commandscript();
	AddSC_ticket_commandscript();
	AddSC_titles_commandscript();
	AddSC_wp_commandscript();
}

void AddWorldScripts()
{
#ifdef SCRIPTS
	AddSC_areatrigger_scripts();
	AddSC_emerald_dragons();
	AddSC_generic_creature();
	AddSC_go_scripts();
	AddSC_guards();
	AddSC_item_scripts();
	AddSC_npc_professions();
	AddSC_npc_innkeeper();
	AddSC_npcs_special();
	AddSC_npc_taxi();
	AddSC_achievement_scripts();
	AddSC_chat_log();
	AddSC_player_scripts();
#endif
}

void AddEasternKingdomsScripts()
{
#ifdef SCRIPTS

	//Alterac Valley
	AddSC_alterac_valley();                 
	AddSC_boss_balinda();
	AddSC_boss_drekthar();
	AddSC_boss_galvangar();
	AddSC_boss_vanndar();

	//Baradin Hold
	AddSC_boss_alizabal();                  
	AddSC_boss_occuthar();
	AddSC_boss_pit_lord_argaloth();
	AddSC_instance_baradin_hold();

	//Blackrock Depths
	AddSC_blackrock_depths();               
	AddSC_boss_ambassador_flamelash();
	AddSC_boss_anubshiah();
	AddSC_boss_draganthaurissan();
	AddSC_boss_general_angerforge();
	AddSC_boss_gorosh_the_dervish();
	AddSC_boss_grizzle();
	AddSC_boss_high_interrogator_gerstahn();
	AddSC_boss_magmus();
	AddSC_boss_moira_bronzebeard();
	AddSC_boss_tomb_of_seven();
	AddSC_instance_blackrock_depths();

	//Blackrock Spire
	AddSC_boss_drakkisath();                
	AddSC_boss_halycon();
	AddSC_boss_highlordomokk();
	AddSC_boss_mothersmolderweb();
	AddSC_boss_overlordwyrmthalak();
	AddSC_boss_shadowvosh();
	AddSC_boss_thebeast();
	AddSC_boss_warmastervoone();
	AddSC_boss_quatermasterzigris();
	AddSC_boss_pyroguard_emberseer();
	AddSC_boss_gyth();
	AddSC_boss_rend_blackhand();
	AddSC_boss_gizrul_the_slavener();
	AddSC_boss_urok_doomhowl();
	AddSC_boss_lord_valthalak();
	AddSC_instance_blackrock_spire();

	//Blackwing lair
	AddSC_boss_razorgore();                 
	AddSC_boss_vaelastrasz();
	AddSC_boss_broodlord();
	AddSC_boss_firemaw();
	AddSC_boss_ebonroc();
	AddSC_boss_flamegor();
	AddSC_boss_chromaggus();
	AddSC_boss_nefarian();
	AddSC_instance_blackwing_lair();

	//Deadmines
	AddSC_deadmines();                      
	AddSC_instance_deadmines();
	AddSC_boss_admiral_ripsnarl();
	AddSC_boss_captain_cookie();
	AddSC_boss_foereaper5000();
	AddSC_boss_glubtok();
	AddSC_boss_helix_gearbreaker();
	AddSC_boss_vanessa_vancleef();

	//Gnomeregan
	AddSC_gnomeregan();                     
	AddSC_instance_gnomeregan();

	//Karazhan
	AddSC_boss_attumen();                  
	AddSC_boss_curator();
	AddSC_boss_maiden_of_virtue();
	AddSC_boss_shade_of_aran();
	AddSC_boss_malchezaar();
	AddSC_boss_terestian_illhoof();
	AddSC_boss_moroes();
	AddSC_bosses_opera();
	AddSC_boss_netherspite();
	AddSC_instance_karazhan();
	AddSC_karazhan();
	AddSC_boss_nightbane();

	// Magister's Terrace
	AddSC_boss_felblood_kaelthas();         
	AddSC_boss_selin_fireheart();
	AddSC_boss_vexallus();
	AddSC_boss_priestess_delrissa();
	AddSC_instance_magisters_terrace();
	AddSC_magisters_terrace();

	//Molten core
	AddSC_boss_lucifron();                  
	AddSC_boss_magmadar();
	AddSC_boss_gehennas();
	AddSC_boss_garr();
	AddSC_boss_baron_geddon();
	AddSC_boss_shazzrah();
	AddSC_boss_golemagg();
	AddSC_boss_sulfuron();
	AddSC_boss_majordomo();
	AddSC_boss_ragnaros();
	AddSC_instance_molten_core();

	//Ragefire Chasm
	AddSC_instance_ragefire_chasm();        

	//Scarlet Enclave
	AddSC_the_scarlet_enclave();            
	AddSC_the_scarlet_enclave_c1();
	AddSC_the_scarlet_enclave_c2();
	AddSC_the_scarlet_enclave_c5();

	//Shadowfang keep
	AddSC_shadowfang_keep();
	AddSC_instance_shadowfang_keep();
	AddSC_boss_baron_ashbury();
	AddSC_boss_baron_silverlaine();
	AddSC_boss_commander_springvale();
	AddSC_boss_lord_godfrey();
	AddSC_boss_lord_valden();

	//Stratholme
	AddSC_boss_magistrate_barthilas();      
	AddSC_boss_maleki_the_pallid();
	AddSC_boss_nerubenkan();
	AddSC_boss_cannon_master_willey();
	AddSC_boss_baroness_anastari();
	AddSC_boss_ramstein_the_gorger();
	AddSC_boss_timmy_the_cruel();
	AddSC_boss_postmaster_malown();
	AddSC_boss_baron_rivendare();
	AddSC_boss_dathrohan_balnazzar();
	AddSC_boss_order_of_silver_hand();
	AddSC_instance_stratholme();
	AddSC_stratholme();

	// Sunken Temple
	AddSC_sunken_temple();                  
	AddSC_instance_sunken_temple();

	//Sunwell Plateau
	AddSC_instance_sunwell_plateau();      
	AddSC_boss_kalecgos();
	AddSC_boss_brutallus();
	AddSC_boss_felmyst();
	AddSC_boss_eredar_twins();
	AddSC_boss_muru();
	AddSC_boss_kiljaeden();
	AddSC_sunwell_plateau();

	//The Stockade
	AddSC_instance_the_stockade();          

	//Uldaman
	AddSC_boss_archaedas();                 
	AddSC_boss_ironaya();
	AddSC_uldaman();
	AddSC_instance_uldaman();

	//Zul'Aman(CATA DUNGEON)
	AddSC_boss_akilzon();                   
	AddSC_boss_halazzi();
	AddSC_boss_hex_lord_malacrass();
	AddSC_boss_janalai();
	AddSC_boss_nalorakk();
	AddSC_boss_daakara();
	AddSC_instance_zulaman();
	AddSC_zulaman();

	// Zul'Gurub(CATA DUNGEON)
	AddSC_boss_grilek();                   
	AddSC_boss_hazzarah();
	AddSC_boss_jindo_the_godbreaker();
	AddSC_boss_kilnara();
	AddSC_boss_mandokir();
	AddSC_boss_renataki();
	AddSC_boss_venoxis();
	AddSC_boss_wushoolay();
	AddSC_boss_zanzil();
	AddSC_instance_zulgurub();


	//Bastion of Twilight (CATA RAID)
	AddSC_bastion_of_twilight();
	AddSC_boss_chogall();
	AddSC_boss_ascendant_council();
	AddSC_boss_halfus_wyrmbreaker();
	AddSC_boss_sinestra();
	AddSC_boss_theralion_and_valiona();
	AddSC_instance_bastion_of_twilight();

	//Blackwing Descent(CATA RAID)
	AddSC_blackwing_descent();
	AddSC_boss_atramedes();
	AddSC_boss_chimaeron();
	AddSC_boss_magmaw();
	AddSC_boss_maloriak();
	AddSC_boss_omnotron_defence_system();
	AddSC_instance_blackwing_descent();

	//Grim Batol (CATA DUNGEON)
	AddSC_boss_drahga_shadowburner();
	AddSC_boss_erudax();
	AddSC_boss_forgemaster_throngus();
	AddSC_boss_general_umbriss();
	AddSC_grim_batol();
	AddSC_instance_grim_batol();

	//The Throne of Tides (CATA DUNGEON)
	AddSC_boss_commander_ulthok();
	AddSC_boss_lady_nazjar();
	AddSC_boss_erunak_stonespeaker();
	AddSC_boss_ozumat();
	AddSC_instance_throne_of_the_tides();
	AddSC_throne_of_the_tides();

	

	//Eastern Kingdoms Zones
	AddSC_alterac_mountains();
	AddSC_arathi_highlands();
	AddSC_blasted_lands();
	AddSC_burning_steppes();
	AddSC_duskwood();
	AddSC_eastern_plaguelands();
	AddSC_eversong_woods();
	AddSC_ghostlands();
	AddSC_hinterlands();
	AddSC_ironforge();
	AddSC_isle_of_queldanas();
	AddSC_loch_modan();
	AddSC_redridge_mountains();
	AddSC_silverpine_forest();
	AddSC_stormwind_city();
	AddSC_stranglethorn_vale();
	AddSC_swamp_of_sorrows();
	AddSC_tirisfal_glades();
	AddSC_undercity();
	AddSC_western_plaguelands();
	AddSC_westfall();
	AddSC_wetlands();
	AddSC_dun_morogh();
	AddSC_elwyn_forest();
	AddSC_silvermoon_city();

#endif
}

void AddKalimdorScripts()
{
#ifdef SCRIPTS

	//Blackfathom Depths
	AddSC_blackfathom_deeps();              
	AddSC_boss_gelihast();
	AddSC_boss_kelris();
	AddSC_boss_aku_mai();
	AddSC_instance_blackfathom_deeps();

    //Battle for Mt.Hyjal(BC RAID)
	AddSC_hyjal();                          
	AddSC_boss_archimonde();
	AddSC_instance_mount_hyjal();
	AddSC_hyjal_trash();
	AddSC_boss_rage_winterchill();
	AddSC_boss_anetheron();
	AddSC_boss_kazrogal();
	AddSC_boss_azgalor();

	//Old Hillsbrad
	AddSC_boss_captain_skarloc();           
	AddSC_boss_epoch_hunter();
	AddSC_boss_lieutenant_drake();
	AddSC_instance_old_hillsbrad();
	AddSC_old_hillsbrad();

	//The Black Morass
	AddSC_boss_aeonus();                    
	AddSC_boss_chrono_lord_deja();
	AddSC_boss_temporus();
	AddSC_the_black_morass();
	AddSC_instance_the_black_morass();

	//Culling Of Stratholme
	AddSC_boss_epoch();                     
	AddSC_boss_infinite_corruptor();
	AddSC_boss_salramm();
	AddSC_boss_mal_ganis();
	AddSC_boss_meathook();
	AddSC_culling_of_stratholme();
	AddSC_instance_culling_of_stratholme();

	//Dire Maul
	AddSC_instance_dire_maul();        

	//Maraudon
	AddSC_boss_celebras_the_cursed();       
	AddSC_boss_landslide();
	AddSC_boss_noxxion();
	AddSC_boss_ptheradras();
	AddSC_instance_maraudon();

	//Onyxia's Lair
	AddSC_boss_onyxia();                    
	AddSC_instance_onyxias_lair();

	//Razorfen Downs
	AddSC_boss_amnennar_the_coldbringer();  
	AddSC_razorfen_downs();
	AddSC_instance_razorfen_downs();

	//Razorfen Kraul
	AddSC_razorfen_kraul();                 
	AddSC_instance_razorfen_kraul();

	//Ruins of ahn'qiraj
	AddSC_boss_kurinnaxx();                 
	AddSC_boss_rajaxx();
	AddSC_boss_moam();
	AddSC_boss_buru();
	AddSC_boss_ayamiss();
	AddSC_boss_ossirian();
	AddSC_instance_ruins_of_ahnqiraj();

	//Temple of ahn'qiraj
	AddSC_boss_cthun();                    
	AddSC_boss_viscidus();
	AddSC_boss_fankriss();
	AddSC_boss_huhuran();
	AddSC_bug_trio();
	AddSC_boss_sartura();
	AddSC_boss_skeram();
	AddSC_boss_twinemperors();
	AddSC_boss_ouro();
	AddSC_npc_anubisath_sentinel();
	AddSC_instance_temple_of_ahnqiraj();

	//Wailing caverns
	AddSC_wailing_caverns();                
	AddSC_instance_wailing_caverns();

	//Zul'Farrak
	AddSC_boss_zum_rah();                   
	AddSC_zulfarrak();
	AddSC_instance_zulfarrak();

	//Kailmador Zones
	AddSC_ashenvale();
	AddSC_azshara();
	AddSC_azuremyst_isle();
	AddSC_bloodmyst_isle();
	AddSC_darkshore();
	AddSC_desolace();
	AddSC_durotar();
	AddSC_dustwallow_marsh();
	AddSC_felwood();
	AddSC_feralas();
	AddSC_moonglade();
	AddSC_mulgore();
	AddSC_orgrimmar();
	AddSC_silithus();
	AddSC_stonetalon_mountains();
	AddSC_tanaris();
	AddSC_teldrassil();
	AddSC_the_barrens();
	AddSC_thousand_needles();
	AddSC_thunder_bluff();
	AddSC_ungoro_crater();
	AddSC_winterspring();

	

	//Firelands(CATA RAID)
	AddSC_instance_firelands();
	AddSC_boss_alysrazor();

	//Dragon Soul(CATA RAID)
	AddSC_instance_dragon_soul();
	AddSC_dragon_soul();
	AddSC_boss_morchok();
	AddSC_boss_yorsahj_the_unsleeping();
	AddSC_boss_warlord_zonozz();
	AddSC_boss_hagara_the_stormbinder();
	AddSC_boss_ultraxion();
	AddSC_boss_warmaster_blackhorn();
	AddSC_spine_of_deathwing();
	AddSC_madness_of_deathwing();

	// End Time(CATA DUNGEON)
    AddSC_instance_end_time(); 
	AddSC_end_time();
	AddSC_end_time_teleport();
	AddSC_boss_echo_of_tyrande();
	AddSC_boss_echo_of_sylvanas();
	AddSC_boss_echo_of_baine();
	AddSC_boss_echo_of_jaina();
	AddSC_boss_murozond();

	// Well of Eternity(CATA DUNGEON)
	AddSC_instance_well_of_eternity(); 
	AddSC_well_of_eternity();
	AddSC_well_of_eternity_teleport();
	AddSC_boss_perotharn();
	AddSC_boss_queen_azshara();
	AddSC_boss_mannoroth();

	// Hour of Twilight (CATA DUNGEON)
	AddSC_instance_hour_of_twilight(); 
	AddSC_hour_of_twilight();
	AddSC_boss_arcurion();
	AddSC_boss_asira_dawnslayer();
	AddSC_boss_archbishop_benedictus();

	// Firelands (CATA RAID)
	AddSC_instance_firelands(); 
	AddSC_firelands();
	AddSC_boss_shannox();
	AddSC_boss_bethtilac();
	AddSC_boss_alysrazor();
	AddSC_boss_lord_rhyolith();
	AddSC_boss_baleroc();
	AddSC_boss_majordomo_staghelm();
	AddSC_boss_ragnaros_firelands();


	// Halls of Origination (CATA DUNGEON)
	AddSC_instance_halls_of_origination(); 
	AddSC_halls_of_origination();
	AddSC_boss_temple_guardian_anhuur();
	AddSC_boss_earthrager_ptah();
	AddSC_boss_anraphet();
	AddSC_boss_ammunae();
	AddSC_boss_isiset();
	AddSC_boss_setesh();
	AddSC_boss_rajh();


	// Lost City of the Tol'Vir(CATA DUNGEON)
	AddSC_instance_lost_city_of_the_tolvir(); 
	AddSC_lost_city_of_the_tolvir();
	AddSC_boss_general_husam();
	AddSC_boss_lockmaw_augh();
	AddSC_boss_high_prophet_barim();
	AddSC_boss_siamat();

	// The Vortex Pinnacle
	AddSC_instance_the_vortex_pinnacle(); 
	AddSC_the_vortex_pinnacle();
	AddSC_boss_grand_vizier_ertan();
	AddSC_boss_altairus();
	AddSC_boss_asaad();

	// Throne of the Four Wind (CATA RAID)
	AddSC_instance_throne_of_the_four_winds();
	AddSC_throne_of_the_four_winds();
	AddSC_boss_conclave_of_wind();
	AddSC_boss_alakir();

#endif
}

void AddOutlandScripts()
{
#ifdef SCRIPTS
	//Auchenai Crypts
	AddSC_boss_shirrak_the_dead_watcher();
	AddSC_boss_exarch_maladaar();
	AddSC_instance_auchenai_crypts();

	//Mana Tombs
	AddSC_boss_pandemonius();
	AddSC_boss_nexusprince_shaffar();
	AddSC_instance_mana_tombs();

	//Sekketh Halls
	AddSC_boss_darkweaver_syth();
	AddSC_boss_talon_king_ikiss();
	AddSC_boss_anzu();
	AddSC_instance_sethekk_halls();

	//Shadow Labyrinth
	AddSC_boss_ambassador_hellmaw();
	AddSC_boss_blackheart_the_inciter();
	AddSC_boss_grandmaster_vorpil();
	AddSC_boss_murmur();
	AddSC_instance_shadow_labyrinth();


	//Black Temple
	AddSC_black_temple();                   
	AddSC_boss_illidan();
	AddSC_boss_shade_of_akama();
	AddSC_boss_supremus();
	AddSC_boss_gurtogg_bloodboil();
	AddSC_boss_mother_shahraz();
	AddSC_boss_reliquary_of_souls();
	AddSC_boss_teron_gorefiend();
	AddSC_boss_najentus();
	AddSC_boss_illidari_council();
	AddSC_instance_black_temple();

	//Serpent Shrine Cavern(BC RAID)
	AddSC_boss_fathomlord_karathress();     
	AddSC_boss_hydross_the_unstable();
	AddSC_boss_lady_vashj();
	AddSC_boss_leotheras_the_blind();
	AddSC_boss_morogrim_tidewalker();
	AddSC_instance_serpentshrine_cavern();
	AddSC_boss_the_lurker_below();

	//Steam Vault
	AddSC_boss_hydromancer_thespia();       
	AddSC_boss_mekgineer_steamrigger();
	AddSC_boss_warlord_kalithresh();
	AddSC_instance_steam_vault();

	//The Slave Pens
	AddSC_instance_the_slave_pens();            

	//The Underbog
	AddSC_boss_hungarfen();                 
	AddSC_boss_the_black_stalker();
	AddSC_instance_the_underbog();

	//Gruul's Lair
	AddSC_boss_gruul();                     
	AddSC_boss_high_king_maulgar();
	AddSC_instance_gruuls_lair();

	//Blood Furnace
	AddSC_boss_broggok();                   
	AddSC_boss_kelidan_the_breaker();
	AddSC_boss_the_maker();
	AddSC_instance_blood_furnace();

	//Magtheridon's Lair(BC RAID)
	AddSC_boss_magtheridon();              
	AddSC_instance_magtheridons_lair();

	//Shattered Halls
	AddSC_boss_grand_warlock_nethekurse();  
	AddSC_boss_warbringer_omrogg();
	AddSC_boss_warchief_kargath_bladefist();
	AddSC_instance_shattered_halls();

    //hellfire Ramparts
	AddSC_boss_watchkeeper_gargolmar();     
	AddSC_boss_omor_the_unscarred();
	AddSC_boss_vazruden_the_herald();
	AddSC_instance_ramparts();

	//Arcatraz
	AddSC_arcatraz();                       
	AddSC_boss_harbinger_skyriss();
	AddSC_instance_arcatraz();

	//The Botanica
	AddSC_boss_high_botanist_freywinn();    
	AddSC_boss_laj();
	AddSC_boss_warp_splinter();
	AddSC_boss_thorngrin_the_tender();
	AddSC_boss_commander_sarannis();
	AddSC_instance_the_botanica();

	//The Eye(BC RAID, Tempest Keep)
	AddSC_boss_alar();                      
	AddSC_boss_kaelthas();
	AddSC_boss_void_reaver();
	AddSC_boss_high_astromancer_solarian();
	AddSC_instance_the_eye();
	AddSC_the_eye();

	//The Mechanar
	AddSC_boss_gatewatcher_iron_hand();     
	AddSC_boss_gatewatcher_gyrokill();
	AddSC_boss_nethermancer_sepethrea();
	AddSC_boss_pathaleon_the_calculator();
	AddSC_boss_mechano_lord_capacitus();
	AddSC_instance_mechanar();


    //Outlands Zones
	AddSC_blades_edge_mountains();
	AddSC_boss_doomlordkazzak();
	AddSC_boss_doomwalker();
	AddSC_hellfire_peninsula();
	AddSC_nagrand();
	AddSC_netherstorm();
	AddSC_shadowmoon_valley();
	AddSC_shattrath_city();
	AddSC_terokkar_forest();
	AddSC_zangarmarsh();
#endif
}

void AddNorthrendScripts()
{
#ifdef SCRIPTS

	//Gundrak
	AddSC_boss_slad_ran();               
	AddSC_boss_moorabi();
	AddSC_boss_drakkari_colossus();
	AddSC_boss_gal_darah();
	AddSC_boss_eck();
	AddSC_instance_gundrak();

	//Ahn'kahet
	AddSC_boss_elder_nadox();
	AddSC_boss_taldaram();
	AddSC_boss_amanitar();
	AddSC_boss_jedoga_shadowseeker();
	AddSC_boss_volazj();
	AddSC_instance_ahnkahet();

	// Azjol-Nerub
	AddSC_boss_krik_thir();
	AddSC_boss_hadronox();
	AddSC_boss_anub_arak();
	AddSC_instance_azjol_nerub();

	// Drak'Tharon Keep
	AddSC_boss_trollgore();
	AddSC_boss_novos();
	AddSC_boss_king_dred();
	AddSC_boss_tharon_ja();
	AddSC_instance_drak_tharon_keep();


	//Trial of the Champion
	AddSC_boss_argent_challenge();      
	AddSC_boss_black_knight();
	AddSC_boss_grand_champions();
	AddSC_instance_trial_of_the_champion();
	AddSC_trial_of_the_champion();

	//Trial of the Crusader
	AddSC_boss_anubarak_trial();        
	AddSC_boss_faction_champions();
	AddSC_boss_jaraxxus();
	AddSC_trial_of_the_crusader();
	AddSC_boss_twin_valkyr();
	AddSC_boss_northrend_beasts();
	AddSC_instance_trial_of_the_crusader();

	//Naxxramas
	AddSC_boss_anubrekhan();           
	AddSC_boss_maexxna();
	AddSC_boss_patchwerk();
	AddSC_boss_grobbulus();
	AddSC_boss_razuvious();
	AddSC_boss_kelthuzad();
	AddSC_boss_loatheb();
	AddSC_boss_noth();
	AddSC_boss_gluth();
	AddSC_boss_sapphiron();
	AddSC_boss_four_horsemen();
	AddSC_boss_faerlina();
	AddSC_boss_heigan();
	AddSC_boss_gothik();
	AddSC_boss_thaddius();
	AddSC_instance_naxxramas();

	//The Nexus(dungeon)
	AddSC_boss_magus_telestra();        
	AddSC_boss_anomalus();
	AddSC_boss_ormorok();
	AddSC_boss_keristrasza();
	AddSC_instance_nexus();

	//The Oculus
	AddSC_boss_drakos();                
	AddSC_boss_urom();
	AddSC_boss_varos();
	AddSC_boss_eregos();
	AddSC_instance_oculus();
	AddSC_oculus();

	//The Eye of Eternity(WOTLK RAID)
	AddSC_boss_malygos();             
	AddSC_instance_eye_of_eternity();

	//Obsidian Sanctum
	AddSC_boss_sartharion();            
	AddSC_instance_obsidian_sanctum();

	//Halls of Lightning
	AddSC_boss_bjarngrim();             
	AddSC_boss_loken();
	AddSC_boss_ionar();
	AddSC_boss_volkhan();
	AddSC_instance_halls_of_lightning();

	//Halls of Stone
	AddSC_boss_maiden_of_grief();       
	AddSC_boss_krystallus();
	AddSC_boss_sjonnir();
	AddSC_instance_halls_of_stone();
	AddSC_halls_of_stone();

	//Ulduar
	AddSC_boss_auriaya();               
	AddSC_boss_flame_leviathan();
	AddSC_boss_ignis();
	AddSC_boss_razorscale();
	AddSC_boss_xt002();
	AddSC_boss_general_vezax();
	AddSC_boss_assembly_of_iron();
	AddSC_boss_kologarn();
	AddSC_ulduar_teleporter();
	AddSC_boss_mimiron();
	AddSC_boss_hodir();
	AddSC_boss_freya();
	AddSC_boss_yogg_saron();
	AddSC_boss_algalon_the_observer();
	AddSC_instance_ulduar();

	// Utgarde Keep
	AddSC_boss_keleseth();
	AddSC_boss_skarvald_dalronn();
	AddSC_boss_ingvar_the_plunderer();
	AddSC_instance_utgarde_keep();
	AddSC_utgarde_keep();

	//Utgarde Pinnacle
	AddSC_boss_svala();
	AddSC_boss_palehoof();
	AddSC_boss_skadi();
	AddSC_boss_ymiron();
	AddSC_instance_utgarde_pinnacle();

	// Vault of Archavon
	AddSC_boss_archavon();
	AddSC_boss_emalon();
	AddSC_boss_koralon();
	AddSC_boss_toravon();
	AddSC_instance_vault_of_archavon();


	//Violet Hold
	AddSC_boss_cyanigosa();             
	AddSC_boss_erekem();
	AddSC_boss_ichoron();
	AddSC_boss_lavanthor();
	AddSC_boss_moragg();
	AddSC_boss_xevozz();
	AddSC_boss_zuramat();
	AddSC_instance_violet_hold();
	AddSC_violet_hold();

	//Forge of Souls
	AddSC_instance_forge_of_souls();   
	AddSC_forge_of_souls();
	AddSC_boss_bronjahm();
	AddSC_boss_devourer_of_souls();

	//Pit of Saron
	AddSC_instance_pit_of_saron();      
	AddSC_pit_of_saron();
	AddSC_boss_garfrost();
	AddSC_boss_ick();
	AddSC_boss_tyrannus();

	// Halls of Reflection
	AddSC_instance_halls_of_reflection();   
	AddSC_halls_of_reflection();
	AddSC_boss_falric();
	AddSC_boss_marwyn();

	// Icecrown Citadel
	AddSC_boss_lord_marrowgar();        
	AddSC_boss_lady_deathwhisper();
	AddSC_boss_deathbringer_saurfang();
	AddSC_boss_festergut();
	AddSC_boss_rotface();
	AddSC_boss_professor_putricide();
	AddSC_boss_blood_prince_council();
	AddSC_boss_blood_queen_lana_thel();
	AddSC_boss_valithria_dreamwalker();
	AddSC_boss_sindragosa();
	AddSC_boss_the_lich_king();
	AddSC_icecrown_citadel_teleport();
	AddSC_instance_icecrown_citadel();
	AddSC_icecrown_citadel();

	// Ruby Sanctum
	AddSC_instance_ruby_sanctum();     
	AddSC_ruby_sanctum();
	AddSC_boss_baltharus_the_warborn();
	AddSC_boss_saviana_ragefire();
	AddSC_boss_general_zarithrian();
	AddSC_boss_halion();

	//Northrend Zones
	AddSC_dalaran();
	AddSC_borean_tundra();
	AddSC_dragonblight();
	AddSC_grizzly_hills();
	AddSC_howling_fjord();
	AddSC_icecrown();
	AddSC_sholazar_basin();
	AddSC_storm_peaks();
	AddSC_wintergrasp();
	AddSC_zuldrak();
	AddSC_crystalsong_forest();
	AddSC_isle_of_conquest();
#endif
}


void AddMaelstromScripts()
{
#ifdef SCRIPTS

	//The Stone Core
	AddSC_boss_corborus();
	AddSC_boss_high_priestess_azil();
	AddSC_boss_ozruk();
	AddSC_boss_slabhide();
	AddSC_instance_the_stonecore();
	AddSC_the_stonecore();

	//Maelstrom Zones
	AddSC_kezan();
	AddSC_lost_isle();
#endif
}

void AddEventScripts()
{
#ifdef SCRIPTS
	AddSC_event_childrens_week();
#endif
}

void AddPandariaScripts()
{
#ifdef SCRIPTS
	// Temple of Jade Serpent
	AddSC_instance_temple_of_jade_serpent();
	AddSC_boss_wise_mari();
	AddSC_boss_lorewalker_stonestep();
	AddSC_boss_liu_flameheat();
	AddSC_boss_sha_of_doubt();
	// Pandaria World Bosses
	AddSC_boss_ordos();
	AddSC_boss_nalak_the_storm_lord();
	AddSC_boss_oondasta();
	AddSC_boss_sha_of_anger();
	AddSC_boss_galion();
	// Pandaria Zones
	AddSC_jade_forest();
	AddSC_krasarang_wilds();
	AddSC_kun_lai_summit();
	AddSC_the_veiled_stair();
	AddSC_townlong_steppes();
	AddSC_vale_of_eternal_blossoms();
	AddSC_valley_of_the_four_winds();
	AddSC_WanderingIsland_East();
	AddSC_WanderingIsland_North();
	AddSC_WanderingIsland_South();
	AddSC_WanderingIsland_West();
	// Timeless Isle
	AddSC_zone_timeless_isle();
	AddSC_timeless_isle();
	AddSC_worldboss_chiji();
	// Pandaria Raids :: Throne of Thunder
	AddSC_instance_ThroneOfThunder();
	AddSC_boss_Council();
	AddSC_boss_DarkAnimus();
	AddSC_boss_Durumu();
	AddSC_boss_Horridon();
	AddSC_boss_IronQon();
	AddSC_boss_JiKun();
	AddSC_boss_Jinrokh();
	AddSC_boss_LeiShen();
	AddSC_boss_Megaera();
	AddSC_boss_Primordius();
	AddSC_boss_Raden();
	AddSC_boss_Tortos();
	AddSC_boss_TwinConsorts();
	// Pandaria Raids :: Terrace of the Endless Spring
	AddSC_instance_terrace_of_the_endless_spring();
	AddSC_boss_lei_shi();
	AddSC_boss_tsulong();
	AddSC_boss_sha_of_fear();
	AddSC_boss_protectors_of_the_endless();
	// Pandaria Raids :: Siege of Orgrimmar
	AddSC_instance_SiegeOfOrgrimmar();
	AddSC_boss_Galakras();
	AddSC_boss_GarroshHellscream();
	AddSC_boss_GeneralNazgrim();
	AddSC_boss_IronJuggernaut();
	AddSC_boss_Immerseus();
	AddSC_boss_KorKron();
	AddSC_boss_Malkorok();
	AddSC_boss_Norushen();
	AddSC_boss_ParagonsOfTheKlaxxi();
	AddSC_boss_ShaOfPride();
	AddSC_boss_SiegecrafterBlackfuse();
	AddSC_boss_SpoilsOfPandaria();
	AddSC_boss_TheFallenProtectors();
	AddSC_boss_Thok();
	// Pandaria Raids :: Mogushan Vault
	AddSC_mogu_shan_vault();
	AddSC_instance_mogu_shan_vault();
	AddSC_boss_feng();
	AddSC_boss_elegon();
	AddSC_boss_garajal();
	AddSC_boss_spirit_kings();
	AddSC_boss_stone_guard();
	AddSC_boss_will_of_emperor();
	// Pandaria Raids :: Heart of Fear
	AddSC_instance_heart_of_fear();
	AddSC_boss_ambershaper_unsok();
	AddSC_boss_blade_lord_tayak();
	AddSC_boss_garalon();
	AddSC_boss_grand_empress_shekzeer();
	AddSC_boss_imperial_vizier_zorlok();
	AddSC_boss_wind_lord_meljarak();
	// Pandaria Dungeons:: Gate of the Setting Sun
	AddSC_instance_gate_setting_sun();
	AddSC_boss_commander_rimok();
	AddSC_boss_raigonn();
	AddSC_boss_saboteur_kiptilak();
	AddSC_boss_striker_gadok();
	// Pandaria Dungeons:: Mogushan Palace
	AddSC_instance_mogu_shan_palace();
	AddSC_boss_xin_the_weaponmaster();
	AddSC_boss_gekkan();
	AddSC_boss_trial_of_king();
	// Pandaria Dungeons:: Scarlet Halls
	AddSC_instance_scarlet_halls();
	AddSC_boss_houndmaster_braun();
	AddSC_boss_flameweaver_koegler();
	AddSC_boss_armsmaster_harlan();
	// Pandaria Dungeons:: Scarlet Monastery
	AddSC_boss_thalnos_the_souldrender();
	AddSC_boss_high_inquisitor_whitemane();
	AddSC_boss_brother_korloff();
	// Pandaria Dungeons:: Scholomance
	AddSC_boss_rattlegore();
	AddSC_boss_lilian_voss();
	AddSC_boss_instructor_chillheart();
	AddSC_boss_darkmaster_gandling();
	// Pandaria Dungeons:: Shado'pan Monastery
	AddSC_instance_shadopan_monastery();
	AddSC_boss_taran_zhu();
	AddSC_boss_sha_of_violence();
	AddSC_boss_gu_cloudstrike();
	AddSC_boss_master_snowdrift();
	// Pandaria Dungeons:: Siege of Niuzao Temple
	AddSC_instance_siege_of_niuzao_temple();
	AddSC_boss_wing_leader_neronok();
	AddSC_boss_vizier_jinbak();
	AddSC_boss_general_pavalak();
	AddSC_boss_commander_vojak();
	// Pandaria Dungeons:: Stormstout Brewery
	AddSC_instance_stormstout_brewery();
	AddSC_boss_yan_zhu();
	AddSC_boss_ook_ook();
	AddSC_boss_hoptallus();
#endif
}

void AddPetScripts()
{
#ifdef SCRIPTS
	AddSC_deathknight_pet_scripts();
	AddSC_generic_pet_scripts();
	AddSC_hunter_pet_scripts();
	AddSC_mage_pet_scripts();
	AddSC_monk_pet_scripts();
	AddSC_priest_pet_scripts();
	AddSC_shaman_pet_scripts();
	AddSC_warlock_pet_scripts();
	AddSC_paladin_pet_scripts();
#endif
}

void AddOutdoorPvPScripts()
{
#ifdef SCRIPTS
	AddSC_outdoorpvp_hp();
	AddSC_outdoorpvp_na();
	AddSC_outdoorpvp_si();
	AddSC_outdoorpvp_tf();
	AddSC_outdoorpvp_zm();
#endif
}

void AddBattlegroundScripts()
{
#ifdef SCRIPTS
#endif
}

#ifdef SCRIPTS
/* This is where custom scripts' loading functions should be declared. */
/*
void AddSC_Npc_Beastmaster();
void AddSC_npc_changer();
void AddSC_world_chat();
void AddSC_Duel_Reset();
void AddSC_Morph_npc();
void AddSC_Professions_NPC();
void AddSC_tele();
void AddSC_npc_global_trainer();
void AddSC_npc_enchantment();
void AddSC_player_loginscript();
*/
#endif

void AddCustomScripts()
{
#ifdef SCRIPTS
	/* This is where custom scripts should be added. */
	/*
	AddSC_Npc_Beastmaster();
	AddSC_npc_changer();
	AddSC_world_chat();
	AddSC_Duel_Reset();
	AddSC_Morph_npc();
	AddSC_Professions_NPC();
	AddSC_tele();
	AddSC_npc_global_trainer();
	AddSC_npc_enchantment();
	AddSC_player_loginscript();
	*/
#endif
}
