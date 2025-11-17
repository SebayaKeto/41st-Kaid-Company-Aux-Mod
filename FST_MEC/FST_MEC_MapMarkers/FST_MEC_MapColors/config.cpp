/*
 * * Config.cpp
 * * STAR WARS MARKER COLOR ADDON
 * * This is the final configuration file utilizing the MEC_Marker_Core.hpp macro
 * * to define a wide array of custom marker colors for Star Wars factions,
 * * units, and organizations within Arma 3.
 * * Author: Maldova Engineering Corporation (MEC)
 * * Date: 22 BBY
 */

#include "MEC_Marker_Core.hpp"

// =========================================================================
// CfgPatches: Defines the mod identity.
// =========================================================================
class CfgPatches
{
	class FST_MEC_MapColors
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_UI_F"}; 
		author = MEC_FULL_NAME;
		name = "MEC Star Wars Marker Colors";
	};
};
// =========================================================================
// CfgMarkerColors: Defines custom marker colors using the macro.
// =========================================================================

class CfgMarkerColors
{

	name = MEC_MARKER_GROUP_NAME; // "MEC SW Factions & Units"

	// MEC_MARKER_COLOR_CLASS(_CLASSNAME, _DISPLAY_NAME, _COLOR_ARRAY)
	
	// --- Generic Factions ---
	MEC_MARKER_COLOR_CLASS(MEC_Republic_Standard, "Republic Standard", COLOR_REP_STANDARD);
	MEC_MARKER_COLOR_CLASS(MEC_CIS_Separatist, "CIS Separatist", COLOR_CIS_SEPARATIST);
	MEC_MARKER_COLOR_CLASS(MEC_Pirate_Syndicate, "Pirate Syndicate", COLOR_PIRATE_SYNDICATE);
	
	// --- MEC Corporate & Logistics ---
	MEC_MARKER_COLOR_CLASS(MEC_Safety_Orange, "MEC Safety Orange", COLOR_MEC_SAFETY_ORANGE);
	MEC_MARKER_COLOR_CLASS(MEC_RLS_Yellow, "MEC RLS Stencil", COLOR_MEC_RLS_YELLOW);
	MEC_MARKER_COLOR_CLASS(MEC_Deep_Grey, "MEC Tactical Grey", COLOR_MEC_TACTICAL_GREY);
	
	// --- Clone Trooper Units ---
	MEC_MARKER_COLOR_CLASS(MEC_Republic_501st, "501st Legion (Blue)", COLOR_REP_501ST);
	MEC_MARKER_COLOR_CLASS(MEC_Republic_212th, "212th Attack Bn (Orange)", COLOR_REP_212TH);
	MEC_MARKER_COLOR_CLASS(MEC_Republic_41st, "41st Elite Corps (Green)", COLOR_REP_41ST);
	MEC_MARKER_COLOR_CLASS(MEC_Republic_Wolfpack, "104th Wolfpack (Grey)", COLOR_REP_WOLFPACK);
	MEC_MARKER_COLOR_CLASS(MEC_Republic_CoruscantGuard, "Coruscant Guard (Red)", COLOR_REP_CORUSCANT_GUARD);
	MEC_MARKER_COLOR_CLASS(MEC_Republic_GalacticMarines, "Galactic Marines (Red)", COLOR_REP_GALACTIC_MARINES);
	MEC_MARKER_COLOR_CLASS(MEC_Republic_KashyyykScouts, "Kashyyyk Scouts (Camo)", COLOR_REP_KASHYYYK_SCOUTS);
	MEC_MARKER_COLOR_CLASS(MEC_Republic_ShockTroopers, "Shock Troopers (Deep Red)", COLOR_REP_SHOCK_TROOPERS);
	MEC_MARKER_COLOR_CLASS(MEC_Republic_327th, "327th Star Corps (Yellow)", COLOR_REP_327TH); 
	MEC_MARKER_COLOR_CLASS(MEC_Republic_KaminoSecurity, "Kamino Security (Grey)", COLOR_REP_KAMINO_SECURITY); 
	MEC_MARKER_COLOR_CLASS(MEC_Republic_Shadow, "Shadow Troopers (Black)", COLOR_REP_SHADOW); 
	MEC_MARKER_COLOR_CLASS(MEC_Republic_RancorBn, "Rancor Battalion (Maroon)", COLOR_REP_RANCOR_BN); 
	MEC_MARKER_COLOR_CLASS(MEC_Republic_TorrentCo, "Torrent Company (Light Blue)", COLOR_REP_TORRENT_CO); 
	MEC_MARKER_COLOR_CLASS(MEC_Republic_HornCo, "Horn Company (Gold)", COLOR_REP_HORN_CO); 
	MEC_MARKER_COLOR_CLASS(MEC_Republic_38thArmored, "38th Armored Division (Maroon)", COLOR_REP_38TH_ARMORED); 
	MEC_MARKER_COLOR_CLASS(MEC_Republic_CamoScout, "Camo Recon/Scout (Forest)", COLOR_REP_CAMO_SCOUT); 
	MEC_MARKER_COLOR_CLASS(MEC_Republic_NovaCorps, "Nova Corps ()", COLOR_REP_NOVA_CORPS);

