class CfgPatches
{
	class FST_Electrobinoculars
	{
		author="Viz";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"A3_Characters_F_Proxies"
		};
		units[]={};
		weapons[]={};
		magazines[]={};
	};
};
class CfgWeapons
{
	class Laserdesignator;
	class FST_Electrobinoculars: Laserdesignator
	{
		author="Adapted from Indecisive Armoury Team by Viz";
		scope=2;
		baseWeapon="IDA_Laserdesignator_Rep";
		displayName="[41st] Kaid Company Electrobinoculars";
		descriptionShort="Republic Electrobinoculars";
		picture="\Indecisive_Armoury_Weapons_REPUBLIC\Data\Electrobinoculars\Electrobinoculars_Rep_UI.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\Electrobinoculars\Model\IDA_Electrobinoculars_Rep.p3d";
		modelOptics="Indecisive_Armoury_Weapons_REPUBLIC\Data\Electrobinoculars\2dScope\IDA_Electrobinoculars_Rep_Scope.p3d";
	};
};