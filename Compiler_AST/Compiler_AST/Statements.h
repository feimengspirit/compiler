#ifndef __STATEMENTS_H__
#define __STATEMENTS_H__
#include "Statement.h"

class Statements
{
public:
	Statements(Statement *s,Statements *ss):m_s(s),m_ss(ss){}
	~Statements(){}
private:
	Statement *m_s;
	Statements *m_ss;
};

#endif