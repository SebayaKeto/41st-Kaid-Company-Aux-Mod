_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

comment "Add weapons";
_plyer addWeapon "FST_DC17";
_plyer addHandgunItem "FST_blaster_cell_low_Blue";
_plyer addHandgunItem "3as_optic_holo_dc15s";

comment "Add items to containers";
for "_i" from 1 to 6 do {_plyer addItemToVest "FST_blaster_cell_low_Blue";};