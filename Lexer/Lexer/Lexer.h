#ifndef _LEXER_H_
#define _LEXER_H_
//字类型
enum WordKind
{
	CLASS = 0,
	PUBLIC,
	STATIC,
	MAIN,
	EXTENDS,
	LENGTH,
	SYSTEM_OUT_PRINTLN,
	THIS,
	NEW,
	RETURN,
	INT,
	BOOLEAN,
	STRING,
	VOID,
	IF,
	ELSE,
	THEN,
	DO,
	WHILE,
	TRUE,
	FALSE,
	OR,
	NOT,
	AND,
	GT,
	EQ,
	LT,
	TIMES,
	MINUS,
	PLUS,
	ASSIGN,
	DIV,
	LPAREN,
	RPAREN,
	LBRACE,
	RBRACE,
	LBRACK,
	RBRACK,
	COLON,
	DOT,
	SEMICOLON,
	COMMA,
	COMMENT,
	EOFF,
	ID,
	NUM
};
//保留字：值+类型
struct KeyWord
{
	char *s;
	WordKind kind;
};
//此处必须声明为static，因为这是定义，不是声明；否则该结构体既被Lexer.cpp包含，又被main.cpp包含
static struct KeyWord KeyWordTable[] =
{
	{"class",CLASS},
	{"public",PUBLIC},
	{"static",STATIC},
	{"main",MAIN},
	{"extends",EXTENDS},
	{"length",LENGTH},
	{"System.out.println",SYSTEM_OUT_PRINTLN},
	{"this",THIS},
	{"new",NEW},
	{"return",RETURN},
	{"int",INT},
	{"bool",BOOLEAN},
	{"string",STRING},
	{"void",VOID},
	{"if",IF},
	{"else",ELSE},
	{"then",THEN},
	{"do",DO},
	{"while",WHILE},
	{"true",TRUE},
	{"false",FALSE},
	{"or",OR},
	{"not",NOT},
	{"and",AND},
	{">",GT},
	{"=",EQ},
	{"<",LT},
	{"*",TIMES},
	{"-",MINUS},
	{"+",PLUS},
	{"=",ASSIGN},
	{"/",DIV},
	{"(",LPAREN},
	{")",RPAREN},
	{"{",LBRACE},
	{"}",RBRACE},
	{"[",LBRACK},
	{"]",RBRACE},
	{":",COLON},
	{".",DOT},
	{";",SEMICOLON},
	{",",COMMA}
	//{EOF,EOFF},
	//{ID}
	//{NUM}
};
//Word位置
struct Pos
{
	int row;
	int column;
};
//Word信息
class NewToken
{
public:
	NewToken(WordKind k,char *str,struct Pos sp,struct Pos ep):kind(k),s(str),startpos(sp),endpos(ep){}
	~NewToken(){}
	WordKind kind;
	char *s;
	struct Pos startpos;
	struct Pos endpos;
};


bool IsLetter(char *s);
bool IsDigit(char *s);
bool IsSymbol(char *s);//+,-,*,/,(,),{,}
char *KeyWordToStr(enum WordKind);
enum WordKind IsKeyWord(const char *s);
bool IsId(char *s);//未完成
bool IsNum(char *s);//未完成
char *ToUpper(char *s);
#endif