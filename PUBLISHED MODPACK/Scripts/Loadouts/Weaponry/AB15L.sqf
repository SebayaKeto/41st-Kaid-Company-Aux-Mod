_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeBackpack _plyer;

comment "Add containers";
_plyer addBackpack "FST_Clone_Backpack_Invisible_15L";

for "_i" from 1 to 15 do {_plyer addItemToBackpack "FST_blaster_battery_DC15L_Blue";};
