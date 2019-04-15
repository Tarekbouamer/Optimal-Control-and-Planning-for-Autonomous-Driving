/* Include files */

#include <stddef.h>
#include "blas.h"
#include "finding_drag_sfun.h"
#include "c1_finding_drag.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "finding_drag_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[11] = { "params", "nargin", "nargout",
  "FxF", "FxR", "wF", "wR", "brake", "handbrake", "TbF", "TbR" };

/* Function Declarations */
static void initialize_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance);
static void initialize_params_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance);
static void enable_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance);
static void disable_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_finding_drag
  (SFc1_finding_dragInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_finding_drag
  (SFc1_finding_dragInstanceStruct *chartInstance);
static void set_sim_state_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance);
static void sf_gateway_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance);
static void initSimStructsc1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_finding_dragInstanceStruct *chartInstance,
  const mxArray *c1_TbR, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_d_emlrt_marshallIn(SFc1_finding_dragInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  c1_snXp3ygPcVyeDzfVLtVbyQF *c1_y);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_finding_drag, const char_T
  *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_finding_dragInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_finding_drag = 0U;
}

static void initialize_params_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance)
{
  const mxArray *c1_m0 = NULL;
  const mxArray *c1_mxField;
  c1_snXp3ygPcVyeDzfVLtVbyQF c1_r0;
  c1_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c1_mxField = sf_mex_getfield(c1_m0, "m", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.m, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "Iz", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.Iz, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "Iw", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.Iw, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "lF", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.lF, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "lR", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.lR, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "h", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.h, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "R", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.R, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "B", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.B, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "C", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.C, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "maxDelta", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.maxDelta, 1, 0,
                      0U, 0, 0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "maxTb", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.maxTb, 1, 0, 0U,
                      0, 0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "maxThb", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.maxThb, 1, 0, 0U,
                      0, 0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "maxTm", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.maxTm, 1, 0, 0U,
                      0, 0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "gammaB", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.gammaB, 1, 0, 0U,
                      0, 0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "gammaM", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.gammaM, 1, 0, 0U,
                      0, 0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "g", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.g, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "mu", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.mu, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "muRoll", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.muRoll, 1, 0, 0U,
                      0, 0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "b", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.b, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "FzF", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.FzF, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "FzR", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.FzR, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "Dz1", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.Dz1, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "Dz2", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.Dz2, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "T", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.T, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "WF0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.WF0, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "WR0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.WR0, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "Ux0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.Ux0, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "Uy0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.Uy0, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "r0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.r0, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "x0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.x0, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "y0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0._y0, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "ksi0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c1_mxField), &c1_r0.ksi0, 1, 0, 0U, 0,
                      0U, 0);
  sf_mex_destroy(&c1_m0);
  chartInstance->c1_params = c1_r0;
}

