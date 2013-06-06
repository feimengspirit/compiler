#ifndef __FALSEEXP_H__
#define __FALSEEXP_H__
#include "Exp.h"
#include "Expp.h"
#include <iostream>
#include <string>
using namespace std;

class FalseExp : public Exp
{
public:
	FalseExp(Expp *expp):m_expp(expp){}
	~FalseExp(){}
	string GenCode();
private:
	Expp *m_expp;
};

#endif