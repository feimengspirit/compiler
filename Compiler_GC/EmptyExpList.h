#ifndef __EMPTYEXPLIST_H__
#define __EMPTYEXPLIST_H__

#include "ExpList.h"
#include <string>
using namespace std;

class EmptyExpList : public ExpList
{
public:
	EmptyExpList(){}
	~EmptyExpList(){}
	string GenCode();

};

#endif