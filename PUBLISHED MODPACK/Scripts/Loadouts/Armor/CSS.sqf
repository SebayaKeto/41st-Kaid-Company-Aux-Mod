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
_plyer forceAddUniform "FST_Uniform_CSS";
_plyer addVest "FST_vest_base";

comment "Add binoculars";
_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";
_plyer addHeadgear "FST_P2_Helmet";

comment "Add items";
_plyer linkItem "ItemMap";
_plyer linkItem "ItemCompass";
_plyer linkItem "ItemWatch";
_plyer linkItem "FST_clone_comlink";
_plyer linkItem "ItemGPS";

_plyer addItemToUniform "ItemcTabHCam";