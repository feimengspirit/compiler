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

	/*
	string pre = "mengfti";
	string next = "mengfti";
	cout<<compare_id(pre,next)<<endl;
	*/

	std::cout<<"here"<<std::endl;
}