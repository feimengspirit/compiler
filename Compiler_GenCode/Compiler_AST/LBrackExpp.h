#ifndef __LBRACKEXPP_H__
#define __LBRACKEXPP_H__
#include "Exp.h"
#include "Expp.h"
#include <string>
using namespace std;
class LBrackExpp : public Expp
{
public:
	LBrackExpp(Exp *exp,Expp *expp):m_exp(exp),m_expp(expp){}
	~LBrackExpp(){}
	string GenCode(string);
private:
	Exp *m_exp;
	Expp *m_expp;
};


#endif