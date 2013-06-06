#include "NotExp.h"

string NotExp::GenCode()
{
	return this->m_expp->GenCode("!" + this->m_exp->GenCode());
}