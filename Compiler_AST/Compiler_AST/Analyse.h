#ifndef __ANALYSE_H__
#define __ANALYSE_H__

#include <string>
class Program;
using namespace std;

//typedef int (*COMPARATOR)(const string&,const string&);

int sort_id(Program*,int (*)(const string&,const string&));
int compare_id(const string&,const string&);
int elimate_extends(Program*);


#endif
