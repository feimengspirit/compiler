#ifndef __PROGRAM_H__
#define __PROGRAM_H__
#include "MainClass.h"
#include "ClassDecl.h"
#include "ClassDecls.h"
#include "Analyse.h"
#include <string>

using namespace std;
class Program
{
public:
	Program(MainClass *mc,ClassDecls *cs):m_mainClass(mc),m_clsdcls(cs){}
	~Program(){}
	string GenCode();

	MainClass *m_mainClass;
	ClassDecls *m_clsdcls;
private:
};

#endif