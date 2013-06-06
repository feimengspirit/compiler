#include "IdExp.h"

string IdExp::GenCode()
{
	return  (this->m_expp == NULL? NULL : 
				this->m_expp->GenCode(this->m_id->GenCode()));
}