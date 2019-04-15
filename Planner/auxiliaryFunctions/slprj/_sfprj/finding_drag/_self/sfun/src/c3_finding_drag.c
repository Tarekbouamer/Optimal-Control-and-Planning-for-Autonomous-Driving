/* Include files */

#include <stddef.h>
#include "blas.h"
#include "finding_drag_sfun.h"
#include "c3_finding_drag.h"
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
static const char * c3_debug_family_names[15] = { "derF", "derR", "params",
  "nargin", "nargout", "wR", "wF", "wRprev", "wFprev", "FxR", "FxF", "xbPrev",
  "xhbPrev", "xb", "xhb" };

/* Function Declarations */
static void initialize_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance);
static void initialize_params_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance);
static void enable_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance);
static void disable_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_finding_drag
  (SFc3_finding_dragInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_finding_drag
  (SFc3_finding_dragInstanceStruct *chartInstance);
static void set_sim_state_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance);
static void sf_gateway_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance);
static void initSimStructsc3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_finding_dragInstanceStruct *chartInstance,
  const mxArray *c3_xhb, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_d_emlrt_marshallIn(SFc3_finding_dragInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  c3_snXp3ygPcVyeDzfVLtVbyQF *c3_y);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_finding_drag, const char_T
  *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_finding_dragInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_finding_drag = 0U;
}

static void initialize_params_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance)
{
  const mxArray *c3_m0 = NULL;
  const mxArray *c3_mxField;
  c3_snXp3ygPcVyeDzfVLtVbyQF c3_r0;
  c3_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c3_mxField = sf_mex_getfield(c3_m0, "m", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.m, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "Iz", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.Iz, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "Iw", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.Iw, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "lF", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.lF, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "lR", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.lR, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "h", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.h, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "R", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.R, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "B", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.B, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "C", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.C, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "maxDelta", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.maxDelta, 1, 0,
                      0U, 0, 0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "maxTb", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.maxTb, 1, 0, 0U,
                      0, 0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "maxThb", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.maxThb, 1, 0, 0U,
                      0, 0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "maxTm", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.maxTm, 1, 0, 0U,
                      0, 0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "gammaB", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.gammaB, 1, 0, 0U,
                      0, 0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "gammaM", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.gammaM, 1, 0, 0U,
                      0, 0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "g", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.g, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "mu", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.mu, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "muRoll", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.muRoll, 1, 0, 0U,
                      0, 0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "b", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.b, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "FzF", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.FzF, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "FzR", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.FzR, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "Dz1", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.Dz1, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "Dz2", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.Dz2, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "T", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.T, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "WF0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.WF0, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "WR0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.WR0, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "Ux0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.Ux0, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "Uy0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.Uy0, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "r0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.r0, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "x0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.x0, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "y0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0._y0, 1, 0, 0U, 0,
                      0U, 0);
  c3_mxField = sf_mex_getfield(c3_m0, "ksi0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c3_mxField), &c3_r0.ksi0, 1, 0, 0U, 0,
                      0U, 0);
  sf_mex_destroy(&c3_m0);
  chartInstance->c3_params = c3_r0;
}

static void enable_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_finding_drag
  (SFc3_finding_dragInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_finding_drag
  (SFc3_finding_dragInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_xb;
  real_T *c3_xhb;
  c3_xhb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(3, 1), false);
  c3_hoistedGlobal = *c3_xb;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_xhb;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_active_c3_finding_drag;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_xb;
  real_T *c3_xhb;
  c3_xhb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *c3_xb = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "xb");
  *c3_xhb = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "xhb");
  chartInstance->c3_is_active_c3_finding_drag = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
     "is_active_c3_finding_drag");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_finding_drag(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance)
{
  real_T *c3_wR;
  real_T *c3_xb;
  real_T *c3_wF;
  real_T *c3_wRprev;
  real_T *c3_wFprev;
  real_T *c3_FxR;
  real_T *c3_FxF;
  real_T *c3_xhb;
  real_T *c3_xbPrev;
  real_T *c3_xhbPrev;
  c3_xhbPrev = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_xbPrev = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_xhb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_FxF = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_FxR = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_wFprev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_wRprev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_wF = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_xb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_wR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_wR, 0U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_finding_drag(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_finding_dragMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c3_xb, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_wF, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_wRprev, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_wFprev, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_FxR, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_FxF, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_xhb, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_xbPrev, 9U);
  _SFD_DATA_RANGE_CHECK(*c3_xhbPrev, 10U);
}

