#ifndef __CLASSNAMEDECL_H__
#define __CLASSNAMEDECL_H__
#include "Id.h"
#include <string>
using namespace std;

class ClassNameDecl
{
public:
	ClassNameDecl(Id *id):m_id(id){}
	~ClassNameDecl(){}
	string GenCode();

	Id *m_id;
};

#endif