static void enable_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_finding_drag
  (SFc1_finding_dragInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_finding_drag
  (SFc1_finding_dragInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_TbF;
  real_T *c1_TbR;
  c1_TbR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_TbF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(3, 1), false);
  c1_hoistedGlobal = *c1_TbF;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_TbR;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_finding_drag;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_TbF;
  real_T *c1_TbR;
  c1_TbR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_TbF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *c1_TbF = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "TbF");
  *c1_TbR = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "TbR");
  chartInstance->c1_is_active_c1_finding_drag = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_finding_drag");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_finding_drag(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_FxF;
  real_T c1_FxR;
  real_T c1_wF;
  real_T c1_wR;
  real_T c1_brake;
  real_T c1_handbrake;
  uint32_T c1_debug_family_var_map[11];
  c1_snXp3ygPcVyeDzfVLtVbyQF c1_b_params;
  real_T c1_nargin = 7.0;
  real_T c1_nargout = 2.0;
  real_T c1_TbF;
  real_T c1_TbR;
  static c1_snXp3ygPcVyeDzfVLtVbyQF c1_r1 = { 1270.0, 1200.0, 1.8, 1.015, 1.895,
    0.54, 0.325, 11.3295, 1.5305, 45.0, 3000.0, 1000.0, 1000.0, 0.4, 0.0, 9.81,
    0.8, 0.03, 2.0, 8113.13969072165, 4345.56030927835, 0.05,
    0.017453292519943295, 0.1, 42.735042735042732, 42.735042735042732,
    13.888888888888889, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T *c1_b_FxF;
  real_T *c1_b_TbF;
  real_T *c1_b_FxR;
  real_T *c1_b_wF;
  real_T *c1_b_wR;
  real_T *c1_b_brake;
  real_T *c1_b_handbrake;
  real_T *c1_b_TbR;
  c1_b_TbR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_handbrake = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_brake = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_wR = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_wF = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_FxR = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_TbF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_FxF = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_FxF, 0U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_FxF;
  c1_b_hoistedGlobal = *c1_b_FxR;
  c1_c_hoistedGlobal = *c1_b_wF;
  c1_d_hoistedGlobal = *c1_b_wR;
  c1_e_hoistedGlobal = *c1_b_brake;
  c1_f_hoistedGlobal = *c1_b_handbrake;
  c1_FxF = c1_hoistedGlobal;
  c1_FxR = c1_b_hoistedGlobal;
  c1_wF = c1_c_hoistedGlobal;
  c1_wR = c1_d_hoistedGlobal;
  c1_brake = c1_e_hoistedGlobal;
  c1_handbrake = c1_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_params, 0U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_FxF, 3U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_FxR, 4U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_wF, 5U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_wR, 6U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_brake, 7U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_handbrake, 8U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TbF, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TbR, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  c1_b_params = c1_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_TbF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_TbR = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c1_brake > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
    if (CV_EML_IF(0, 1, 1, c1_wF != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
      c1_x = c1_wF;
      c1_b_x = c1_x;
      c1_b_x = muDoubleScalarSign(c1_b_x);
      c1_TbF = -c1_brake * 0.6 * c1_b_x;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
      c1_TbF = c1_FxF * 0.325;
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
    if (CV_EML_IF(0, 1, 2, c1_wR != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
      c1_c_x = c1_wR;
      c1_d_x = c1_c_x;
      c1_d_x = muDoubleScalarSign(c1_d_x);
      c1_TbR -= c1_brake * 0.4 * c1_d_x;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      c1_TbR = c1_FxR * 0.325;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  if (CV_EML_IF(0, 1, 3, c1_handbrake > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
    if (CV_EML_IF(0, 1, 4, c1_wR != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
      c1_e_x = c1_wR;
      c1_f_x = c1_e_x;
      c1_f_x = muDoubleScalarSign(c1_f_x);
      c1_TbR -= c1_handbrake * c1_f_x;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
      c1_TbR = c1_FxR * 0.325;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_TbF = c1_TbF;
  *c1_b_TbR = c1_TbR;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_finding_dragMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c1_b_TbF, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_FxR, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_wF, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_wR, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_b_brake, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_b_handbrake, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_b_TbR, 8U);
}

static void initSimStructsc1_finding_drag(SFc1_finding_dragInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc1_finding_dragInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_finding_dragInstanceStruct *chartInstance,
  const mxArray *c1_TbR, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_TbR), &c1_thisId);
  sf_mex_destroy(&c1_TbR);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_TbR;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc1_finding_dragInstanceStruct *)chartInstanceVoid;
  c1_TbR = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_TbR), &c1_thisId);
  sf_mex_destroy(&c1_TbR);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_snXp3ygPcVyeDzfVLtVbyQF c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_m_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_n_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_o_u;
  const mxArray *c1_o_y = NULL;
  real_T c1_p_u;
  const mxArray *c1_p_y = NULL;
  real_T c1_q_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_r_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_s_u;
  const mxArray *c1_s_y = NULL;
  real_T c1_t_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_u_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_v_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_w_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_x_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_y_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_ab_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_bb_u;
  const mxArray *c1_bb_y = NULL;
  real_T c1_cb_u;
  const mxArray *c1_cb_y = NULL;
  real_T c1_db_u;
  const mxArray *c1_db_y = NULL;
  real_T c1_eb_u;
  const mxArray *c1_eb_y = NULL;
  real_T c1_fb_u;
  const mxArray *c1_fb_y = NULL;
  real_T c1_gb_u;
  const mxArray *c1_gb_y = NULL;
  real_T c1_hb_u;
  const mxArray *c1_hb_y = NULL;
  SFc1_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc1_finding_dragInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_snXp3ygPcVyeDzfVLtVbyQF *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_b_u = c1_u.m;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_b_y, "m", "m", 0);
  c1_c_u = c1_u.Iz;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_c_y, "Iz", "Iz", 0);
  c1_d_u = c1_u.Iw;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_d_y, "Iw", "Iw", 0);
  c1_e_u = c1_u.lF;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_e_y, "lF", "lF", 0);
  c1_f_u = c1_u.lR;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_f_y, "lR", "lR", 0);
  c1_g_u = c1_u.h;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_g_y, "h", "h", 0);
  c1_h_u = c1_u.R;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_h_y, "R", "R", 0);
  c1_i_u = c1_u.B;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_i_y, "B", "B", 0);
  c1_j_u = c1_u.C;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_j_y, "C", "C", 0);
  c1_k_u = c1_u.maxDelta;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_k_y, "maxDelta", "maxDelta", 0);
  c1_l_u = c1_u.maxTb;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_l_y, "maxTb", "maxTb", 0);
  c1_m_u = c1_u.maxThb;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_m_y, "maxThb", "maxThb", 0);
  c1_n_u = c1_u.maxTm;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_n_y, "maxTm", "maxTm", 0);
  c1_o_u = c1_u.gammaB;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_o_y, "gammaB", "gammaB", 0);
  c1_p_u = c1_u.gammaM;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_p_y, "gammaM", "gammaM", 0);
  c1_q_u = c1_u.g;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_q_y, "g", "g", 0);
  c1_r_u = c1_u.mu;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_r_y, "mu", "mu", 0);
  c1_s_u = c1_u.muRoll;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_s_y, "muRoll", "muRoll", 0);
  c1_t_u = c1_u.b;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_t_y, "b", "b", 0);
  c1_u_u = c1_u.FzF;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_u_y, "FzF", "FzF", 0);
  c1_v_u = c1_u.FzR;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_v_y, "FzR", "FzR", 0);
  c1_w_u = c1_u.Dz1;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_w_y, "Dz1", "Dz1", 0);
  c1_x_u = c1_u.Dz2;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_x_y, "Dz2", "Dz2", 0);
  c1_y_u = c1_u.T;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_y_y, "T", "T", 0);
  c1_ab_u = c1_u.WF0;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_ab_y, "WF0", "WF0", 0);
  c1_bb_u = c1_u.WR0;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_bb_y, "WR0", "WR0", 0);
  c1_cb_u = c1_u.Ux0;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_cb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_cb_y, "Ux0", "Ux0", 0);
  c1_db_u = c1_u.Uy0;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_db_y, "Uy0", "Uy0", 0);
  c1_eb_u = c1_u.r0;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_eb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_eb_y, "r0", "r0", 0);
  c1_fb_u = c1_u.x0;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_fb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_fb_y, "x0", "x0", 0);
  c1_gb_u = c1_u._y0;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_gb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_gb_y, "y0", "y0", 0);
  c1_hb_u = c1_u.ksi0;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_hb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_hb_y, "ksi0", "ksi0", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_finding_drag_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("sign"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1356541494U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc1_finding_dragInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc1_finding_dragInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_d_emlrt_marshallIn(SFc1_finding_dragInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  c1_snXp3ygPcVyeDzfVLtVbyQF *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[32] = { "m", "Iz", "Iw", "lF", "lR", "h",
    "R", "B", "C", "maxDelta", "maxTb", "maxThb", "maxTm", "gammaB", "gammaM",
    "g", "mu", "muRoll", "b", "FzF", "FzR", "Dz1", "Dz2", "T", "WF0", "WR0",
    "Ux0", "Uy0", "r0", "x0", "y0", "ksi0" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 32, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "m";
  c1_y->m = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "m", "m", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Iz";
  c1_y->Iz = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Iz", "Iz", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Iw";
  c1_y->Iw = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Iw", "Iw", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "lF";
  c1_y->lF = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "lF", "lF", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "lR";
  c1_y->lR = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "lR", "lR", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "h";
  c1_y->h = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "h", "h", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "R";
  c1_y->R = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "R", "R", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "B";
  c1_y->B = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "B", "B", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "C";
  c1_y->C = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "C", "C", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "maxDelta";
  c1_y->maxDelta = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "maxDelta", "maxDelta", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "maxTb";
  c1_y->maxTb = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "maxTb", "maxTb", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "maxThb";
  c1_y->maxThb = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "maxThb", "maxThb", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "maxTm";
  c1_y->maxTm = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "maxTm", "maxTm", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "gammaB";
  c1_y->gammaB = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "gammaB", "gammaB", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "gammaM";
  c1_y->gammaM = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "gammaM", "gammaM", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "g";
  c1_y->g = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "g", "g", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "mu";
  c1_y->mu = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "mu", "mu", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "muRoll";
  c1_y->muRoll = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "muRoll", "muRoll", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "b";
  c1_y->b = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "b", "b", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "FzF";
  c1_y->FzF = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "FzF", "FzF", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "FzR";
  c1_y->FzR = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "FzR", "FzR", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Dz1";
  c1_y->Dz1 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Dz1", "Dz1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Dz2";
  c1_y->Dz2 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Dz2", "Dz2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "T";
  c1_y->T = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "T", "T", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "WF0";
  c1_y->WF0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "WF0", "WF0", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "WR0";
  c1_y->WR0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "WR0", "WR0", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Ux0";
  c1_y->Ux0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Ux0", "Ux0", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Uy0";
  c1_y->Uy0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Uy0", "Uy0", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "r0";
  c1_y->r0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "r0", "r0", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "x0";
  c1_y->x0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "x0", "x0", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "y0";
  c1_y->_y0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "y0", "y0", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "ksi0";
  c1_y->ksi0 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "ksi0", "ksi0", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_params;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_snXp3ygPcVyeDzfVLtVbyQF c1_y;
  SFc1_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc1_finding_dragInstanceStruct *)chartInstanceVoid;
  c1_b_params = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_params), &c1_thisId,
                        &c1_y);
  sf_mex_destroy(&c1_b_params);
  *(c1_snXp3ygPcVyeDzfVLtVbyQF *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_finding_drag, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_finding_drag), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_finding_drag);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_finding_dragInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_finding_dragInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_finding_drag_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2311990233U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2685968589U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3592479146U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1117112286U);
}

