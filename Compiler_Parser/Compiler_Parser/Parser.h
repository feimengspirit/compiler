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
		Lexer(filename);			//���ôʷ�������	
		Move();						//�ƽ�һ������
	}
	~Parser(){}
	void Match(WordKind);			//ƥ��һ������
	void Parse();
	void Move()						//�ƽ�����
	{
		look = scan();				
	}
	
private:
	NewToken look;					//��һ���������ĵ���
	void Program();					//���������﷨
	void MainClass();				//���������﷨
	void ClassDecls();				//�����������﷨��������
	void Id();						//������ʶ���﷨
	void Statements();				//������������﷨
	void Statement();				//������������﷨ 
	void ClassDecl();				//�����������﷨
	void ClassNameDecl();			//���������﷨
	void VarDecls();				//����������������﷨
	void VarDecl();					//�����������������﷨
	void MethodDecls();				//����������������﷨
	void MethodDecl();				//������緽�������﷨
	void Type();					//���������﷨
	void FormalList();				//������ʽ�б��﷨
	void FormalRests();				//������ʽ�б�β���﷨��������Ŀ��
	void FormalRest();				//������ʽ�б�β���﷨
	void Exp();						//�������ʽ�﷨
	void Expp();					//������ݹ������ķ��ս��
	void ExpList();					//�������ʽ�б��﷨
	void ExpRests();				//�������ʽ�б�β���﷨��������Ŀ��
	void ExpRest();					//�������ʽ�б�β���﷨
	void Op();						//������

};
void syntax_error(NewToken,WordKind);	//���﷨�����ı���

#endif