#ifndef __NEEXPLIST_H__
#define __NEEXPLIST_H__
#include "ExpList.h"
#include "Exp.h"
#include "ExpRests.h"

class NeExpList : public ExpList
{
public:
	NeExpList(Exp *exp,ExpRests *eps):m_exp(exp),m_eps(eps){}
	~NeExpList(){}
	string GenCode();
private:
	Exp *m_exp;
	ExpRests *m_eps;
};


#endif