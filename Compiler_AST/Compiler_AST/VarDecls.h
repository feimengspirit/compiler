#ifndef __VARDECLS_H__
#define __VARDECLS_H__
#include "VarDecl.h"
#include "Analyse.h"
#include "Program.h"

class VarDecls
{
public:
	VarDecls(VarDecl *vd,VarDecls *vds):m_vd(vd),m_vds(vds){}
	~VarDecls(){}
	friend int sort_id(Program*,int (*)(const string&,const string&));
private:
	VarDecl *m_vd;
	VarDecls *m_vds;
};

#endif