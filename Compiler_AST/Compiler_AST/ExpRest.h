#ifndef __EXPREST_H__
#define __EXPREST_H__
#include "Exp.h"

class ExpRest
{
public:
	ExpRest(Exp *exp):m_exp(exp){}
	~ExpRest(){}
private:
	Exp *m_exp;
};


#endif