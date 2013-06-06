#include "Program.h"

string Program::GenCode()
{
	string mdcode;
	ClassDecls *cls = this->m_clsdcls;
	while(cls)
	{
		ClassDecl *cd = cls->m_clsdcl;
		MethodDecls *mds = cd->m_mds;
		while(mds)						//�Ƚ��������еĳ�Ա������ȡ��ȥ���ڿ�ʼ��
		{
			mdcode += mds->GenCode(cd);
			mds = mds->m_mds;	
		}
		cls = cls->m_clsdcls;
	}
	string mclscode = this->m_mainClass->GenCode();	//�����ࣨ�ṹ�壩����
	string clsdeclcode = this->m_clsdcls->GenCode();//��������������
	return (mdcode + "\n" + clsdeclcode + mclscode );
}