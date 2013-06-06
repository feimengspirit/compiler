#ifndef __NUMEXP_H__
#define __NUMEXP_H__
#include "Exp.h"
#include "Expp.h"
#include "Lexer.h"
#include <string>
using namespace std;

class NumExp : public Exp
{
public:
	NumExp(NewToken num,Expp *expp):m_num(num),m_expp(expp){}
	~NumExp(){}
	string GenCode();

private:
	NewToken m_num;
	Expp *m_expp;
};

#endif