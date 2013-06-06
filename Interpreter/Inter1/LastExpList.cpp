#include "LastExpList.h"
#include <iostream>

int LastExpList::GetExpCount()
{
	return 1;
}
void LastExpList::Print()
{
	std::cout<<m_head->Compute()<<" ";
}