class CfgPatches
{
	class FST_Audio_Tracks
	{
		requiredAddons[]={};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
	};
};
class CfgMusicClasses
{
	class FST_StarWars
	{
		displayName="41st - Star Wars";
	};
	class FST_OtherGames
	{
		displayName="41st - Game Tracks";
	};
	class FST_OtherFilms
	{
		displayName="41st - Film Tracks";
	};
	class FST_Misc
	{
		displayName="41st - Misc Tracks";
	};
	class FST_Mission_Music
	{
		displayName="41st - Mission Tracks (Daara Only)";
	};
};

// With Thanks to Splice for all his help.

class CfgMusic
{
	Tracks[]=
	{
		//Star Wars
		"FST_AftermathMandalore",
		"FST_Arrival",
		"FST_BuryingtheDead",
		"FST_CloneArmyTheme",
		"FST_CloneSacrifice",
		"FST_DroidArmyMarch",
		"FST_Immolation",
		"FST_JourneytoMosPelgo",
		"FST_ScherzoforXWings",
		"FST_Shattered",
		"FST_Shipohoj",
		"FST_SneakingUnderTheShield",
		"FST_ThroneRoom",
		"FST_battleOfChristophsis",
		"FST_PointRain",
		"FST_GeneralGrevious",
		"FST_AhsokaVsRex",
		"FST_ObiWanToTheRescue",
		"FST_BattleOfTeth",
		"FST_MaulSavageTheme",
		"FST_CrashCourseMoon",
		"FST_TowerBattle",
		"FST_BattleOfUmbara",
		"FST_BuzzDroids",
		"FST_BattleOfGeonosis",
		"FST_ObiWanVSVader_Epic",
		"FST_ShadyClubMusic",

		//Game tracks
		"FST_Halo2_MjolnirMix",
		"FST_HaloReach_DeadAhead",
		"FST_Destiny_TheLastArray",
		"FST_Destiny_UntoldLegends",
		"FST_TFFOC_MainTheme",
		"FST_WT_WaltzoftheTornado",		
		"FST_HelldiversTheme",
		"FST_HelldiversExtraction",
		"FST_SeekingtheLight",
		"FST_ForsakenGunslinger",
		"FST_DarktideWarpTraveller",
		"FST_DarktideImmortalImperum",
		"FST_DarktideNightsider",
		"FST_DarktideRealitySlipping",
		"FST_DarktideDisposalUnit",
		"FST_DarktideDataInterference",
		"FST_Destiny_StrongerTogether",
		"FST_Destiny_TheRose",
		"FST_Destiny_WhatWeFightFor",
		"FST_Destiny_Warmind",
		"FST_Destiny_HeraldofFinality",
		"FST_Destiny_HopeInBloom",
		"FST_Destiny_MakeYourOwnFate",
		"FST_Destiny_ParacausalMutilation",
		"FST_Destiny_Perservate",
		
		
		//Misc tracks
		"FST_TF1_Youreasoldiernow",
		"FST_banana",
		"FST_TornadoOfSouls",
		"FST_Stormtroopers",
		"FST_SteelCommanders",
		"FST_NightWitches",
		"FST_GhostDivision",
		"FST_KlendathuDropCover",
		"FST_RideoftheValkyriesMetal",
		"FST_Gloryhammer",
		"FST_Hill3234",
		"FST_BuddyHollyHatsuneMiku",
		
		//Mission Tracks
		"FST_Totharvis_Moon_1",
		"FST_Totharvis_Moon_2",
		"FST_Totharvis_Moon_3",
		"FST_Totharvis_Moon_4",	
		"FST_Horn_of_Plenty",
		"FST_ShipAlert",
	};
	
	//Mission Tracks
	
