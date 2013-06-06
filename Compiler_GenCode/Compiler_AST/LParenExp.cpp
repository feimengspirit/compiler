#include "LParenExp.h"

string LParenExp::GenCode()
{
	return	(this->m_expp == NULL? "(" + this->m_exp->GenCode() + ")" : 
				this->m_expp->GenCode("(" + this->m_exp->GenCode() + ")"));
}