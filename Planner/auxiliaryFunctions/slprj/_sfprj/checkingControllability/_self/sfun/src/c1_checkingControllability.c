/* Include files */

#include <stddef.h>
#include "blas.h"
#include "checkingControllability_sfun.h"
#include "c1_checkingControllability.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "checkingControllability_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[12] = { "nargin", "nargout", "FxF",
  "FxR", "wF", "wR", "R", "gammaB", "brake", "handbrake", "TbF", "TbR" };

/* Function Declarations */
static void initialize_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static void initialize_params_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static void enable_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static void disable_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static void set_sim_state_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static void sf_gateway_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static void initSimStructsc1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct
  *chartInstance, const mxArray *c1_TbR, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_checkingControllability, const
  char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_checkingControllabilityInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_checkingControllability = 0U;
}

static void initialize_params_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
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
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_checkingControllability;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance, const mxArray
   *c1_st)
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
  chartInstance->c1_is_active_c1_checkingControllability = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_checkingControllability");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_checkingControllability(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal;
  real_T c1_FxF;
  real_T c1_FxR;
  real_T c1_wF;
  real_T c1_wR;
  real_T c1_R;
  real_T c1_gammaB;
  real_T c1_brake;
  real_T c1_handbrake;
  uint32_T c1_debug_family_var_map[12];
  real_T c1_nargin = 8.0;
  real_T c1_nargout = 2.0;
  real_T c1_TbF;
  real_T c1_TbR;
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
  real_T *c1_b_R;
  real_T *c1_b_gammaB;
  real_T *c1_b_brake;
  real_T *c1_b_handbrake;
  real_T *c1_b_TbR;
  c1_b_TbR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_handbrake = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_brake = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_gammaB = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
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
  c1_e_hoistedGlobal = *c1_b_R;
  c1_f_hoistedGlobal = *c1_b_gammaB;
  c1_g_hoistedGlobal = *c1_b_brake;
  c1_h_hoistedGlobal = *c1_b_handbrake;
  c1_FxF = c1_hoistedGlobal;
  c1_FxR = c1_b_hoistedGlobal;
  c1_wF = c1_c_hoistedGlobal;
  c1_wR = c1_d_hoistedGlobal;
  c1_R = c1_e_hoistedGlobal;
  c1_gammaB = c1_f_hoistedGlobal;
  c1_brake = c1_g_hoistedGlobal;
  c1_handbrake = c1_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_FxF, 2U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_FxR, 3U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_wF, 4U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_wR, 5U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_R, 6U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_gammaB, 7U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_brake, 8U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_handbrake, 9U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TbF, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TbR, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
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
      c1_TbF = -c1_brake * (1.0 - c1_gammaB) * c1_b_x;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
      c1_TbF = c1_FxF * c1_R;
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
    if (CV_EML_IF(0, 1, 2, c1_wR != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
      c1_c_x = c1_wR;
      c1_d_x = c1_c_x;
      c1_d_x = muDoubleScalarSign(c1_d_x);
      c1_TbR -= c1_brake * c1_gammaB * c1_d_x;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      c1_TbR = c1_FxR * c1_R;
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
      c1_TbR = c1_FxR * c1_R;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_TbF = c1_TbF;
  *c1_b_TbR = c1_TbR;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_checkingControllabilityMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c1_b_TbF, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_FxR, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_wF, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_wR, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_b_R, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_b_gammaB, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_b_brake, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_b_handbrake, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_b_TbR, 9U);
}

static void initSimStructsc1_checkingControllability
  (SFc1_checkingControllabilityInstanceStruct *chartInstance)
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
  SFc1_checkingControllabilityInstanceStruct *chartInstance;
  chartInstance = (SFc1_checkingControllabilityInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct
  *chartInstance, const mxArray *c1_TbR, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_TbR), &c1_thisId);
  sf_mex_destroy(&c1_TbR);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct
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
  SFc1_checkingControllabilityInstanceStruct *chartInstance;
  chartInstance = (SFc1_checkingControllabilityInstanceStruct *)
    chartInstanceVoid;
  c1_TbR = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_TbR), &c1_thisId);
  sf_mex_destroy(&c1_TbR);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_checkingControllability_get_eml_resolved_functions_info
  (void)
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

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_checkingControllabilityInstanceStruct *chartInstance;
  chartInstance = (SFc1_checkingControllabilityInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
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
  SFc1_checkingControllabilityInstanceStruct *chartInstance;
  chartInstance = (SFc1_checkingControllabilityInstanceStruct *)
    chartInstanceVoid;
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

static uint8_T c1_d_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_checkingControllability, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_checkingControllability), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_checkingControllability);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_checkingControllabilityInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_checkingControllabilityInstanceStruct
  *chartInstance)
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

void sf_c1_checkingControllability_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3004818137U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(622982124U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1939291815U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(70621619U);
}

