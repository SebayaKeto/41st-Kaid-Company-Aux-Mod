class MEC_FusionCell: class Land_WoodenCrate_01_F;
	{
		author = MEC_AUTHOR;
        scope = 2;
        scopecurator = 2;
        displayName = "MEC-P1 M-Pulse Fusion Cell (Stationary)";
        model = "\FST\FST_MEC\FST_MEC_FusionCell\MEC_M-PulseFusionCell.p3d";
        editorCategory = "FST_MEC_CategoryEquipment";
        editorSubcategory = "FST_MEC_SubcategoryBatteries";
        placement = "vertical";
        mapSize = 1;
        destrType = "DestructNo";
		aggregateReflectors[] =
		{
			{"Light_1","Light_2","Light_3","Light_4","Light_5","Light_6","Light_7"}
		};
		class Reflectors
		{
			class Light_1
			{
				color[]= {2500,1000,1000};
				ambient[]= {2.5,1,1};
				intensity= 1;
				size= 0.5;
				innerAngle= 20;
				outerAngle= 100;
				coneFadeCoe= 3;

				position= "Light_1_pos";
				direction= "Light_1_dir";
				hitpoint= "Light_1_HitPoint";

				useFlare= true;
				flareSize= 2;
				flareMaxDistance= 130;

				class Attenuation
				{
					start= 0;
					constant= 0;
					linear= 0;
					quadratic= 0.3;

					hardLimitStart= 50;
					hardLimitEnd= 65;
				};
			};
            class Light_2: Light_1
            {
                position= "Light_2_pos";
                direction= "Light_2_dir";
            };
            class Light_3: Light_1
            {
                position= "Light_3_pos";
                direction= "Light_3_dir";
            };
            class Light_4: Light_1
            {
                position= "Light_4_pos";
                direction= "Light_4_dir";
                blinking= true;
				blinkingPattern[]= {0.25, 1.0};
				blinkingStartsOn= true;
				blinkingPatternGuarantee= true;
            };
            class Light_5: Light_1
            {
                position= "Light_5_pos";
                direction= "Light_5_dir";
            };
            class Light_6: Light_1
            {
                position= "Light_6_pos";
                direction= "Light_6_dir";
            };
            class Light_7: Light_1
            {
                position= "Light_7_pos";
                direction= "Light_7_dir";
                blinking= true;
				blinkingPattern[]= {0.45, 1.30};
				blinkingStartsOn= true;
				blinkingPatternGuarantee= true;
            };
		};
	};