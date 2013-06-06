#ifndef __DOTIDEXPP_H__
#define __DOTIDEXPP_H__
class DotIdExpp : public Expp
{
public:
	DotIdExpp(ExpList *explist,Expp *expp):m_explist(explist),
		m_expp(expp){}
	~DotIdExpp(){}
private:
	ExpList *m_explist;
	Expp *m_expp;
};

#endif