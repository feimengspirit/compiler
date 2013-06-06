#include "ExpRests.h"

string ExpRests::GenCode()
{
	return m_er->GenCode() + 
			(m_ers == NULL? NULL : m_ers->GenCode());
}