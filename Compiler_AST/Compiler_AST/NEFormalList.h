#ifndef __NEFORMALLIST_H__
#define __NEFORMALLIST_H__
#include <vector>
#include "FormalRest.h"
#include "FormalRests.h"
#include "Type.h"
#include "Id.h"
#include "FormalList.h"

using namespace std;

class NEFormalList : public FormalList
{
public:
	NEFormalList(Type *type,Id *id,FormalRests *frs):
			     m_type(type),m_id(id),m_frs(frs){}
	~NEFormalList(){}
private:
	Type *m_type;
	Id *m_id;
	FormalRests *m_frs;
};


#endif