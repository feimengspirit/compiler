#include "IfStatement.h"

string IfStatement::GenCode()
{
	return "if(" + m_exp->GenCode() + ")\n{" + m_iStatement->GenCode()
		+ "}\n else {" + m_eStatement->GenCode() +"}\n" ;
}