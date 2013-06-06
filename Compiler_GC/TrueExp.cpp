#include "TrueExp.h"

string TrueExp::GenCode()
{
	return this->m_expp->GenCode("true");
}