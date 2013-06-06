#include<iostream>
#include<locale> //isdigit
#include<string>
#include<vector>
#include<fstream>//�ļ�����
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
	return (enum WordKind)EOF;//ID����NUM****************************
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
char *ToUpper(char *s)//Сдת��д
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
bool IsId(char *s)//C���Ա�����
{
	if((s[0] == '_')||(('A'<=(*s))&&((*s)<='Z'))||(((*s)>='a')&&((*s)<='z')))//�ж�����ĸ�Ƿ�Ϊ���ֻ��»���
		return true;
	else
		return false;
}
bool IsNum(char *s)//����
{

	if(((*s)==' ')||((*s)=='\n')||((*s)=='\t')||((*s)==' '))
		return false;
	for(int i=0;i<strlen(s);i++)
	{
		if(!IsDigit(&s[i]))//����*s++����Ϊ�������Ŀ�����ȫ�����飬����ָ�벻��++
		{
			return false;
		}
	}
	return true;
}

int Lexer(string filename)
{
	//ʹ��Buffer��һ�δӻ������ж�ȡһ���ַ�
	fflush(stdin);
	BufferMgr bm(filename);

	ofstream Input;
	Input.open("Lexer.txt",ios::trunc);//д�ļ����ļ��������򴴽���trunc��ʾ���ļ�ǰ����գ�
	
	int count = 0;//��¼Token�ĸ���

	char ch = ' ';
	//string temp = "";
	WordKind wk;
	struct Pos sp;
	struct Pos ep;
	int row = 1;
	int column = 0;

	char *to_insert;//ǿ������ת��temp������NewToken NT(wk,to_insert,sp,ep);

	/*****************************************************************/
	cout<<endl<<"**************************Lexer Begin**************************"<<endl;
	while(-1 != bm.GetChar(row,column))//�ļ�δ����
	{
		//cout<<"***********Loop*********************"<<endpl;
		string temp = "";
		bm.PutChar(row,column);//���ع��
		ch = (char)bm.GetChar(row,column);
		//cout<<ch;
		if(ch == '\n')//������У�������1������0
		{
			temp = "";
			continue;
		}
		else
		{
			if((ch == ' ')||(ch == '\t'))
			{temp = "";continue;}
		}
		if(IsSymbol(&ch))//�����:(){}+-*/=
		{
			//cout<<endpl<<ch<<endpl<<"�Ƿ���"<<endpl;
			temp += ch;
			sp.column = column;
			to_insert = (char *)(temp.c_str());
			wk = IsKeyWord(to_insert);//��ȡ�ñ�ʶ��������Kind
			//����ñ�ʶ������Ϣ������vector
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
		else//���ǵ������ţ������Ǳ����֡���ʶ��������
		{
			sp.column = column;
			if((ch != ' ')&&(ch != '\n')&&(ch != '\t'))
			{temp += ch;}
			else
			{temp = "";continue;}
			ch = (char)bm.GetChar(row,column);//�������ַ�
			while((ch != ' ')&&(ch != '\n')&&(ch != '\t')&&(!IsSymbol(&ch)))//�����������ַ���ֱ��' '���߱�����Ϊֹ
			{
				temp += ch;
				ch = (char)bm.GetChar(row,column);
			}
			bm.PutChar(row,column);//���ع��
			ep.column = column;
			cout<<endl<<temp<<endl;
			//�ж�temp�Ƿ��Ǳ����֡���ʶ��������
			to_insert = (char *)(temp.c_str());
			//cout<<"***********"<<endl;
			//cout<<"�ж��ǣ������֡����֡����Ǳ�ʶ��"<<endpl;
			if((int)(wk=IsKeyWord(temp.c_str()))!=-1)//�Ǳ�����
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
				//cout<<"�Ǳ�����"<<endpl;
				temp = "";
			}
			else
			{
				if(IsNum(to_insert))//������
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
					//cout<<to_insert<<"������"<<endl;
					temp = "";
				}
				else
				{
					if(IsId(to_insert))
					{

						if("System"==temp)//����Sytem.out.println
						{
							ch = (char)bm.GetChar(row,column);
							//temp += ch;
							while((ch != ' ')&&(ch != '\n')&&(ch != '\t')&&(/*!IsSymbol(&ch)*/ch != '('))//�����������ַ���ֱ��' '���߱�����Ϊֹ
								{
									temp += ch;
									ch = (char)bm.GetChar(row,column);
								}
							bm.PutChar(row,column);
							//cout<<"temp:"<<temp<<endl;
							to_insert = (char *)(temp.c_str());
							//cout<<"to_insert:"<<to_insert<<endl;
							if((int)(wk=IsKeyWord(temp.c_str()))!=-1)//�Ǳ�����
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
			
									//cout<<"�Ǳ�����"<<endl;
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
			
							//cout<<"�Ǳ�ʶ��"<<endl;
							temp = "";
						}
					}
					else//�Ƿ���ʶ��
					{
						cout<<"Error,illegal identifier!"<<endl;
						cout<<"line:"<<row<<",";
						cout<<"column��"<<sp.column<<"."<<endl;
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
	//��ӡvector��Ϣ
	
	Input.close();
}
NewToken scan()
{
	static int i = 0;
	return N[i++];
}

