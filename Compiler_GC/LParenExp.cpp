#include "LParenExp.h"

string LParenExp::GenCode()
{
	return	(this->m_expp == NULL? NULL : 
				this->m_expp->GenCode("(" + this->m_exp->GenCode() + ")"));
}