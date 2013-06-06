#ifndef __STATEMENTS_H__
#define __STATEMENTS_H__
#include "Statement.h"
#include <string>
using namespace std;

class Statements
{
public:
	Statements(Statement *s,Statements *ss):m_s(s),m_ss(ss){}
	~Statements(){}
	string GenCode()
	{
		return m_s->GenCode() + (m_ss == NULL? NULL : m_ss->GenCode());
	}
private:
	Statement *m_s;
	Statements *m_ss;
};

#endif