#include "NumExp.h"

string NumExp::GenCode()
{
	return (this->m_expp == NULL ? this->m_num.s : this->m_expp->GenCode(this->m_num.s));
}