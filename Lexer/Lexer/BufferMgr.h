#include <iostream>
#include <stdio.h>
using namespace std;

static const int bufferSize = 4096;

class BufferMgr
{
public:
	char GetChar(int&,int&);
	void PutChar(int&,int&);
	BufferMgr(string);
	~BufferMgr(void);
	
	
private:
	void FillBuffer();
	void SavePositon(int,int);
	char GetCharC(int&,int&);
	FILE *m_file;
	int m_forward;
	int m_iRow,m_iColumn;
	static char buf[bufferSize];
	
};

