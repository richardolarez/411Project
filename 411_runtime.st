PROGRAM program0
  VAR
    Emrg_Stop AT %QX0.0 : BOOL;
    Output_switch AT %QX0.1 : BOOL;
    Gray_water_level AT %IW1 : INT := 35;
    Filter_Input_water_level AT %IW2 : INT := 35;
    Filter_Output_water_level AT %IW3 : INT := 10;
    Clean_water_level AT %IW4 : INT := 3;
    Graywater_Pump_RPM AT %IW5 : INT;
    Filterwater_Pump_RPM AT %IW6 : INT;
    Cleanwater_Pump_RPM AT %IW7 : INT;
    Filterwater_Valve AT %QX0.3 : BOOL;
    Cleanwater_Valve AT %QX0.4 : BOOL;
    Filter_inflow_Valve AT %QX0.5 : BOOL;
    Min_Water_Level AT %MW0 : INT := 5;
    Max_Water_Level AT %MW1 : INT := 25;
    Max_pump_speed AT %MW2 : INT := 2000;
    Min_pump_speed AT %MW3 : INT := 0;
    Mem1 AT %MX4.0 : BOOL;
    Mem2 AT %MX4.1 : BOOL;
    Mem3 AT %MX4.2 : BOOL;
  END_VAR
  VAR
    _TMP_GT5_OUT : BOOL;
    _TMP_AND7_OUT : BOOL;
    _TMP_NOT21_OUT : BOOL;
    _TMP_AND13_OUT : BOOL;
    _TMP_SEL16_OUT : INT;
    _TMP_GT15_OUT : BOOL;
    _TMP_AND18_OUT : BOOL;
    _TMP_NOT24_OUT : BOOL;
    _TMP_AND25_OUT : BOOL;
    _TMP_SEL32_OUT : INT;
    _TMP_GT53_OUT : BOOL;
    _TMP_LT37_OUT : BOOL;
    _TMP_NOT40_OUT : BOOL;
    _TMP_AND39_OUT : BOOL;
    _TMP_SEL44_OUT : INT;
  END_VAR

  _TMP_GT5_OUT := GT(Clean_water_level, Min_Water_Level);
  _TMP_AND7_OUT := AND(Output_switch, _TMP_GT5_OUT);
  _TMP_NOT21_OUT := NOT(Emrg_Stop);
  _TMP_AND13_OUT := AND(_TMP_AND7_OUT, _TMP_NOT21_OUT);
  Mem1 := _TMP_AND13_OUT;
  _TMP_SEL16_OUT := SEL(Mem1, Min_pump_speed, Max_pump_speed);
  Cleanwater_Pump_RPM := _TMP_SEL16_OUT;
  Cleanwater_Valve := Mem1;
  _TMP_GT15_OUT := GT(Gray_water_level, Min_Water_Level);
  _TMP_AND18_OUT := AND(Output_switch, _TMP_GT15_OUT);
  _TMP_NOT24_OUT := NOT(Emrg_Stop);
  _TMP_AND25_OUT := AND(_TMP_AND18_OUT, _TMP_NOT24_OUT);
  Mem2 := _TMP_AND25_OUT;
  _TMP_SEL32_OUT := SEL(Mem2, Min_pump_speed, Max_pump_speed);
  Graywater_Pump_RPM := _TMP_SEL32_OUT;
  Filter_inflow_Valve := Mem2;
  _TMP_GT53_OUT := GT(Filter_Input_water_level, Min_Water_Level);
  _TMP_LT37_OUT := LT(Filter_Output_water_level, Max_Water_Level);
  _TMP_NOT40_OUT := NOT(Emrg_Stop);
  _TMP_AND39_OUT := AND(_TMP_GT53_OUT, _TMP_LT37_OUT, _TMP_NOT40_OUT, Output_switch);
  Mem3 := _TMP_AND39_OUT;
  _TMP_SEL44_OUT := SEL(Mem3, Min_pump_speed, Max_pump_speed);
  Filterwater_Pump_RPM := _TMP_SEL44_OUT;
  Filterwater_Valve := Mem3;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
