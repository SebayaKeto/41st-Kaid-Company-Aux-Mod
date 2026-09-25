// Player-tanker rehearsal tuning. Keep existing forward speed limits.
class CfgPatches {
 class FST_Saber_Handling {
  author="41st Aux";
  requiredAddons[]={"3AS_SaberTank","FST_SaberTank"};
  requiredVersion=2.18;units[]={};weapons[]={};
 };
};
class CfgVehicles {
 class 3AS_Saber_01_Base {class complexGearbox;};
 class FST_Saber: 3AS_Saber_01_Base {
  maxSpeed=60;
  peakTorque=7200;
  tankTurnForce=1200000;
  tankTurnForceAngMinSpd=0.2;
  tankTurnForceAngSpd=0.65;
  class complexGearbox: complexGearbox {
   // Stronger reverse pulling force; every forward and transmission ratio stays.
   GearboxRatios[]={"R2",-2.4,"N",0,"D1",4.8,"D2",3.5,"D3",2.6,"D4",2,"D5",1.5,"D6",1.125,"D7",0.85};
  };
 };
 class FST_Recon_Saber: FST_Saber {
  peakTorque=7200;
  // Its existing separate 120 km/h setting is inherited from the loaded class.
 };
};
