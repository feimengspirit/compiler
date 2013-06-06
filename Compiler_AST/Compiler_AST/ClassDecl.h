#ifndef __CLASSDECL_H__
#define __CLASSDECL_H__
#include "ClassNameDecl.h"
#include "VarDecls.h"
#include "MethodDecls.h"
#include "Analyse.h"
#include "Program.h"

class ClassDecl
{
public:
	ClassDecl(ClassNameDecl *cnd,VarDecls *vds,MethodDecls *mds):
					m_cnd(cnd),m_vds(vds),m_mds(mds){}
	~ClassDecl(){}
	friend int sort_id(Program*,int (*)(const string&,const string&));

private:
	ClassNameDecl *m_cnd;
	VarDecls *m_vds;
	MethodDecls *m_mds;
};

#endif