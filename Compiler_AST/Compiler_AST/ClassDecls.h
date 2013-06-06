#ifndef __CLASSDECLS_H__
#define __CLASSDECLS_H__
#include "ClassDecl.h"
#include "Analyse.h"


class ClassDecls
{
public:
	ClassDecls(ClassDecl *c,ClassDecls *cs):m_clsdcl(c),
			m_clsdcls(cs){}
	~ClassDecls(){}
	friend int sort_id(Program*,int (*)(const string&,const string&));

private:
	ClassDecl *m_clsdcl;
	ClassDecls *m_clsdcls;
};

#endif