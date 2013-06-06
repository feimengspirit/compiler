#ifndef __EXPRESTS_H__
#define __EXPRESTS_H__
#include "ExpRest.h"
#include <string>
using namespace std;

class ExpRests 
{
public:
	ExpRests(ExpRest *er,ExpRests *ers):m_er(er),m_ers(ers){}
	~ExpRests(){}
	string GenCode();
private:
	ExpRest *m_er;
	ExpRests *m_ers;
};


#endif