static void c3_chartstep_c3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_wR;
  real_T c3_wF;
  real_T c3_wRprev;
  real_T c3_wFprev;
  real_T c3_FxR;
  real_T c3_FxF;
  real_T c3_xbPrev;
  real_T c3_xhbPrev;
  uint32_T c3_debug_family_var_map[15];
  real_T c3_derF;
  real_T c3_derR;
  c3_snXp3ygPcVyeDzfVLtVbyQF c3_b_params;
  real_T c3_nargin = 9.0;
  real_T c3_nargout = 2.0;
  real_T c3_xb;
  real_T c3_xhb;
  static c3_snXp3ygPcVyeDzfVLtVbyQF c3_r1 = { 1270.0, 1200.0, 1.8, 1.015, 1.895,
    0.54, 0.325, 11.3295, 1.5305, 45.0, 3000.0, 1000.0, 1000.0, 0.4, 0.0, 9.81,
    0.8, 0.03, 2.0, 8113.13969072165, 4345.56030927835, 0.05,
    0.017453292519943295, 0.1, 42.735042735042732, 42.735042735042732,
    13.888888888888889, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T c3_A;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_b_A;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_c_A;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_y;
  real_T c3_d_A;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_e_A;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T *c3_b_xhb;
  real_T *c3_b_xb;
  real_T *c3_b_xhbPrev;
  real_T *c3_b_xbPrev;
  real_T *c3_b_FxF;
  real_T *c3_b_FxR;
  real_T *c3_b_wFprev;
  real_T *c3_b_wRprev;
  real_T *c3_b_wF;
  real_T *c3_b_wR;
  c3_b_xhbPrev = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_xbPrev = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_xhb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_FxF = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_FxR = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_wFprev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_wRprev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_wF = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_xb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_wR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_wR;
  c3_b_hoistedGlobal = *c3_b_wF;
  c3_c_hoistedGlobal = *c3_b_wRprev;
  c3_d_hoistedGlobal = *c3_b_wFprev;
  c3_e_hoistedGlobal = *c3_b_FxR;
  c3_f_hoistedGlobal = *c3_b_FxF;
  c3_g_hoistedGlobal = *c3_b_xbPrev;
  c3_h_hoistedGlobal = *c3_b_xhbPrev;
  c3_wR = c3_hoistedGlobal;
  c3_wF = c3_b_hoistedGlobal;
  c3_wRprev = c3_c_hoistedGlobal;
  c3_wFprev = c3_d_hoistedGlobal;
  c3_FxR = c3_e_hoistedGlobal;
  c3_FxF = c3_f_hoistedGlobal;
  c3_xbPrev = c3_g_hoistedGlobal;
  c3_xhbPrev = c3_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_derF, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_derR, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_params, 2U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_wR, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_wF, 6U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_wRprev, 7U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_wFprev, 8U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_FxR, 9U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_FxF, 10U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_xbPrev, 11U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_xhbPrev, 12U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_xb, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_xhb, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_b_params = c3_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, c3_FxR > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
    c3_FxR = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  if (CV_EML_IF(0, 1, 1, c3_FxF > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
    c3_FxF = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_A = c3_wF - c3_wFprev;
  c3_x = c3_A;
  c3_b_x = c3_x;
  c3_c_x = c3_b_x;
  c3_derF = c3_c_x / 0.1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_b_A = c3_wR - c3_wRprev;
  c3_d_x = c3_b_A;
  c3_e_x = c3_d_x;
  c3_f_x = c3_e_x;
  c3_derR = c3_f_x / 0.1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  c3_c_A = -(1.8 * c3_derF + c3_FxF * 0.325);
  c3_g_x = c3_c_A;
  c3_h_x = c3_g_x;
  c3_i_x = c3_h_x;
  c3_y = c3_i_x / 0.6;
  c3_d_A = c3_y;
  c3_j_x = c3_d_A;
  c3_k_x = c3_j_x;
  c3_l_x = c3_k_x;
  c3_xb = c3_l_x / 3000.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_e_A = -((1.8 * c3_derR + c3_FxR * 0.325) + 0.4 * c3_xb * 3000.0);
  c3_m_x = c3_e_A;
  c3_n_x = c3_m_x;
  c3_o_x = c3_n_x;
  c3_xhb = c3_o_x / 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  if (CV_EML_IF(0, 1, 2, c3_wF == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
    c3_xb = c3_xbPrev;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  if (CV_EML_IF(0, 1, 3, c3_wR == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
    c3_xhb = c3_xhbPrev;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
  if (CV_EML_IF(0, 1, 4, c3_xb < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
    c3_xb = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
  if (CV_EML_IF(0, 1, 5, c3_xb > 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
    c3_xb = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  if (CV_EML_IF(0, 1, 6, c3_xhb < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
    c3_xhb = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
  if (CV_EML_IF(0, 1, 7, c3_xhb > 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
    c3_xhb = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -42);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_xb = c3_xb;
  *c3_b_xhb = c3_xhb;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_finding_drag(SFc3_finding_dragInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc3_finding_dragInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_finding_dragInstanceStruct *chartInstance,
  const mxArray *c3_xhb, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_xhb), &c3_thisId);
  sf_mex_destroy(&c3_xhb);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_xhb;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc3_finding_dragInstanceStruct *)chartInstanceVoid;
  c3_xhb = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_xhb), &c3_thisId);
  sf_mex_destroy(&c3_xhb);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  c3_snXp3ygPcVyeDzfVLtVbyQF c3_u;
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_h_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_i_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_j_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_k_u;
  const mxArray *c3_k_y = NULL;
  real_T c3_l_u;
  const mxArray *c3_l_y = NULL;
  real_T c3_m_u;
  const mxArray *c3_m_y = NULL;
  real_T c3_n_u;
  const mxArray *c3_n_y = NULL;
  real_T c3_o_u;
  const mxArray *c3_o_y = NULL;
  real_T c3_p_u;
  const mxArray *c3_p_y = NULL;
  real_T c3_q_u;
  const mxArray *c3_q_y = NULL;
  real_T c3_r_u;
  const mxArray *c3_r_y = NULL;
  real_T c3_s_u;
  const mxArray *c3_s_y = NULL;
  real_T c3_t_u;
  const mxArray *c3_t_y = NULL;
  real_T c3_u_u;
  const mxArray *c3_u_y = NULL;
  real_T c3_v_u;
  const mxArray *c3_v_y = NULL;
  real_T c3_w_u;
  const mxArray *c3_w_y = NULL;
  real_T c3_x_u;
  const mxArray *c3_x_y = NULL;
  real_T c3_y_u;
  const mxArray *c3_y_y = NULL;
  real_T c3_ab_u;
  const mxArray *c3_ab_y = NULL;
  real_T c3_bb_u;
  const mxArray *c3_bb_y = NULL;
  real_T c3_cb_u;
  const mxArray *c3_cb_y = NULL;
  real_T c3_db_u;
  const mxArray *c3_db_y = NULL;
  real_T c3_eb_u;
  const mxArray *c3_eb_y = NULL;
  real_T c3_fb_u;
  const mxArray *c3_fb_y = NULL;
  real_T c3_gb_u;
  const mxArray *c3_gb_y = NULL;
  real_T c3_hb_u;
  const mxArray *c3_hb_y = NULL;
  SFc3_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc3_finding_dragInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(c3_snXp3ygPcVyeDzfVLtVbyQF *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c3_b_u = c3_u.m;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_b_y, "m", "m", 0);
  c3_c_u = c3_u.Iz;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_c_y, "Iz", "Iz", 0);
  c3_d_u = c3_u.Iw;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_d_y, "Iw", "Iw", 0);
  c3_e_u = c3_u.lF;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_e_y, "lF", "lF", 0);
  c3_f_u = c3_u.lR;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_f_y, "lR", "lR", 0);
  c3_g_u = c3_u.h;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_g_y, "h", "h", 0);
  c3_h_u = c3_u.R;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_h_y, "R", "R", 0);
  c3_i_u = c3_u.B;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_i_y, "B", "B", 0);
  c3_j_u = c3_u.C;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_j_y, "C", "C", 0);
  c3_k_u = c3_u.maxDelta;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_k_y, "maxDelta", "maxDelta", 0);
  c3_l_u = c3_u.maxTb;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_l_y, "maxTb", "maxTb", 0);
  c3_m_u = c3_u.maxThb;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_m_y, "maxThb", "maxThb", 0);
  c3_n_u = c3_u.maxTm;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_n_y, "maxTm", "maxTm", 0);
  c3_o_u = c3_u.gammaB;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_o_y, "gammaB", "gammaB", 0);
  c3_p_u = c3_u.gammaM;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_p_y, "gammaM", "gammaM", 0);
  c3_q_u = c3_u.g;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_q_y, "g", "g", 0);
  c3_r_u = c3_u.mu;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_r_y, "mu", "mu", 0);
  c3_s_u = c3_u.muRoll;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_s_y, "muRoll", "muRoll", 0);
  c3_t_u = c3_u.b;
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_t_y, "b", "b", 0);
  c3_u_u = c3_u.FzF;
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_u_y, "FzF", "FzF", 0);
  c3_v_u = c3_u.FzR;
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_v_y, "FzR", "FzR", 0);
  c3_w_u = c3_u.Dz1;
  c3_w_y = NULL;
  sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_w_y, "Dz1", "Dz1", 0);
  c3_x_u = c3_u.Dz2;
  c3_x_y = NULL;
  sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_x_y, "Dz2", "Dz2", 0);
  c3_y_u = c3_u.T;
  c3_y_y = NULL;
  sf_mex_assign(&c3_y_y, sf_mex_create("y", &c3_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_y_y, "T", "T", 0);
  c3_ab_u = c3_u.WF0;
  c3_ab_y = NULL;
  sf_mex_assign(&c3_ab_y, sf_mex_create("y", &c3_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_ab_y, "WF0", "WF0", 0);
  c3_bb_u = c3_u.WR0;
  c3_bb_y = NULL;
  sf_mex_assign(&c3_bb_y, sf_mex_create("y", &c3_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_bb_y, "WR0", "WR0", 0);
  c3_cb_u = c3_u.Ux0;
  c3_cb_y = NULL;
  sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_cb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_cb_y, "Ux0", "Ux0", 0);
  c3_db_u = c3_u.Uy0;
  c3_db_y = NULL;
  sf_mex_assign(&c3_db_y, sf_mex_create("y", &c3_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_db_y, "Uy0", "Uy0", 0);
  c3_eb_u = c3_u.r0;
  c3_eb_y = NULL;
  sf_mex_assign(&c3_eb_y, sf_mex_create("y", &c3_eb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_eb_y, "r0", "r0", 0);
  c3_fb_u = c3_u.x0;
  c3_fb_y = NULL;
  sf_mex_assign(&c3_fb_y, sf_mex_create("y", &c3_fb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_fb_y, "x0", "x0", 0);
  c3_gb_u = c3_u._y0;
  c3_gb_y = NULL;
  sf_mex_assign(&c3_gb_y, sf_mex_create("y", &c3_gb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_gb_y, "y0", "y0", 0);
  c3_hb_u = c3_u.ksi0;
  c3_hb_y = NULL;
  sf_mex_assign(&c3_hb_y, sf_mex_create("y", &c3_hb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_hb_y, "ksi0", "ksi0", 0);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_finding_drag_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc3_finding_dragInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc3_finding_dragInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_d_emlrt_marshallIn(SFc3_finding_dragInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  c3_snXp3ygPcVyeDzfVLtVbyQF *c3_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[32] = { "m", "Iz", "Iw", "lF", "lR", "h",
    "R", "B", "C", "maxDelta", "maxTb", "maxThb", "maxTm", "gammaB", "gammaM",
    "g", "mu", "muRoll", "b", "FzF", "FzR", "Dz1", "Dz2", "T", "WF0", "WR0",
    "Ux0", "Uy0", "r0", "x0", "y0", "ksi0" };

  c3_thisId.fParent = c3_parentId;
  sf_mex_check_struct(c3_parentId, c3_u, 32, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "m";
  c3_y->m = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "m", "m", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "Iz";
  c3_y->Iz = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "Iz", "Iz", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "Iw";
  c3_y->Iw = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "Iw", "Iw", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "lF";
  c3_y->lF = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "lF", "lF", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "lR";
  c3_y->lR = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "lR", "lR", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "h";
  c3_y->h = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "h", "h", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "R";
  c3_y->R = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "R", "R", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "B";
  c3_y->B = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "B", "B", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "C";
  c3_y->C = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "C", "C", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "maxDelta";
  c3_y->maxDelta = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_u, "maxDelta", "maxDelta", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "maxTb";
  c3_y->maxTb = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "maxTb", "maxTb", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "maxThb";
  c3_y->maxThb = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "maxThb", "maxThb", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "maxTm";
  c3_y->maxTm = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "maxTm", "maxTm", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "gammaB";
  c3_y->gammaB = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "gammaB", "gammaB", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "gammaM";
  c3_y->gammaM = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "gammaM", "gammaM", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "g";
  c3_y->g = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "g", "g", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "mu";
  c3_y->mu = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "mu", "mu", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "muRoll";
  c3_y->muRoll = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "muRoll", "muRoll", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "b";
  c3_y->b = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "b", "b", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "FzF";
  c3_y->FzF = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "FzF", "FzF", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "FzR";
  c3_y->FzR = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "FzR", "FzR", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "Dz1";
  c3_y->Dz1 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "Dz1", "Dz1", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "Dz2";
  c3_y->Dz2 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "Dz2", "Dz2", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "T";
  c3_y->T = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "T", "T", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "WF0";
  c3_y->WF0 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "WF0", "WF0", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "WR0";
  c3_y->WR0 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "WR0", "WR0", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "Ux0";
  c3_y->Ux0 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "Ux0", "Ux0", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "Uy0";
  c3_y->Uy0 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "Uy0", "Uy0", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "r0";
  c3_y->r0 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "r0", "r0", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "x0";
  c3_y->x0 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "x0", "x0", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "y0";
  c3_y->_y0 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "y0", "y0", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "ksi0";
  c3_y->ksi0 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "ksi0", "ksi0", 0)), &c3_thisId);
  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_params;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  c3_snXp3ygPcVyeDzfVLtVbyQF c3_y;
  SFc3_finding_dragInstanceStruct *chartInstance;
  chartInstance = (SFc3_finding_dragInstanceStruct *)chartInstanceVoid;
  c3_b_params = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_params), &c3_thisId,
                        &c3_y);
  sf_mex_destroy(&c3_b_params);
  *(c3_snXp3ygPcVyeDzfVLtVbyQF *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_finding_drag, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_finding_drag), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_finding_drag);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_finding_dragInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_finding_dragInstanceStruct *chartInstance)
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

void sf_c3_finding_drag_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3673883474U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2412412105U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3313430581U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3387334861U);
}

