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