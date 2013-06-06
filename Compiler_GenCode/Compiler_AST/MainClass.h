#ifndef __MAINCLASS_H__
#define __MAINCLASS_H__
#include "Statement.h"
#include "Id.h"
#include <string>
using namespace std;
class MainClass
{
public:
	MainClass(Id *className,Id *argumentName,Statement *statement):
				m_className(className),m_argumentName(argumentName),
				m_statement(statement){}
	~MainClass(){}
	string GenCode();

	Id *m_className;
	Id *m_argumentName;
	Statement *m_statement;
};

#endif