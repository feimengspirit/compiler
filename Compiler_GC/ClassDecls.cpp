#include "ClassDecls.h"

string ClassDecls::GenCode()
{
	return m_clsdcl->GenCode() +
			(m_clsdcls == NULL? NULL : m_clsdcls->GenCode());
}