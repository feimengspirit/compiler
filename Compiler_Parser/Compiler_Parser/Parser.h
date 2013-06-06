#ifndef __PARSER_H__
#define __PARSER_H__
#include "Lexer.h"
#include <iostream>
using namespace std;
class Parser
{
public:
	Parser(string filename)
	{	
		Lexer(filename);			//调用词法分析器	
		Move();						//移进一个单词
	}
	~Parser(){}
	void Match(WordKind);			//匹配一个单词
	void Parse();
	void Move()						//移进函数
	{
		look = scan();				
	}
	
private:
	NewToken look;					//下一个待分析的单词
	void Program();					//分析程序语法
	void MainClass();				//分析主类语法
	void ClassDecls();				//分析类声明语法（不定）
	void Id();						//分析标识符语法
	void Statements();				//分析多条语句语法
	void Statement();				//分析单条语句语法 
	void ClassDecl();				//分析类声明语法
	void ClassNameDecl();			//分析类名语法
	void VarDecls();				//分析多个变量声明语法
	void VarDecl();					//分析单个变量声明语法
	void MethodDecls();				//分析多个方法声明语法
	void MethodDecl();				//分析大哥方法声明语法
	void Type();					//分析类型语法
	void FormalList();				//分析形式列表语法
	void FormalRests();				//分析形式列表尾端语法（不定数目）
	void FormalRest();				//分析形式列表尾端语法
	void Exp();						//分析表达式语法
	void Expp();					//消除左递归新增的非终结符
	void ExpList();					//分析表达式列表语法
	void ExpRests();				//分析表达式列表尾部语法（不定数目）
	void ExpRest();					//分析表达式列表尾部语法
	void Op();						//操作符

};
void syntax_error(NewToken,WordKind);	//做语法分析的报错

#endif