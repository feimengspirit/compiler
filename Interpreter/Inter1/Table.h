#ifndef _TABLE_H_
#define _TABLE_H_
#pragma once
#include <iostream>

class Table
{
public:
	Table(std::string i,int v,Table *t):m_strId(i),m_Ivalue(v),m_tail(t){}
	~Table(void){}
	std::string m_strId;
	int m_Ivalue;
	Table *m_tail;
};

#endif