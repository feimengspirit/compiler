#include "SingleClassDecl.h"

string SingleClassDecl::GenCode()
{
	return m_cnd->GenCode() + "{\n" + m_vds->GenCode() + "\n}";
}