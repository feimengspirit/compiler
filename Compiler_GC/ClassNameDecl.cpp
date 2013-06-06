#include "ClassNameDecl.h"

string ClassNameDecl::GenCode()
{
	return "struct" + m_id->GenCode();
}