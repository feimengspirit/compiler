#include "CompoundStm.h"
int CompoundStm::GetPrintMaxargs()
{
	int l = stm1->GetPrintMaxargs();
	int r = stm2->GetPrintMaxargs();
	return l > r? l : r;
}
void CompoundStm::Execute()
{
	stm1->Execute();
	stm2->Execute();
}