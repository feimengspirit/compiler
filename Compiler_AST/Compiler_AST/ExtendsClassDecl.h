#ifndef __EXTENDSCLASSDECL_H__
#define __EXTENDSCLASSDECL_H__
#include <vector>
#include "VarDecl.h"
#include "VarDecls.h"
#include "MethodDecl.h"
#include "MethodDecls.h"
#include "Id.h"
#include "ClassDecl.h"
#include "ClassNameDecl.h"
using namespace std;

class ExtendsClassDecl : public ClassDecl
{
public:
	ExtendsClassDecl(ClassNameDecl *cnd,Id *pId,VarDecls *vds,
					 MethodDecls *mds):ClassDecl(cnd,vds,mds),m_cnd(cnd),
					 m_pId(pId),m_vds(vds), m_mds(mds){}
	~ExtendsClassDecl(){}

private:
	ClassNameDecl *m_cnd;
	Id *m_pId;
	VarDecls *m_vds;
	MethodDecls *m_mds;
};

#endif