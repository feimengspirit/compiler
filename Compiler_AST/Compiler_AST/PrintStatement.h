#ifndef __PRINTSTATEMENT_H__
#define __PRINTSTATEMENT_H__
#include "Statement.h"
#include "Exp.h"

class PrintStatement : public Statement
{
public:
	PrintStatement(Exp *exp):m_exp(exp){}
	~PrintStatement(){}
private:
	Exp *m_exp;
};


#endif