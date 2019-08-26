INPUT_A_age_driver := 0;
INPUT_A_policyholder := 0;
INPUT_A_drivers_under_25 := 0;
INPUT_A_driving_license := 0;
INPUT_A_job := 0;
return_value == 233;
---
INPUT_A_age_driver := 1;
INPUT_A_policyholder := 0;
INPUT_A_drivers_under_25 := 0;
INPUT_A_driving_license := 0;
INPUT_A_job := 1;
return_value == 153;
---
INPUT_A_age_driver := 1;
INPUT_A_policyholder := 1;
INPUT_A_drivers_under_25 := 0;
INPUT_A_driving_license := 0;
INPUT_A_job := 2;
return_value == 158;
---
INPUT_A_age_driver := 1;
INPUT_A_policyholder := 2;
INPUT_A_drivers_under_25 := 0;
INPUT_A_driving_license := 0;
INPUT_A_job := 3;
return_value == 171;
---
INPUT_A_age_driver := 1;
INPUT_A_policyholder := 3;
INPUT_A_drivers_under_25 := 0;
INPUT_A_driving_license := 0;
INPUT_A_job := 4;
return_value == 207;
---
INPUT_A_age_driver := 1;
INPUT_A_policyholder := 4;
INPUT_A_drivers_under_25 := 0;
INPUT_A_driving_license := 0;
INPUT_A_job := 0;
return_value == 229;
---
INPUT_A_age_driver := 0;
INPUT_A_policyholder := 4;
INPUT_A_drivers_under_25 := 1;
INPUT_A_driving_license := 0;
INPUT_A_job := 0;
return_value == 307;
---
INPUT_A_age_driver := 1;
INPUT_A_policyholder := 4;
INPUT_A_drivers_under_25 := 1;
INPUT_A_driving_license := 0;
INPUT_A_job := 0;
return_value == 242;
---
INPUT_A_age_driver := 1;
INPUT_A_policyholder := 4;
INPUT_A_drivers_under_25 := 2;
INPUT_A_driving_license := 0;
INPUT_A_job := 0;
return_value == 255;
---
INPUT_A_age_driver := 1;
INPUT_A_policyholder := 4;
INPUT_A_drivers_under_25 := 2;
INPUT_A_driving_license := 5;
INPUT_A_job := 0;
return_value == 182;
