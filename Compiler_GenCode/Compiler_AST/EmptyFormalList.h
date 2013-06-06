#ifndef __EMPTYFORMALLIST_H__
#define __EMPTYFORMALLIST_H__
#include "FormalList.h"
#include <string>
using namespace std;

class EmptyFormalList : public FormalList
{
public:
	EmptyFormalList(){}
	~EmptyFormalList(){}
	string GenCode();
private:
};

#endif