#ifndef __TRUEEXP_H__
#define __TRUEEXP_H__
#include "Exp.h"
#include "Expp.h"
#include <iostream>
#include <string>
using namespace std;

class TrueExp : public Exp
{
public:
	TrueExp(Expp *expp):m_expp(expp){}
	~TrueExp(){}
	string GenCode();
private:
	Expp *m_expp;
};

#endif