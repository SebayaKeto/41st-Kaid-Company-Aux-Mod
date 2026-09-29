class CfgPatches
{
 class ck_character_fit
 {
  units[]={"CK_Fit_Jedi"};
  weapons[]={"CK_U_Fit_Jedi"};
  requiredVersion=2.14;
  requiredAddons[]={"A3_Characters_F"};
  author="Miran";
 };
};
class CfgVehicles
{
 class B_Soldier_base_F;
 class CK_Fit_Jedi: B_Soldier_base_F
 {
  scope=2;scopeCurator=2;
  author="Miran";
  displayName="Jedi Body C - Arma Fit V2";
  model="\ck_character_fit\ck_uniform.p3d";
  uniformClass="CK_U_Fit_Jedi";
  modelSides[]={0,1,2,3};
  hiddenSelections[]={};
  hiddenSelectionsTextures[]={};
  linkedItems[]={"ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  respawnLinkedItems[]={"ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  weapons[]={"Throw","Put"};
  respawnWeapons[]={"Throw","Put"};
  magazines[]={};respawnMagazines[]={};
 };
};
class CfgWeapons
{
 class Uniform_Base;class UniformItem;
 class CK_U_Fit_Jedi: Uniform_Base
 {
  scope=2;author="Miran";
  displayName="Jedi Body C - Fit V2 Uniform";
  picture="\A3\characters_f\data\ui\icon_U_BasicBody_CA.paa";
  model="\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
  hiddenSelections[]={};hiddenSelectionsTextures[]={};
  class ItemInfo: UniformItem
  {
   uniformModel="-";uniformClass="CK_Fit_Jedi";
   containerClass="Supply40";mass=40;
  };
 };
};
