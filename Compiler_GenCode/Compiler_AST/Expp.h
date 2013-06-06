#ifndef __EXPP_H__
#define __EXPP_H__
#include <string>

using namespace std;

class Expp
{
public:
	Expp(){}
	~Expp(){}
	virtual string GenCode(string) = 0;
private:
};
#endif