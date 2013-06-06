#include "PrintStatement.h"

string PrintStatement::GenCode()
{
	return "printf(" + this->m_exp->GenCode() + ")\n";
}