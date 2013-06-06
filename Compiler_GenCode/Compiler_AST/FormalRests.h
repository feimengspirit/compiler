#ifndef __FORMALRESTS_H__
#define __FORMALRESTS_H__
#include "FormalRest.h"
#include <string>
using namespace std;

class FormalRests
{
public:
	FormalRests(FormalRest *fr,FormalRests *frs):m_fr(fr),m_frs(frs){}
	~FormalRests(){}
	string GenCode();
private:
	FormalRest *m_fr;
	FormalRests *m_frs;
};

#endif