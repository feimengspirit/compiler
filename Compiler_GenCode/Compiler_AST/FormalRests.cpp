#include "FormalRests.h"

string FormalRests::GenCode()
{
	return m_fr->GenCode() + 
		(m_frs == NULL ? "" : m_frs->GenCode());
}