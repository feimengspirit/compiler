#include "Program.h"

string Program::GenCode()
{
	string mdcode;
	ClassDecls *cls = this->m_clsdcls;
	while(cls)
	{
		ClassDecl *cd = cls->m_clsdcl;
		MethodDecls *mds = cd->m_mds;
		while(mds)						//先将所有类中的成员方法提取出去加在开始处
		{
			mdcode += mds->GenCode(cd);
			mds = mds->m_mds;	
		}
		cls = cls->m_clsdcls;
	}
	string mclscode = this->m_mainClass->GenCode();	//生成类（结构体）声明
	string clsdeclcode = this->m_clsdcls->GenCode();//生成主函数声明
	return (mdcode + "\n" + clsdeclcode + mclscode );
}