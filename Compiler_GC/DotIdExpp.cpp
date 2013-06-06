#include "DotIdExpp.h"

string DotIdExpp::GenCode(string s)
{
	string v = m_id->GenCode()+ "("  + s + "," + m_explist->GenCode() + ")";
	return v + (m_expp == NULL? NULL : m_expp->GenCode(v));
}