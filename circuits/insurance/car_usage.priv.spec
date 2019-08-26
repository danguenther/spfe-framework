INPUT_A_parkingspace := 0;
INPUT_A_carusage := 0;
return_value == 10;
---
INPUT_A_parkingspace := 0;
INPUT_A_carusage := 1;
return_value == 30;
---
INPUT_A_parkingspace := 1;
INPUT_A_carusage := 0;
return_value == 20;
---
INPUT_A_parkingspace := 1;
INPUT_A_carusage := 1;
return_value == 40;
---
INPUT_A_parkingspace := 2;
INPUT_A_carusage := 0;
return_value == 35;
---
INPUT_A_parkingspace := 2;
INPUT_A_carusage := 1;
return_value == 55;
