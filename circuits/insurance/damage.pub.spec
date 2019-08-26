INPUT_A_dmg1 := {years : 1; ensurance : 0; workshop_costs : 200;};
INPUT_A_dmg2 := {years : 0; ensurance : 0; workshop_costs : 0;};
INPUT_B_workshopthres := 100; 
INPUT_B_yearsthres := 5;
INPUT_B_liabilitycosts := 1310;
INPUT_B_partialcoveredcosts := 655;
INPUT_B_fullycomprehensivecosts := 1966;
INPUT_B_workshopcosts := 1310;
return_value == 1310;
---
INPUT_A_dmg1 := {years : 5; ensurance : 1; workshop_costs : 50;};
INPUT_A_dmg2 := {years : 5; ensurance : 2; workshop_costs : 50;};
INPUT_B_workshopthres := 100; 
INPUT_B_yearsthres := 5;
INPUT_B_liabilitycosts := 1310;
INPUT_B_partialcoveredcosts := 655;
INPUT_B_fullycomprehensivecosts := 1966;
INPUT_B_workshopcosts := 1310;
return_value == 1965;
---
INPUT_A_dmg1 := {years : 5; ensurance : 3; workshop_costs : 700;};
INPUT_A_dmg2 := {years : 5; ensurance : 2; workshop_costs : 500;};
INPUT_B_workshopthres := 100; 
INPUT_B_yearsthres := 5;
INPUT_B_liabilitycosts := 1310;
INPUT_B_partialcoveredcosts := 655;
INPUT_B_fullycomprehensivecosts := 1966;
INPUT_B_workshopcosts := 1310;
return_value == 5241;
---

