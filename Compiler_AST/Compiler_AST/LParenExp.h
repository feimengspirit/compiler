#ifndef __LPARENEXP_H__
#define __LPARENEXP_H__
#include "Exp.h"
#include "Expp.h"

class LParenExp : public Exp
{
public:
	LParenExp(Exp *exp,Expp *expp):m_exp(exp),m_expp(expp){}
	~LParenExp(){}
private:
	Exp *m_exp;
	Expp *m_expp;
};

#endif