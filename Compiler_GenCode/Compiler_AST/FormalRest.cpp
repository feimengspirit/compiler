#include "FormalRest.h"

string FormalRest::GenCode()
{
	return "," + m_type->GenCode() + m_id->GenCode();
} 