#ifndef _COMPOUNDSTM_H_
#define _COMPOUNDSTM_H_

#include "Stm.h"

class CompoundStm : public Stm
{
public:
	CompoundStm(Stm *s1,Stm *s2):stm1(s1),stm2(s2){}
	virtual ~CompoundStm()
	{
		delete stm1;
		delete stm2;
	}
	int GetPrintMaxargs();
	void Execute();
private:
	Stm *stm1;
	Stm *stm2;
};

#endif