#include "EseqExp.h"


int EseqExp::Compute()
{
	return m_exp->Compute();
}
void EseqExp::Execute()
{
	m_stm->Execute();
}
int EseqExp::GetPrintMaxargs()
{
	return m_stm->GetPrintMaxargs();
}
