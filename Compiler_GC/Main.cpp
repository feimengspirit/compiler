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


	elimate_extends(p);					//消除extends
	string code = p->GenCode();
	std::cout<<"generated code is:"<<std::endl<<code<<std::endl;
	std::cout<<"here"<<std::endl;
	sort_id(p);							//对类中的成员和函数进行排序
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
}