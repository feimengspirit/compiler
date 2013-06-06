#ifndef _IDEXP_H_
#define _IDEXP_H_
#pragma once
#include "exp.h"
#include <iostream>

class IdExp :
	public Exp
{
public:
	IdExp(std::string i):m_strId(i){}
	~IdExp(void);
	int Compute();
private:
	std::string m_strId;
};

#endif