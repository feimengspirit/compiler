#ifndef __ASSIGNSTM_H__
#define __ASSIGNSTM_H__
#include "Statement.h"
#include "Exp.h"
#include "Id.h"
#include <string>
using namespace std;

class AssignStm : public Statement
{
public:
	AssignStm(Id *id,Exp *exp):m_id(id),m_exp(exp){}
	~AssignStm(){}
	string GenCode();
private:
	Id *m_id;
	Exp *m_exp;
};

#endif