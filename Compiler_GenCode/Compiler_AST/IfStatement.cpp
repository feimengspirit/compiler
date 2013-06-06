#include "IfStatement.h"

string IfStatement::GenCode()
{
	return "if(" + m_exp->GenCode() + ")\n{\n" + m_iStatement->GenCode()
		+ "}\nelse\n{\n" + m_eStatement->GenCode() +"}\n" ;
}