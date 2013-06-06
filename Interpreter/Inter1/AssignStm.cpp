#include "AssignStm.h"
#include <iostream>
#include "EseqExp.h"
#include "Inter.h"

int AssignStm::GetPrintMaxargs()
{
	if (typeid(*m_exp).name()== typeid(EseqExp).name())
		return ((EseqExp*)m_exp)->GetPrintMaxargs();
	return 0;
}
void AssignStm::Execute()
{
	if (typeid(*m_exp).name()== typeid(EseqExp).name())
		((EseqExp*)m_exp)->Execute();
	Inter::Update(m_exp->Compute(),m_strId);
}