#ifndef __THISEXP_H__
#define __THISEXP_H__

class ThisExp : public Exp
{
public:
	ThisExp(Expp *expp):m_expp(expp){}
	~ThisExp(){}
private:
	Expp *m_expp;
};


#endif