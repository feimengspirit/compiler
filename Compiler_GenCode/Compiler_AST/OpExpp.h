#ifndef __OPEXPP_H__
#define __OPEXPP_H__
#include "Expp.h"
#include "Exp.h"
#include "Op.h"
#include <string>
using namespace std;
class OpExpp : public Expp
{
public:
	OpExpp(Op *op,Exp *exp,Expp *expp):
			m_op(op),m_exp(exp),m_expp(expp){}
	~OpExpp(){}
	string GenCode(string);
private:
	Op *m_op;
	Exp *m_exp;
	Expp *m_expp;
};

#endif