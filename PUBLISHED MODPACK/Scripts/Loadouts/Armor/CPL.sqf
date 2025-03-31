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

_plyer linkItem "FST_NVG";

comment "Add containers";
_plyer forceAddUniform "FST_Uniform_CPL";
_plyer addVest "FST_Vest_NCO";
_plyer addBackpack "FST_Clone_LR_attachment";

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