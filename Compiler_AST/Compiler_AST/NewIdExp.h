#ifndef __NEWIDEXP_H__
#define __NEWIDEXP_H__
#include "Expp.h"
#include "Id.h"

class NewIdExp : public Exp
{
public:
	NewIdExp(Id *id,Expp *expp):m_id(id),m_expp(expp){}
	~NewIdExp(){}
private:
	Id *m_id;
	Expp *m_expp;
};

#endif