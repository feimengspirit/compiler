#ifndef __METHODDECLS_H__
#define __METHODDECLS_H__
#include "MethodDecl.h"
#include "Analyse.h"
#include "Program.h"

class MethodDecls
{
public:
	MethodDecls(MethodDecl *md,MethodDecls *mds):m_md(md),m_mds(mds){}
	~MethodDecls(){}
	friend int sort_id(Program*,int (*)(const string&,const string&));
private:
	MethodDecl *m_md;
	MethodDecls *m_mds;
};
#endif