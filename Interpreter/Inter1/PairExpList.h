#ifndef _PAIREXPLIST_H_
#define _PAIREXPLIST_H_

#pragma once
#include "explist.h"
#include "Exp.h"
class PairExpList :
	public ExpList
{
public:
	PairExpList(Exp *h,ExpList *t):m_head(h),m_tail(t){}
	virtual ~PairExpList(void)
	{
		delete m_head;
		delete m_tail;
	}
	virtual int GetExpCount();
	void Execute();
	void Print();
private:
	Exp *m_head;
	ExpList *m_tail;
};

#endif