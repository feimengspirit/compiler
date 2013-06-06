#include "AssignStm.h"

string AssignStm::GenCode()
{
	return (this->m_id->GenCode() + "=" + this->m_exp->GenCode()+";\n");
}