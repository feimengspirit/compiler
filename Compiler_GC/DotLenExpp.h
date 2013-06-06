#ifndef __DOTLENEXPP_H__
#define __DOTLENEXPP_H__

#include "Expp.h"
#include <string>
using namespace std;
class DotLenExpp : public Expp
{
public:
	DotLenExpp(Expp *expp):m_expp(expp){}
	~DotLenExpp(){}
	string GenCode(string);

private:

	Expp *m_expp;
};

#endif