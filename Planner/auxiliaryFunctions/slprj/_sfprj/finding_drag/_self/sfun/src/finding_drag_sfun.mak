# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


!include <ntwin32.mak>

MACHINE     = finding_drag
TARGET      = sfun
CHART_SRCS   = c1_finding_drag.c c2_finding_drag.c c3_finding_drag.c
MACHINE_SRC  = finding_drag_sfun.c
MACHINE_REG = finding_drag_sfun_registry.c
MAKEFILE    = finding_drag_sfun.mak
MATLAB_ROOT  = D:\Program Files\MATLAB\R2014a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "D:\Program Files\MATLAB\R2014a\extern\include" \
    /I "D:\Program Files\MATLAB\R2014a\simulink\include" \
    /I "D:\Program Files\MATLAB\R2014a\stateflow\c\mex\include" \
    /I "D:\Program Files\MATLAB\R2014a\rtw\c\src" \
    /I "C:\Users\Edo\Documents\master thesis\model_complex\auxiliaryFunctions\slprj\_sfprj\finding_drag\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MACHINE_SRC) $(MACHINE_REG) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = finding_drag_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = 
BLAS_LIBS = "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw32
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

TMWLIB = "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\sf_runtime.lib" "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libmx.lib" "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libmex.lib" "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libmat.lib" "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libfixedpoint.lib" "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libut.lib" "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libmwmathutil.lib" "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libemlrt.lib" "D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft\libmwsl_log_load_blocks.lib" "D:\Program Files\MATLAB\R2014a\lib\win32\libippmwipt.lib" 

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(TMWLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


