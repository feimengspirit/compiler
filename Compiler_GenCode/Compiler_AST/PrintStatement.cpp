#include "PrintStatement.h"

string PrintStatement::GenCode()
{
	return "printf(\"%d\"," + this->m_exp->GenCode() + ")\n";
}