#ifndef __VARDECL_H__
#define __VARDECL_H__
#include "Type.h"
#include "Id.h"

#include "Analyse.h"
#include <string>

class VarDecl
{
public:
	VarDecl(Type *type,Id *id):m_type(type),m_id(id){}
	~VarDecl(){}
	string GenCode();

	Type *m_type;
	Id *m_id;
};

#endif