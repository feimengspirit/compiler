#ifndef __ID_H__
#define __ID_H__

#include <string>
#include "Lexer.h"
#include "Analyse.h"

using namespace std;
class Id
{
public:
	Id(NewToken id):m_id(id){}
	~Id(){}
	friend int sort_id(Program*,int (*)(const string&,const string&));

private:
	NewToken m_id;
};

#endif