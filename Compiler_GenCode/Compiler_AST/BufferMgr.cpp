#include "BufferMgr.h"
#include <iostream>

char BufferMgr::buf[2][bufferSize];

BufferMgr::BufferMgr(std::string fileName):m_iBufNum(0),m_forward(::bufferSize)
{
	this->m_file = fopen(fileName.c_str(),"r");
	if(this->m_file == NULL)
	{
		std::cout<<"file open failed!"<<std::endl;
		exit(0);
	}
}

char BufferMgr::GetCharC(int &row,int &column)
{

	char c =  BufferMgr::buf[m_iBufNum][m_forward++];


	this->SavePositon(row,column);
	if(c == '\n')
	{
		row += 1;
		column = 0;
	}
	else
		column++;
	/*
	if((c != ' ' && c != '\t')||(column != 0 && (c ==' '||c =='\t')) )
	{	
		column += (c == '\t'? 4:1);
	}
	*/
	return c;
}

char BufferMgr::GetChar(int &row,int &column)
{
	int count = 0;
	if (this->m_forward>=::bufferSize)
	{	
		if(0 == m_iBufNum)			//ÅÐ¶Ï¸Ã¸²¸ÇÄÄ¸ö»º³åÇø
		{
			FillBuffer(1);
			m_iBufNum = 1;
		}
		else
		{
			FillBuffer(0);
			m_iBufNum = 0;
		}
		
	}
	if(GetCharC(row,column) == '/')
	{	
		if(GetCharC(row,column) == '*')
		{
			count++;
			char c1 = GetCharC(row,column);
			char c2 = GetCharC(row,column);
		
			while(count)
			{
				if(c1== EOF || c2 == EOF)
				{
					std::cout<<"comment wrong !"<<row<<":"<<column<<std::endl;
					exit(0);
				}

				if(c1 == '/' && c2 == '*')
				{
					c1 = GetCharC(row,column);
					c2 = GetCharC(row,column);
					count++;
				}
				else if(c1 == '*' && c2 == '/')
				{	
					if(!(--count))
						return GetCharC(row,column);

					c1 = GetCharC(row,column);
					c2 = GetCharC(row,column);
				
				}
				else
				{
					c1 = c2;
					c2 = GetCharC(row,column);
					//continue;
				}
			}
		}
		else
		{
			PutChar(row,column);
		}
	}
	else
	{
		PutChar(row,column);
		return GetCharC(row,column);
	}
}

void BufferMgr::PutChar(int &row,int &column)
{	
	row = this->m_iRow;
	column = this->m_iColumn;
	this->m_forward--;
	return;
}

BufferMgr::~BufferMgr(void)
{
	fclose(m_file);
}

void BufferMgr::FillBuffer(int bn)
{
	int r;
	this->m_forward = 0;
	if (feof (this->m_file))
	{	
		BufferMgr::buf[bn][0] = EOF;
		return;
	}
	r = fread(buf[bn]
             , sizeof(char)
			 , ::bufferSize
			 , this->m_file);
	if (r<::bufferSize)
	{
		BufferMgr::buf[bn][r] = EOF;
	}
	return;
}

void BufferMgr::SavePositon(int row,int column)
{
	this->m_iRow = row;
	this->m_iColumn = column;
}