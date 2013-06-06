#include "MainClass.h"

string MainClass::GenCode()
{
	string stmcode = this->m_statement->GenCode();
	return "int main(char *argv,int argc)\n{" + stmcode + "return 0;\n}";
}