_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeBackpack _plyer;

comment "Add containers";
_plyer addBackpack "FST_Backpack_Jumppack";

for "_i" from 1 to 10 do {_plyer addItemToBackpack "FST_blaster_battery_DC15L_Blue";};
