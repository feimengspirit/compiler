#include "MethodDecl.h"
#include "ClassDecl.h"

string MethodDecl::GenCode(ClassDecl *cd)
{
	string pointer = "struct " + cd->m_cnd->m_id->m_id.s;	//���������Ĵ���������Ҫ�ݹ�����ӳ�Ա
	return m_type->GenCode() + " " + m_id->GenCode() + "(" + pointer +" *this," + m_fl->GenCode() +
		")\n{" + m_vds->GenCode() + m_ss->GenCode() + "return " + m_exp->GenCode() +";\n}\n";
												//ע��������������һ��thisָ��ʵ�ֶ�̬
}