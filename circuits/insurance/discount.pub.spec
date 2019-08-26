INPUT_A_price := 19660800;
INPUT_A_payment := 0;
INPUT_A_clubmember := 0;
INPUT_A_publictransport := 0;
INPUT_A_access := 0;
return_value == 0;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 1;
INPUT_A_clubmember := 0;
INPUT_A_publictransport := 0;
INPUT_A_access := 0;
return_value == 196500;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 2;
INPUT_A_clubmember := 0;
INPUT_A_publictransport := 0;
INPUT_A_access := 0;
return_value == 589800;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 3;
INPUT_A_clubmember := 0;
INPUT_A_publictransport := 0;
INPUT_A_access := 0;
return_value == 982800;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 0;
INPUT_A_clubmember := 0;
INPUT_A_publictransport := 0;
INPUT_A_access := 1;
return_value == -294900;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 0;
INPUT_A_clubmember := 0;
INPUT_A_publictransport := 1;
INPUT_A_access := 0;
return_value == -255300;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 0;
INPUT_A_clubmember := 0;
INPUT_A_publictransport := 1;
INPUT_A_access := 1;
return_value == -550200;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 0;
INPUT_A_clubmember := 1;
INPUT_A_publictransport := 0;
INPUT_A_access := 0;
return_value == -982800;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 0;
INPUT_A_clubmember := 1;
INPUT_A_publictransport := 0;
INPUT_A_access := 1;
return_value == -1277700;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 0;
INPUT_A_clubmember := 1;
INPUT_A_publictransport := 1;
INPUT_A_access := 0;
return_value == -1238100;
---
INPUT_A_price := 19660800;
INPUT_A_payment := 0;
INPUT_A_clubmember := 1;
INPUT_A_publictransport := 1;
INPUT_A_access := 1;
return_value == -1533000;
