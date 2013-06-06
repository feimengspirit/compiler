#ifndef __THISEXP_H__
#define __THISEXP_H__

#include <iostream>
#include "Exp.h"
#include "Expp.h"
#include <string>
using namespace std;

class ThisExp : public Exp
{
public:
	ThisExp(Expp *expp):m_expp(expp){}
	~ThisExp(){}
	string GenCode();
private:
	Expp *m_expp;
};


#endif