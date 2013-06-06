#ifndef __FORMALREST_H__
#define __FORMALREST_H__
#include "Type.h"
#include "Id.h"
#include <string>
using namespace std;

class FormalRest
{
public:
	FormalRest(Type *type,Id *id):m_type(type),m_id(id){}
	~FormalRest(){}
	string GenCode();
private:
	Type *m_type;
	Id *m_id;
};
#endif