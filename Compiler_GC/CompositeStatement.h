#ifndef __COMPOSITESTATEMENT_H__
#define __COMPOSITESTATEMENT_H__
#include <string>
#include "Statement.h"
#include "Statements.h"
using namespace std;

class CompositeStatement : public Statement
{
public:
	CompositeStatement(Statements *ss):m_ss(ss){}
	~CompositeStatement(){}
	string GenCode();

private:
	Statements *m_ss;

};
#endif