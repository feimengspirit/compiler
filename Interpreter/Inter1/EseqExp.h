#ifndef _ESEQEXP_H_
#define _ESEQEXP_H_

#include "exp.h"
#include "Stm.h"
class EseqExp : public Exp
{
public:
	EseqExp(Stm *s,Exp *e):m_stm(s),m_exp(e){}
	~EseqExp(void)
	{
		delete m_stm;
		delete m_exp;
	}
	int GetPrintMaxargs();
	int Compute();
	void Execute();
private:
	Stm *m_stm;
	Exp *m_exp;
};

#endif