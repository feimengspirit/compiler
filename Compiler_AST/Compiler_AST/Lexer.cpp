#include<iostream>
#include<locale> //isdigit
#include<string>
#include<vector>
#include<fstream>//文件操作
#include"BufferMgr.h"
#include"Lexer.h"
using namespace std;
vector <class NewToken> N;


enum WordKind IsKeyWord(const char *s)
{
	int i;
	char *temp;
	for(i=0;temp = KeyWordTable[i].s;i++)
	{
		if(0 == strcmp(s,temp))
			return KeyWordTable[i].kind;
	}
	return (enum WordKind)EOF;//ID或者NUM****************************
}
bool IsLetter(char s[])
{
	if(('A'<=(*s))&&((*s)<='Z')||((*s)>='a')&&((*s)<='z'))
		return true;
	else
		return false;
}
bool IsDigit(char s[])
{
	if(((*s)>='0')&&((*s)<='9'))
		return true;
	else
		return false;
}
char *ToUpper(char *s)//小写转大写
{
	int i = 0;
	while(s[i]&&IsLetter(&s[i]))
	{
		if(('a'<=s[i])&&(s[i]<='z'))
			s[i] = 'A' + s[i] - 'a';
	}
	return s;
}
bool IsSymbol(char *s)
{
	char sym[] = {'(',')','[',']','{','}','+','-','*','/','=','.',';'};
	int i = 0;
	while((i<strlen(sym))&&(*s)!=sym[i])
		i++;
	if(i == strlen(sym))
		return false;
	else
		return true;
}
char *KeyWordToStr(enum WordKind wordkind)
{
	switch(wordkind)
	{
	case CLASS:return "CLASS";
	case PUBLIC:return "PUBLIC";
	case STATIC:return "STATIC";
	case MAIN:return "MAIN";
	case EXTENDS:return "EXTENDS";
	case LENGTH:return "LENGTH";
	case SYSTEM_OUT_PRINTLN:return "SYSTEM_OUT_PRINTLN";
	case THIS:return "THIS";
	case NEW:return "NEW";
	case RETURN:return "RETURN";
	case INT:return "INT";
	case BOOLEAN:return "BOOLEAN";
	case STRING:return "STRING";
	case VOID:return "VOID";
	case IF:return "IF";
	case ELSE:return "ELSE";
	case THEN:return "THEN";
	case DO:return "DO";
	case WHILE:return "WHILE";
	case TRUE:return "TRUE";
	case FALSE:return "FALSE";
	case OR:return "OR";
	case NOT:return "NOT";
	case AND:return "AND";
	case GT:return "GT";
	case EQ:return "EQ";
	case LT:return "LT";
	case TIMES:return "TIMES";
	case MINUS:return "MINUS";
	case PLUS:return "PLUS";
	case ASSIGN:return "ASSIGN";
	case DIV:return "DIV";
	case LPAREN:return "LPAREN";
	case RPAREN:return "RPAREN";
	case LBRACE:return "LBRACE";
	case RBRACE:return "RBRACE";
	case LBRACK:return "LBRACK";
	case RBRACK:return "RBRACK";
	case COLON:return "COLON";
	case DOT:return "DOT";
	case SEMICOLON:return "SEMICOLON";
	case COMMA:return "SEMICOLON";
	case COMMENT:return "COMMENT";
	case EOFF:return "EOF";
	case ID:return "ID";
	case NUM:return "NUM";
	default:return "Error";
	}

}
bool IsId(char *s)//C语言变量名
{
	if((s[0] == '_')||(('A'<=(*s))&&((*s)<='Z'))||(((*s)>='a')&&((*s)<='z')))//判断首字母是否为数字或下划线
		return true;
	else
		return false;
}
bool IsNum(char *s)//数字
{

	if(((*s)==' ')||((*s)=='\n')||((*s)=='\t')||((*s)==' '))
		return false;
	for(int i=0;i<strlen(s);i++)
	{
		if(!IsDigit(&s[i]))//不能*s++，因为传进来的可能是全局数组，常量指针不能++
		{
			return false;
		}
	}
	return true;
}

