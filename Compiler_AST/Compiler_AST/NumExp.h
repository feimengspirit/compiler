#ifndef __NUMEXP_H__
#define __NUMEXP_H__
#include "Exp.h"
#include "Expp.h"

class NumExp : public Exp
{
public:
	NumExp(Expp *expp):m_expp(expp){}
	~NumExp(){}
private:
	Expp *m_expp;
};

#endif