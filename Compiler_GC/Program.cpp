#include "Program.h"

string Program::GenCode()
{
	string mclscode = this->m_mainClass->GenCode();
	string clsdeclcode = this->m_clsdcls->GenCode();
	return (mclscode + "\n" + clsdeclcode);
}