_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeAllWeapons _plyer;
removeAllItems _plyer;
removeAllAssignedItems _plyer;
removeUniform _plyer;
removeVest _plyer;
removeBackpack _plyer;
removeHeadgear _plyer;
removeGoggles _plyer;

comment "Add containers";
_plyer forceAddUniform "FST_Uniform_P1_41st_Krayt";
_plyer addVest "IDA_vest_base";

comment "Add binoculars";
_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";
_plyer addHeadgear "FST_P1_41st";


comment "Add items";
_plyer linkItem "ItemMap";
_plyer linkItem "ItemCompass";
_plyer linkItem "ItemWatch";
_plyer linkItem "JLTS_clone_comlink";
_plyer linkItem "ItemGPS";

_plyer addItemToUniform "ItemcTabHCam";