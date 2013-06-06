#ifndef __FORMALRESTS_H__
#define __FORMALRESTS_H__
#include "FormalRest.h"

class FormalRests
{
public:
	FormalRests(FormalRest *fr,FormalRests *frs):m_fr(fr),m_frs(frs){}
	~FormalRests(){}
private:
	FormalRest *m_fr;
	FormalRests *m_frs;
};

#endif