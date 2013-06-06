#include "CompositeStatement.h"

string CompositeStatement::GenCode()
{
	if(!(this->m_ss))
		return this->m_ss->GenCode();
	return NULL;
}