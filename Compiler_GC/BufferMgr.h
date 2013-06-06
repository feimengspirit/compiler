#include <iostream>
#include <stdio.h>
using namespace std;

static const int bufferSize = 4096;		//每个缓冲区的大小

class BufferMgr
{
public:
	char GetChar(int&,int&);		//取字符
	void PutChar(int&,int&);		//回退字符
	BufferMgr(string);
	~BufferMgr(void);
	
	
private:
	void FillBuffer(int);			//填充指定缓冲区
	void SavePositon(int,int);		//取字符前先保存位置，防止跨行注释问题
	char GetCharC(int&,int&);		//从缓冲区取字符
	FILE *m_file;					//待分析文件
	int m_forward;					//指明当前缓冲区的读取位置
	int m_iRow,m_iColumn;			//保存祁下一个字符前的位置信息，主要处理换行注释
	int m_iBufNum;					//指明当前所在的缓冲区
	static char buf[2][bufferSize]; //嵌套注释需要向前看两个字符，防止无法回退，采用双缓冲区
	
};

