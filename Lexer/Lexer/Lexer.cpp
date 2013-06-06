#include"Lexer.h"
#include<locale> //isdigit
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