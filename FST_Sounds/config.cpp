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
};

class CfgSoundShaders
{
	#include "Grenades\SoundShaders.hpp"
	#include "Weapons\SoundShaders.hpp"
};

class CfgSoundSets
{
	#include "Grenades\SoundSets.hpp"
	#include "Weapons\SoundSets.hpp"
};
