#include "Parser.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string filename = "Test.java";		//�������ļ���
	
	
	Parser parser(filename);			//�����﷨���������󣬴�����������ļ�
	parser.Parse();						//���з���

}