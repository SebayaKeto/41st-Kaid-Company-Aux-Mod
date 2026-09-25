params ["_unit"];
!isNull _unit && {_unit isKindOf "CAManBase"} && {alive _unit} && {
    lifeState _unit=="INCAPACITATED" || {_unit getVariable ["ACE_isUnconscious",false]}
}