	// --- Separatist & CIS ---
	MEC_MARKER_COLOR_CLASS(MEC_CIS_Geonosian, "CIS Geonosian Separatists", COLOR_CIS_GEONOSIAN); 
	MEC_MARKER_COLOR_CLASS(MEC_CIS_Banking, "CIS Banking Clan", COLOR_CIS_BANKING); 
	MEC_MARKER_COLOR_CLASS(MEC_CIS_Techno, "CIS Techno Union", COLOR_CIS_TECHNO); 
	MEC_MARKER_COLOR_CLASS(MEC_CIS_Hyperdrive, "CIS Hyperdrive Mfg", COLOR_CIS_HYPERDRIVE); 
	MEC_MARKER_COLOR_CLASS(MEC_CIS_Commerce, "CIS Commerce Guild", COLOR_CIS_COMMERCE); 
	
	// --- Criminal & Hutt Cartel ---
	MEC_MARKER_COLOR_CLASS(MEC_Syndicate_CrimsonDawn, "Crimson Dawn", COLOR_CRIMSON_DAWN);
	MEC_MARKER_COLOR_CLASS(MEC_Syndicate_BlackSun, "Black Sun (Gold)", COLOR_BLACK_SUN);
	MEC_MARKER_COLOR_CLASS(MEC_Syndicate_HaxionBrood, "Haxion Brood", COLOR_HAXION_BROOD);
	MEC_MARKER_COLOR_CLASS(MEC_Syndicate_HuttCartel, "Hutt Cartel (Green)", COLOR_HUTT_CARTEL);
	MEC_MARKER_COLOR_CLASS(MEC_Syndicate_ZannConsortium, "Zann Consortium (Purple)", COLOR_ZANN_CONSORTIUM);
	MEC_MARKER_COLOR_CLASS(MEC_Syndicate_Pike, "Pike Syndicate (Yellow)", COLOR_SYNDICATE_PIKE); 
	MEC_MARKER_COLOR_CLASS(MEC_Mandalorian_Loyalist, "Mandalorian Loyalists", COLOR_MANDALORIAN_LOYALIST); 
	MEC_MARKER_COLOR_CLASS(MEC_Mandalorian_DeathWatch, "Mandalorian Death Watch", COLOR_MANDALORIAN_DEATHWATCH); 
	MEC_MARKER_COLOR_CLASS(MEC_Dark_Side, "Dark Side / Sith", COLOR_DARK_SIDE); 
	MEC_MARKER_COLOR_CLASS(MEC_Rebel_Alliance, "Rebel Alliance", COLOR_REBEL_ALLIANCE); 

	// --- Corporate & Neutral ---
	MEC_MARKER_COLOR_CLASS(MEC_Neutral_CorellianEng, "Corellian Eng. Corp.", COLOR_CORELLIAN_ENG);
	MEC_MARKER_COLOR_CLASS(MEC_Neutral_TradeFederation, "Trade Federation", COLOR_TRADE_FED);
	MEC_MARKER_COLOR_CLASS(MEC_Neutral_BlackMarket, "Black Market Smugglers", COLOR_BLACK_MARKET);
	MEC_MARKER_COLOR_CLASS(MEC_Neutral_MiningCorp, "Mining Guild", COLOR_CORP_MINING); 

	// --- Imperial / Post-Clone Wars ---
	MEC_MARKER_COLOR_CLASS(MEC_Empire_ImperialGrey, "Imperial Standard", COLOR_EMPIRE_GREY);
	MEC_MARKER_COLOR_CLASS(MEC_Empire_RoyalGuard, "Royal Guard", COLOR_EMPIRE_ROYAL_GUARD);
	MEC_MARKER_COLOR_CLASS(MEC_FirstOrder_Standard, "First Order Standard", COLOR_FIRST_ORDER);

};