mxArray *sf_c3_finding_drag_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("43eEaZikk8RmNvrEX8M5lD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c3_finding_drag_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_finding_drag_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_finding_drag(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"xb\",},{M[1],M[14],T\"xhb\",},{M[8],M[0],T\"is_active_c3_finding_drag\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_finding_drag_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_finding_dragInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_finding_dragInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _finding_dragMachineNumber_,
           3,
           1,
           1,
           0,
           11,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"wR");
          _SFD_SET_DATA_PROPS(1,2,0,1,"xb");
          _SFD_SET_DATA_PROPS(2,1,1,0,"wF");
          _SFD_SET_DATA_PROPS(3,1,1,0,"wRprev");
          _SFD_SET_DATA_PROPS(4,1,1,0,"wFprev");
          _SFD_SET_DATA_PROPS(5,1,1,0,"FxR");
          _SFD_SET_DATA_PROPS(6,1,1,0,"FxF");
          _SFD_SET_DATA_PROPS(7,10,0,0,"params");
          _SFD_SET_DATA_PROPS(8,2,0,1,"xhb");
          _SFD_SET_DATA_PROPS(9,1,1,0,"xbPrev");
          _SFD_SET_DATA_PROPS(10,1,1,0,"xhbPrev");
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
        _SFD_CV_INIT_EML(0,1,1,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,574);
        _SFD_CV_INIT_EML_IF(0,1,0,106,116,-1,133);
        _SFD_CV_INIT_EML_IF(0,1,1,135,145,-1,164);
        _SFD_CV_INIT_EML_IF(0,1,2,392,402,-1,423);
        _SFD_CV_INIT_EML_IF(0,1,3,425,435,-1,458);
        _SFD_CV_INIT_EML_IF(0,1,4,462,470,-1,486);
        _SFD_CV_INIT_EML_IF(0,1,5,488,496,-1,512);
        _SFD_CV_INIT_EML_IF(0,1,6,514,523,-1,540);
        _SFD_CV_INIT_EML_IF(0,1,7,542,551,-1,568);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_wR;
          real_T *c3_xb;
          real_T *c3_wF;
          real_T *c3_wRprev;
          real_T *c3_wFprev;
          real_T *c3_FxR;
          real_T *c3_FxF;
          real_T *c3_xhb;
          real_T *c3_xbPrev;
          real_T *c3_xhbPrev;
          c3_xhbPrev = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_xbPrev = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_xhb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_FxF = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_FxR = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_wFprev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_wRprev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_wF = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_xb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_wR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_wR);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_xb);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_wF);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_wRprev);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_wFprev);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_FxR);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_FxF);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c3_params);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_xhb);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_xbPrev);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_xhbPrev);
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
  return "MPYYJYkTbVjK1S44oNRkbH";
}

