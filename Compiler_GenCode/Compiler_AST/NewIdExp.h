#ifndef __NEWIDEXP_H__
#define __NEWIDEXP_H__
#include "Expp.h"
#include "Id.h"
#include "Exp.h"	
#include <string>
using namespace std;

class NewIdExp : public Exp
{
public:
	NewIdExp(Id *id,Expp *expp):m_id(id),m_expp(expp){}
	~NewIdExp(){}
	string GenCode();
private:
	Id *m_id;
	Expp *m_expp;
};

#endif