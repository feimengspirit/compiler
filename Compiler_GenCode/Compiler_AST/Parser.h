#ifndef __PARSER_H__
#define __PARSER_H__
#include "Lexer.h"
#include "Program.h"
#include "MainClass.h"
#include "ClassDecl.h"
#include "ClassDecls.h"
#include "ClassNameDecl.h"
#include "ExtendsClassDecl.h"
#include "SingleClassDecl.h"
#include "MethodDecl.h"
#include "MethodDecls.h"
#include "EmptyFormalList.h"
#include "FormalList.h"
#include "FormalRest.h"
#include "FormalRests.h"
#include "NEFormalList.h"
#include "EmptyExpList.h"
#include "ExpList.h"
#include "ExpRest.h"
#include "ExpRests.h"
#include "NeExpList.h"
#include "Exp.h"
#include "FalseExp.h"
#include "IdExp.h"
#include "LParenExp.h"
#include "NewIdExp.h"
#include "NewIntExp.h"
#include "NotExp.h"
#include "NumExp.h"
#include "ThisExp.h"
#include "TrueExp.h"
#include "DotIdExpp.h"
#include "DotLenExpp.h"
#include "Expp.h"
#include "LBrackExpp.h"
#include "OpExpp.h"
#include "Type.h"
#include "BoolType.h"
#include "IArrayType.h"
#include "IdType.h"
#include "IntType.h"
#include "ArrayAssignStm.h"
#include "AssignStm.h"
#include "CompositeStatement.h"
#include "IfStatement.h"
#include "PrintStatement.h"
#include "Statement.h"
#include "Statements.h"
#include "WhileStatement.h"
#include "VarDecl.h"
#include "VarDecls.h"
#include "Id.h"
#include "Op.h"

#include <string>
#include <iostream>

using namespace std;



class Parser
{
public:
	Parser(string filename)			//构造函数
	{	
		Lexer(filename);			//调用词法分析器	
		Move();						//移进一个单词
	}
	~Parser(){}						//析构函数
	void Match(WordKind);			//匹配一个单词
	Program* Parse();				//语法分析入口函数
	void Move()						//移进函数
	{
		look = scan();				
	}
	
private:
	NewToken look;							//下一个待分析的单词
//*****************************************************************************
	Program* FProgram();					//分析程序语法
	MainClass* FMainClass();				//分析主类语法
	ClassDecls* FClassDecls();				//分析类声明语法（不定）
	Id* FId();								//分析标识符语法
	Statements* FStatements();				//分析多条语句语法
	Statement* FStatement();				//分析单条语句语法 
	ClassDecl* FClassDecl();				//分析类声明语法
	ClassNameDecl* FClassNameDecl();		//分析类名语法
	VarDecls* FVarDecls();					//分析多个变量声明语法
	VarDecl* FVarDecl();					//分析单个变量声明语法
	MethodDecls* FMethodDecls();			//分析多个方法声明语法
	MethodDecl* FMethodDecl();				//分析大哥方法声明语法
	Type* FType();							//分析类型语法
	FormalList* FFormalList();				//分析形式列表语法
	FormalRests* FFormalRests();			//分析形式列表尾端语法（不定数目）
	FormalRest* FFormalRest();				//分析形式列表尾端语法
	Exp* FExp();							//分析表达式语法
	Expp* FExpp();							//消除左递归新增的非终结符
	ExpList* FExpList();					//分析表达式列表语法
	ExpRests* FExpRests();					//分析表达式列表尾部语法（不定数目）
	ExpRest* FExpRest();					//分析表达式列表尾部语法
	Op* FOp();								//操作符

};

void syntax_error(NewToken,WordKind);		//做语法分析的报错




#endif