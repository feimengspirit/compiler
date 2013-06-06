#ifndef __CLASSNAMEDECL_H__
#define __CLASSNAMEDECL_H__
#include "Id.h"
class ClassNameDecl
{
public:
	ClassNameDecl(Id *id):m_id(id){}
	~ClassNameDecl(){}
private:
	Id *m_id;
};

#endif