#include "SingleClassDecl.h"

string SingleClassDecl::GenCode()
{
	return m_cnd->GenCode() + "{\n" + m_vds->GenCode() + "};\n";
						//递归调用类名生成器和成员代码生成器
}