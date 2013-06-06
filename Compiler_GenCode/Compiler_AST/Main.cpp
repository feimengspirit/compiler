#include "Parser.h"
#include <iostream>
#include "Analyse.h"
#include <fstream>

using namespace std;


int main()
{
	string filename = "Test.java";		//�������ļ���
	
	
	Parser parser(filename);			//�����﷨���������󣬴�����������ļ�
	Program *p = parser.Parse();		//���з���,����AST���ڵ�


	elimate_extends(p);					//����extends
	
	
	sort_id(p);							//�����еĳ�Ա�ͺ�����������
	string code = p->GenCode();
	std::cout<<"generated code is:"<<std::endl<<code<<std::endl;

	FILE *pfout;
	pfout = fopen("resultcode.c","wt");
	fprintf(pfout,"%s\n",code.c_str());
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
	std::cout<<"here"<<std::endl;
}