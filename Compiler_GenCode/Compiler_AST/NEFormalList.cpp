#include "NEFormalList.h"

string NEFormalList::GenCode()
{
	return (m_type->GenCode() + " " + m_id->GenCode()) + 
			(m_frs == NULL ? "" : m_frs->GenCode());
}