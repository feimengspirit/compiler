#include "ThisExp.h"

string ThisExp::GenCode()
{
	return (this->m_expp == NULL ? "" : this->m_expp->GenCode("this"));
}