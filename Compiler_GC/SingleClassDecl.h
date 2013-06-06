#ifndef __SINGLECLASSDECL_H__
#define __SINGLECLASSDECL_H__
#include <vector>
#include "VarDecl.h"
#include "VarDecls.h"
#include "MethodDecl.h"
#include "MethodDecls.h"
#include "Id.h"
#include "ClassDecl.h"
#include "ClassNameDecl.h"
using namespace std;
class SingleClassDecl : public ClassDecl
{
public:
	SingleClassDecl(ClassNameDecl *cnd,VarDecls *vds,MethodDecls *mds):
	  ClassDecl(cnd,vds,mds),m_cnd(cnd),m_vds(vds),m_mds(mds){}
	 
	string GenCode();
private:
	ClassNameDecl *m_cnd;
	VarDecls *m_vds;
	MethodDecls *m_mds;
};

#endif