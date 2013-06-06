#ifndef __EXPREST_H__
#define __EXPREST_H__
#include "Exp.h"
#include <string>
using namespace std;

class ExpRest
{
public:
	ExpRest(Exp *exp):m_exp(exp){}
	~ExpRest(){}
	string GenCode();
private:
	Exp *m_exp;
};


#endif