int Lexer(string filename)
{
	//使用Buffer，一次从缓冲区中读取一个字符
	fflush(stdin);
	BufferMgr bm(filename);

	ofstream Input;
	Input.open("Lexer.txt",ios::trunc);//写文件，文件不存在则创建；trunc表示打开文件前先清空；
	
	int count = 0;//记录Token的个数

	char ch = ' ';
	//string temp = "";
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
		string temp = "";
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
				NewToken NT(wk,temp,sp,ep);
				N.push_back(NT);
				count++;
			}
			cout<<endl<<temp<<endl;
			cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<ch<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
			//cout<<"kind:"<<KeyWordToStr(N[count-1].kind)<<" value:"<<N[count-1].s<<" start:("<<N[count-1].startpos.row<<","<<N[count-1].startpos.column<<") end:("<<N[count-1].endpos.row<<","<<N[count-1].endpos.column<<")"<<endl;
			Input<<KeyWordToStr(wk)<<","<<ch<<","<<sp.row<<","<<sp.column<<","<<ep.row<<","<<ep.column<<endl;
			
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
			//cout<<"***********"<<endl;
			//cout<<"判断是：保留字、数字、还是标识符"<<endpl;
			if((int)(wk=IsKeyWord(temp.c_str()))!=-1)//是保留字
			{
				//wk,WordKind k = CLASS;char *s = "class";struct Pos sp;struct Pos ep;
			//************************************************************
				sp.row = row;ep.row = row;
				if(wk!=-1)
				{
					NewToken NT(wk,temp,sp,ep);
					N.push_back(NT);
					count++;
				}

				cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
				//cout<<"kind:"<<KeyWordToStr(N[count-1].kind)<<" value:"<<N[count-1].s<<" start:("<<N[count-1].startpos.row<<","<<N[count-1].startpos.column<<") end:("<<N[count-1].endpos.row<<","<<N[count-1].endpos.column<<")"<<endl;
			
				Input<<KeyWordToStr(wk)<<","<<to_insert<<","<<sp.row<<","<<sp.column<<","<<ep.row<<","<<ep.column<<endl;
			
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
						NewToken NT(wk,temp,sp,ep);
						N.push_back(NT);
						count++;
					}

					cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
					//cout<<"kind:"<<KeyWordToStr(N[count-1].kind)<<" value:"<<N[count-1].s<<" start:("<<N[count-1].startpos.row<<","<<N[count-1].startpos.column<<") end:("<<N[count-1].endpos.row<<","<<N[count-1].endpos.column<<")"<<endl;
			
					Input<<KeyWordToStr(wk)<<","<<to_insert<<","<<sp.row<<","<<sp.column<<","<<ep.row<<","<<ep.column<<endl;
			
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
									NewToken NT(wk,temp,sp,ep);
									if(wk!=-1)
									{
										N.push_back(NT);
										count++;
									}
									//************************************************************
									cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
									//cout<<"kind:"<<KeyWordToStr(N[count-1].kind)<<" value:"<<N[count-1].s<<" start:("<<N[count-1].startpos.row<<","<<N[count-1].startpos.column<<") end:("<<N[count-1].endpos.row<<","<<N[count-1].endpos.column<<")"<<endl;
			
									Input<<KeyWordToStr(wk)<<","<<to_insert<<","<<sp.row<<","<<sp.column<<","<<ep.row<<","<<ep.column<<endl;
			
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
								NewToken NT(wk,temp,sp,ep);
								N.push_back(NT);
								count++;
							}
							//************************************************************
							cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
							//cout<<"kind:"<<KeyWordToStr(N[count-1].kind)<<" value:"<<N[count-1].s<<" start:("<<N[count-1].startpos.row<<","<<N[count-1].startpos.column<<") end:("<<N[count-1].endpos.row<<","<<N[count-1].endpos.column<<")"<<endl;
			
							Input<<KeyWordToStr(wk)<<","<<to_insert<<","<<sp.row<<","<<sp.column<<","<<ep.row<<","<<ep.column<<endl;
			
							//cout<<"是标识符"<<endl;
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
	//add EOF
	wk = EOFF;
	sp.row = row;ep.row = row;
	sp.column = 1;ep.column = 1;
	count++;
	NewToken NT(wk,"EOFF",sp,ep);
	N.push_back(NT);
	cout<<endl<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
							
	cout<<endl<<"********************Lexer End********************"<<endl<<endl<<endl;
	/*****************************************************************/
	//打印vector信息
	
	Input.close();
}
NewToken scan()
{
	static int i = 0;
	return N[i++];
}

