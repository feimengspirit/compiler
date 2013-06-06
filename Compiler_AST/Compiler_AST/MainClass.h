#ifndef __MAINCLASS_H__
#define __MAINCLASS_H__
#include "Statement.h"
#include "Id.h"
#include "Analyse.h"
class MainClass
{
public:
	MainClass(Id *className,Id *argumentName,Statement *statement):
				m_className(className),m_argumentName(argumentName),
				m_statement(statement){}
	~MainClass(){}
	friend int sort_id(Program*,int (*)(const string&,const string&));
private:
	Id *m_className;
	Id *m_argumentName;
	Statement *m_statement;
};

#endif