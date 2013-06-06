#ifndef __EXP_H__
#define __EXP_H__
#include <string>
using namespace std;
class Exp
{
public:
	Exp(){}
	~Exp(){}
	virtual string GenCode() = 0;
};

#endif