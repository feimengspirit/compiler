#ifndef _LASTEXPLIST_H_
#define _LASTEXPLIST_H_
#pragma once
#include "explist.h"
#include "Exp.h"
class LastExpList :
	public ExpList
{
public:
	LastExpList(Exp *h):m_head(h){}
	virtual ~LastExpList()
	{
		delete m_head;
	}
	int GetExpCount();
	void Print();
private:
	Exp *m_head;
};

#endif