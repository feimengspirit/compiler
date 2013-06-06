#ifndef __OP_H__
#define __OP_H__
#include<string>
#include "Lexer.h"
#include <string>
using namespace std;

class Op
{
public:
	Op(NewToken op):m_op(op){}
	~Op(){}
	inline string GenCode()
	{
		return m_op.s;
	}

private:
	NewToken m_op;
};

#endif