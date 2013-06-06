#include "OpExpp.h"

string OpExpp::GenCode(string s)
{
	string v = s + this->m_op->GenCode() + this->m_exp->GenCode();
	return  v +(this->m_expp == NULL? NULL : this->m_expp->GenCode(v));
}