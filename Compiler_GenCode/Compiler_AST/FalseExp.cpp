#include "FalseExp.h"

string FalseExp::GenCode()
{
	return (this->m_expp == NULL ? "false" : this->m_expp->GenCode("false"));
}