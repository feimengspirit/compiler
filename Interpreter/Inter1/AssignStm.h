#ifndef _ASSIGNSTM_H_
#define _ASSIGNSTM_H_

#include "Stm.h"
#include "Exp.h"
#include <iostream>
class AssignStm : public Stm
{
public:
	AssignStm(std::string id,Exp *e):m_strId(id),m_exp(e){}
	virtual ~AssignStm()
	{
		delete m_exp;
	}
	int GetPrintMaxargs();
	void Execute();
private:
	std::string m_strId;
	Exp *m_exp;
};
#endif