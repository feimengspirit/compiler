#include "MethodDecl.h"
#include "ClassDecl.h"

string MethodDecl::GenCode(ClassDecl *cd)
{
	string pointer = "struct " + cd->m_cnd->m_id->m_id.s;	//方法声明的代码生成需要递归调用子成员
	return m_type->GenCode() + " " + m_id->GenCode() + "(" + pointer +" *this," + m_fl->GenCode() +
		")\n{" + m_vds->GenCode() + m_ss->GenCode() + "return " + m_exp->GenCode() +";\n}\n";
												//注意这里故意添加了一个this指针实现多态
}