#include "LBrackExpp.h"

string LBrackExpp::GenCode(string s)
{
	string v = s + "[" + m_exp->GenCode() + "]";
	return v + (m_expp == NULL? "" : m_expp->GenCode(v));
}