#include "NewIdExp.h"

string NewIdExp::GenCode()
{
	return (this->m_expp == NULL? NULL : 
		this->m_expp->GenCode("(" + this->m_id->m_id.s + "*)malloc(sizeof(" + this->m_id->GenCode() + "))") );
}
	