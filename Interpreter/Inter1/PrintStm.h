#ifndef _PRINTSTM_H_
#define _PRINTSTM_H_
#include "Stm.h"
#include "ExpList.h"
class PrintStm : public Stm
{
public:
	PrintStm(ExpList *e):m_exps(e){}
	virtual ~PrintStm()
	{
		delete m_exps;
	}
	int GetPrintMaxargs();
	void Execute();
private:
	ExpList *m_exps;

};
#endif