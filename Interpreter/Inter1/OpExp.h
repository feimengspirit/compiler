#ifndef _OPEXP_H_
#define _OPEXP_H_
#pragma once
#include "exp.h"
class OpExp :
	public Exp
{
public:
	OpExp(Exp *l,int o,Exp *r):m_left(l),m_iOper(o),m_right(r){}
	virtual ~OpExp(void)
	{
		delete m_left;
		delete m_right;
	}
	int Compute();
	const static int Plus,Minus,Times,Div;
private:
	Exp *m_left;
	Exp *m_right;
	int m_iOper;
	
};


#endif