#include "ArrayAssignStm.h"

string ArrayAssignStm::GenCode()
{
	return this->m_id->GenCode() +"[" + this->m_index->GenCode() + "] = " 
			+ this->m_exp->GenCode();	
}