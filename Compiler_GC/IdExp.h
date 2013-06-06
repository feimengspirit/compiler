#ifndef __IDEXP_H__
#define __IDEXP_H__
#include "Exp.h"
#include "Expp.h"
#include "Id.h"
#include <iostream>
using namespace std;

class IdExp : public Exp
{
public:
	IdExp(Id *id,Expp *expp):m_id(id),m_expp(expp){}
	~IdExp(){}
	string GenCode();
	
private:
	Id *m_id;
	Expp *m_expp;
};

#endif