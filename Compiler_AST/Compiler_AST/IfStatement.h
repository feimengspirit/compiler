#ifndef __IFSTATEMENT_H__
#define __IFSTATEMENT_H__
#include "Exp.h"
#include "Statement.h"

class IfStatement : public Statement
{
public:
	IfStatement(Exp *exp,Statement *iStatement,Statement *eStatement):
				m_exp(exp),m_iStatement(iStatement),m_eStatement(eStatement){}

	~IfStatement(){}

private:
	Exp *m_exp;
	Statement *m_iStatement;
	Statement *m_eStatement;
};

#endif