/*
 * MEC_Marker_Core.hpp
 * * MALDOVA ENGINEERING CORPORATION (MEC)
 * STAR WARS MARKER COLOR CORE HEADER
 * * Provides common definitions and a macro for easily generating custom marker
 * * colors within CfgWorlds/CfgMarkerColors.
 * * Designed by MEC for standardized tactical identification.
 */

// =========================================================================
// I. MEC BRANDING AND IDENTIFICATION DEFINITIONS
// =========================================================================

#define MEC_FULL_NAME "Maldova Engineering Corporation (MEC)"
#define MEC_MARKER_GROUP_NAME "MEC SW Factions & Units"

// =========================================================================
// II. STAR WARS COLOR DEFINITIONS (R, G, B, A)
// =========================================================================

// --- MEC Logistics & Base Colors ---
#define COLOR_MEC_TACTICAL_GREY 	{0.2, 0.2, 0.2, 1}
#define COLOR_MEC_SAFETY_ORANGE 	{0.8, 0.35, 0.1, 1}
#define COLOR_MEC_RLS_YELLOW 		{0.9, 0.9, 0.1, 1}

// --- Republic Faction Colors ---
#define COLOR_REP_STANDARD 			{0.25, 0.0, 0.0, 1} 	// Standard GAR Maroon/Red (Default)
#define COLOR_REP_501ST 			{0.1, 0.15, 0.6, 1} // 501st Legion (Blue)
#define COLOR_REP_212TH 			{0.85, 0.4, 0.05, 1} // 212th Attack Bn (Orange)
#define COLOR_REP_41ST 				{0.3, 0.5, 0.3, 1} 	// 41st Elite Corps (Camo Green)
#define COLOR_REP_WOLFPACK 			{0.5, 0.5, 0.5, 1} 	// 104th Wolfpack (Grey)
#define COLOR_REP_CORUSCANT_GUARD 	{0.7, 0.05, 0.05, 1} // Coruscant Guard Red
#define COLOR_REP_GALACTIC_MARINES 	{0.8, 0.1, 0.1, 1} 	// Galactic Marines Crimson
#define COLOR_REP_KASHYYYK_SCOUTS 	{0.3, 0.4, 0.1, 1} 	// Camouflage Green/Brown
#define COLOR_REP_SHOCK_TROOPERS 	{0.5, 0.1, 0.1, 1} 	// Deep Red/Maroon
#define COLOR_REP_327TH 			{0.9, 0.7, 0.1, 1} 	// 327th Star Corps (Yellow/Tan)
#define COLOR_REP_KAMINO_SECURITY 	{0.6, 0.65, 0.7, 1} // Kamino Security (Cool Gray/Silver)
#define COLOR_REP_SHADOW 			{0.0, 0.0, 0.0, 1} 	// Shadow Troopers (Black)
#define COLOR_REP_RANCOR_BN 		{0.3, 0.0, 0.0, 1} 	// Rancor Battalion (Maroon/Dark Red)
#define COLOR_REP_TORRENT_CO 		{0.3, 0.4, 0.8, 1} 	// Torrent Company (Light Blue)
#define COLOR_REP_HORN_CO 			{0.9, 0.5, 0.0, 1} 	// Horn Company (Gold/Orange)
#define COLOR_REP_38TH_ARMORED 		{0.6, 0.2, 0.2, 1} 	// 38th Armored Division (Maroon/Red)
#define COLOR_REP_CAMO_SCOUT 		{0.2, 0.3, 0.1, 1} 	// Camo Recon/Scout Troopers (Forest Camo)
#define COLOR_REP_NOVA_CORPS        {0.6, 0.3, 0.3, 1}  // Nova Corps (Maroon)

// --- Separatist & CIS Colors ---
#define COLOR_CIS_SEPARATIST 		{0.4, 0.5, 0.5, 1} 	// Grey/Teal Droid Color
#define COLOR_CIS_GEONOSIAN 		{0.6, 0.3, 0.1, 1} 	// Geonosian Separatists (Red/Brown)
#define COLOR_CIS_BANKING 			{0.65, 0.65, 0.0, 1} // InterGalactic Banking Clan (Bronze/Gold)
#define COLOR_CIS_TECHNO 			{0.8, 0.8, 0.9, 1} 	// Techno Union (Silver/White)
#define COLOR_CIS_HYPERDRIVE 		{0.5, 0.55, 0.55, 1} // Hyperdrive Manufacturing (Silver/Gray)
#define COLOR_CIS_COMMERCE 			{0.4, 0.2, 0.05, 1} // Commerce Guild (Dark Brown/Copper)

// --- Criminal & Neutral Faction Colors ---
#define COLOR_PIRATE_SYNDICATE 		{0.5, 0.2, 0.1, 1} 	// Generic Criminal Red/Brown
#define COLOR_CRIMSON_DAWN 			{0.6, 0.0, 0.0, 1} 	// Blood Red
#define COLOR_BLACK_SUN 			{0.7, 0.5, 0.05, 1} // Black Sun (Gold/Bronze)
#define COLOR_HAXION_BROOD 			{0.3, 0.1, 0.4, 1} 	// Dark Purple Bounty Hunters
#define COLOR_HUTT_CARTEL 			{0.1, 0.4, 0.0, 1} 	// Jabba's Green
#define COLOR_ZANN_CONSORTIUM 		{0.5, 0.1, 0.6, 1} 	// Zann Purple
#define COLOR_SYNDICATE_PIKE 		{0.8, 0.7, 0.0, 1} 	// Pike Syndicate (Yellow)
#define COLOR_MANDALORIAN_LOYALIST 	{0.1, 0.3, 0.5, 1} 	// Mandalorian Loyalists (Blue/Grey)
#define COLOR_MANDALORIAN_DEATHWATCH {0.15, 0.15, 0.3, 1} // Mandalorian Death Watch (Dark Blue/Grey)
#define COLOR_DARK_SIDE 			{0.3, 0.0, 0.3, 1} 	// Dark Side / Sith (Deep Purple) 
#define COLOR_REBEL_ALLIANCE 		{0.6, 0.1, 0.1, 1} 	// Rebel Alliance (Red/Orange) 

// --- Corporate & Neutral Colors ---
#define COLOR_CORELLIAN_ENG 		{0.9, 0.9, 0.9, 1} 	// Clean White/Silver (CEC) 
#define COLOR_TRADE_FED 			{0.7, 0.6, 0.3, 1} 	// Yellow-Brown/Gold 
#define COLOR_BLACK_MARKET 			{0.05, 0.05, 0.05, 1} // Near Black/Smuggler Dark 
#define COLOR_CORP_MINING 			{0.9, 0.5, 0.0, 1} 	// Mining Guild (Deep Yellow/Orange)

// --- Imperial/Future Colors ---
#define COLOR_EMPIRE_GREY 			{0.5, 0.5, 0.5, 1} 	// Imperial Standard Grey 
#define COLOR_EMPIRE_ROYAL_GUARD 	{0.9, 0.0, 0.0, 1} 	// Royal Guard Scarlet Red
#define COLOR_FIRST_ORDER 			{0.85, 0.85, 0.85, 1} // Clean White/Silver (First Order)

#define MEC_MARKER_COLOR_CLASS(_NAME, _DISPLAY_NAME, _COLOR_ARRAY) \
class ##_NAME \
{ \
    name = _DISPLAY_NAME; \
    color[] = _COLOR_ARRAY; \
    scope = 2; \
};