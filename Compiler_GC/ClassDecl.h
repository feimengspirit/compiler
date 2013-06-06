#ifndef __CLASSDECL_H__
#define __CLASSDECL_H__
#include "ClassNameDecl.h"
#include "VarDecls.h"
#include "MethodDecls.h"


class ClassDecl
{
public:
	ClassDecl(ClassNameDecl *cnd,VarDecls *vds,MethodDecls *mds):
					m_cnd(cnd),m_vds(vds),m_mds(mds){}
	~ClassDecl(){}
	virtual string GenCode() = 0;

	ClassNameDecl *m_cnd;
	VarDecls *m_vds;
	MethodDecls *m_mds;
};

#endif