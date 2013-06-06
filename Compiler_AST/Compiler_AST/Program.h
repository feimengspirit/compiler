#ifndef __PROGRAM_H__
#define __PROGRAM_H__
#include "MainClass.h"
#include "Analyse.h"
#include "ClassDecls.h"

class Program
{
public:
	Program(MainClass *mc,ClassDecls *cs):m_mainClass(mc),m_clsdcls(cs){}
	~Program(){}

	friend int sort_id(Program*,int (*)(const string&,const string&));
private:
	MainClass *m_mainClass;
	ClassDecls *m_clsdcls;
private:
};

#endif