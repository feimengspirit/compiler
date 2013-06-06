#ifndef __FALSEEXP_H__
#define __FALSEEXP_H__
#include "Exp.h"
#include "Expp.h"

class FalseExp : public Exp
{
public:
	FalseExp(Expp *expp):m_expp(expp){}
	~FalseExp(){}
private:
	Expp *m_expp;
};

#endif