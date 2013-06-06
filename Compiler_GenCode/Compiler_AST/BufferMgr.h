#include <iostream>
#include <stdio.h>
using namespace std;

static const int bufferSize = 4096;		//ÿ���������Ĵ�С

class BufferMgr
{
public:
	char GetChar(int&,int&);		//ȡ�ַ�
	void PutChar(int&,int&);		//�����ַ�
	BufferMgr(string);
	~BufferMgr(void);
	
	
private:
	void FillBuffer(int);			//���ָ��������
	void SavePositon(int,int);		//ȡ�ַ�ǰ�ȱ���λ�ã���ֹ����ע������
	char GetCharC(int&,int&);		//�ӻ�����ȡ�ַ�
	FILE *m_file;					//�������ļ�
	int m_forward;					//ָ����ǰ�������Ķ�ȡλ��
	int m_iRow,m_iColumn;			//��������һ���ַ�ǰ��λ����Ϣ����Ҫ������ע��
	int m_iBufNum;					//ָ����ǰ���ڵĻ�����
	static char buf[2][bufferSize]; //Ƕ��ע����Ҫ��ǰ�������ַ�����ֹ�޷����ˣ�����˫������
	
};

