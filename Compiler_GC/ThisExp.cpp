#include "ThisExp.h"

string ThisExp::GenCode()
{
	return this->m_expp->GenCode("this");
}