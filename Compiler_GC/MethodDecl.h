#ifndef __METHODDECL_H__
#define __METHODDECL_H__
#include <vector>
#include "Type.h"
#include "Id.h"
#include "FormalList.h"
#include "VarDecl.h"
#include "VarDecls.h"
#include "Statement.h"
#include "Statements.h"
#include "Exp.h"


using namespace std;
class MethodDecl
{
public:
	MethodDecl(Type *type,Id *id,FormalList *fl,VarDecls *vds,
			   Statements *ss,Exp *exp):m_type(type),m_id(id),
										m_fl(fl),m_vds(vds),
										m_ss(ss),m_exp(exp){}

	~MethodDecl(){}

	Type *m_type;
	Id *m_id;
	FormalList *m_fl;
	VarDecls *m_vds;
	Statements *m_ss;
	Exp *m_exp;
};

#endif