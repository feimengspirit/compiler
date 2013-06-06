#include "Parser.h"
#include <iostream>

void Parser::Parse()
{
	std::cout<<"Parsing began"<<std::endl;
	Program();
	std::cout<<"Parsing ended successfully!"<<std::endl;
}
void syntax_error(NewToken look,WordKind tag)
{
	std::cout<<"syntax error here: "<<look.startpos.row<<
			"|"<<look.startpos.column<<" "<<look.s
			<<" "<<KeyWordToStr(look.kind)<<" but a/an "<<KeyWordToStr(tag)
			<<" is expected"<<std::endl;
	exit(0);
}
void Parser::Match(WordKind tag)
{
	if(this->look.kind == tag)
	{
		std::cout<<KeyWordToStr(look.kind)<<" " <<look.s<<std::endl;
		Move();
	}
		
	else{
		syntax_error(look,tag);
	}	
}
void Parser::Program()
{
	MainClass();
	ClassDecls();
}
void Parser::MainClass()
{
	Match(CLASS);
	Id();
	Match(LBRACE);
	Match(PUBLIC);
	Match(STATIC);
	Match(VOID);
	Match(MAIN);
	Match(LPAREN);
	Match(STRING);
	Match(LBRACK);
	Match(RBRACK);
	Id();
	Match(RPAREN);
	Match(LBRACE);
	Statement();
	Match(RBRACE);
	Match(RBRACE);
}
void Parser::ClassDecl()
{
	ClassNameDecl();
	switch(look.kind)
	{
	case LBRACE:
		Match(LBRACE);
		VarDecls();
		MethodDecls();
		Match(RBRACE);
		return;
	case EXTENDS:
		Match(EXTENDS);
		Id();
		Match(LBRACE);
		VarDecls();
		MethodDecls();
		Match(RBRACE);
		return;
	}
}
void Parser::ClassNameDecl()
{
	Match(CLASS);
	Id();
}
void Parser::ClassDecls()
{
	if(look.kind == EOFF)
		return;
	ClassDecl();
	ClassDecls();
}
void Parser::VarDecl()
{
	Type();
	Id();
	Match(SEMICOLON);
	return;
}
void Parser::VarDecls()
{
	if(look.kind == PUBLIC || look.kind == LBRACE
		|| look.kind == IF || look.kind == WHILE
		|| look.kind == SYSTEM_OUT_PRINTLN 
		|| look.kind == ID)
		return;
	VarDecl();
	VarDecls();
}
void Parser::MethodDecl()
{
	Match(PUBLIC);
	Type();
	Id();
	Match(LPAREN);
	FormalList();
	Match(RPAREN);
	Match(LBRACE);
	VarDecls();
	Statements();
	Match(RETURN);
	Exp();
	Match(SEMICOLON);
	Match(RBRACE);
}
void Parser::MethodDecls()
{
	if(look.kind == RBRACE)
		return;
	MethodDecl();
	MethodDecls();
}
void Parser::FormalList()
{
	if(look.kind == RPAREN)
		return;
	Type();
	Id();
	FormalRests();
}
void Parser::FormalRest()
{
	Match(COMMA);
	Type();
	Id();
}
void Parser::FormalRests()
{
	if(look.kind == RPAREN)
		return;
	FormalRest();
	FormalRests();
}
void Parser::Type()
{
	switch(look.kind)
	{
	case INT:
		Match(INT);
		if(look.kind != LBRACK)
			return;
		Match(LBRACK);
		Match(RBRACK);
	case BOOLEAN:
		Match(BOOLEAN);
		return;
	default:
		Id();
		return;
	}
}
void Parser::Statement()
{
	switch(look.kind)
	{
	case LBRACE:
		Match(LBRACE);
		Statements();
		Match(RBRACE);
		return;
	case IF:
		Match(IF);
		Match(LPAREN);
		Exp();
		Match(RPAREN);
		Statement();
		Match(ELSE);
		Statement();
		return;
	case WHILE:
		Match(WHILE);
		Match(LPAREN);
		Exp();
		Match(RPAREN);
		Statement();
		return;
	case SYSTEM_OUT_PRINTLN:
		Match(SYSTEM_OUT_PRINTLN);
		Match(LPAREN);
		Exp();
		Match(RPAREN);
		Match(SEMICOLON);
		return;
	default:
		Id();
		switch(look.kind)
		{
		case EQ:
			Match(EQ);
			Exp();
			Match(SEMICOLON);
			return;
		case LBRACK:
			Match(LBRACK);
			Exp();
			Match(RBRACK);
			Match(EQ);
			Exp();
			Match(SEMICOLON);
			return;
		}
		return;
	}
}

void Parser::Statements()
{
	if(look.kind == RETURN)
		return;
	Statement();
	Statements();
}
void Parser::Expp()
{
	switch(look.kind)
	{
	case LT:
	case TIMES:
	case PLUS:
	case OR:
	case AND:
	case GT:
	case EQ:
	case MINUS:
	case DIV: Op();Exp();Expp();return;
	case LBRACK: Match(LBRACK);Exp();Match(RBRACK);Expp();return;
	case DOT: Match(DOT);
		switch(look.kind)
		{
		case LENGTH:Match(LENGTH);Expp();return;
		case ID: Id();Match(LPAREN);ExpList();Match(RPAREN);Expp();
		default: return;
		}
	case RPAREN:
	case SEMICOLON: return;	
	}
}
void Parser::Exp()
{
	switch(look.kind)
	{
	case NUM: Match(NUM);Expp(); return;
	case TRUE: Match(TRUE);Expp(); return;
	case FALSE: Match(FALSE);Expp();return;
	case ID: Id();Expp();return;
	case THIS: Match(THIS);Expp();return;
	case NEW: Match(NEW);
		switch(look.kind)
		{
		case INT: Match(INT); Match(LBRACK);Exp();Match(RBRACK);Expp();return;
		case ID: Id();Match(LPAREN);Match(RPAREN);Expp();return;
		default: return;
		}
	case NOT: Match(NOT);Exp();Expp();return;
	case LPAREN: Match(LPAREN);Exp();Match(RPAREN);Expp(); return;
	}
}
void Parser::Op()
{
	switch(look.kind)
	{
	case LT:
		Match(LT);
		return;
	case TIMES:
		Match(TIMES);
		return;
	case PLUS:
		Match(PLUS);
		return;
	case OR:
		Match(OR);
		return;
	case AND:
		Match(AND);
		return;
	case GT:
		Match(GT);
		return;
	case EQ:
		Match(EQ);
		return;
	case MINUS:
		Match(MINUS);
		return;
	case DIV:
		Match(DIV);
		return;
	}
}

void Parser::ExpList()
{
	if(look.kind == RPAREN)
		return;
	Exp();
	ExpRests();
}
void Parser::ExpRest()
{
	Match(COMMA);
	Exp();
}
void Parser::ExpRests()
{
	if(look.kind == RPAREN)
		return;
	ExpRest();
	ExpRests();
}
void Parser::Id()
{
	Match(ID);
}