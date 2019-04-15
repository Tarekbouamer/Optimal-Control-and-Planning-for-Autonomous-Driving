/* Include files */

#include <stddef.h>
#include "blas.h"
#include "model_sfun.h"
#include "c2_model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[34] = { "eps", "UxF", "UyF", "UxR",
  "UyR", "SxF", "SyF", "SxR", "SyR", "SR", "SF", "muF", "muR", "muxF", "muyF",
  "muxR", "muyR", "num", "den", "FzF", "FzR", "params", "nargin", "nargout",
  "Ux", "Uy", "wR", "wF", "delta", "r", "FxF", "FyF", "FxR", "FyR" };

static const char * c2_b_debug_family_names[6] = { "nargin", "nargout", "num",
  "den", "epsilon", "z" };

static const char * c2_c_debug_family_names[6] = { "nargin", "nargout", "num",
  "den", "epsilon", "z" };

/* Function Declarations */
static void initialize_c2_model(SFc2_modelInstanceStruct *chartInstance);
static void initialize_params_c2_model(SFc2_modelInstanceStruct *chartInstance);
static void enable_c2_model(SFc2_modelInstanceStruct *chartInstance);
static void disable_c2_model(SFc2_modelInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_model(SFc2_modelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_model(SFc2_modelInstanceStruct
  *chartInstance);
static void set_sim_state_c2_model(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_model(SFc2_modelInstanceStruct *chartInstance);
static void sf_gateway_c2_model(SFc2_modelInstanceStruct *chartInstance);
static void c2_chartstep_c2_model(SFc2_modelInstanceStruct *chartInstance);
static void initSimStructsc2_model(SFc2_modelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance, const
  mxArray *c2_FyR, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static real_T c2_robustDiv2(SFc2_modelInstanceStruct *chartInstance, real_T
  c2_num, real_T c2_den, real_T c2_epsilon);
static real_T c2_mpower(SFc2_modelInstanceStruct *chartInstance, real_T c2_a);
static void c2_eml_scalar_eg(SFc2_modelInstanceStruct *chartInstance);
static void c2_eml_error(SFc2_modelInstanceStruct *chartInstance);
static real_T c2_robustDiv(SFc2_modelInstanceStruct *chartInstance, real_T
  c2_num, real_T c2_den, real_T c2_epsilon);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_d_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sTXaXgTBgcsTeEwtC20RoaB *c2_y);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_model, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_modelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_model(SFc2_modelInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_model = 0U;
}

static void initialize_params_c2_model(SFc2_modelInstanceStruct *chartInstance)
{
  const mxArray *c2_m0 = NULL;
  const mxArray *c2_mxField;
  c2_sTXaXgTBgcsTeEwtC20RoaB c2_r0;
  c2_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c2_mxField = sf_mex_getfield(c2_m0, "m", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.m, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Iz", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.Iz, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Iw", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.Iw, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "lF", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.lF, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "lR", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.lR, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "h", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.h, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "R", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.R, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "B", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.B, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "C", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.C, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "maxDelta", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.maxDelta, 1, 0,
                      0U, 0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "maxTb", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.maxTb, 1, 0, 0U,
                      0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "maxThb", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.maxThb, 1, 0, 0U,
                      0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "maxTm", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.maxTm, 1, 0, 0U,
                      0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "gammaB", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.gammaB, 1, 0, 0U,
                      0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "gammaM", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.gammaM, 1, 0, 0U,
                      0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "g", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.g, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "mu", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.mu, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "muRoll", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.muRoll, 1, 0, 0U,
                      0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "b", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.b, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "fric", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.fric, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "FzF", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.FzF, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "FzR", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.FzR, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Dz1", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.Dz1, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Dz2", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.Dz2, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "T", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.T, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "WF0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.WF0, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "WR0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.WR0, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Ux0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.Ux0, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Uy0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.Uy0, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "r0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.r0, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "x0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.x0, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "y0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0._y0, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "ksi0", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.ksi0, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Press2TorF", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.Press2TorF, 1, 0,
                      0U, 0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Press2TorR", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.Press2TorR, 1, 0,
                      0U, 0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "maxPress", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.maxPress, 1, 0,
                      0U, 0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "press2torF", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.press2torF, 1, 0,
                      0U, 0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "press2torR", "params", 0);
  sf_mex_import_named("params", sf_mex_dup(c2_mxField), &c2_r0.press2torR, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c2_m0);
  chartInstance->c2_params = c2_r0;
}

static void enable_c2_model(SFc2_modelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_model(SFc2_modelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_model(SFc2_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_model(SFc2_modelInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_FxF;
  real_T *c2_FxR;
  real_T *c2_FyF;
  real_T *c2_FyR;
  c2_FyR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_FxR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_FyF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_FxF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(5, 1), false);
  c2_hoistedGlobal = *c2_FxF;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_FxR;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_FyF;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_FyR;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_active_c2_model;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_model(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_FxF;
  real_T *c2_FxR;
  real_T *c2_FyF;
  real_T *c2_FyR;
  c2_FyR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_FxR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_FyF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_FxF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *c2_FxF = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "FxF");
  *c2_FxR = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "FxR");
  *c2_FyF = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "FyF");
  *c2_FyR = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
    "FyR");
  chartInstance->c2_is_active_c2_model = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 4)), "is_active_c2_model");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_model(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_model(SFc2_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_model(SFc2_modelInstanceStruct *chartInstance)
{
  real_T *c2_Ux;
  real_T *c2_FxF;
  real_T *c2_Uy;
  real_T *c2_wR;
  real_T *c2_wF;
  real_T *c2_delta;
  real_T *c2_r;
  real_T *c2_FyF;
  real_T *c2_FxR;
  real_T *c2_FyR;
  c2_FyR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_FxR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_FyF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_delta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_wF = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_wR = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_Uy = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_FxF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_Ux = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_Ux, 0U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_model(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_modelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c2_FxF, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_Uy, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_wR, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_wF, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_delta, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_r, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_FyF, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_FxR, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_FyR, 10U);
}

static void c2_chartstep_c2_model(SFc2_modelInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_Ux;
  real_T c2_Uy;
  real_T c2_wR;
  real_T c2_wF;
  real_T c2_delta;
  real_T c2_r;
  uint32_T c2_debug_family_var_map[34];
  real_T c2_eps;
  real_T c2_UxF;
  real_T c2_UyF;
  real_T c2_UxR;
  real_T c2_UyR;
  real_T c2_SxF;
  real_T c2_SyF;
  real_T c2_SxR;
  real_T c2_SyR;
  real_T c2_SR;
  real_T c2_SF;
  real_T c2_muF;
  real_T c2_muR;
  real_T c2_muxF;
  real_T c2_muyF;
  real_T c2_muxR;
  real_T c2_muyR;
  real_T c2_num;
  real_T c2_den;
  real_T c2_FzF;
  real_T c2_FzR;
  c2_sTXaXgTBgcsTeEwtC20RoaB c2_b_params;
  real_T c2_nargin = 7.0;
  real_T c2_nargout = 4.0;
  real_T c2_FxF;
  real_T c2_FyF;
  real_T c2_FxR;
  real_T c2_FyR;
  static c2_sTXaXgTBgcsTeEwtC20RoaB c2_r1 = { 1270.0, 1200.0, 1.8, 1.015, 1.895,
    0.54, 0.325, 11.3295, 1.5305, 45.0, 3000.0, 1000.0, 1000.0, 0.4, 0.0, 9.81,
    0.85, 0.0, 5.0, 40.0, 8113.13969072165, 4345.56030927835, 0.05,
    0.017453292519943295, 0.1, 29.914529914529911, 29.914529914529911,
    9.7222222222222214, 0.0, 0.0, 0.0, 0.0, 0.0, 250.0, 150.0, 13.0, 250.0,
    150.0 };

  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T *c2_b_Ux;
  real_T *c2_b_Uy;
  real_T *c2_b_wR;
  real_T *c2_b_wF;
  real_T *c2_b_delta;
  real_T *c2_b_r;
  real_T *c2_b_FxF;
  real_T *c2_b_FyF;
  real_T *c2_b_FxR;
  real_T *c2_b_FyR;
  c2_b_FyR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_FxR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_FyF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_delta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_wF = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_wR = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_Uy = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_FxF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_Ux = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_Ux;
  c2_b_hoistedGlobal = *c2_b_Uy;
  c2_c_hoistedGlobal = *c2_b_wR;
  c2_d_hoistedGlobal = *c2_b_wF;
  c2_e_hoistedGlobal = *c2_b_delta;
  c2_f_hoistedGlobal = *c2_b_r;
  c2_Ux = c2_hoistedGlobal;
  c2_Uy = c2_b_hoistedGlobal;
  c2_wR = c2_c_hoistedGlobal;
  c2_wF = c2_d_hoistedGlobal;
  c2_delta = c2_e_hoistedGlobal;
  c2_r = c2_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 34U, 34U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_eps, 0U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_UxF, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_UyF, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_UxR, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_UyR, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_SxF, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_SyF, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_SxR, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_SyR, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_SR, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_SF, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_muF, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_muR, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_muxF, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_muyF, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_muxR, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_muyR, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_num, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_den, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_FzF, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_FzR, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_params, 21U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 22U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 23U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Ux, 24U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Uy, 25U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_wR, 26U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_wF, 27U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_delta, 28U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_r, 29U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_FxF, 30U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_FyF, 31U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_FxR, 32U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_FyR, 33U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  c2_b_params = c2_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_eps = 0.0001;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_x = c2_delta;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_delta;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_e_x = c2_delta;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_UxF = (c2_Ux * c2_b_x + c2_Uy * c2_d_x) + c2_r * 1.015 * c2_f_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_g_x = c2_delta;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_i_x = c2_delta;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarCos(c2_j_x);
  c2_k_x = c2_delta;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarCos(c2_l_x);
  c2_UyF = (-c2_Ux * c2_h_x + c2_Uy * c2_j_x) + c2_r * 1.015 * c2_l_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_UxR = c2_Ux;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_UyR = c2_Uy - 1.895 * c2_r;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_SxF = c2_robustDiv2(chartInstance, c2_UxF - 0.325 * c2_wF, 0.325 * c2_wF,
    0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_SyF = (1.0 + c2_SxF) * c2_robustDiv2(chartInstance, c2_UyF, c2_UxF, 0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_SxR = c2_robustDiv2(chartInstance, c2_UxR - 0.325 * c2_wR, 0.325 * c2_wR,
    0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_SyR = (1.0 + c2_SxR) * c2_robustDiv2(chartInstance, c2_UyR, c2_UxR, 0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_m_x = c2_mpower(chartInstance, c2_SxR) + c2_mpower(chartInstance, c2_SyR);
  c2_SR = c2_m_x;
  if (c2_SR < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_n_x = c2_SR;
  c2_SR = c2_n_x;
  c2_SR = muDoubleScalarSqrt(c2_SR);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_o_x = c2_mpower(chartInstance, c2_SxF) + c2_mpower(chartInstance, c2_SyF);
  c2_SF = c2_o_x;
  if (c2_SF < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_p_x = c2_SF;
  c2_SF = c2_p_x;
  c2_SF = muDoubleScalarSqrt(c2_SF);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_q_x = 11.3295 * c2_SF;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarAtan(c2_r_x);
  c2_s_x = 1.5305 * c2_r_x;
  c2_muF = c2_s_x;
  c2_t_x = c2_muF;
  c2_muF = c2_t_x;
  c2_muF = muDoubleScalarSin(c2_muF);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_u_x = 11.3295 * c2_SR;
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarAtan(c2_v_x);
  c2_w_x = 1.5305 * c2_v_x;
  c2_muR = c2_w_x;
  c2_x_x = c2_muR;
  c2_muR = c2_x_x;
  c2_muR = muDoubleScalarSin(c2_muR);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_muxF = -c2_muF * c2_robustDiv(chartInstance, c2_SxF, c2_SF, 0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_muyF = -c2_muF * c2_robustDiv(chartInstance, c2_SyF, c2_SF, 0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_muxR = -c2_muR * c2_robustDiv(chartInstance, c2_SxR, c2_SR, 0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_muyR = -c2_muR * c2_robustDiv(chartInstance, c2_SyR, c2_SR, 0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_num = 23609.236500000003 - 5718.5433000000012 * c2_muxR;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_y_x = c2_delta;
  c2_ab_x = c2_y_x;
  c2_ab_x = muDoubleScalarCos(c2_ab_x);
  c2_bb_x = c2_delta;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarSin(c2_cb_x);
  c2_den = 2.91 + 0.459 * ((c2_muxF * c2_ab_x - c2_muyF * c2_cb_x) - c2_muxR);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_FzF = c2_robustDiv(chartInstance, c2_num, c2_den, 0.0001);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_FzR = 12458.7 - c2_FzF;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_FxF = 0.85 * c2_FzF * c2_muxF;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_FyF = 0.85 * c2_FzF * c2_muyF;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_FxR = 0.85 * c2_FzR * c2_muxR;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
  c2_FyR = 0.85 * c2_FzR * c2_muyR;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_FxF = c2_FxF;
  *c2_b_FyF = c2_FyF;
  *c2_b_FxR = c2_FxR;
  *c2_b_FyR = c2_FyR;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_model(SFc2_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance, const
  mxArray *c2_FyR, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_FyR), &c2_thisId);
  sf_mex_destroy(&c2_FyR);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_FyR;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelInstanceStruct *)chartInstanceVoid;
  c2_FyR = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_FyR), &c2_thisId);
  sf_mex_destroy(&c2_FyR);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  c2_sTXaXgTBgcsTeEwtC20RoaB c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_k_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_l_u;
  const mxArray *c2_l_y = NULL;
  real_T c2_m_u;
  const mxArray *c2_m_y = NULL;
  real_T c2_n_u;
  const mxArray *c2_n_y = NULL;
  real_T c2_o_u;
  const mxArray *c2_o_y = NULL;
  real_T c2_p_u;
  const mxArray *c2_p_y = NULL;
  real_T c2_q_u;
  const mxArray *c2_q_y = NULL;
  real_T c2_r_u;
  const mxArray *c2_r_y = NULL;
  real_T c2_s_u;
  const mxArray *c2_s_y = NULL;
  real_T c2_t_u;
  const mxArray *c2_t_y = NULL;
  real_T c2_u_u;
  const mxArray *c2_u_y = NULL;
  real_T c2_v_u;
  const mxArray *c2_v_y = NULL;
  real_T c2_w_u;
  const mxArray *c2_w_y = NULL;
  real_T c2_x_u;
  const mxArray *c2_x_y = NULL;
  real_T c2_y_u;
  const mxArray *c2_y_y = NULL;
  real_T c2_ab_u;
  const mxArray *c2_ab_y = NULL;
  real_T c2_bb_u;
  const mxArray *c2_bb_y = NULL;
  real_T c2_cb_u;
  const mxArray *c2_cb_y = NULL;
  real_T c2_db_u;
  const mxArray *c2_db_y = NULL;
  real_T c2_eb_u;
  const mxArray *c2_eb_y = NULL;
  real_T c2_fb_u;
  const mxArray *c2_fb_y = NULL;
  real_T c2_gb_u;
  const mxArray *c2_gb_y = NULL;
  real_T c2_hb_u;
  const mxArray *c2_hb_y = NULL;
  real_T c2_ib_u;
  const mxArray *c2_ib_y = NULL;
  real_T c2_jb_u;
  const mxArray *c2_jb_y = NULL;
  real_T c2_kb_u;
  const mxArray *c2_kb_y = NULL;
  real_T c2_lb_u;
  const mxArray *c2_lb_y = NULL;
  real_T c2_mb_u;
  const mxArray *c2_mb_y = NULL;
  real_T c2_nb_u;
  const mxArray *c2_nb_y = NULL;
  SFc2_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_sTXaXgTBgcsTeEwtC20RoaB *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_b_u = c2_u.m;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_b_y, "m", "m", 0);
  c2_c_u = c2_u.Iz;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_c_y, "Iz", "Iz", 0);
  c2_d_u = c2_u.Iw;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_d_y, "Iw", "Iw", 0);
  c2_e_u = c2_u.lF;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_e_y, "lF", "lF", 0);
  c2_f_u = c2_u.lR;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_f_y, "lR", "lR", 0);
  c2_g_u = c2_u.h;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_g_y, "h", "h", 0);
  c2_h_u = c2_u.R;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_h_y, "R", "R", 0);
  c2_i_u = c2_u.B;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_i_y, "B", "B", 0);
  c2_j_u = c2_u.C;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_j_y, "C", "C", 0);
  c2_k_u = c2_u.maxDelta;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_k_y, "maxDelta", "maxDelta", 0);
  c2_l_u = c2_u.maxTb;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_l_y, "maxTb", "maxTb", 0);
  c2_m_u = c2_u.maxThb;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_m_y, "maxThb", "maxThb", 0);
  c2_n_u = c2_u.maxTm;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_n_y, "maxTm", "maxTm", 0);
  c2_o_u = c2_u.gammaB;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_o_y, "gammaB", "gammaB", 0);
  c2_p_u = c2_u.gammaM;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_p_y, "gammaM", "gammaM", 0);
  c2_q_u = c2_u.g;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_q_y, "g", "g", 0);
  c2_r_u = c2_u.mu;
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_r_y, "mu", "mu", 0);
  c2_s_u = c2_u.muRoll;
  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_s_y, "muRoll", "muRoll", 0);
  c2_t_u = c2_u.b;
  c2_t_y = NULL;
  sf_mex_assign(&c2_t_y, sf_mex_create("y", &c2_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_t_y, "b", "b", 0);
  c2_u_u = c2_u.fric;
  c2_u_y = NULL;
  sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_u_y, "fric", "fric", 0);
  c2_v_u = c2_u.FzF;
  c2_v_y = NULL;
  sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_v_y, "FzF", "FzF", 0);
  c2_w_u = c2_u.FzR;
  c2_w_y = NULL;
  sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_w_y, "FzR", "FzR", 0);
  c2_x_u = c2_u.Dz1;
  c2_x_y = NULL;
  sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_x_y, "Dz1", "Dz1", 0);
  c2_y_u = c2_u.Dz2;
  c2_y_y = NULL;
  sf_mex_assign(&c2_y_y, sf_mex_create("y", &c2_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_y_y, "Dz2", "Dz2", 0);
  c2_ab_u = c2_u.T;
  c2_ab_y = NULL;
  sf_mex_assign(&c2_ab_y, sf_mex_create("y", &c2_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_ab_y, "T", "T", 0);
  c2_bb_u = c2_u.WF0;
  c2_bb_y = NULL;
  sf_mex_assign(&c2_bb_y, sf_mex_create("y", &c2_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_bb_y, "WF0", "WF0", 0);
  c2_cb_u = c2_u.WR0;
  c2_cb_y = NULL;
  sf_mex_assign(&c2_cb_y, sf_mex_create("y", &c2_cb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_cb_y, "WR0", "WR0", 0);
  c2_db_u = c2_u.Ux0;
  c2_db_y = NULL;
  sf_mex_assign(&c2_db_y, sf_mex_create("y", &c2_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_db_y, "Ux0", "Ux0", 0);
  c2_eb_u = c2_u.Uy0;
  c2_eb_y = NULL;
  sf_mex_assign(&c2_eb_y, sf_mex_create("y", &c2_eb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_eb_y, "Uy0", "Uy0", 0);
  c2_fb_u = c2_u.r0;
  c2_fb_y = NULL;
  sf_mex_assign(&c2_fb_y, sf_mex_create("y", &c2_fb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_fb_y, "r0", "r0", 0);
  c2_gb_u = c2_u.x0;
  c2_gb_y = NULL;
  sf_mex_assign(&c2_gb_y, sf_mex_create("y", &c2_gb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_gb_y, "x0", "x0", 0);
  c2_hb_u = c2_u._y0;
  c2_hb_y = NULL;
  sf_mex_assign(&c2_hb_y, sf_mex_create("y", &c2_hb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_hb_y, "y0", "y0", 0);
  c2_ib_u = c2_u.ksi0;
  c2_ib_y = NULL;
  sf_mex_assign(&c2_ib_y, sf_mex_create("y", &c2_ib_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_ib_y, "ksi0", "ksi0", 0);
  c2_jb_u = c2_u.Press2TorF;
  c2_jb_y = NULL;
  sf_mex_assign(&c2_jb_y, sf_mex_create("y", &c2_jb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_jb_y, "Press2TorF", "Press2TorF", 0);
  c2_kb_u = c2_u.Press2TorR;
  c2_kb_y = NULL;
  sf_mex_assign(&c2_kb_y, sf_mex_create("y", &c2_kb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_kb_y, "Press2TorR", "Press2TorR", 0);
  c2_lb_u = c2_u.maxPress;
  c2_lb_y = NULL;
  sf_mex_assign(&c2_lb_y, sf_mex_create("y", &c2_lb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_lb_y, "maxPress", "maxPress", 0);
  c2_mb_u = c2_u.press2torF;
  c2_mb_y = NULL;
  sf_mex_assign(&c2_mb_y, sf_mex_create("y", &c2_mb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_mb_y, "press2torF", "press2torF", 0);
  c2_nb_u = c2_u.press2torR;
  c2_nb_y = NULL;
  sf_mex_assign(&c2_nb_y, sf_mex_create("y", &c2_nb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_nb_y, "press2torR", "press2torR", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_model_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 32, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  const mxArray *c2_rhs11 = NULL;
  const mxArray *c2_lhs11 = NULL;
  const mxArray *c2_rhs12 = NULL;
  const mxArray *c2_lhs12 = NULL;
  const mxArray *c2_rhs13 = NULL;
  const mxArray *c2_lhs13 = NULL;
  const mxArray *c2_rhs14 = NULL;
  const mxArray *c2_lhs14 = NULL;
  const mxArray *c2_rhs15 = NULL;
  const mxArray *c2_lhs15 = NULL;
  const mxArray *c2_rhs16 = NULL;
  const mxArray *c2_lhs16 = NULL;
  const mxArray *c2_rhs17 = NULL;
  const mxArray *c2_lhs17 = NULL;
  const mxArray *c2_rhs18 = NULL;
  const mxArray *c2_lhs18 = NULL;
  const mxArray *c2_rhs19 = NULL;
  const mxArray *c2_lhs19 = NULL;
  const mxArray *c2_rhs20 = NULL;
  const mxArray *c2_lhs20 = NULL;
  const mxArray *c2_rhs21 = NULL;
  const mxArray *c2_lhs21 = NULL;
  const mxArray *c2_rhs22 = NULL;
  const mxArray *c2_lhs22 = NULL;
  const mxArray *c2_rhs23 = NULL;
  const mxArray *c2_lhs23 = NULL;
  const mxArray *c2_rhs24 = NULL;
  const mxArray *c2_lhs24 = NULL;
  const mxArray *c2_rhs25 = NULL;
  const mxArray *c2_lhs25 = NULL;
  const mxArray *c2_rhs26 = NULL;
  const mxArray *c2_lhs26 = NULL;
  const mxArray *c2_rhs27 = NULL;
  const mxArray *c2_lhs27 = NULL;
  const mxArray *c2_rhs28 = NULL;
  const mxArray *c2_lhs28 = NULL;
  const mxArray *c2_rhs29 = NULL;
  const mxArray *c2_lhs29 = NULL;
  const mxArray *c2_rhs30 = NULL;
  const mxArray *c2_lhs30 = NULL;
  const mxArray *c2_rhs31 = NULL;
  const mxArray *c2_lhs31 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("abs"), "name", "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c2_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c2_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c2_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mpower"), "name", "name", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c2_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c2_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c2_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("power"), "name", "name", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c2_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c2_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c2_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c2_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c2_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c2_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c2_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c2_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c2_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c2_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sqrt"), "name", "name", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c2_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_error"), "name", "name",
                  28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c2_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818738U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c2_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("atan"), "name", "name", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c2_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_atan"), "name",
                  "name", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818718U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c2_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs31), "lhs", "lhs",
                  31);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
  sf_mex_destroy(&c2_rhs11);
  sf_mex_destroy(&c2_lhs11);
  sf_mex_destroy(&c2_rhs12);
  sf_mex_destroy(&c2_lhs12);
  sf_mex_destroy(&c2_rhs13);
  sf_mex_destroy(&c2_lhs13);
  sf_mex_destroy(&c2_rhs14);
  sf_mex_destroy(&c2_lhs14);
  sf_mex_destroy(&c2_rhs15);
  sf_mex_destroy(&c2_lhs15);
  sf_mex_destroy(&c2_rhs16);
  sf_mex_destroy(&c2_lhs16);
  sf_mex_destroy(&c2_rhs17);
  sf_mex_destroy(&c2_lhs17);
  sf_mex_destroy(&c2_rhs18);
  sf_mex_destroy(&c2_lhs18);
  sf_mex_destroy(&c2_rhs19);
  sf_mex_destroy(&c2_lhs19);
  sf_mex_destroy(&c2_rhs20);
  sf_mex_destroy(&c2_lhs20);
  sf_mex_destroy(&c2_rhs21);
  sf_mex_destroy(&c2_lhs21);
  sf_mex_destroy(&c2_rhs22);
  sf_mex_destroy(&c2_lhs22);
  sf_mex_destroy(&c2_rhs23);
  sf_mex_destroy(&c2_lhs23);
  sf_mex_destroy(&c2_rhs24);
  sf_mex_destroy(&c2_lhs24);
  sf_mex_destroy(&c2_rhs25);
  sf_mex_destroy(&c2_lhs25);
  sf_mex_destroy(&c2_rhs26);
  sf_mex_destroy(&c2_lhs26);
  sf_mex_destroy(&c2_rhs27);
  sf_mex_destroy(&c2_lhs27);
  sf_mex_destroy(&c2_rhs28);
  sf_mex_destroy(&c2_lhs28);
  sf_mex_destroy(&c2_rhs29);
  sf_mex_destroy(&c2_lhs29);
  sf_mex_destroy(&c2_rhs30);
  sf_mex_destroy(&c2_lhs30);
  sf_mex_destroy(&c2_rhs31);
  sf_mex_destroy(&c2_lhs31);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static real_T c2_robustDiv2(SFc2_modelInstanceStruct *chartInstance, real_T
  c2_num, real_T c2_den, real_T c2_epsilon)
{
  real_T c2_z;
  uint32_T c2_debug_family_var_map[6];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_y;
  real_T c2_A;
  real_T c2_B;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  real_T c2_c_y;
  real_T c2_e_x;
  real_T c2_d_y;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_f_x;
  real_T c2_e_y;
  real_T c2_g_x;
  real_T c2_f_y;
  real_T c2_h_x;
  real_T c2_g_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_num, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_den, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_epsilon, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_z, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
  if (CV_EML_IF(0, 1, 2, c2_den == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
    c2_x = c2_num;
    c2_b_x = c2_x;
    c2_y = muDoubleScalarAbs(c2_b_x);
    if (CV_EML_IF(0, 1, 3, c2_y > c2_epsilon)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
      c2_A = c2_num;
      c2_B = c2_epsilon;
      c2_c_x = c2_A;
      c2_b_y = c2_B;
      c2_d_x = c2_c_x;
      c2_c_y = c2_b_y;
      c2_e_x = c2_d_x;
      c2_d_y = c2_c_y;
      c2_z = c2_e_x / c2_d_y;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
      c2_z = 0.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
    c2_b_A = c2_num;
    c2_b_B = c2_den;
    c2_f_x = c2_b_A;
    c2_e_y = c2_b_B;
    c2_g_x = c2_f_x;
    c2_f_y = c2_e_y;
    c2_h_x = c2_g_x;
    c2_g_y = c2_f_y;
    c2_z = c2_h_x / c2_g_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -65);
  _SFD_SYMBOL_SCOPE_POP();
  return c2_z;
}

static real_T c2_mpower(SFc2_modelInstanceStruct *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  return c2_d_a * c2_d_a;
}

static void c2_eml_scalar_eg(SFc2_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_error(SFc2_modelInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  int32_T c2_i1;
  static char_T c2_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  for (c2_i0 = 0; c2_i0 < 30; c2_i0++) {
    c2_u[c2_i0] = c2_cv0[c2_i0];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    c2_b_u[c2_i1] = c2_cv1[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_y, 14, c2_b_y));
}

static real_T c2_robustDiv(SFc2_modelInstanceStruct *chartInstance, real_T
  c2_num, real_T c2_den, real_T c2_epsilon)
{
  real_T c2_z;
  uint32_T c2_debug_family_var_map[6];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  real_T c2_A;
  real_T c2_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_f_x;
  real_T c2_f_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c2_c_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_num, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_den, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_epsilon, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_z, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  if (CV_EML_IF(0, 1, 0, c2_den == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
    if (CV_EML_IF(0, 1, 1, c2_num != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
      c2_A = c2_num;
      c2_B = c2_epsilon;
      c2_x = c2_A;
      c2_y = c2_B;
      c2_b_x = c2_x;
      c2_b_y = c2_y;
      c2_c_x = c2_b_x;
      c2_c_y = c2_b_y;
      c2_z = c2_c_x / c2_c_y;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
      c2_z = 0.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
    c2_b_A = c2_num;
    c2_b_B = c2_den;
    c2_d_x = c2_b_A;
    c2_d_y = c2_b_B;
    c2_e_x = c2_d_x;
    c2_e_y = c2_d_y;
    c2_f_x = c2_e_x;
    c2_f_y = c2_e_y;
    c2_z = c2_f_x / c2_f_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -51);
  _SFD_SYMBOL_SCOPE_POP();
  return c2_z;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i2;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i2, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_d_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sTXaXgTBgcsTeEwtC20RoaB *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[38] = { "m", "Iz", "Iw", "lF", "lR", "h",
    "R", "B", "C", "maxDelta", "maxTb", "maxThb", "maxTm", "gammaB", "gammaM",
    "g", "mu", "muRoll", "b", "fric", "FzF", "FzR", "Dz1", "Dz2", "T", "WF0",
    "WR0", "Ux0", "Uy0", "r0", "x0", "y0", "ksi0", "Press2TorF", "Press2TorR",
    "maxPress", "press2torF", "press2torR" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 38, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "m";
  c2_y->m = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "m", "m", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Iz";
  c2_y->Iz = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Iz", "Iz", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Iw";
  c2_y->Iw = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Iw", "Iw", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "lF";
  c2_y->lF = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "lF", "lF", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "lR";
  c2_y->lR = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "lR", "lR", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "h";
  c2_y->h = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "h", "h", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "R";
  c2_y->R = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "R", "R", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "B";
  c2_y->B = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "B", "B", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "C";
  c2_y->C = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "C", "C", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "maxDelta";
  c2_y->maxDelta = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "maxDelta", "maxDelta", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "maxTb";
  c2_y->maxTb = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "maxTb", "maxTb", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "maxThb";
  c2_y->maxThb = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "maxThb", "maxThb", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "maxTm";
  c2_y->maxTm = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "maxTm", "maxTm", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "gammaB";
  c2_y->gammaB = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "gammaB", "gammaB", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "gammaM";
  c2_y->gammaM = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "gammaM", "gammaM", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "g";
  c2_y->g = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "g", "g", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "mu";
  c2_y->mu = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "mu", "mu", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "muRoll";
  c2_y->muRoll = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_u, "muRoll", "muRoll", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "b";
  c2_y->b = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "b", "b", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "fric";
  c2_y->fric = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "fric", "fric", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "FzF";
  c2_y->FzF = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "FzF", "FzF", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "FzR";
  c2_y->FzR = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "FzR", "FzR", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Dz1";
  c2_y->Dz1 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Dz1", "Dz1", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Dz2";
  c2_y->Dz2 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Dz2", "Dz2", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "T";
  c2_y->T = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "T", "T", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "WF0";
  c2_y->WF0 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "WF0", "WF0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "WR0";
  c2_y->WR0 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "WR0", "WR0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Ux0";
  c2_y->Ux0 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Ux0", "Ux0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Uy0";
  c2_y->Uy0 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Uy0", "Uy0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "r0";
  c2_y->r0 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "r0", "r0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "x0";
  c2_y->x0 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "x0", "x0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "y0";
  c2_y->_y0 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "y0", "y0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "ksi0";
  c2_y->ksi0 = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "ksi0", "ksi0", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Press2TorF";
  c2_y->Press2TorF = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "Press2TorF", "Press2TorF", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Press2TorR";
  c2_y->Press2TorR = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "Press2TorR", "Press2TorR", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "maxPress";
  c2_y->maxPress = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "maxPress", "maxPress", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "press2torF";
  c2_y->press2torF = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "press2torF", "press2torF", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "press2torR";
  c2_y->press2torR = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "press2torR", "press2torR", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_params;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sTXaXgTBgcsTeEwtC20RoaB c2_y;
  SFc2_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelInstanceStruct *)chartInstanceVoid;
  c2_b_params = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_params), &c2_thisId,
                        &c2_y);
  sf_mex_destroy(&c2_b_params);
  *(c2_sTXaXgTBgcsTeEwtC20RoaB *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_model, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_is_active_c2_model),
    &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_model);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_modelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_modelInstanceStruct *chartInstance)
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

void sf_c2_model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(427214375U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1798586615U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1325165994U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2821842907U);
}

mxArray *sf_c2_model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("f0AtmexA08dhLCscepHxHD");
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"FxF\",},{M[1],M[21],T\"FxR\",},{M[1],M[20],T\"FyF\",},{M[1],M[22],T\"FyR\",},{M[8],M[0],T\"is_active_c2_model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_modelInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_modelInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _modelMachineNumber_,
           2,
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
        init_script_number_translation(_modelMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_modelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _modelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ux");
          _SFD_SET_DATA_PROPS(1,2,0,1,"FxF");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Uy");
          _SFD_SET_DATA_PROPS(3,1,1,0,"wR");
          _SFD_SET_DATA_PROPS(4,1,1,0,"wF");
          _SFD_SET_DATA_PROPS(5,1,1,0,"delta");
          _SFD_SET_DATA_PROPS(6,1,1,0,"r");
          _SFD_SET_DATA_PROPS(7,10,0,0,"params");
          _SFD_SET_DATA_PROPS(8,2,0,1,"FyF");
          _SFD_SET_DATA_PROPS(9,2,0,1,"FxR");
          _SFD_SET_DATA_PROPS(10,2,0,1,"FyR");
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
        _SFD_CV_INIT_EML(0,1,3,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1110);
        _SFD_CV_INIT_EML_FCN(0,1,"robustDiv",1112,-1,1313);
        _SFD_CV_INIT_EML_FCN(0,2,"robustDiv2",1315,-1,1529);
        _SFD_CV_INIT_EML_IF(0,1,0,1154,1165,1275,1300);
        _SFD_CV_INIT_EML_IF(0,1,1,1171,1182,1212,1274);
        _SFD_CV_INIT_EML_IF(0,1,2,1358,1369,1489,1514);
        _SFD_CV_INIT_EML_IF(0,1,3,1375,1396,1426,1488);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_Ux;
          real_T *c2_FxF;
          real_T *c2_Uy;
          real_T *c2_wR;
          real_T *c2_wF;
          real_T *c2_delta;
          real_T *c2_r;
          real_T *c2_FyF;
          real_T *c2_FxR;
          real_T *c2_FyR;
          c2_FyR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_FxR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_FyF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_delta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_wF = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_wR = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_Uy = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_FxF = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Ux = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_Ux);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_FxF);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_Uy);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_wR);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_wF);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_delta);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_r);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c2_params);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_FyF);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_FxR);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_FyR);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _modelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "tVyL23ll6dokSpwJgEjSPD";
}

static void sf_opaque_initialize_c2_model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_modelInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_model((SFc2_modelInstanceStruct*) chartInstanceVar);
  initialize_c2_model((SFc2_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_model(void *chartInstanceVar)
{
  enable_c2_model((SFc2_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_model(void *chartInstanceVar)
{
  disable_c2_model((SFc2_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_model(void *chartInstanceVar)
{
  sf_gateway_c2_model((SFc2_modelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_model(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_model((SFc2_modelInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_model();/* state var info */
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

extern void sf_internal_set_sim_state_c2_model(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_model((SFc2_modelInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_model(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_model(S);
}

static void sf_opaque_set_sim_state_c2_model(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_model(S, st);
}

static void sf_opaque_terminate_c2_model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_modelInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_model_optimization_info();
    }

    finalize_c2_model((SFc2_modelInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_model((SFc2_modelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_model(SimStruct *S)
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
    initialize_params_c2_model((SFc2_modelInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_model(SimStruct *S)
{
  /* Actual parameters from chart:
     params
   */
  const char_T *rtParamNames[] = { "params" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3895109549U));
  ssSetChecksum1(S,(3748741837U));
  ssSetChecksum2(S,(1610511329U));
  ssSetChecksum3(S,(1450045253U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_model(SimStruct *S)
{
  SFc2_modelInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_modelInstanceStruct *)utMalloc(sizeof
    (SFc2_modelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_modelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_model;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_model;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_model;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_model;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_model;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_model;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_model;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_model;
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

void c2_model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