	class FST_Totharvis_Moon_1
	{
		name="Totharvis Moon 1";
		musicClass="FST_Mission_Music";
		sound[]=
		{
			"41st_Music\MissionTracks\Palchaff_Totharvis_Moon_1.ogg",
			1,
			1
		};
		duration="18";
	};
	class FST_Totharvis_Moon_2
	{
		name="Totharvis Moon 2";
		musicClass="FST_Mission_Music";
		sound[]=
		{
			"41st_Music\MissionTracks\Palchaff_Totharvis_Moon_2.ogg",
			1,
			1
		};
		duration="16";
	};
	class FST_Totharvis_Moon_3
	{
		name="Totharvis Moon 3";
		musicClass="FST_Mission_Music";
		sound[]=
		{
			"41st_Music\MissionTracks\Palchaff_Totharvis_Moon_3.ogg",
			1,
			1
		};
		duration="20";
	};
	class FST_Totharvis_Moon_4
	{
		name="Totharvis Moon 4";
		musicClass="FST_Mission_Music";
		sound[]=
		{
			"41st_Music\MissionTracks\Palchaff_Totharvis_Moon_4.ogg",
			1,
			1
		};
		duration="19";
	};
	class FST_Horn_Of_Plenty
	{
		name="Hunger Games - Horn of Plenty";
		musicClass="FST_Mission_Music";
		sound[]=
		{
			"41st_Music\MissionTracks\Horn_Of_Plenty.ogg",
			1,
			1
		};
		duration="211";
	};
	class FST_ShipAlert
	{
		name="Ship Alert Siren";
		musicClass="FST_Mission_Music";
		sound[]=
		{
			"41st_Music\MissionTracks\ShipAlert (1).ogg",
			2,
			1
		};
		duration="60";
	};
	// Star Wars
	class FST_GeneralGrevious
	{
		name="(The Clone Wars) General Grevious' theme";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\General_Grevious_KIM.ogg",
			1,
			1
		};
		duration="184";
	};
	class FST_AhsokaVsRex
	{
		name="(The Clone Wars) Ahsoka vs Rex, Order 66";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Ahsoka_vs_Rex_Order_66.ogg",
			1,
			1
		};
		duration="87";
	};
	class FST_ObiWanToTheRescue
	{
		name="(The Clone Wars) Obi-Wan to the rescue";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Obi-Wan_To_The_Rescue.ogg",
			1,
			1
		};
		duration="74";
	};
	class FST_BattleOfTeth
	{
		name="(The Clone Wars) Battle of Teth";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Battle_of_Teth.ogg",
			1,
			1
		};
		duration="146";
	};
	class FST_MaulSavageTheme
	{
		name="(The Clone Wars) Maul & Savage's Theme";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Darth_Maul_Savage_Opress_Theme_KIM.ogg",
			1,
			1
		};
		duration="260";
	};
	class FST_CrashCourseMoon
	{
		name="(The Clone Wars) Crash Course Moon";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Crash_Course_Moon.ogg",
			1,
			1
		};
		duration="77";
	};
	class FST_TowerBattle
	{
		name="(The Clone Wars) Tower Battle";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Tower_Battle.ogg",
			1,
			1
		};
		duration="134";
	};
	class FST_battleOfChristophsis
	{
		name="(The Clone Wars) Battle of Christophsis";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\battleOfChristophsis.ogg",
			1,
			1
		};
		duration="199";
	};
	class FST_BattleOfUmbara
	{
		name="(The Clone Wars) Battle Of Umbara";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Battle_of_Umbara.ogg",
			1,
			1
		};
		duration="125";
	};
	class FST_BattleOfGeonosis
	{
		name="(The Clone Wars) Battle Of Geonosis";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Battle_of_Geonosis.ogg",
			1,
			1
		};
		duration="298";
	};
	class FST_BuzzDroids
	{
		name="(The Clone Wars) Buzz Droids";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\BuzzDroids.ogg",
			1,
			1
		};
		duration="179";
	};
	class FST_PointRain
	{
		name="(The Clone Wars) Landing At Point Rain";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\pointRain.ogg",
			1,
			1
		};
		duration="90";
	};
	class FST_AftermathMandalore
	{
		name="(The Clone Wars) Aftermath in Mandalore";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Aftermath_in_Mandalore.ogg",
			1,
			1
		};
		duration="82";
	};
	class FST_BuryingtheDead
	{
		name="(The Clone Wars) Burying the Dead";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Burying_the_Dead.ogg",
			1,
			1
		};
		duration="133";
	};
	class FST_CloneSacrifice
	{
		name="(The Clone Wars) Clone Sacrifice";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Clone_Sacrifice.ogg",
			1,
			1
		};
		duration="179";
	};
	class FST_Shattered
	{
		name="(The Clone Wars) Shattered";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Shattered.ogg",
			1,
			1
		};
		duration="151";
	};
	class FST_SneakingUnderTheShield
	{
		name="(The Clone Wars) Sneaking Under The Shield";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\SneakingUnderTheShield.ogg",
			1,
			1
		};
		duration="219";
	};
	class FST_ScherzoforXWings
	{
		name="(Episode 4) Scherzo for X-Wings";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Scherzo_for_X-Wings.ogg",
			1,
			1
		};
		duration="93";
	};
	class FST_DroidArmyMarch
	{
		name="(Episode 1) Droid Army March";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Droid_Army_March.ogg",
			1,
			1
		};
		duration="206";
	};
	class FST_ThroneRoom
	{
		name="(Episode 1) Throne Room";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\ThroneRoom.ogg",
			1,
			1
		};
		duration="121";
	};
	class FST_JourneytoMosPelgo
	{
		name="(The Mandalorian) Journey to Mos Pelgo";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\JourneytoMosPelgo.ogg",
			1,
			1
		};
		duration="266";
	};
	class FST_Arrival
	{
		name="(The Mandalorian) The Arrival, Gideon's Theme";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Arrival.ogg",
			1,
			1
		};
		duration="196";
	};
	class FST_Shipohoj
	{
		name="(The Mandalorian) Ship O' Hoj!";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Shipohoj.ogg",
			1,
			1
		};
		duration="306";
	};
	class FST_CloneArmyTheme
	{
		name="(Playlist) Clone Army Theme";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\CloneArmyTheme.ogg",
			1,
			1
		};
		duration="555";
	};
	class FST_Immolation
	{
		name="(Playlist) Immolation";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Immolation.ogg",
			1,
			1
		};
		duration="557";
	};
	class FST_ObiWanVSVader_Epic
	{
		name="(Samual Kim EPIC cover) ObiWan Vs Vader";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\ObiWanVSVader_Epic.ogg",
			1,
			1
		};
		duration="298";
	};
	class FST_ShadyClubMusic
	{
		name="(PufferGlitch) Shady Nightclub";
		musicClass="FST_StarWars";
		sound[]=
		{
			"41st_Music\StarWarsTracks\Shady Nightclub - Star Wars Ambience (Cantina Music Dark Club) [TubeRipper.cc].ogg",
			1,
			1
		};
		duration="5422";
	};
	
	
	
	//Games
	class FST_Halo2_MjolnirMix
	{
		name="(Halo 2) Mjolnir Mix";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Halo2_MjolnirMix.ogg",
			1,
			1
		};
		duration="250";
	};
	class FST_HaloReach_DeadAhead
	{
		name="(Halo Reach) Dead Ahead";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\HaloReach_Dead_Ahead.ogg",
			1,
			1
		};
		duration="150";
	};
	class FST_Destiny_TheLastArray
	{
		name="(Destiny) The Last Array";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Destiny_TheLastArray.ogg",
			1,
			1
		};
		duration="415";
	};
	class FST_Destiny_UntoldLegends
	{
		name="(Destiny) Untold Legends";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Destiny_UntoldLegends.ogg",
			1,
			1
		};
		duration="212";
	};
	class FST_TFFOC_MainTheme
	{
		name="(Transformers Fall Of Cybertron) Main Theme";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\TFFOC_Main.ogg",
			1,
			1
		};
		duration="142";
	};
	class FST_WT_WaltzoftheTornado
	{
		name="(War Thunder) Waltz of the Tornado";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\WT_Waltz.ogg",
			1,
			1
		};
		duration="293";
	};
	class FST_HelldiversTheme
	{
		name="(Helldivers 2) Main Theme";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Helldivers-2-Main-Theme.ogg",
			1,
			1
		};
		duration="217";
	};
	class FST_HelldiversExtraction
	{
		name="(Helldivers 2) Extraction Theme";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Helldivers-2-ExtractionMission-Completion-Theme.ogg",
			1,
			1
		};
		duration="301";
	};
	class FST_SeekingtheLight
	{
		name="(Destiny 2) Seeking the Light";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Destiny_SeekingtheLight.ogg",
			1,
			1
		};
		duration="180";
	};
	class FST_ForsakenGunslinger
	{
		name="(Destiny 2) Forsaken - The Gunslinger";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Destiny-2-Forsaken-Soundtrack-The-Gunslinger.ogg",
			1,
			1
		};
		duration="890";
	};
	class FST_DarktideWarpTraveller
	{
		name="(Darktide) Warp Traveller";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Warhammer_40000_Darktide_-_Official_Soundtrack_Warp_Traveller_TubeRipper.cc.ogg",
			1,
			1
		};
		duration="190";
	};
	class FST_DarktideImmortalImperum
	{
		name="(Darktide) Immortal Imperium";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Darktide_OST__IMMORTAL_IMPERIUM_TubeRipper.cc.ogg",
			1,
			1
		};
		duration="232";
	};
	class FST_DarktideNightsider
	{
		name="(Darktide) Nightsider";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Darktide_OST__NIGHTSIDER_TubeRipper.cc.ogg",
			1,
			1
		};
		duration="181";
	};
	class FST_DarktideRealitySlipping
	{
		name="(Darktide) Reality Slipping";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Darktide_OST__REALITY_SLIPPING_TubeRipper.cc.ogg",
			1,
			1
		};
		duration="220";
	};
	class FST_DarktideDisposalUnit
	{
		name="(Darktide) Disposal Unit";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Darktide_OST__DISPOSAL_UNIT_TubeRipper.cc.ogg",
			1,
			1
		};
		duration="220";
	};
	class FST_DarktideDataInterference
	{
		name="(Darktide) Data Interference";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Darktide_OST__DATA_INTERFERENCE_TubeRipper.cc.ogg",
			1,
			1
		};
		duration="194";
	};
	class FST_Destiny_StrongerTogether
	{
		name="(Destiny 2) Stronger Together";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Stronger_-Together-_High-Action_-Destiny-2_-The-Final-Shape-OST.ogg",
			1,
			1
		};
		duration="192";
	};
	class FST_Destiny_TheRose
	{
		name="(Destiny 2) The Rose";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Destiny-OST-15-Excerpt-1-from-The-Rose.ogg",
			1,
			1
		};
		duration="121";
	};
	class FST_Destiny_WhatWeFightFor
	{
		name="(Destiny 2) What We Fight For";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Destiny-2-Original-Soundtrack-Track-15-What-We-Fight-For.ogg",
			1,
			1
		};
		duration="190";
	};
	class FST_Destiny_Warmind
	{
		name="(Destiny 2) The Warmind";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Destiny-OST-5-The-Warmind.ogg",
			1,
			1
		};
		duration="190";
	};
	class FST_Destiny_HeraldofFinality
	{
		name="(Destiny 2) Herald of Finality";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Herald-of-finality.ogg",
			1,
			1
		};
		duration="187";
	};
	class FST_Destiny_HopeInBloom
	{
		name="(Destiny 2) Hope in Bloom";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Hope-in-Bloom.ogg",
			1,
			1
		};
		duration="202";
	};
	class FST_Destiny_MakeYourOwnFate
	{
		name="(Destiny 2) Make Your Own Fate";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Make-your-own-fate.ogg",
			1,
			1
		};
		duration="268";
	};
	class FST_Destiny_ParacausalMutilation
	{
		name="(Destiny 2) Paracausal Mutilation";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Paracausal-Mutilation.ogg",
			1,
			1
		};
		duration="260";
	};
	class FST_Destiny_Perservate
	{
		name="(Destiny 2) Perserverate";
		musicClass="FST_OtherGames";
		sound[]=
		{
			"41st_Music\GameTracks\Perserverate.ogg",
			1,
			1
		};
		duration="189";
	};

	//Films
	
	class FST_TF1_Youreasoldiernow
	{
		name="(Transformers 2007) You're a soldier now";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\TF1_YoureASoldierNow.ogg",
			1,
			1
		};
		duration="49";
	};
	
	//Other
	
	class FST_banana
	{
		name="banana";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\banana.ogg",
			1,
			1
		};
		duration="4";
	};
	class FST_TornadoOfSouls
	{
		name="Tornado Of Souls - Megadeth";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\TornadoOfSouls.ogg",
			1,
			1
		};
		duration="318";
	};
	class FST_Stormtroopers
	{
		name="Stormtroopers - Sabaton";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\Stormtroopers.ogg",
			1,
			1
		};
		duration="236";
	};
	class FST_SteelCommanders
	{
		name="Steel Commanders - Sabaton";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\SteelCommanders.ogg",
			1,
			1
		};
		duration="231";
	};
	class FST_NightWitches
	{
		name="Night Witches - Sabaton";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\NightWitches.ogg",
			1,
			1
		};
		duration="181";
	};
	class FST_GhostDivision
	{
		name="Ghost Division - Sabaton";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\GhostDivision.ogg",
			1,
			1
		};
		duration="230";
	};
	class FST_KlendathuDropCover
	{
		name="Klendathu Drop - Enhanced Replications";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\KlendathuDropCover.ogg",
			1,
			1
		};
		duration="274";
	};
	class FST_ShatterTheEmpires
	{
		name="Shatter The Empires - HoI IV";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\ShatterTheEmpires.ogg",
			1,
			1
		};
		duration="240";
	};
	class FST_RideoftheValkyriesMetal
	{
		name="Ride of the Valkyries - Metal Edition";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\Ride-of-the-Valkyries.ogg",
			1,
			1
		};
		duration="206";
	};
	class FST_Gloryhammer
	{
		name="Gloryhammer - Hootsforce";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\Gloryhammer-Hootsforce.ogg",
			1,
			1
		};
		duration="230";
	};
	class FST_Hill3234
	{
		name="Hill 3234 - Sabaton";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\SABATON_-_Hill_3234.ogg",
			1,
			1
		};
		duration="211";
	};
	class FST_BuddyHollyHatsuneMiku
	{
		name="Buddy Holly - Hatsune Miku Cover";
		musicClass="FST_Misc";
		sound[]=
		{
			"41st_Music\MiscTracks\Hatsune_Miku_Buddy_Holly.ogg",
			1,
			1
		};
		duration="160";
	};
};
