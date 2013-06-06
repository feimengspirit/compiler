#ifndef __WHILESTATEMENT_H__
#define __WHILESTATEMENT_H__
#include "Statement.h"
#include "Exp.h"
#include <string>
using namespace std;

class WhileStatement : public Statement
{
public:
	WhileStatement(Exp *exp,Statement *statement):m_exp(exp),m_statement(statement){}
	~WhileStatement(){}
	string GenCode();

private:
	Exp *m_exp;
	Statement *m_statement;
};

#endif