@echo off
set COMPILER=cl 
				set COMPFLAGS=/c  /GR /W3 /EHs /nologo /MD /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0  /DMATLAB_MEX_FILE -I"D:\Program Files\MATLAB\R2014a\extern\include" -I"D:\Program Files\MATLAB\R2014a\simulink\include" /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0  /DMATLAB_MEX_FILE  /DMATLAB_MEX_FILE 
				set OPTIMFLAGS=/O2 /Oy- /DNDEBUG 
				set DEBUGFLAGS=/Z7 
				set LINKER=link 
				set LINKFLAGS= /nologo  /manifest kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /incremental:NO /export:%ENTRYPOINT% /DLL /LIBPATH:"D:\Program Files\MATLAB\R2014a\extern\lib\win32\microsoft" libmx.lib libmex.lib libmat.lib 
				set LINKDEBUGFLAGS=/debug /PDB:"%OUTDIR%%MEX_NAME%.mexw32.pdb" 
				set NAME_OUTPUT=/out:"%OUTDIR%%MEX_NAME%%MEX_EXT%" 
set PATH=d:\Program Files\Microsoft Visual Studio 10.0\VC\Bin;d:\Program Files\Microsoft Visual Studio 10.0\VC\Bin\VCPackages;d:\Program Files\Microsoft Visual Studio 10.0\Common7\IDE;d:\Program Files\Microsoft Visual Studio 10.0\Common7\Tools;d:\Program Files\Microsoft Visual Studio 10.0\Common7\Tools\bin;C:\Program Files\Microsoft SDKs\Windows\v7.0A\\Bin;;%MATLAB_BIN%;%PATH%
set INCLUDE=d:\Program Files\Microsoft Visual Studio 10.0\VC\ATLMFC\INCLUDE;d:\Program Files\Microsoft Visual Studio 10.0\VC\INCLUDE;C:\Program Files\Microsoft SDKs\Windows\v7.0A\\include;%INCLUDE%
set LIB=d:\Program Files\Microsoft Visual Studio 10.0\VC\ATLMFC\LIB;d:\Program Files\Microsoft Visual Studio 10.0\VC\Lib;C:\Program Files\Microsoft SDKs\Windows\v7.0A\\Lib;%LIB%
set LIBPATH=d:\Program Files\Microsoft Visual Studio 10.0\VC\Lib;d:\Program Files\Microsoft Visual Studio 10.0\VC\ATLMFC\LIB;C:\Program Files\Microsoft SDKs\Windows\v7.0A\\lib;D:\Program Files\MATLAB\R2014a\extern\lib\win32;;%LIBPATH%

nmake -f maneuvers_sfun.mak
