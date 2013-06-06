#ifndef __IARRAYTYPE_H__
#define __IARRAYTYPE_H__
#include "Type.h"
#include <string>

class IArrayType : public Type
{
public:
	IArrayType(){}
	~IArrayType(){}
	string GenCode();
};

#endif