#ifndef __ARRAYASSIGNSTM_H__
#define __ARRAYASSIGNSTM_H__
#include "Statement.h"
#include "Exp.h"
#include "Id.h"
#include <string>
using namespace std;
class ArrayAssignStm : public Statement
{
public:
	ArrayAssignStm(Id *id,Exp *index,Exp *exp):m_id(id),m_index(index),m_exp(exp){}
	~ArrayAssignStm(){}
	string GenCode();
private:
	Id *m_id;
	Exp *m_index;
	Exp *m_exp;
};
#endif