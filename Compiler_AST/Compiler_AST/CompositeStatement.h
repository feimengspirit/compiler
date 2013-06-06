#ifndef __COMPOSITESTATEMENT_H__
#define __COMPOSITESTATEMENT_H__
#include <vector>
#include "Statement.h"
#include "Statements.h"
using namespace std;

class CompositeStatement : public Statement
{
public:
	CompositeStatement(Statements *ss):m_ss(ss){}
	~CompositeStatement(){}

private:
	Statements *m_ss;

};
#endif