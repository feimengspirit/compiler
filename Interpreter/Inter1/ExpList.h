#ifndef _EXPLIST_H_
#define _EXPLIST_H_
#pragma once
class ExpList
{
public:
	ExpList(void){}
	virtual ~ExpList(void){}
	virtual int GetExpCount()=0;
	virtual void Print()=0;
};

#endif