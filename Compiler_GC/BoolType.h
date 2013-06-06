#ifndef __BOOLTYPE_H__
#define __BOOLTYPE_H_
#include "Type.h"
#include <string>

class BoolType : public Type
{
public:
	BoolType(){}
	~BoolType(){}
	string GenCode();
};
#endif