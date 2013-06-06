#include "ExpRest.h"

string ExpRest::GenCode()
{
	return "," + m_exp->GenCode();
}