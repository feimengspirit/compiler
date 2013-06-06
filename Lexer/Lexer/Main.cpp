#include<string>
#include<locale> //isdigit
#include<vector>
#include<iostream>
#include"BufferMgr.h"
#include"Lexer.h"
using namespace std;

int main()
{
	vector <class NewToken> N;
	//使用Buffer，一次从缓冲区中读取一个字符
	fflush(stdin);
	string filename = "Test.java";
	BufferMgr bm(filename);

	int count = 0;//记录Token的个数

	char ch = ' ';
	string temp = "";
	WordKind wk;
	struct Pos sp;
	struct Pos ep;
	int row = 1;
	int column = 0;

	char *to_insert;//强制类型转换temp，用于NewToken NT(wk,to_insert,sp,ep);

	/*****************************************************************/
	cout<<endl<<"**************************Lexer Begin**************************"<<endl;
	while(-1 != bm.GetChar(row,column))//文件未结束
	{
		//cout<<"***********Loop*********************"<<endpl;
		bm.PutChar(row,column);//返回光标
		ch = (char)bm.GetChar(row,column);
		//cout<<ch;
		if(ch == '\n')//如果换行，行数加1，列置0
		{
			temp = "";
			continue;
		}
		else
		{
			if((ch == ' ')||(ch == '\t'))
			{temp = "";continue;}
		}
		if(IsSymbol(&ch))//如果是:(){}+-*/=
		{
			//cout<<endpl<<ch<<endpl<<"是符号"<<endpl;
			temp += ch;
			sp.column = column;
			to_insert = (char *)(temp.c_str());
			wk = IsKeyWord(to_insert);//获取该标识符的类型Kind
			//保存该标识符的信息，插入vector
			//************************************************************
			sp.row = row;
			ep.row = row;
			ep.column = column;
			if(wk!=-1)
			{
				NewToken NT(wk,to_insert,sp,ep);
				N.push_back(NT);
				count++;
			}
			cout<<endl<<temp<<endl;
			cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<ch<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
			//cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<N[count-1].s<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
			
			//************************************************************
			temp = "";
			continue;
		}
		else//不是单个符号，可能是保留字、标识符、数字
		{
			sp.column = column;
			if((ch != ' ')&&(ch != '\n')&&(ch != '\t'))
			{temp += ch;}
			else
			{temp = "";continue;}
			ch = (char)bm.GetChar(row,column);//继续读字符
			while((ch != ' ')&&(ch != '\n')&&(ch != '\t')&&(!IsSymbol(&ch)))//读出完整的字符，直至' '或者标点符号为止
			{
				temp += ch;
				ch = (char)bm.GetChar(row,column);
			}
			bm.PutChar(row,column);//返回光标
			ep.column = column;
			cout<<endl<<temp<<endl;
			//判读temp是否是保留字、标识符、数字
			to_insert = (char *)(temp.c_str());
			//cout<<"判断是：保留字、数字、还是标识符"<<endpl;
			if((int)(wk=IsKeyWord(temp.c_str()))!=-1)//是保留字
			{
				//wk,WordKind k = CLASS;char *s = "class";struct Pos sp;struct Pos ep;
			//************************************************************
				sp.row = row;ep.row = row;
				if(wk!=-1)
				{
					NewToken NT(wk,to_insert,sp,ep);
					N.push_back(NT);
					count++;
				}

				cout<<" "<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
				//cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<N[count-1].s<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
			//************************************************************
				//cout<<"是保留字"<<endpl;
				temp = "";
			}
			else
			{
				if(IsNum(to_insert))//是数字
				{
					//************************************************************
					wk = NUM;
					sp.row = row;ep.row = row;
					if(wk!=-1)
					{
						NewToken NT(wk,to_insert,sp,ep);
						N.push_back(NT);
						count++;
					}

					cout<<" "<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
					//cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<N[count-1].s<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
					//************************************************************
					//cout<<to_insert<<"是数字"<<endl;
					temp = "";
				}
				else
				{
					if(IsId(to_insert))
					{

						if("System"==temp)//处理Sytem.out.println
						{
							ch = (char)bm.GetChar(row,column);
							//temp += ch;
							while((ch != ' ')&&(ch != '\n')&&(ch != '\t')&&(/*!IsSymbol(&ch)*/ch != '('))//读出完整的字符，直至' '或者标点符号为止
								{
									temp += ch;
									ch = (char)bm.GetChar(row,column);
								}
							bm.PutChar(row,column);
							//cout<<"temp:"<<temp<<endl;
							to_insert = (char *)(temp.c_str());
							//cout<<"to_insert:"<<to_insert<<endl;
							if((int)(wk=IsKeyWord(temp.c_str()))!=-1)//是保留字
								{
									//wk,WordKind k = CLASS;char *s = "class";struct Pos sp;struct Pos ep;
									//************************************************************
									sp.row = row;ep.row = row;ep.column = column;
									NewToken NT(wk,to_insert,sp,ep);
									if(wk!=-1)
									{
										N.push_back(NT);
										count++;
									}
									//************************************************************
									cout<<" "<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
									//cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<N[count-1].s<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
									//cout<<"是保留字"<<endl;
									temp = "";
								}
							continue;
						}
						else
						{
							//************************************************************
							wk = ID;
							sp.row = row;ep.row = row;
							if(wk!=-1)
							{
								NewToken NT(wk,to_insert,sp,ep);
								N.push_back(NT);
								count++;
							}
							//************************************************************
							cout<<" "<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
							//cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<N[count-1].s<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
							//cout<<"是标识符"<<endpl;
							temp = "";
						}
					}
					else//非法标识符
					{
						cout<<"Error,illegal identifier!"<<endl;
						cout<<"line:"<<row<<",";
						cout<<"column："<<sp.column<<"."<<endl;
						temp = "";
						return -1;
					}
				}
			}
		}
	}
	cout<<endl<<"********************Lexer End********************"<<endl<<endl<<endl;
	/*****************************************************************/
	//打印vector信息
	/*cout<<"Length of vector："<<N.size()<<endl;
	for(int i=0;i<N.size();i++)
	{
		cout<<"kind:"<<KeyWordToStr(N[i].kind)<<" value:"<<N[i].s<<" startpp:"<<N[i].startpos.row<<","<<N[i].startpos.column<<" endpp"<<N[i].endpos.row<<","<<N[i].endpos.column<<endl;
		cout<<endl;
	}*/
	return 0;
}
