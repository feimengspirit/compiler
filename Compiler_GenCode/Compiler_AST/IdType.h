#ifndef __IDTYPE_H__
#define __IDTYPE_H__
#include "Type.h"
#include "Id.h"
#include <string>

class IdType : public Type
{
public:
	IdType(Id *id):m_id(id){}
	~IdType(){}
	string GenCode();
private:
	Id *m_id;
};
#endif