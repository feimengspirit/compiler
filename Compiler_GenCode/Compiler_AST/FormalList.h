#ifndef __FORMALLIST_H__
#define __FORMALLIST_H__
#include <string>
using namespace std;
class FormalList
{
public:
	FormalList(){}
	~FormalList(){}
	virtual string GenCode() = 0;
private:

};
#endif