void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->EMRG_STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUTPUT_SWITCH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GRAY_WATER_LEVEL,35,retain)
  __INIT_VAR(data__->FILTER_INPUT_WATER_LEVEL,35,retain)
  __INIT_VAR(data__->FILTER_OUTPUT_WATER_LEVEL,10,retain)
  __INIT_VAR(data__->CLEAN_WATER_LEVEL,3,retain)
  __INIT_VAR(data__->GRAYWATER_PUMP_RPM,0,retain)
  __INIT_VAR(data__->FILTERWATER_PUMP_RPM,0,retain)
  __INIT_VAR(data__->CLEANWATER_PUMP_RPM,0,retain)
  __INIT_VAR(data__->FILTERWATER_VALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLEANWATER_VALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILTER_INFLOW_VALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MIN_WATER_LEVEL,5,retain)
  __INIT_VAR(data__->MAX_WATER_LEVEL,25,retain)
  __INIT_VAR(data__->MAX_PUMP_SPEED,2000,retain)
  __INIT_VAR(data__->MIN_PUMP_SPEED,0,retain)
  __INIT_VAR(data__->MEM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MEM2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MEM3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT5_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT21_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL16_OUT,0,retain)
  __INIT_VAR(data__->_TMP_GT15_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND18_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT24_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND25_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL32_OUT,0,retain)
  __INIT_VAR(data__->_TMP_GT53_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT37_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT40_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND39_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL44_OUT,0,retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_GT5_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CLEAN_WATER_LEVEL,),
    (INT)__GET_VAR(data__->MIN_WATER_LEVEL,)));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->OUTPUT_SWITCH,),
    (BOOL)__GET_VAR(data__->_TMP_GT5_OUT,)));
  __SET_VAR(data__->,_TMP_NOT21_OUT,,!(__GET_VAR(data__->EMRG_STOP,)));
  __SET_VAR(data__->,_TMP_AND13_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND7_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_NOT21_OUT,)));
  __SET_VAR(data__->,MEM1,,__GET_VAR(data__->_TMP_AND13_OUT,));
  __SET_VAR(data__->,_TMP_SEL16_OUT,,SEL__INT__BOOL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->MEM1,),
    (INT)__GET_VAR(data__->MIN_PUMP_SPEED,),
    (INT)__GET_VAR(data__->MAX_PUMP_SPEED,)));
  __SET_VAR(data__->,CLEANWATER_PUMP_RPM,,__GET_VAR(data__->_TMP_SEL16_OUT,));
  __SET_VAR(data__->,CLEANWATER_VALVE,,__GET_VAR(data__->MEM1,));
  __SET_VAR(data__->,_TMP_GT15_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->GRAY_WATER_LEVEL,),
    (INT)__GET_VAR(data__->MIN_WATER_LEVEL,)));
  __SET_VAR(data__->,_TMP_AND18_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->OUTPUT_SWITCH,),
    (BOOL)__GET_VAR(data__->_TMP_GT15_OUT,)));
  __SET_VAR(data__->,_TMP_NOT24_OUT,,!(__GET_VAR(data__->EMRG_STOP,)));
  __SET_VAR(data__->,_TMP_AND25_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND18_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_NOT24_OUT,)));
  __SET_VAR(data__->,MEM2,,__GET_VAR(data__->_TMP_AND25_OUT,));
  __SET_VAR(data__->,_TMP_SEL32_OUT,,SEL__INT__BOOL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->MEM2,),
    (INT)__GET_VAR(data__->MIN_PUMP_SPEED,),
    (INT)__GET_VAR(data__->MAX_PUMP_SPEED,)));
  __SET_VAR(data__->,GRAYWATER_PUMP_RPM,,__GET_VAR(data__->_TMP_SEL32_OUT,));
  __SET_VAR(data__->,FILTER_INFLOW_VALVE,,__GET_VAR(data__->MEM2,));
  __SET_VAR(data__->,_TMP_GT53_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->FILTER_INPUT_WATER_LEVEL,),
    (INT)__GET_VAR(data__->MIN_WATER_LEVEL,)));
  __SET_VAR(data__->,_TMP_LT37_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->FILTER_OUTPUT_WATER_LEVEL,),
    (INT)__GET_VAR(data__->MAX_WATER_LEVEL,)));
  __SET_VAR(data__->,_TMP_NOT40_OUT,,!(__GET_VAR(data__->EMRG_STOP,)));
  __SET_VAR(data__->,_TMP_AND39_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)4,
    (BOOL)__GET_VAR(data__->_TMP_GT53_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_LT37_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_NOT40_OUT,),
    (BOOL)__GET_VAR(data__->OUTPUT_SWITCH,)));
  __SET_VAR(data__->,MEM3,,__GET_VAR(data__->_TMP_AND39_OUT,));
  __SET_VAR(data__->,_TMP_SEL44_OUT,,SEL__INT__BOOL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->MEM3,),
    (INT)__GET_VAR(data__->MIN_PUMP_SPEED,),
    (INT)__GET_VAR(data__->MAX_PUMP_SPEED,)));
  __SET_VAR(data__->,FILTERWATER_PUMP_RPM,,__GET_VAR(data__->_TMP_SEL44_OUT,));
  __SET_VAR(data__->,FILTERWATER_VALVE,,__GET_VAR(data__->MEM3,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





