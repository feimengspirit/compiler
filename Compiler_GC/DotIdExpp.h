#ifndef __DOTIDEXPP_H__
#define __DOTIDEXPP_H__
#include "Expp.h"
#include "ExpList.h"
#include "Id.h"
#include <string>
using namespace std;
class DotIdExpp : public Expp
{
public:
	DotIdExpp(Id *id,ExpList *explist,Expp *expp):m_id(id),m_explist(explist),
		m_expp(expp){}
	~DotIdExpp(){}
	string GenCode(string);
private:
	Id *m_id;
	ExpList *m_explist;
	Expp *m_expp;
};

#endif