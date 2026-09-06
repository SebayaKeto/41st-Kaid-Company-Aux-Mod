#define _ARMA_

class CfgPatches
{
	class FST_Sounds
	{
		author = "Maldova";
		name = "FST Sounds";
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_Sounds_F"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
		magazines[]=
		{
		};
		ammo[]=
		{
		};	
	};
	class FST_Sounds_Grenades
	{
		author = "Maldova";
		requiredAddons[] = {"FST_Sounds"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
	};
	class FST_Sounds_Weapons
	{
		author = "Maldova";
		requiredAddons[] = {"FST_Sounds"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
	};
};

class CfgSoundShaders
{
	#define FST_SOUNDS_INCLUDE_SHADERS
	#include "Grenades\SoundShaders.hpp"
	#include "Weapons\SoundShaders.hpp"
	#undef FST_SOUNDS_INCLUDE_SHADERS
};

class CfgSoundSets
{
	#define FST_SOUNDS_INCLUDE_SOUNDSETS
	#include "Grenades\SoundShaders.hpp"
	#include "Weapons\SoundShaders.hpp"
	#undef FST_SOUNDS_INCLUDE_SOUNDSETS
};
