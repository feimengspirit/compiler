#ifndef __CLASSDECLS_H__
#define __CLASSDECLS_H__
#include "ClassDecl.h"
#include <string>
using namespace std;



class ClassDecls
{
public:
	ClassDecls(ClassDecl *c,ClassDecls *cs):m_clsdcl(c),
			m_clsdcls(cs){}
	~ClassDecls(){}
	string GenCode();

	ClassDecl *m_clsdcl;
	ClassDecls *m_clsdcls;
};

#endif