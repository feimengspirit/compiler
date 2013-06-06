#ifndef __IDTYPE_H__
#define __IDTYPE_H__
#include "Type.h"
#include "Id.h"

class IdType : public Type
{
public:
	IdType(Id *id):m_id(id){}
	~IdType(){}
private:
	Id *m_id;
};
#endif