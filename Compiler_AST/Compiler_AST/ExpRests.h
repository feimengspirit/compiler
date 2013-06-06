#ifndef __EXPRESTS_H__
#define __EXPRESTS_H__
#include "ExpRest.h"

class ExpRests 
{
public:
	ExpRests(ExpRest *er,ExpRests *ers):m_er(er),m_ers(ers){}
	~ExpRests(){}
private:
	ExpRest *m_er;
	ExpRests *m_ers;
};


#endif