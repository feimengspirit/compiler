#include "Parser.h"
#include <iostream>
#include <vector>
#include "Analyse.h"
using namespace std;


int main()
{
	string filename = "Test.java";		//�������ļ���
	
	
	Parser parser(filename);			//�����﷨���������󣬴�����������ļ�
	Program *p = parser.Parse();		//���з���,����AST���ڵ�


	elimate_extends(p);					//����extends
	string code = p->GenCode();
	std::cout<<"generated code is:"<<std::endl<<code<<std::endl;
	std::cout<<"here"<<std::endl;
	sort_id(p);							//�����еĳ�Ա�ͺ�����������
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
}