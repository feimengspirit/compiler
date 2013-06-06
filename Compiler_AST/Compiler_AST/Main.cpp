#include "Parser.h"
#include <iostream>
#include <vector>
#include "Analyse.h"
using namespace std;


int main()
{
	string filename = "Test.java";		//待分析文件名
	
	
	Parser parser(filename);			//构造语法分析器对象，传入待分析的文件
	Program *p = parser.Parse();		//进行分析,返回AST根节点

	/*
	string pre = "mengfti";
	string next = "mengfti";
	cout<<compare_id(pre,next)<<endl;
	*/

	std::cout<<"here"<<std::endl;
}