#ifndef __STATEMENT_H__
#define __STATEMENT_H__
#include <string>
using namespace std;

class Statement
{
public:
	Statement(){}
	~Statement(){}
	virtual string GenCode() = 0;
};
#endif