#ifndef __ID_H__
#define __ID_H__

#include <string>
#include "Lexer.h"
#include <string>

using namespace std;
class Id
{
public:
	Id(NewToken id):m_id(id){}
	~Id(){}
	string GenCode()
	{
		return m_id.s;
	}

	NewToken m_id;
};

#endif