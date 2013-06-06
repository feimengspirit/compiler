#ifndef __EXPLIST_H__
#define __EXPLIST_H__
#include <string>
using namespace std;
class ExpList
{
public:
	ExpList(){}
	~ExpList(){}
	virtual string GenCode() = 0;
private:
};

#endif