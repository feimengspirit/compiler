#include "PrintStm.h"
#include <iostream>
int PrintStm::GetPrintMaxargs()
{
	return m_exps->GetExpCount();
}
void PrintStm::Execute()
{
	m_exps->Print();
	std::cout<<std::endl;
}