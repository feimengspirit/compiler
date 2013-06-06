#ifndef __NEWINTEXP_H__
#define __NEWINTEXP_H__
#include "Exp.h"
#include "Expp.h"

class NewIntExp : public Exp
{
public:
	NewIntExp(Exp *exp,Expp *expp):m_exp(exp),m_expp(expp){}
	~NewIntExp(){}
private:
	Exp *m_exp;
	Expp *m_expp;
};


#endif