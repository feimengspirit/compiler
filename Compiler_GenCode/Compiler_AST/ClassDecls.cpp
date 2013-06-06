#include "ClassDecls.h"

string ClassDecls::GenCode()
{
	return m_clsdcl->GenCode() +
			(m_clsdcls == NULL? "" : m_clsdcls->GenCode());
}