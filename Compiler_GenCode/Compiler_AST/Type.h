#ifndef __TYPE_H__
#define __TYPE_H__
#include <string>
using namespace std;
class Type
{
public:
	Type(){}
	~Type(){}
	virtual string GenCode();
};
#endif