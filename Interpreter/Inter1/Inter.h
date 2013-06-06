#ifndef _INTER_H_
#define _INTER_H_

#include "Table.h"
#include "Stm.h"
#include <iostream>
class Inter
{
public:
	Inter(void);
	~Inter(void);
	static void InterpStm(Stm *s);
	static int Lookup(std::string key);
	static void Update(int i,std::string k);
	static Table *s_resultTable;
	static int maxargs(Stm *);
private:
	static int Lookup(std::string key,Table *t);
};

#endif