#include "BufferMgr.h"
#include <iostream>

char BufferMgr::buf[bufferSize];
BufferMgr::BufferMgr(std::string fileName)
{
	this->m_file = fopen(fileName.c_str(),"r");
	if(this->m_file == NULL)
	{
		std::cout<<"file open failed!"<<std::endl;
		exit(0);
	}
	this->m_forward = ::bufferSize;
}

char BufferMgr::GetCharC(int &row,int &column)
{

	char c =  BufferMgr::buf[m_forward++];
	this->SavePositon(row,column);
	if(c == '\n')
	{
		row += 1;
		column = 0;
		//std::cout<<"»»ÐÐ";
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
		FillBuffer ();
	}
	if(BufferMgr::buf[m_forward] == '/' && BufferMgr::buf[m_forward + 1] == '*')
	{	
		GetCharC(row,column);
		GetCharC(row,column);
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
				if(!(count--))
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

void BufferMgr::FillBuffer()
{
	int r;
	this->m_forward = 0;
	if (feof (this->m_file))
	{
		BufferMgr::buf[0] = EOF;
		return;
	}
	r = fread(buf
             , sizeof(char)
			 , ::bufferSize
			 , this->m_file);
	if (r<::bufferSize)
	{
		BufferMgr::buf[r] = EOF;
	}
	return;
}

void BufferMgr::SavePositon(int row,int column)
{
	this->m_iRow = row;
	this->m_iColumn = column;
}