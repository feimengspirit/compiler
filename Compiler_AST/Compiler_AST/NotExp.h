#ifndef __NOTEXP_H__
#define __NOTEXP_H__
#include "Exp.h"
#include "Expp.h"

class NotExp : public Exp
{
public:
	NotExp(Exp *exp,Expp *expp):m_exp(exp),m_expp(expp){}
	~NotExp(){}
private:
	Exp *m_exp;
	Expp *m_expp;
};

#endif