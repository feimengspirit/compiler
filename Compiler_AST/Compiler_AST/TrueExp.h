#ifndef __TRUEEXP_H__
#define __TRUEEXP_H__
#include "Exp.h"
#include "Expp.h"
class TrueExp : public Exp
{
public:
	TrueExp(Expp *expp):m_expp(expp){}
	~TrueExp(){}
private:
	Expp *m_expp;
};

#endif