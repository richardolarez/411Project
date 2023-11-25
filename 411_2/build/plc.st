TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM program0
  VAR
    Emrg_Stop : BOOL;
    Output_switch : BOOL;
    Gray_water_level : INT := 35;
    Filter_Input_water_level : INT := 35;
    Filter_Output_water_level : INT := 10;
    Clean_water_level : INT := 3;
    Graywater_Pump_RPM : INT;
    Filterwater_Pump_RPM : INT;
    Cleanwater_Pump_RPM : INT;
    Filterwater_Valve : BOOL;
    Cleanwater_Valve : BOOL;
    Filter_inflow_Valve : BOOL;
    Min_Water_Level : INT := 5;
    Max_Water_Level : INT := 25;
    Max_pump_speed : INT := 2000;
    Min_pump_speed : INT := 0;
    Mem1 : BOOL;
    Mem2 : BOOL;
    Mem3 : BOOL;
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
