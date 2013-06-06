#ifndef _NUMEXP_H_
#define _NUMEXP_H_
#pragma once
#include "exp.h"
class NumExp :
	public Exp
{
public:
	NumExp(int n):m_iNum(n){}
	~NumExp(void);
	int Compute();
private:
	int m_iNum;
};

#endif