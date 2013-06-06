#include "NeExpList.h"

string NeExpList::GenCode()
{
	return m_exp->GenCode() + 
			(m_eps == NULL? NULL : m_eps->GenCode());
}