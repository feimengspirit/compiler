# Microsoft Developer Studio Project File - Name="Compiler_GC" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Compiler_GC - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Compiler_GC.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Compiler_GC.mak" CFG="Compiler_GC - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Compiler_GC - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Compiler_GC - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Compiler_GC - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "Compiler_GC - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Compiler_GC - Win32 Release"
# Name "Compiler_GC - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Analyse.cpp
# End Source File
# Begin Source File

SOURCE=.\Analyse.h
# End Source File
# Begin Source File

SOURCE=.\ArrayAssignStm.cpp
# End Source File
# Begin Source File

SOURCE=.\ArrayAssignStm.h
# End Source File
# Begin Source File

SOURCE=.\AssignStm.cpp
# End Source File
# Begin Source File

SOURCE=.\AssignStm.h
# End Source File
# Begin Source File

SOURCE=.\BoolType.cpp
# End Source File
# Begin Source File

SOURCE=.\BoolType.h
# End Source File
# Begin Source File

SOURCE=.\BufferMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\BufferMgr.h
# End Source File
# Begin Source File

SOURCE=.\ClassDecl.h
# End Source File
# Begin Source File

SOURCE=.\ClassDecls.cpp
# End Source File
# Begin Source File

SOURCE=.\ClassDecls.h
# End Source File
# Begin Source File

SOURCE=.\ClassNameDecl.cpp
# End Source File
# Begin Source File

SOURCE=.\ClassNameDecl.h
# End Source File
# Begin Source File

SOURCE=.\CompositeStatement.cpp
# End Source File
# Begin Source File

SOURCE=.\CompositeStatement.h
# End Source File
# Begin Source File

SOURCE=.\DotIdExpp.cpp
# End Source File
# Begin Source File

SOURCE=.\DotIdExpp.h
# End Source File
# Begin Source File

SOURCE=.\DotLenExpp.cpp
# End Source File
# Begin Source File

SOURCE=.\DotLenExpp.h
# End Source File
# Begin Source File

SOURCE=.\EmptyExpList.cpp
# End Source File
# Begin Source File

SOURCE=.\EmptyExpList.h
# End Source File
# Begin Source File

SOURCE=.\EmptyFormalList.h
# End Source File
# Begin Source File

SOURCE=.\Exp.h
# End Source File
# Begin Source File

SOURCE=.\ExpList.h
# End Source File
# Begin Source File

SOURCE=.\Expp.h
# End Source File
# Begin Source File

SOURCE=.\ExpRest.cpp
# End Source File
# Begin Source File

SOURCE=.\ExpRest.h
# End Source File
# Begin Source File

SOURCE=.\ExpRests.cpp
# End Source File
# Begin Source File

SOURCE=.\ExpRests.h
# End Source File
# Begin Source File

SOURCE=.\ExtendsClassDecl.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtendsClassDecl.h
# End Source File
# Begin Source File

SOURCE=.\FalseExp.cpp
# End Source File
# Begin Source File

SOURCE=.\FalseExp.h
# End Source File
# Begin Source File

SOURCE=.\FormalList.h
# End Source File
# Begin Source File

SOURCE=.\FormalRest.h
# End Source File
# Begin Source File

SOURCE=.\FormalRests.h
# End Source File
# Begin Source File

SOURCE=.\IArrayType.cpp
# End Source File
# Begin Source File

SOURCE=.\IArrayType.h
# End Source File
# Begin Source File

SOURCE=.\Id.h
# End Source File
# Begin Source File

SOURCE=.\IdExp.cpp
# End Source File
# Begin Source File

SOURCE=.\IdExp.h
# End Source File
# Begin Source File

SOURCE=.\IdType.cpp
# End Source File
# Begin Source File

SOURCE=.\IdType.h
# End Source File
# Begin Source File

SOURCE=.\IfStatement.cpp
# End Source File
# Begin Source File

SOURCE=.\IfStatement.h
# End Source File
# Begin Source File

SOURCE=.\IntType.cpp
# End Source File
# Begin Source File

SOURCE=.\IntType.h
# End Source File
# Begin Source File

SOURCE=.\LBrackExpp.cpp
# End Source File
# Begin Source File

SOURCE=.\LBrackExpp.h
# End Source File
# Begin Source File

SOURCE=.\Lexer.cpp
# End Source File
# Begin Source File

SOURCE=.\Lexer.h
# End Source File
# Begin Source File

SOURCE=.\LParenExp.cpp
# End Source File
# Begin Source File

SOURCE=.\LParenExp.h
# End Source File
# Begin Source File

SOURCE=.\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\MainClass.cpp
# End Source File
# Begin Source File

SOURCE=.\MainClass.h
# End Source File
# Begin Source File

SOURCE=.\MethodDecl.h
# End Source File
# Begin Source File

SOURCE=.\MethodDecls.h
# End Source File
# Begin Source File

SOURCE=.\NeExpList.cpp
# End Source File
# Begin Source File

SOURCE=.\NeExpList.h
# End Source File
# Begin Source File

SOURCE=.\NEFormalList.h
# End Source File
# Begin Source File

SOURCE=.\NewIdExp.cpp
# End Source File
# Begin Source File

SOURCE=.\NewIdExp.h
# End Source File
# Begin Source File

SOURCE=.\NewIntExp.cpp
# End Source File
# Begin Source File

SOURCE=.\NewIntExp.h
# End Source File
# Begin Source File

SOURCE=.\NotExp.cpp
# End Source File
# Begin Source File

SOURCE=.\NotExp.h
# End Source File
# Begin Source File

SOURCE=.\NumExp.cpp
# End Source File
# Begin Source File

SOURCE=.\NumExp.h
# End Source File
# Begin Source File

SOURCE=.\Op.h
# End Source File
# Begin Source File

SOURCE=.\OpExpp.cpp
# End Source File
# Begin Source File

SOURCE=.\OpExpp.h
# End Source File
# Begin Source File

SOURCE=.\Parser.cpp
# End Source File
# Begin Source File

SOURCE=.\Parser.h
# End Source File
# Begin Source File

SOURCE=.\PrintStatement.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintStatement.h
# End Source File
# Begin Source File

SOURCE=.\Program.cpp
# End Source File
# Begin Source File

SOURCE=.\Program.h
# End Source File
# Begin Source File

SOURCE=.\SingleClassDecl.cpp
# End Source File
# Begin Source File

SOURCE=.\SingleClassDecl.h
# End Source File
# Begin Source File

SOURCE=.\Statement.h
# End Source File
# Begin Source File

SOURCE=.\Statements.h
# End Source File
# Begin Source File

SOURCE=.\ThisExp.cpp
# End Source File
# Begin Source File

SOURCE=.\ThisExp.h
# End Source File
# Begin Source File

SOURCE=.\TrueExp.cpp
# End Source File
# Begin Source File

SOURCE=.\TrueExp.h
# End Source File
# Begin Source File

SOURCE=.\Type.h
# End Source File
# Begin Source File

SOURCE=.\VarDecl.cpp
# End Source File
# Begin Source File

SOURCE=.\VarDecl.h
# End Source File
# Begin Source File

SOURCE=.\VarDecls.cpp
# End Source File
# Begin Source File

SOURCE=.\VarDecls.h
# End Source File
# Begin Source File

SOURCE=.\WhileStatement.cpp
# End Source File
# Begin Source File

SOURCE=.\WhileStatement.h
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