mxArray *sf_c1_finding_drag_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("VLxW1hfYpAAIaaDVzt5UdD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_finding_drag_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_finding_drag_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_finding_drag(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"TbF\",},{M[1],M[11],T\"TbR\",},{M[8],M[0],T\"is_active_c1_finding_drag\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_finding_drag_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_finding_dragInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_finding_dragInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _finding_dragMachineNumber_,
           1,
           1,
           1,
           0,
           9,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_finding_dragMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_finding_dragMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _finding_dragMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"FxF");
          _SFD_SET_DATA_PROPS(1,2,0,1,"TbF");
          _SFD_SET_DATA_PROPS(2,1,1,0,"FxR");
          _SFD_SET_DATA_PROPS(3,1,1,0,"wF");
          _SFD_SET_DATA_PROPS(4,1,1,0,"wR");
          _SFD_SET_DATA_PROPS(5,10,0,0,"params");
          _SFD_SET_DATA_PROPS(6,1,1,0,"brake");
          _SFD_SET_DATA_PROPS(7,1,1,0,"handbrake");
          _SFD_SET_DATA_PROPS(8,2,0,1,"TbR");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,495);
        _SFD_CV_INIT_EML_IF(0,1,0,98,110,-1,355);
        _SFD_CV_INIT_EML_IF(0,1,1,119,129,188,230);
        _SFD_CV_INIT_EML_IF(0,1,2,240,250,309,351);
        _SFD_CV_INIT_EML_IF(0,1,3,357,373,-1,488);
        _SFD_CV_INIT_EML_IF(0,1,4,382,392,439,481);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_FxF;
          real_T *c1_TbF;
          real_T *c1_FxR;
          real_T *c1_wF;
          real_T *c1_wR;
          real_T *c1_brake;
          real_T *c1_handbrake;
          real_T *c1_TbR;
          c1_TbR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_handbrake = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_brake = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_wR = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_wF = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_FxR = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_TbF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_FxF = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_FxF);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_TbF);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_FxR);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_wF);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_wR);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c1_params);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_brake);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_handbrake);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_TbR);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _finding_dragMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "kSnkM8uDBD16H0jaT0NMzF";
}