static void sf_opaque_initialize_c3_finding_drag(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_finding_dragInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_finding_drag((SFc3_finding_dragInstanceStruct*)
    chartInstanceVar);
  initialize_c3_finding_drag((SFc3_finding_dragInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_finding_drag(void *chartInstanceVar)
{
  enable_c3_finding_drag((SFc3_finding_dragInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_finding_drag(void *chartInstanceVar)
{
  disable_c3_finding_drag((SFc3_finding_dragInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_finding_drag(void *chartInstanceVar)
{
  sf_gateway_c3_finding_drag((SFc3_finding_dragInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_finding_drag(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_finding_drag
    ((SFc3_finding_dragInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_finding_drag();/* state var info */
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

extern void sf_internal_set_sim_state_c3_finding_drag(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_finding_drag();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_finding_drag((SFc3_finding_dragInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_finding_drag(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_finding_drag(S);
}

static void sf_opaque_set_sim_state_c3_finding_drag(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c3_finding_drag(S, st);
}

static void sf_opaque_terminate_c3_finding_drag(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_finding_dragInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_finding_drag_optimization_info();
    }

    finalize_c3_finding_drag((SFc3_finding_dragInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_finding_drag((SFc3_finding_dragInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_finding_drag(SimStruct *S)
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
    initialize_params_c3_finding_drag((SFc3_finding_dragInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_finding_drag(SimStruct *S)
{
  /* Actual parameters from chart:
     params
   */
  const char_T *rtParamNames[] = { "params" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_finding_drag_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3165104737U));
  ssSetChecksum1(S,(3421753275U));
  ssSetChecksum2(S,(337887222U));
  ssSetChecksum3(S,(2690672139U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_finding_drag(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_finding_drag(SimStruct *S)
{
  SFc3_finding_dragInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_finding_dragInstanceStruct *)utMalloc(sizeof
    (SFc3_finding_dragInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_finding_dragInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_finding_drag;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_finding_drag;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_finding_drag;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_finding_drag;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_finding_drag;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_finding_drag;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_finding_drag;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_finding_drag;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_finding_drag;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_finding_drag;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_finding_drag;
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

void c3_finding_drag_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_finding_drag(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_finding_drag(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_finding_drag(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_finding_drag_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
