#include "PairExpList.h"
#include <iostream>

int PairExpList::GetExpCount()
{
	return 1 + (m_tail == NULL? 0 : m_tail->GetExpCount());
}
void PairExpList::Print()
{
	std::cout<<m_head->Compute()<<" ";
	m_tail->Print();
}
