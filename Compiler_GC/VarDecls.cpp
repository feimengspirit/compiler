#include "VarDecls.h"

string VarDecls::GenCode()
{
	return m_vd->GenCode() + 
			(m_vds == NULL ? NULL : m_vds->GenCode());
}