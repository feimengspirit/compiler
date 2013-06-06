#ifndef __ANALYSE_H__
#define __ANALYSE_H__

#include <string>
#include <iostream>

using namespace std;

class Program;
//typedef int (*COMPARATOR)(const string&,const string&);

int sort_id(Program*);
int compare_id(const string,const string);
int elimate_extends(Program*);


#endif
