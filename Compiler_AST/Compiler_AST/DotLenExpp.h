#ifndef __DOTLENEXPP_H__
#define __DOTLENEXPP_H__

#include "Expp.h"
class DotLenExpp : public Expp
{
public:
	DotLenExpp(Expp *expp):m_expp(expp){}
	~DotLenExpp(){}

private:

	Expp *m_expp;
};

#endif