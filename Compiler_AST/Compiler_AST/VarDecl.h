#ifndef __VARDECL_H__
#define __VARDECL_H__
#include "Type.h"
#include "Id.h"

#include "Analyse.h"

class VarDecl
{
public:
	VarDecl(Type *type,Id *id):m_type(type),m_id(id){}
	~VarDecl(){}
	friend int sort_id(Program*,int (*)(const string&,const string&));
private:
	Type *m_type;
	Id *m_id;
};

#endif