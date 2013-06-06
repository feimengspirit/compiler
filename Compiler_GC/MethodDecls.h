#ifndef __METHODDECLS_H__
#define __METHODDECLS_H__
#include "MethodDecl.h"


class MethodDecls
{
public:
	MethodDecls(MethodDecl *md,MethodDecls *mds):m_md(md),m_mds(mds){}
	MethodDecls(){}
	~MethodDecls(){}

	MethodDecl *m_md;
	MethodDecls *m_mds;
};
#endif