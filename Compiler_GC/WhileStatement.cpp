#include "WhileStatement.h"

string WhileStatement::GenCode()
{
	return "while(" + this->m_exp->GenCode() + "(\n{"
			+ this->m_statement->GenCode() + "\n}\n";
}