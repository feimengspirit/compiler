#include "NewIntExp.h"

string NewIntExp::GenCode()
{
	return (this->m_expp == NULL? "" : 
			this->m_expp->GenCode("(int*)malloc( sizeof(int) * " + this->m_exp->GenCode() + ")"));
}