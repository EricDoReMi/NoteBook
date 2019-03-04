# Microsoft Developer Studio Project File - Name="Helloworld" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Helloworld - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Helloworld.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Helloworld.mak" CFG="Helloworld - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Helloworld - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Helloworld - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Helloworld - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "Helloworld - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Helloworld - Win32 Release"
# Name "Helloworld - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\arr.cpp
# End Source File
# Begin Source File

SOURCE=.\basicC.cpp
# End Source File
# Begin Source File

SOURCE=.\charStr.cpp
# End Source File
# Begin Source File

SOURCE=.\charType.cpp
# End Source File
# Begin Source File

SOURCE=.\dataType.cpp
# End Source File
# Begin Source File

SOURCE=.\declspec.cpp
# End Source File
# Begin Source File

SOURCE=.\DefineDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\FilePractice.cpp
# End Source File
# Begin Source File

SOURCE=.\findStrInArr.cpp
# End Source File
# Begin Source File

SOURCE=.\FunPointer.cpp
# End Source File
# Begin Source File

SOURCE=.\Helloworld.cpp
# End Source File
# Begin Source File

SOURCE=.\Helloworld2.cpp
# End Source File
# Begin Source File

SOURCE=.\IncludeDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\LogicTest.cpp
# End Source File
# Begin Source File

SOURCE=.\Pointer02.cpp
# End Source File
# Begin Source File

SOURCE=.\Pointer03.cpp
# End Source File
# Begin Source File

SOURCE=.\Pointer05.cpp
# End Source File
# Begin Source File

SOURCE=.\Pointer1.cpp
# End Source File
# Begin Source File

SOURCE=.\Pointer3.cpp
# End Source File
# Begin Source File

SOURCE=.\PointerArr.cpp
# End Source File
# Begin Source File

SOURCE=.\PointerArr2.cpp
# End Source File
# Begin Source File

SOURCE=.\PointerArr3.cpp
# End Source File
# Begin Source File

SOURCE=.\PointerArrPra.cpp
# End Source File
# Begin Source File

SOURCE=.\PointerArrPra2.cpp
# End Source File
# Begin Source File

SOURCE=.\PointerStr.cpp
# End Source File
# Begin Source File

SOURCE=.\returnCode.cpp
# End Source File
# Begin Source File

SOURCE=.\sizeOf1.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\strArrDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\StructDemo5.cpp
# End Source File
# Begin Source File

SOURCE=.\StructModel.cpp
# End Source File
# Begin Source File

SOURCE=.\StructModel2.cpp
# End Source File
# Begin Source File

SOURCE=.\StructModel3.cpp
# End Source File
# Begin Source File

SOURCE=.\switchCaseModel.cpp
# End Source File
# Begin Source File

SOURCE=.\typeChange.cpp
# End Source File
# Begin Source File

SOURCE=.\typeDefDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\UnionDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\xunhuan.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\x.h
# End Source File
# Begin Source File

SOURCE=.\y.h
# End Source File
# Begin Source File

SOURCE=.\z.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
