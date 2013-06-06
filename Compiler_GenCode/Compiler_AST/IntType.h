#ifndef __INTTYPE_H__
#define __INTTYPE_H__
#include "Type.h"
#include <string>

class IntType : public Type
{
public:
	IntType(){}
	~IntType(){}

	string GenCode();
};


#endif