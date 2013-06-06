#ifndef __OP_H__
#define __OP_H__
#include<string>
#include "Lexer.h"
class Op
{
public:
	Op(NewToken op):m_op(op){}
	~Op(){}
private:
	NewToken m_op;
};

#endif