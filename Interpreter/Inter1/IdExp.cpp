#include "IdExp.h"
#include "Inter.h"

int IdExp::Compute()
{
	return Inter::Lookup(m_strId);
}