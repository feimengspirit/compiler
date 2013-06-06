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
	//ʹ��Buffer��һ�δӻ������ж�ȡһ���ַ�
	fflush(stdin);
	string filename = "Test.java";
	BufferMgr bm(filename);

	int count = 0;//��¼Token�ĸ���

	char ch = ' ';
	string temp = "";
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
			//cout<<"�ж��ǣ������֡����֡����Ǳ�ʶ��"<<endpl;
			if((int)(wk=IsKeyWord(temp.c_str()))!=-1)//�Ǳ�����
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
						NewToken NT(wk,to_insert,sp,ep);
						N.push_back(NT);
						count++;
					}

					cout<<" "<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
					//cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<N[count-1].s<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
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
									NewToken NT(wk,to_insert,sp,ep);
									if(wk!=-1)
									{
										N.push_back(NT);
										count++;
									}
									//************************************************************
									cout<<" "<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
									//cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<N[count-1].s<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
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
								NewToken NT(wk,to_insert,sp,ep);
								N.push_back(NT);
								count++;
							}
							//************************************************************
							cout<<" "<<"kind:"<<KeyWordToStr(wk)<<" value:"<<to_insert<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
							//cout<<"kind:"<<KeyWordToStr(wk)<<" value:"<<N[count-1].s<<" start:("<<sp.row<<","<<sp.column<<") end:("<<ep.row<<","<<ep.column<<")"<<endl;
							//cout<<"�Ǳ�ʶ��"<<endpl;
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
	cout<<endl<<"********************Lexer End********************"<<endl<<endl<<endl;
	/*****************************************************************/
	//��ӡvector��Ϣ
	/*cout<<"Length of vector��"<<N.size()<<endl;
	for(int i=0;i<N.size();i++)
	{
		cout<<"kind:"<<KeyWordToStr(N[i].kind)<<" value:"<<N[i].s<<" startpp:"<<N[i].startpos.row<<","<<N[i].startpos.column<<" endpp"<<N[i].endpos.row<<","<<N[i].endpos.column<<endl;
		cout<<endl;
	}*/
	return 0;
}