mxArray *sf_c1_checkingControllability_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SPHZxBo5UOnpyiL8mYfARC");
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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

mxArray *sf_c1_checkingControllability_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_checkingControllability_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_checkingControllability(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"TbF\",},{M[1],M[11],T\"TbR\",},{M[8],M[0],T\"is_active_c1_checkingControllability\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_checkingControllability_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_checkingControllabilityInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_checkingControllabilityInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _checkingControllabilityMachineNumber_,
           1,
           1,
           1,
           0,
           10,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_checkingControllabilityMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_checkingControllabilityMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _checkingControllabilityMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"FxF");
          _SFD_SET_DATA_PROPS(1,2,0,1,"TbF");
          _SFD_SET_DATA_PROPS(2,1,1,0,"FxR");
          _SFD_SET_DATA_PROPS(3,1,1,0,"wF");
          _SFD_SET_DATA_PROPS(4,1,1,0,"wR");
          _SFD_SET_DATA_PROPS(5,1,1,0,"R");
          _SFD_SET_DATA_PROPS(6,1,1,0,"gammaB");
          _SFD_SET_DATA_PROPS(7,1,1,0,"brake");
          _SFD_SET_DATA_PROPS(8,1,1,0,"handbrake");
          _SFD_SET_DATA_PROPS(9,2,0,1,"TbR");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,463);
        _SFD_CV_INIT_EML_IF(0,1,0,101,113,-1,330);
        _SFD_CV_INIT_EML_IF(0,1,1,122,132,184,219);
        _SFD_CV_INIT_EML_IF(0,1,2,229,239,291,326);
        _SFD_CV_INIT_EML_IF(0,1,3,332,348,-1,456);
        _SFD_CV_INIT_EML_IF(0,1,4,357,367,414,449);
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
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_FxF;
          real_T *c1_TbF;
          real_T *c1_FxR;
          real_T *c1_wF;
          real_T *c1_wR;
          real_T *c1_R;
          real_T *c1_gammaB;
          real_T *c1_brake;
          real_T *c1_handbrake;
          real_T *c1_TbR;
          c1_TbR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_handbrake = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_brake = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_gammaB = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
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
          _SFD_SET_DATA_VALUE_PTR(5U, c1_R);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_gammaB);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_brake);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_handbrake);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_TbR);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _checkingControllabilityMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "QXysOhuMt4hDF9LdRowTv";
}

static void sf_opaque_initialize_c1_checkingControllability(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_checkingControllabilityInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_checkingControllability
    ((SFc1_checkingControllabilityInstanceStruct*) chartInstanceVar);
  initialize_c1_checkingControllability
    ((SFc1_checkingControllabilityInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_checkingControllability(void *chartInstanceVar)
{
  enable_c1_checkingControllability((SFc1_checkingControllabilityInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_checkingControllability(void *chartInstanceVar)
{
  disable_c1_checkingControllability((SFc1_checkingControllabilityInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_checkingControllability(void *chartInstanceVar)
{
  sf_gateway_c1_checkingControllability
    ((SFc1_checkingControllabilityInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_checkingControllability
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_checkingControllability
    ((SFc1_checkingControllabilityInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_checkingControllability();/* state var info */
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

extern void sf_internal_set_sim_state_c1_checkingControllability(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_checkingControllability();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_checkingControllability
    ((SFc1_checkingControllabilityInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_checkingControllability
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_checkingControllability(S);
}

static void sf_opaque_set_sim_state_c1_checkingControllability(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_checkingControllability(S, st);
}

static void sf_opaque_terminate_c1_checkingControllability(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_checkingControllabilityInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_checkingControllability_optimization_info();
    }

    finalize_c1_checkingControllability
      ((SFc1_checkingControllabilityInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_checkingControllability
    ((SFc1_checkingControllabilityInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_checkingControllability(SimStruct *S)
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
    initialize_params_c1_checkingControllability
      ((SFc1_checkingControllabilityInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_checkingControllability(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_checkingControllability_optimization_info();
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
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
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
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1489562425U));
  ssSetChecksum1(S,(1231217673U));
  ssSetChecksum2(S,(3919859458U));
  ssSetChecksum3(S,(284953863U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_checkingControllability(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_checkingControllability(SimStruct *S)
{
  SFc1_checkingControllabilityInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_checkingControllabilityInstanceStruct *)utMalloc(sizeof
    (SFc1_checkingControllabilityInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_checkingControllabilityInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_checkingControllability;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_checkingControllability;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_checkingControllability;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_checkingControllability;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_checkingControllability;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_checkingControllability;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_checkingControllability;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_checkingControllability;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_checkingControllability;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_checkingControllability;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_checkingControllability;
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

void c1_checkingControllability_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_checkingControllability(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_checkingControllability(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_checkingControllability(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_checkingControllability_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
