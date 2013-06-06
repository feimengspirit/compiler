#include "BufferMgr.h"
#include <iostream>
int main()
{
	std::string fileName = "123.txt";
	BufferMgr bm(fileName);
	int row = 1;
	int column = 1;
	char c;
	while((c = bm.GetChar(row,column)) != EOF)
	{
		std::cout<<c;//<<row<<":"<<column<<std::endl;
		
	}
	std::cout<<std::endl;

}