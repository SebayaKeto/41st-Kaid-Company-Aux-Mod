_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Add items";
removeVest _plyer;
_plyer addVest "FST_Vest_NCO_Kama";
for "_i" from 1 to 2 do {_plyer addItemToVest "FST_grenade_emp_mag";};