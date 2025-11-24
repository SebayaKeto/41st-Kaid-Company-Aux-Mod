params ["_logic"];
// Called on server from client to request cancellation of a running spawn (sets a variable on the module object)
if (!isNull _logic) then {
    _logic setVariable ['HKD_Spawn_Cancel', true, true];
};