static void sf_opaque_initialize_c1_finding_drag(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_finding_dragInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_finding_drag((SFc1_finding_dragInstanceStruct*)
    chartInstanceVar);
  initialize_c1_finding_drag((SFc1_finding_dragInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_finding_drag(void *chartInstanceVar)
{
  enable_c1_finding_drag((SFc1_finding_dragInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_finding_drag(void *chartInstanceVar)
{
  disable_c1_finding_drag((SFc1_finding_dragInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_finding_drag(void *chartInstanceVar)
{
  sf_gateway_c1_finding_drag((SFc1_finding_dragInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_finding_drag(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_finding_drag
    ((SFc1_finding_dragInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_finding_drag();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_finding_drag(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_finding_drag();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_finding_drag((SFc1_finding_dragInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_finding_drag(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_finding_drag(S);
}

static void sf_opaque_set_sim_state_c1_finding_drag(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c1_finding_drag(S, st);
}

static void sf_opaque_terminate_c1_finding_drag(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_finding_dragInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_finding_drag_optimization_info();
    }

    finalize_c1_finding_drag((SFc1_finding_dragInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_finding_drag((SFc1_finding_dragInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_finding_drag(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c1_finding_drag((SFc1_finding_dragInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_finding_drag(SimStruct *S)
{
  /* Actual parameters from chart:
     params
   */
  const char_T *rtParamNames[] = { "params" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_finding_drag_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1900098169U));
  ssSetChecksum1(S,(709525688U));
  ssSetChecksum2(S,(594414049U));
  ssSetChecksum3(S,(1435222380U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_finding_drag(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_finding_drag(SimStruct *S)
{
  SFc1_finding_dragInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_finding_dragInstanceStruct *)utMalloc(sizeof
    (SFc1_finding_dragInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_finding_dragInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_finding_drag;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_finding_drag;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_finding_drag;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_finding_drag;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_finding_drag;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_finding_drag;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_finding_drag;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_finding_drag;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_finding_drag;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_finding_drag;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_finding_drag;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_finding_drag_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_finding_drag(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_finding_drag(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_finding_drag(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_finding_drag_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
