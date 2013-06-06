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

using namespace std;



class Parser
{
public:
	Parser(string filename)			//���캯��
	{	
		Lexer(filename);			//���ôʷ�������	
		Move();						//�ƽ�һ������
	}
	~Parser(){}						//��������
	void Match(WordKind);			//ƥ��һ������
	Program* Parse();				//�﷨������ں���
	void Move()						//�ƽ�����
	{
		look = scan();				
	}
	
private:
	NewToken look;							//��һ���������ĵ���
//*****************************************************************************
	Program* FProgram();					//���������﷨
	MainClass* FMainClass();				//���������﷨
	ClassDecls* FClassDecls();				//�����������﷨��������
	Id* FId();								//������ʶ���﷨
	Statements* FStatements();				//������������﷨
	Statement* FStatement();				//������������﷨ 
	ClassDecl* FClassDecl();				//�����������﷨
	ClassNameDecl* FClassNameDecl();		//���������﷨
	VarDecls* FVarDecls();					//����������������﷨
	VarDecl* FVarDecl();					//�����������������﷨
	MethodDecls* FMethodDecls();			//����������������﷨
	MethodDecl* FMethodDecl();				//������緽�������﷨
	Type* FType();							//���������﷨
	FormalList* FFormalList();				//������ʽ�б��﷨
	FormalRests* FFormalRests();			//������ʽ�б�β���﷨��������Ŀ��
	FormalRest* FFormalRest();				//������ʽ�б�β���﷨
	Exp* FExp();							//�������ʽ�﷨
	Expp* FExpp();							//������ݹ������ķ��ս��
	ExpList* FExpList();					//�������ʽ�б��﷨
	ExpRests* FExpRests();					//�������ʽ�б�β���﷨��������Ŀ��
	ExpRest* FExpRest();					//�������ʽ�б�β���﷨
	Op* FOp();								//������

};

void syntax_error(NewToken,WordKind);		//���﷨�����ı���




#endif