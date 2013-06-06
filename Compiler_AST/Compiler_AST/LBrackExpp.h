#ifndef __LBRACKEXPP_H__
#define __LBRACKEXPP_H__
#include "Exp.h"
#include "Expp.h"
class LBrackExpp : public Expp
{
public:
	LBrackExpp(Exp *exp,Expp *expp):m_exp(exp),m_expp(expp){}
	~LBrackExpp(){}
private:
	Exp *m_exp;
	Expp *m_expp;
};


#endif