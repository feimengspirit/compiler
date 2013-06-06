#include "Inter.h"

Table * Inter::s_resultTable = NULL;

int Inter::Lookup(std::string key,Table *t)
{
	if(key.compare(t->m_strId) == 0)
		return t->m_Ivalue;
	if(t->m_tail == NULL)
		return -1;
	return Inter::Lookup(key,t->m_tail);
}
int Inter::Lookup(std::string key)
{
	return Inter::Lookup(key,Inter::s_resultTable);
}
void Inter::Update(int i,std::string k)
{
	Inter::s_resultTable = new Table(k,i,Inter::s_resultTable);
}
void Inter::InterpStm(Stm *s)
{
	s->Execute();
	while(s_resultTable !=NULL)
	{
		Table *next = s_resultTable->m_tail;
		delete s_resultTable;
		s_resultTable = next;
	}
}
int Inter::maxargs(Stm *s)
{
	return s->GetPrintMaxargs();
}
