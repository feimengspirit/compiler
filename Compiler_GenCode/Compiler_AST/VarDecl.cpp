#include "VarDecl.h"

string VarDecl::GenCode()
{
	return m_type->GenCode() + " " + m_id->GenCode() + ";\n";
}