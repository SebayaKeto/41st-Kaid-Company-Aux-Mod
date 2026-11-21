class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;

    class BUZZ_Radiation_Iodine: ACE_ItemCore {
        scope = 2;
        author = "Connor";
        displayName = "Iodine Tablets";
        descriptionShort = "Potassium iodide blister pack. Halts radiation poisoning for a while and slowly clears the absorbed dose. Give from the ACE medical menu (head).";
        picture = "\BUZZ_Radiation\data\BUZZ_Radiation_iodine_ca.paa";
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class BUZZ_Radiation_Monitor: ACE_ItemCore {
        scope = 2;
        author = "Connor";
        displayName = "Radiation Detection Device";
        descriptionShort = "Wrist-mounted radiation sensor. Open it in the left or right info panel ([ / ] keys). Lets you check a patient's dose from the ACE medical menu.";
        picture = "\BUZZ_Radiation\data\BUZZ_Radiation_monitor_ca.paa";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 2;
        };
    };

    class BUZZ_Radiation_FlushIV: ACE_ItemCore {
        scope = 2;
        author = "Connor";
        displayName = "Radiation Flush IV";
        descriptionShort = "Chelating IV solution. Rapidly clears absorbed radiation, then keeps clearing it for a few minutes. Works even inside a zone. Apply to an arm or leg from the ACE medical menu.";
        picture = "\BUZZ_Radiation\data\BUZZ_Radiation_flushIV_ca.paa";
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 4;
        };
    };
};
