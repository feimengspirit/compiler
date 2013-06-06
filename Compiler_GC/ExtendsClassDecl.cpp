#include "ExtendsClassDecl.h"

string ExtendsClassDecl::GenCode()
{
	return m_cnd->GenCode() + "{\n" + m_vds->GenCode() + "\n}";
}