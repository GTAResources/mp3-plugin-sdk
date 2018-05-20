#pragma once

#include <string>

inline constexpr char ToLower(const char c)
{
	return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}

inline constexpr char ToUpper(const char c)
{
	return (c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c;
}

inline constexpr uint32_t HashString(const char* string)
{
	uint32_t hash = 0;

	for (; *string; ++string)
	{
		hash += ToLower(*string);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}

	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash;
}

inline constexpr uint16_t GetEntityBoneNameHash(const char* boneName)
{
	uint32_t hash = 0;

	for (; *boneName; ++boneName)
	{
		hash = ToUpper(*boneName) + 16 * hash;
		if (hash & 0xF0000000)
			hash ^= hash & 0xF0000000 ^ ((hash & 0xF0000000) >> 24);
	}

	return hash % 0xFE8F + 0x170;
}

static const std::string weaponNames[] = {
	"VEHICLE_WEAPON_CAVEIRAO_GUN",
	"VEHICLE_WEAPON_CAVEIRAO_VAR_GUN",
	"VEHICLE_WEAPON_DUNE",
	"VEHICLE_WEAPON_HIND_GUN",
	"VEHICLE_WEAPON_HIND_ROCKET",
	"VEHICLE_WEAPON_TANK",
	"WEAPON_AMMO_BAG",
	"WEAPON_BEANBAG_LAUNCHER",
	"WEAPON_BLEEDOUT",
	"WEAPON_BOOBYTRAP",
	"WEAPON_C4",
	"WEAPON_C4_DETONATOR",
	"WEAPON_CATTLE_PROD",
	"WEAPON_CRUSH",
	"WEAPON_DROWNING",
	"WEAPON_DROWNING_IN_VEHICLE",
	"WEAPON_EXPLOSION",
	"WEAPON_FALL",
	"WEAPON_GRENADE_LAUNCHER",
	"WEAPON_GRENADE_LAUNCHER_BECKER",
	"WEAPON_GRENADE_LAUNCHER_FINALE",
	"WEAPON_GRENADE_LAUNCHER_G9",
	"WEAPON_HIT_BY_WATER_CANNON",
	"WEAPON_LAW",
	"WEAPON_MG_21E",
	"WEAPON_MG_RPD",
	"WEAPON_MONEY_BAG",
	"WEAPON_MP_BAG",
	"WEAPON_NIGHT_STICK",
	"WEAPON_PEPPER_SPRAY",
	"WEAPON_PISTOL_38",
	"WEAPON_PISTOL_BROWNING",
	"WEAPON_PISTOL_BROWNING_SILENCED",
	"WEAPON_PISTOL_COLT1911",
	"WEAPON_PISTOL_DEAGLE",
	"WEAPON_PISTOL_GLOCK18",
	"WEAPON_PISTOL_PT92",
	"WEAPON_PISTOL_PT92_BOTTLE",
	"WEAPON_PISTOL_TAURUS608",
	"WEAPON_RAMMED_BY_CAR",
	"WEAPON_RIFLE_97LC",
	"WEAPON_RIFLE_AK47",
	"WEAPON_RIFLE_AK47_UNDERBARREL_GRENADE",
	"WEAPON_RIFLE_FAL",
	"WEAPON_RIFLE_FAL_RUBBER",
	"WEAPON_RIFLE_G36K",
	"WEAPON_RIFLE_GALIL",
	"WEAPON_RIFLE_IA2",
	"WEAPON_RIFLE_L1A1",
	"WEAPON_RIFLE_L1A1_GRENADE",
	"WEAPON_RIFLE_M4",
	"WEAPON_RIFLE_RUG30",
	"WEAPON_RIFLE_RUG30_HELI",
	"WEAPON_RIFLE_TAR",
	"WEAPON_RIOT_SHIELD",
	"WEAPON_RPG",
	"WEAPON_RUN_OVER_BY_CAR",
	"WEAPON_SHOTGUN",
	"WEAPON_SHOTGUN_BENELLIM3",
	"WEAPON_SHOTGUN_DOUBLEBARREL",
	"WEAPON_SHOTGUN_HAMMERHEAD",
	"WEAPON_SHOTGUN_MOSSBERG590",
	"WEAPON_SHOTGUN_SPAS12",
	"WEAPON_SHOTGUN_SPAS15",
	"WEAPON_SHOTGUN_WINCHESTERSX3",
	"WEAPON_SMG_FAMAEMT40",
	"WEAPON_SMG_MAC10",
	"WEAPON_SMG_MP5",
	"WEAPON_SMG_MP5_UNDERBARREL_GRENADE",
	"WEAPON_SMG_PM12",
	"WEAPON_SMG_SKORPION",
	"WEAPON_SMG_UZI",
	"WEAPON_SNIPER_ENFORCER",
	"WEAPON_SNIPER_M24",
	"WEAPON_SNIPER_M82",
	"WEAPON_SNIPER_SG1",
	"WEAPON_SPEARGUN",
	"WEAPON_STINGER",
	"WEAPON_STUN_GUN",
	"WEAPON_TASER",
	"WEAPON_THROWN_BOUNCING_BETTY",
	"WEAPON_THROWN_FLASH",
	"WEAPON_THROWN_GRENADE",
	"WEAPON_THROWN_GRENADE_SCRIPT",
	"WEAPON_THROWN_GRENADE_SMALL",
	"WEAPON_THROWN_INCENDIARY",
	"WEAPON_THROWN_INCENDIARY_FAST",
	"WEAPON_THROWN_INCENDIARY_MP",
	"WEAPON_THROWN_SMOKE",
	"WEAPON_THROWN_TEAR_GAS",
	"WEAPON_THROWN_TEAR_GAS_INF",
	"WEAPON_THROWN_TIN_CAN",
	"WEAPON_THROWN_TRIPWIRE",
	"WEAPON_TRAM_TEAR_GAS",
	"WEAPON_UNARMED",
	"WEAPON_XMG_21E",
	"WEAPON_XPISTOL_DUMMY",
	"WEAPON_XRIFLE_97LC",
	"WEAPON_XRIFLE_RUG30",
	"WEAPON_XRPG",
	"WEAPON_XSMG_MAC10",
	"WEAPON_XSMG_PM12",
	"WEAPON_XSNIPER_DUMMY"
};

static const std::string weatherTypeNames[] = {
	"EXTRASUNNY",
	"SUNNY",
	"SUNNY_WINDY",
	"CLOUDY",
	"FOGGY",
	"DRIZZLE",
	"RAIN",
	"STORMY"
};

static const std::string unlockSemantics[] = {
	"16BIT_MAX",
	"1HITKILL",
	"ASSOC",
	"AVATAR_CUST_UL",
	"AVATAR_SLOT_AWODEN_HR",
	"AVATAR_SLOT_BACHMEYER",
	"AVATAR_SLOT_BAD_DAY_BECKER",
	"AVATAR_SLOT_BG_PASSOS",
	"AVATAR_SLOT_CLAUDIO",
	"AVATAR_SLOT_COMANDO_SOMBRE_F",
	"AVATAR_SLOT_COMANDO_SOMBRE_M",
	"AVATAR_SLOT_CRACHA_PRETO_F",
	"AVATAR_SLOT_CRACHA_PRETO_M",
	"AVATAR_SLOT_DE_MARCOS_F",
	"AVATAR_SLOT_DE_MARCOS_M",
	"AVATAR_SLOT_DR_FISCHER",
	"AVATAR_SLOT_FABIANA",
	"AVATAR_SLOT_FDO_F",
	"AVATAR_SLOT_FDO_M",
	"AVATAR_SLOT_GIOVANNA_BUS",
	"AVATAR_SLOT_IT_GUY",
	"AVATAR_SLOT_JACK_LUP_HR",
	"AVATAR_SLOT_MARCELO_YACHT",
	"AVATAR_SLOT_MAX_BOOZE_PILLS",
	"AVATAR_SLOT_MAX_PAYNE1_HR",
	"AVATAR_SLOT_MILO",
	"AVATAR_SLOT_MONA_SAX_HR",
	"AVATAR_SLOT_MP2_HR",
	"AVATAR_SLOT_NIC_HORNE_HR",
	"AVATAR_SLOT_NYBAR_GIRL",
	"AVATAR_SLOT_PASSOS_DOCKS",
	"AVATAR_SLOT_PASSOS_NY",
	"AVATAR_SLOT_PASSOS_PILOT",
	"AVATAR_SLOT_PUNCHINELLOS_F",
	"AVATAR_SLOT_PUNCHINELLOS_M",
	"AVATAR_SLOT_RODRIGO_CASUAL",
	"AVATAR_SLOT_RUDY",
	"AVATAR_SLOT_SPP_F",
	"AVATAR_SLOT_SPP_M",
	"AVATAR_SLOT_STRIP_BT",
	"AVATAR_SLOT_TERCEIRO_FALANGE_F",
	"AVATAR_SLOT_TERCEIRO_FALANGE_M",
	"AVATAR_SLOT_UFE_F",
	"AVATAR_SLOT_UFE_M",
	"AVATAR_SLOT_USP_F",
	"AVATAR_SLOT_USP_M",
	"AVATAR_SLOT_VAL_WINTERSON_HR",
	"AVATAR_SLOT_VICTOR_TUX",
	"AVATAR_SLOT_VIN_GOG_HR",
	"AVATAR_SLOT_VLAD_HR",
	"AVATAR_SLOT_YCHT_F",
	"AVATAR_SLOT_YCHT_M",
	"AV_UL_FEMALE",
	"AV_UL_MALE",
	"BECKER_HEAD",
	"BIKER",
	"BW_MAX",
	"CAPO",
	"CLST_KID",
	"CONSIG",
	"COOLBULLETS",
	"CREW_OUTFIT_UNLOCK",
	"CREW_OUTFIT_UNLOCK_DE_MARCO_MALE",
	"CUSTOM_MAX",
	"DC_UL_LOOKOUT",
	"DEALER",
	"DEMARCO_HEAD",
	"EXPAMMO",
	"FAV_GEN",
	"FLD_COP",
	"FTBALL",
	"GRINDS",
	"HEADSHOTSONLY",
	"HPREGEN",
	"INCAMMO",
	"INFAMMO",
	"INFBT",
	"INFPAYNEKILLERS",
	"INVISIBLE_UNLOCK",
	"IS_UL_CHEST",
	"IS_UL_GEAR_ONE",
	"IS_UL_GEAR_THREE",
	"IS_UL_GEAR_TWO",
	"IS_UL_HEAD",
	"LEVEL1GRIND",
	"LEVEL2GRIND",
	"LEVEL3GRIND",
	"LOADOUT_SLOT_1",
	"LOADOUT_SLOT_2",
	"LOADOUT_SLOT_3",
	"LOADOUT_SLOT_4",
	"LOADOUT_SLOT_5",
	"LOADOUT_WEIGHT_16",
	"LOADOUT_WEIGHT_17",
	"LOADOUT_WEIGHT_18",
	"LOADOUT_WEIGHT_19",
	"LOADOUT_WEIGHT_20",
	"LOADOUT_WEIGHT_21",
	"LOADOUT_WEIGHT_22",
	"LOADOUT_WEIGHT_23",
	"LOADOUT_WEIGHT_24",
	"LOADOUT_WEIGHT_25",
	"LOADOUT_WEIGHT_26",
	"LONEWOLF",
	"LOOKOUT",
	"LOWAMMO",
	"MAX_HEAD",
	"MAX_LEG1",
	"MAX_LEG10",
	"MAX_LEG10",
	"MAX_LEG2",
	"MAX_LEG3",
	"MAX_LEG4",
	"MAX_LEG5",
	"MAX_LEG6",
	"MAX_LEG6",
	"MAX_LEG7",
	"MAX_LEG7",
	"MAX_LEG8",
	"MAX_LEG8",
	"MAX_LEG9",
	"MAX_LEG9",
	"MOB_MEET",
	"MOON_DET",
	"MUGGER_HEAD",
	"NEVES_HEAD",
	"NGHT_OUT",
	"NOIREMODE",
	"OLSKLARCADE",
	"PATCH_1",
	"PATCH_2",
	"PATCH_3",
	"PATCH_4",
	"PL_UL_DLC",
	"PL_UL_DM_HCL",
	"PL_UL_DM_HL",
	"PL_UL_DM_ML",
	"PL_UL_DM_TF",
	"PL_UL_DM_TL",
	"PL_UL_GSTOP_FR",
	"PL_UL_GSTOP_LK",
	"PL_UL_GWS_H",
	"PL_UL_GWS_HC",
	"PL_UL_GWS_M",
	"PL_UL_LMS_H",
	"PL_UL_LMS_M",
	"PL_UL_PK_H",
	"PL_UL_PK_M",
	"PL_UL_SDM_FA",
	"PL_UL_SDM_SL",
	"PL_UL_STDM_FA",
	"PL_UL_STDM_SL",
	"PL_UL_TDM_HCL",
	"PL_UL_TDM_HL",
	"PL_UL_TDM_ML",
	"PL_UL_TDM_TF",
	"PL_UL_TDM_TL",
	"PRESTIGE_UP",
	"PUNCH_HEAD",
	"REPLAY_A1",
	"REPLAY_A10",
	"REPLAY_A11",
	"REPLAY_A12",
	"REPLAY_A13",
	"REPLAY_A14",
	"REPLAY_A15",
	"REPLAY_A16",
	"REPLAY_A17",
	"REPLAY_A18",
	"REPLAY_A19",
	"REPLAY_A2",
	"REPLAY_A20",
	"REPLAY_A21",
	"REPLAY_A22",
	"REPLAY_A23",
	"REPLAY_A24",
	"REPLAY_A25",
	"REPLAY_A26",
	"REPLAY_A27",
	"REPLAY_A28",
	"REPLAY_A29",
	"REPLAY_A3",
	"REPLAY_A30",
	"REPLAY_A4",
	"REPLAY_A5",
	"REPLAY_A6",
	"REPLAY_A7",
	"REPLAY_A8",
	"REPLAY_A9",
	"REPLAY_B1",
	"REPLAY_B10",
	"REPLAY_B11",
	"REPLAY_B12",
	"REPLAY_B13",
	"REPLAY_B14",
	"REPLAY_B15",
	"REPLAY_B16",
	"REPLAY_B17",
	"REPLAY_B18",
	"REPLAY_B19",
	"REPLAY_B2",
	"REPLAY_B20",
	"REPLAY_B21",
	"REPLAY_B22",
	"REPLAY_B23",
	"REPLAY_B24",
	"REPLAY_B25",
	"REPLAY_B26",
	"REPLAY_B27",
	"REPLAY_B28",
	"REPLAY_B29",
	"REPLAY_B3",
	"REPLAY_B30",
	"REPLAY_B4",
	"REPLAY_B5",
	"REPLAY_B6",
	"REPLAY_B7",
	"REPLAY_B8",
	"REPLAY_B9",
	"REPLAY_C1",
	"REPLAY_C10",
	"REPLAY_C11",
	"REPLAY_C12",
	"REPLAY_C13",
	"REPLAY_C14",
	"REPLAY_C15",
	"REPLAY_C16",
	"REPLAY_C17",
	"REPLAY_C18",
	"REPLAY_C19",
	"REPLAY_C2",
	"REPLAY_C20",
	"REPLAY_C21",
	"REPLAY_C22",
	"REPLAY_C23",
	"REPLAY_C24",
	"REPLAY_C25",
	"REPLAY_C26",
	"REPLAY_C27",
	"REPLAY_C28",
	"REPLAY_C29",
	"REPLAY_C3",
	"REPLAY_C30",
	"REPLAY_C4",
	"REPLAY_C5",
	"REPLAY_C6",
	"REPLAY_C7",
	"REPLAY_C8",
	"REPLAY_C9",
	"SC_MEMBER_PLAYLIST",
	"SERRANO_HEAD",
	"SPCL_OP",
	"SPP_DASILVA_HEAD",
	"SPP_MAX_PAYNE_HEAD",
	"TZ_DJ",
	"T_UL_15_CORONEL",
	"T_UL_1_SARGENTO",
	"T_UL_1_TENENTE",
	"T_UL_2_SARGENTO",
	"T_UL_2_TENENTE",
	"T_UL_3_SARGENTO",
	"T_UL_3_TENENTE",
	"T_UL_9_LIVES",
	"T_UL_AMBIDEXTROUS",
	"T_UL_ASPIRANTE",
	"T_UL_BULLETPROOF",
	"T_UL_CABO",
	"T_UL_CADETE",
	"T_UL_CAPTAIN",
	"T_UL_CHIEF",
	"T_UL_CHIEF",
	"T_UL_COMMANDO",
	"T_UL_DEADEYE",
	"T_UL_DEDICATED",
	"T_UL_DEFENDER",
	"T_UL_DIFFUSER",
	"T_UL_DIVE_BOMBER",
	"T_UL_DOCTOR",
	"T_UL_DOMINATOR",
	"T_UL_DUALIST",
	"T_UL_EXECUTIONER",
	"T_UL_FEARLESS",
	"T_UL_FUGITIVE",
	"T_UL_GATE_CRASHER",
	"T_UL_GLADIATOR",
	"T_UL_GOLDEN",
	"T_UL_GOLDEN",
	"T_UL_GRIM_REAPER",
	"T_UL_GUN_COLLECTOR",
	"T_UL_HARD_KNUCKLED",
	"T_UL_HEAD_OF_CLASS",
	"T_UL_HIGHSTRUNG",
	"T_UL_INDOMIDABLE",
	"T_UL_INVISIBLE",
	"T_UL_JUGGERNAUT",
	"T_UL_KLEPTO",
	"T_UL_K_CAPPER",
	"T_UL_LIGHTNING",
	"T_UL_LIVINGLEGEND",
	"T_UL_LUCKY",
	"T_UL_MAJOR",
	"T_UL_MARKED",
	"T_UL_MARKED",
	"T_UL_MASTER_OF_ARMS",
	"T_UL_MONEYBAGS",
	"T_UL_NINJA",
	"T_UL_ONE_MAN_ARMY",
	"T_UL_OT_SPOT",
	"T_UL_PACKRAT",
	"T_UL_PATIENT",
	"T_UL_PEERLESS",
	"T_UL_PEERLESS",
	"T_UL_PLAYBOY",
	"T_UL_POSTMASTER",
	"T_UL_PYRO",
	"T_UL_QUATERMASTER",
	"T_UL_RENOWNED",
	"T_UL_RESPECTED",
	"T_UL_SLIPPERY",
	"T_UL_SMOKEY",
	"T_UL_SNAKE",
	"T_UL_SOLDADO",
	"T_UL_SPEEDY",
	"T_UL_SPOTTER",
	"T_UL_STEAMROLLER",
	"T_UL_SUB_TENETE",
	"T_UL_SURESHOT",
	"T_UL_SURVIVALIST",
	"T_UL_SURVIVOR",
	"T_UL_TACTITIAN",
	"T_UL_THEFEARED",
	"T_UL_TRUSTWORTHY",
	"T_UL_UNRIVALED",
	"T_UL_UNRIVALED",
	"T_UL_UNSTOPBLE",
	"T_UL_VENGEFUL",
	"T_UL_WARLORD",
	"T_UL_WAR_CRIMINAL",
	"T_UL_X_RAY",
	"UFE_CMBT_SPPT",
	"UL_ARMOUR_BOMB_SUIT",
	"UL_ARMOUR_HEAVY",
	"UL_ARMOUR_HELMET",
	"UL_ARMOUR_HELMET_HEAVY",
	"UL_ARMOUR_MAX",
	"UL_ARMOUR_STANDARD",
	"UL_BADGEOFHONOR",
	"UL_BOOBY_TRAP",
	"UL_DLC_3_PACK",
	"UL_GAS_MASK",
	"UL_HOLLOWPOINTS",
	"UL_IDCARD",
	"UL_LMS_BT_ACTIVATOR",
	"UL_MANUFACTURER_GUARANTEE",
	"UL_MAX_PRESTIGE_LEVEL",
	"UL_MILITARY_GOGGLES",
	"UL_MP_SPECIAL_AMMO_HOOVER",
	"UL_MP_SPECIAL_AMMO_POUCH",
	"UL_MP_SPECIAL_ANTISTUNGUN",
	"UL_MP_SPECIAL_BALACLAVA",
	"UL_MP_SPECIAL_BETTING_SLIP",
	"UL_MP_SPECIAL_BOUNTY_ORDERS",
	"UL_MP_SPECIAL_CALCULATOR",
	"UL_MP_SPECIAL_CANCERSTICKS",
	"UL_MP_SPECIAL_FIELDBANDAGES",
	"UL_MP_SPECIAL_FIREPROOF_SPRAY",
	"UL_MP_SPECIAL_HIP_FLASK",
	"UL_MP_SPECIAL_INTIMIDATION",
	"UL_MP_SPECIAL_LIGHT_FINGERS",
	"UL_MP_SPECIAL_LOCKBOX",
	"UL_MP_SPECIAL_LUCKY_COIN",
	"UL_MP_SPECIAL_PILLBOTTLE",
	"UL_MP_SPECIAL_POKERCHIP",
	"UL_MP_SPECIAL_QUICK_HOLSTER",
	"UL_MP_SPECIAL_SC_ARCANE_SKULL",
	"UL_MP_SPECIAL_SC_DEAD_SKULL",
	"UL_MP_SPECIAL_SC_DEMON_SKULL",
	"UL_MP_SPECIAL_SC_HUMAN_SKULL",
	"UL_MP_SPECIAL_SC_WEDD_SKULL",
	"UL_MP_SPECIAL_SMARTPHONE",
	"UL_MP_SPECIAL_SNIPER_DETECTOR",
	"UL_MP_SPECIAL_SPRAYCAN",
	"UL_MP_SPECIAL_STEALTH_BOOTS",
	"UL_MP_SPECIAL_STICKY_TAPE",
	"UL_MP_SPECIAL_SUTURES",
	"UL_MP_SPECIAL_TRACKINGDEVICE",
	"UL_MP_SPECIAL_WALKIE_TALKIE",
	"UL_MP_SPECIAL_WRESTLEMASK",
	"UL_MP_STREAK_BB_LVL2",
	"UL_MP_STREAK_BB_LVL3",
	"UL_MP_STREAK_BIGDOG",
	"UL_MP_STREAK_BIGDOG_LVL2",
	"UL_MP_STREAK_BIGDOG_LVL3",
	"UL_MP_STREAK_BT_LVL2",
	"UL_MP_STREAK_BT_LVL3",
	"UL_MP_STREAK_BULLETTIME",
	"UL_MP_STREAK_BURSTBUBBLE",
	"UL_MP_STREAK_DEATHSQUAD",
	"UL_MP_STREAK_DEATHSQUAD_LVL2",
	"UL_MP_STREAK_DEATHSQUAD_LVL3",
	"UL_MP_STREAK_EXPLOSIVES",
	"UL_MP_STREAK_EX_LVL2",
	"UL_MP_STREAK_EX_LVL3",
	"UL_MP_STREAK_FB_LVL2",
	"UL_MP_STREAK_FB_LVL3",
	"UL_MP_STREAK_FRESHBLOOD",
	"UL_MP_STREAK_GRNDED_LVL2",
	"UL_MP_STREAK_GRNDED_LVL3",
	"UL_MP_STREAK_GROUNDED",
	"UL_MP_STREAK_HANGOVER",
	"UL_MP_STREAK_HANGOVER_LVL2",
	"UL_MP_STREAK_HANGOVER_LVL3",
	"UL_MP_STREAK_INTUITION",
	"UL_MP_STREAK_INT_LVL2",
	"UL_MP_STREAK_INT_LVL3",
	"UL_MP_STREAK_PARANOIA",
	"UL_MP_STREAK_PARANOIA_LVL2",
	"UL_MP_STREAK_PARANOIA_LVL3",
	"UL_MP_STREAK_SC_LVL2",
	"UL_MP_STREAK_SC_LVL3",
	"UL_MP_STREAK_SLIPPERYCHARACTER",
	"UL_MP_STREAK_SNEAKY",
	"UL_MP_STREAK_SNEAKY_LVL2",
	"UL_MP_STREAK_SNEAKY_LVL3",
	"UL_MP_STREAK_TRIGGERHAPPY",
	"UL_MP_STREAK_TRIGGERHAPPY_LVL2",
	"UL_MP_STREAK_TRIGGERHAPPY_LVL3",
	"UL_MP_STREAK_UNSTOPPABLE",
	"UL_MP_STREAK_UNSTOPPABLE_LVL2",
	"UL_MP_STREAK_UNSTOPPABLE_LVL3",
	"UL_MP_STREAK_WDD_LVL2",
	"UL_MP_STREAK_WDD_LVL3",
	"UL_MP_STREAK_WD_LVL2",
	"UL_MP_STREAK_WD_LVL3",
	"UL_MP_STREAK_WEAPONDEALER",
	"UL_MP_STREAK_WEAPONDOUBLEDEALER",
	"UL_PAID_DLC4",
	"UL_PAID_DLC5",
	"UL_PAID_DLC6",
	"UL_POCKETWATCH",
	"UL_PRECINCT_DLC",
	"UL_SPECIAL_EDITION",
	"UL_SWISS_ARMY_KNIFE",
	"UL_URBAN_CAMO",
	"UL_VAMPIRIC",
	"UL_WEAPON_CATTLE_PROD",
	"UL_WEAPON_GRENADE_LAUNCHER",
	"UL_WEAPON_GRENADE_LAUNCHER_G9",
	"UL_WEAPON_LAW",
	"UL_WEAPON_MG_21E",
	"UL_WEAPON_MG_RPD",
	"UL_WEAPON_NIGHT_STICK",
	"UL_WEAPON_PEPPER_SPRAY",
	"UL_WEAPON_PISTOL_38",
	"UL_WEAPON_PISTOL_COLT1911",
	"UL_WEAPON_PISTOL_DEAGLE",
	"UL_WEAPON_PISTOL_GLOCK18",
	"UL_WEAPON_PISTOL_PT92",
	"UL_WEAPON_PISTOL_TAURUS608",
	"UL_WEAPON_RIFLE_97LC",
	"UL_WEAPON_RIFLE_AK47",
	"UL_WEAPON_RIFLE_FAL",
	"UL_WEAPON_RIFLE_G36K",
	"UL_WEAPON_RIFLE_GALIL",
	"UL_WEAPON_RIFLE_IA2",
	"UL_WEAPON_RIFLE_M24",
	"UL_WEAPON_RIFLE_M4",
	"UL_WEAPON_RIFLE_RUG30",
	"UL_WEAPON_RIFLE_TAR",
	"UL_WEAPON_RPG",
	"UL_WEAPON_SHOTGUN_BENELLIM3",
	"UL_WEAPON_SHOTGUN_DOUBLEBARREL",
	"UL_WEAPON_SHOTGUN_HAMMERHEAD",
	"UL_WEAPON_SHOTGUN_MOSSBERG590",
	"UL_WEAPON_SHOTGUN_SPAS15",
	"UL_WEAPON_SHOTGUN_WINCHESTERSX3",
	"UL_WEAPON_SMG_FAMAEMT40",
	"UL_WEAPON_SMG_MAC10",
	"UL_WEAPON_SMG_MP5",
	"UL_WEAPON_SMG_PM12",
	"UL_WEAPON_SMG_UZI",
	"UL_WEAPON_SNIPER_M82",
	"UL_WEAPON_SNIPER_SG1",
	"UL_WEAPON_STUN_GUN",
	"UL_WEAPON_THROWN_BOUNCING_BETTY",
	"UL_WEAPON_THROWN_FLASH",
	"UL_WEAPON_THROWN_GRENADE",
	"UL_WEAPON_THROWN_INCENDIARY_MP",
	"UL_WEAPON_THROWN_SMOKE",
	"UL_WEAPON_THROWN_TEAR_GAS",
	"UL_WEAPON_THROWN_TIN_CAN",
	"UN_REP",
	"URBN_CMBT",
	"VENDETTAS",
	"WAGERS",
	"WEAPON_CATTLE_PROD_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_CATTLE_PROD_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_GRENADE_LAUNCHER_G9_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_GRENADE_LAUNCHER_G9_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_GRENADE_LAUNCHER_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_GRENADE_LAUNCHER_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_LAW_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_LAW_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_MG_21E_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_MG_21E_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_MG_21E_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_MG_21E_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_MG_21E_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_MG_21E_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_MG_RPD_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_MG_RPD_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_MG_RPD_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_MG_RPD_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_MG_RPD_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_MG_RPD_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_NIGHT_STICK_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_NIGHT_STICK_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_PEPPER_SPRAY_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_PEPPER_SPRAY_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_PISTOL_38_DUAL_WIELD",
	"WEAPON_PISTOL_38_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_PISTOL_38_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_PISTOL_38_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_PISTOL_38_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_PISTOL_38_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_PISTOL_COLT1911_DUAL_WIELD",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_PISTOL_COLT1911_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_PISTOL_DEAGLE_DUAL_WIELD",
	"WEAPON_PISTOL_DEAGLE_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_PISTOL_DEAGLE_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_PISTOL_DEAGLE_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_PISTOL_DEAGLE_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_PISTOL_DEAGLE_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_PISTOL_DEAGLE_WEAPON_ATTACHMENT_RED_DOT_SCOPE",
	"WEAPON_PISTOL_GLOCK18_DUAL_WIELD",
	"WEAPON_PISTOL_GLOCK18_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_PISTOL_GLOCK18_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_PISTOL_GLOCK18_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_PISTOL_GLOCK18_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_PISTOL_GLOCK18_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_PISTOL_GLOCK18_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_PISTOL_GLOCK18_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_PISTOL_GLOCK18_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_PISTOL_PT92_DUAL_WIELD",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_PISTOL_PT92_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_PISTOL_TAURUS608_DUAL_WIELD",
	"WEAPON_PISTOL_TAURUS608_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_PISTOL_TAURUS608_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_PISTOL_TAURUS608_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_PISTOL_TAURUS608_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_PISTOL_TAURUS608_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_97LC_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_AK47_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_FAL_WEAPON_ATTACHMENT_RED_DOT_SCOPE",
	"WEAPON_RIFLE_G36K_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_G36K_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_G36K_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_G36K_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_G36K_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_G36K_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_RIFLE_G36K_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_G36K_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_RED_DOT_SCOPE",
	"WEAPON_RIFLE_GALIL_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_IA2_WEAPON_ATTACHMENT_SNIPER_SCOPE",
	"WEAPON_RIFLE_M4_CHROME",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_RED_DOT_SCOPE",
	"WEAPON_RIFLE_M4_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_SNIPER_SCOPE",
	"WEAPON_RIFLE_RUG30_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_RED_DOT_SCOPE",
	"WEAPON_RIFLE_TAR_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_RPG_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_RPG_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SHOTGUN_BENELLIM3_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SHOTGUN_BENELLIM3_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SHOTGUN_BENELLIM3_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SHOTGUN_BENELLIM3_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SHOTGUN_BENELLIM3_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SHOTGUN_BENELLIM3_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SHOTGUN_DOUBLEBARREL_DUAL_WIELD",
	"WEAPON_SHOTGUN_DOUBLEBARREL_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SHOTGUN_DOUBLEBARREL_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SHOTGUN_HAMMERHEAD_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SHOTGUN_HAMMERHEAD_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SHOTGUN_HAMMERHEAD_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SHOTGUN_HAMMERHEAD_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SHOTGUN_HAMMERHEAD_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SHOTGUN_HAMMERHEAD_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SHOTGUN_MOSSBERG590_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SHOTGUN_MOSSBERG590_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SHOTGUN_MOSSBERG590_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SHOTGUN_MOSSBERG590_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SHOTGUN_MOSSBERG590_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SHOTGUN_MOSSBERG590_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SHOTGUN_MOSSBERG590_WEAPON_ATTACHMENT_RED_DOT_SCOPE",
	"WEAPON_SHOTGUN_SPAS15_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SHOTGUN_SPAS15_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SHOTGUN_SPAS15_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SHOTGUN_SPAS15_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SHOTGUN_SPAS15_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SHOTGUN_SPAS15_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SHOTGUN_SPAS15_WEAPON_ATTACHMENT_RED_DOT_SCOPE",
	"WEAPON_SHOTGUN_WINCHESTERSX3_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SHOTGUN_WINCHESTERSX3_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SHOTGUN_WINCHESTERSX3_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SHOTGUN_WINCHESTERSX3_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SHOTGUN_WINCHESTERSX3_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SHOTGUN_WINCHESTERSX3_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SHOTGUN_WINCHESTERSX3_WEAPON_ATTACHMENT_RED_DOT_SCOPE",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_SMG_FAMAEMT40_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_SMG_MAC10_DUAL_WIELD",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SMG_MAC10_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_SMG_MP5_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_SMG_PM12_DUAL_WIELD",
	"WEAPON_SMG_PM12_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SMG_PM12_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SMG_PM12_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SMG_PM12_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SMG_PM12_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SMG_PM12_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_SMG_PM12_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_SMG_UZI_DUAL_WIELD",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_LASER_SIGHT",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_SMG_UZI_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_SNIPER_M24_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SNIPER_M24_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SNIPER_M24_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SNIPER_M24_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SNIPER_M24_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SNIPER_M24_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_SNIPER_M24_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_SNIPER_M24_WEAPON_ATTACHMENT_SUPPRESSOR",
	"WEAPON_SNIPER_M82_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SNIPER_M82_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SNIPER_M82_WEAPON_ATTACHMENT_COMPENSATOR",
	"WEAPON_SNIPER_M82_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SNIPER_M82_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SNIPER_M82_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SNIPER_M82_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_SNIPER_M82_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_SNIPER_SG1_WEAPON_ATTACHMENT_BARREL_UPGRADES",
	"WEAPON_SNIPER_SG1_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_SNIPER_SG1_WEAPON_ATTACHMENT_GAS_BLOCK",
	"WEAPON_SNIPER_SG1_WEAPON_ATTACHMENT_GAS_SYSTEMS",
	"WEAPON_SNIPER_SG1_WEAPON_ATTACHMENT_GOLD",
	"WEAPON_SNIPER_SG1_WEAPON_ATTACHMENT_HIGH_CAPACITY_CLIP",
	"WEAPON_SNIPER_SG1_WEAPON_ATTACHMENT_MAG_GUIDE",
	"WEAPON_STUN_GUN_WEAPON_ATTACHMENT_CHROME",
	"WEAPON_STUN_GUN_WEAPON_ATTACHMENT_GOLD"
};

static const Hash profileSettingHashes[] = {
	0x002C5D94,
	0x003327FC,
	0x02041719,
	0x0278EDEB,
	0x03BD2DCC,
	0x03CC561B,
	0x05034C6B,
	0x067E3D12, // Gamepad Aiming Acceleration (1 - 10)
	0x06F0C30B,
	0x07EB6EF6,
	0x08B15025, // Gamepad Configuration (0 = Type 1, 1 = Type 2, 2 = Type 3, 3 = Type 4)
	0x09D0A733,
	0x0D129969,
	0x0DB72E68,
	0x0DD39DE4, // Gamepad Vertical Aiming Speed (1 - 10)
	0x0F755F93,
	0x104114E0,
	0x10E336FF,
	0x1265DE3C,
	0x1428D037,
	0x1588EC2A,
	0x15AB1A2F,
	0x16352426,
	0x1868B3A2,
	0x1A746B2B,
	0x1A77A188,
	0x1A9E6B57, // Sound Effects Volume (0 - 9)
	0x1D40CAB9,
	0x21EDFA60,
	0x228D33B0,
	0x22C597A2,
	0x22E3C03B, // Outline Pickups (0 = Off, 1 = On)
	0x23541117,
	0x2435D98A,
	0x2538C364,
	0x27EE4A36,
	0x2AF19527,
	0x2DA50EE4, // Bullet Time FX (0 = Off, 1 = On)
	0x2E188466,
	0x2EFD64DF, // Gamepad Vibration (0 = Off, 1 = On)
	0x2FB34367,
	0x309D3AAE, // Reticle Type (0 = Weapon Specific, 1 = Always White, 2 = Default)
	0x31A6A855,
	0x3235691B,
	0x33417882,
	0x33D7A8F0,
	0x3661E0BD,
	0x3693BC63,
	0x39F9769E,
	0x3D2F6692,
	0x3DC3237C,
	0x3F52BB08,
	0x3FDDFDBD,
	0x3FE4999E, // Display Contrast (0 - 15)
	0x42566993,
	0x43C87D2D,
	0x44C98022,
	0x45FBAE77, // Mouse Horizontal Aiming Speed (1 - 10)
	0x479CDBD8,
	0x485366B9,
	0x48F6AD77,
	0x4B55F932,
	0x4B9B417A,
	0x4D2F41F6,
	0x4D5E3B21,
	0x4DB76EB1,
	0x4F5665EB,
	0x4FA52B02,
	0x50469DBF,
	0x516F63E8,
	0x526032D2,
	0x53E76C7D,
	0x58815D51,
	0x5A37C9F2,
	0x5A62AC99,
	0x5B3C396C,
	0x5C366591,
	0x5C79772F,
	0x5F6D3863,
	0x5FA13B6D,
	0x60AD5B05,
	0x6230CC8D, // Mouse Acceleration (0 = Off, 1 = On)
	0x62E83B9D,
	0x64BCDDB0,
	0x65167E7E,
	0x66581809,
	0x66C7928C,
	0x68C62AB0,
	0x6AC88C9E,
	0x6BBDB259,
	0x6BCF7AD9,
	0x6D8117CF,
	0x6EA06D85,
	0x6EB7A700,
	0x72BFB39B,
	0x732CAEE2,
	0x74C4E84A,
	0x75839196,
	0x76AC7BAB,
	0x78B5C76F,
	0x7909F088,
	0x79943CB3,
	0x7C446C3F,
	0x7CCB4272,
	0x7D4DECE8,
	0x80941CCA,
	0x8166E782,
	0x839396E0, // Kill Indicator (0 = Off, 1 = On)
	0x856B3738,
	0x8748DA5D,
	0x88D7C78D,
	0x8A013F38,
	0x8ACA1F6D,
	0x8B9B4936,
	0x8B9D0781,
	0x8BB3CDEE,
	0x8D021C19,
	0x8FEEE257, // Display Brightness (0 - 15)
	0x9080DE47,
	0x90F749A1,
	0x90FA918F,
	0x91738223,
	0x92CA70F0,
	0x92F12890, // Music Volume (0 - 9)
	0x938D185C,
	0x94460682,
	0x9482EF81, // Subtitles (0 = Off, 1 = On)
	0x9591340D,
	0x95D830AB,
	0x95ED8395,
	0x961050C7, // Golden Gun Effects (0 = Off, 1 = On)
	0x9835B79A,
	0x9A9379D3,
	0x9AE69488,
	0xA0B89735,
	0xA301C041,
	0xA37ABF38,
	0xA535D78D,
	0xA6A15F24,
	0xA7DD5C4B,
	0xA894F50D, // Gamepad Invert Vertical Look (0 = Off, 1 = On)
	0xABF3FA41,
	0xAC1F4639, // Target Tracking (0 = Off, 1 = On)
	0xAC821F61,
	0xAD605BE6,
	0xAEFD40DD,
	0xB017B11F,
	0xB0D35F5E,
	0xB165393A,
	0xB2221AAF,
	0xB24AE515,
	0xB54F61FA,
	0xB8F263B8,
	0xB9444A15,
	0xBA067756,
	0xBB48D695, // Gamepad Invert Horizontal Look (0 = Off, 1 = On)
	0xBC50E82D, // Target Slowdown (0 = Off, 1 = On)
	0xBD9A0493,
	0xBFDD0BAD,
	0xC3562A04,
	0xC37E728F,
	0xC63CC639,
	0xC850ECD6,
	0xC9CB92C3,
	0xC9F7C06F,
	0xCACCE34B,
	0xCB172E30,
	0xCC96A601,
	0xCE4D486E,
	0xCFA3929C,
	0xD21A2A10, // Audio Output (0 = Stereo, 1 = Surround Side, 2 = Surround Rear, 3 = Headphones)
	0xD27877F3,
	0xD464262F,
	0xD47CAA6F,
	0xD51D9DB3,
	0xD5F9F3AE,
	0xD6426AA4, // Mouse Vertical Aiming Speed (1 - 10)
	0xD65B1768, // Gamepad Horizontal Aiming Speed (1 - 10)
	0xD6B4F130,
	0xD6F5C4BD,
	0xD753BB28,
	0xD87B9AEB,
	0xD9D151A9,
	0xDA456A49,
	0xDD0B0AF2, // Invert Mouse Look (0 = Off, 1 = On)
	0xE0C47748,
	0xE19FEAF3,
	0xE1A44622,
	0xE1FF9376,
	0xE4B3082F,
	0xE4CAFBDB,
	0xE5A90D5D,
	0xE6C9C60A,
	0xEA509C79,
	0xEBDFBEF5,
	0xEC7EF8D1,
	0xECCDFFBC,
	0xECE6E2A5,
	0xEE1F2222,
	0xEE9F65E1,
	0xEF234C82,
	0xF2121B49,
	0xF3554A46,
	0xF621009C,
	0xF673C721,
	0xF73A0618,
	0xF78FDA07,
	0xF7BF082C,
	0xF81C63C7,
	0xF8299660,
	0xF9CCB8C7,
	0xFAF59DCD, // Southpaw Mode (0 = Off, 1 = On)
	0xFB4FBA51,
	0xFB7124C6,
	0xFEA632BB,
	0xFF15BE0F
};
