#include "NumExp.h"

string NumExp::GenCode()
{
	return this->m_expp->GenCode(this->m_num.s);
}