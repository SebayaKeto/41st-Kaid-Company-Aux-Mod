// FST_FieldMedicine preInit: who may use the field-medicine items (Options > Addon Options > 41st Field Medicine).
// ACE reads these through the treatment actions' medicRequired (0 Anyone, 1 Medics, 2 Doctors).

[
    "FST_fieldMed_medicBacta", "LIST",
    ["Bacta Bandage: who can use it", "Anyone keeps today's behaviour. Medics makes riflemen rely on Kolto Wraps and Synthflesh, so serious wounds need a medic."],
    ["41st Field Medicine", ""], [[0, 1, 2], ["Anyone", "Medics", "Doctors"], 0], 1
] call CBA_fnc_addSetting;

[
    "FST_fieldMed_medicFoam", "LIST",
    ["Coagulant Foam: who can use it", "Medics by default: stopping serious bleeding is the medic's job."],
    ["41st Field Medicine", ""], [[0, 1, 2], ["Anyone", "Medics", "Doctors"], 1], 1
] call CBA_fnc_addSetting;
