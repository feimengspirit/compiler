#include "Analyse.h"
#include "ClassDecls.h"
#include "VarDecls.h"

int compare_id(const string pre,const string next)
{
	return (pre.compare(next));
}

int sort_id(Program*p,int (*cmp)(const string&,const string&))
{
	ClassDecls *cds = p->m_clsdcls;
	VarDecls *vds;
	while(cds)
	{

		
	}

}

int elimate_extends(Program *p)
{
	return 0;
}