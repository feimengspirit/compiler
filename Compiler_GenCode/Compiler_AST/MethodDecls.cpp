#include "MethodDecls.h"

string MethodDecls::GenCode(ClassDecl *cd)
{
	return m_md->GenCode(cd) + (m_mds ==NULL ? "" : m_mds->GenCode(cd));
}