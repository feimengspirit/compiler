#ifndef __VARDECLS_H__
#define __VARDECLS_H__
#include "VarDecl.h"
#include <string>

class VarDecls
{
public:
	VarDecls(VarDecl *vd,VarDecls *vds):m_vd(vd),m_vds(vds){}
	VarDecls(){}
	~VarDecls(){}
	string GenCode();

	VarDecl *m_vd;
	VarDecls *m_vds;
};

#endif