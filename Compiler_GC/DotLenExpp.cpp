#include "DotLenExpp.h"

string DotLenExpp::GenCode(string s)
{
	string v = "sizeof(" + s + ")";
	return v + (m_expp == NULL? NULL : m_expp->GenCode(v));
}