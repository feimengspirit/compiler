#include "Parser.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string filename = "Test.java";		//待分析文件名
	
	
	Parser parser(filename);			//构造语法分析器对象，传入待分析的文件
	parser.Parse();						//进行分析

}