#include "Parser.h"
#include <iostream>

Program* Parser::Parse()
{
	std::cout<<"Parsing began"<<std::endl;
	Program *p = FProgram();
	std::cout<<"Parsing ended successfully!"<<std::endl;
	return p;
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
Program* Parser::FProgram()
{
	MainClass *mc = FMainClass();
	ClassDecls *cds = FClassDecls();
	return new Program(mc,cds);		//递归的根据已构建的子节点构建AST根节点
}
MainClass* Parser::FMainClass()
{
	Match(CLASS);
	Id *cname = FId();
	Match(LBRACE);
	Match(PUBLIC);
	Match(STATIC);
	Match(VOID);
	Match(MAIN);
	Match(LPAREN);
	Match(STRING);
	Match(LBRACK);
	Match(RBRACK);
	Id *argname = FId();
	Match(RPAREN);
	Match(LBRACE);
	Statement *s = FStatement();
	Match(RBRACE);
	Match(RBRACE);

	return new MainClass(cname,argname,s);
}
ClassDecl* Parser::FClassDecl()
{
	ClassNameDecl *cnd = FClassNameDecl();
	VarDecls *vds;
	MethodDecls *mds;
	Id *pId;
	switch(look.kind)
	{
	case LBRACE:
		Match(LBRACE);
		vds = FVarDecls();
		mds = FMethodDecls();
		Match(RBRACE);
		return new SingleClassDecl(cnd,vds,mds);
	case EXTENDS:
		Match(EXTENDS);
		pId = FId();
		Match(LBRACE);
		vds = FVarDecls();
		mds = FMethodDecls();
		Match(RBRACE);
		return new ExtendsClassDecl(cnd,pId,vds,mds);
	}
}
ClassNameDecl* Parser::FClassNameDecl()
{
	Match(CLASS);
	Id *id = FId();
	return new ClassNameDecl(id);
}
ClassDecls* Parser::FClassDecls()
{
	if(look.kind == EOFF)
		return NULL;
	ClassDecl *cd = FClassDecl();
	ClassDecls *cds = FClassDecls();
	return new ClassDecls(cd,cds);
}
VarDecl* Parser::FVarDecl()
{
	Type *t = FType();
	Id *id = FId();
	Match(SEMICOLON);
	return new VarDecl(t,id);
}
VarDecls* Parser::FVarDecls()
{
	if(look.kind == PUBLIC || look.kind == LBRACE
		|| look.kind == IF || look.kind == WHILE
		|| look.kind == SYSTEM_OUT_PRINTLN 
		|| look.kind == ID)
		return NULL;
	VarDecl *vd = FVarDecl();
	VarDecls *vds = FVarDecls();
	return new VarDecls(vd,vds);
}
MethodDecl* Parser::FMethodDecl()
{
	Match(PUBLIC);
	Type *t = FType();
	Id *id = FId();
	Match(LPAREN);
	FormalList *fl = FFormalList();
	Match(RPAREN);
	Match(LBRACE);
	VarDecls *vds = FVarDecls();
	Statements *s = FStatements();
	Match(RETURN);
	Exp *exp = FExp();
	Match(SEMICOLON);
	Match(RBRACE);
	return new MethodDecl(t,id,fl,vds,s,exp);
}
MethodDecls* Parser::FMethodDecls()
{
	if(look.kind == RBRACE)
		return NULL;
	MethodDecl *md = FMethodDecl();
	MethodDecls *mds = FMethodDecls();
	return new MethodDecls(md,mds);
}
FormalList* Parser::FFormalList()
{
	if(look.kind == RPAREN)
		return NULL;
	Type *t = FType();
	Id *id = FId();
	FormalRests *fr = FFormalRests();
	return new NEFormalList(t,id,fr);
}
FormalRest* Parser::FFormalRest()
{
	Match(COMMA);
	Type *t = FType();
	Id *id = FId();
	return new FormalRest(t,id);
}
FormalRests* Parser::FFormalRests()
{
	if(look.kind == RPAREN)
		return NULL;
	FormalRest *fr = FFormalRest();
	FormalRests *frs = FFormalRests();
	return new FormalRests(fr,frs);
}
Type* Parser::FType()
{
	switch(look.kind)
	{
	case INT:
		Match(INT);
		if(look.kind != LBRACK)
			return new IntType();
		Match(LBRACK);
		Match(RBRACK);
		return new IArrayType();
	case BOOLEAN:
		Match(BOOLEAN);
		return new BoolType();
	default:
		Id *id = FId();
		return new IdType(id);
	}
}
Statement* Parser::FStatement()
{	
	switch(look.kind)
	{
	case LBRACE:
		{
		Match(LBRACE);
		Statements *ss = FStatements();
		Match(RBRACE);
		return new CompositeStatement(ss);
		}
	case IF:
		{
		Match(IF);
		Match(LPAREN);
		Exp *exp = FExp();
		Match(RPAREN);
		Statement *s1 = FStatement();
		Match(ELSE);
		Statement *s2 = FStatement();
		return new IfStatement(exp,s1,s2);
		}
	case WHILE:
		{
		Match(WHILE);
		Match(LPAREN);
		Exp *exp1 = FExp();
		Match(RPAREN);
		Statement *s3 = FStatement();
		return new WhileStatement(exp1,s3);
		}
	case SYSTEM_OUT_PRINTLN:
		{
		Match(SYSTEM_OUT_PRINTLN);
		Match(LPAREN);
		Exp *exp2 = FExp();
		Match(RPAREN);
		Match(SEMICOLON);
		return new PrintStatement(exp2);
		}
	default:
		{
		Id *id = FId();
		switch(look.kind)
		{
		case EQ:
			{
			Match(EQ);
			Exp *exp3 = FExp();
			Match(SEMICOLON);
			return new AssignStm(id,exp3);
			}
		case LBRACK:
			{
			Match(LBRACK);
			Exp *index = FExp();
			Match(RBRACK);
			Match(EQ);
			Exp *exp4 = FExp();
			Match(SEMICOLON);
			return new ArrayAssignStm(id,index,exp4);
			}
		}
		return NULL;
		}
	}
}

Statements* Parser::FStatements()
{
	if(look.kind == RETURN)
		return NULL;
	Statement *s = FStatement();
	Statements *ss = FStatements();
	return new Statements(s,ss);

}
Expp* Parser::FExpp()
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
	case DIV: 
		{
		Op *op = FOp();
		Exp *exp = FExp();
		Expp *expp = FExpp();
		return new OpExpp(op,exp,expp);
		}
	case LBRACK: 
		{
		Match(LBRACK);
		Exp *exp1 = FExp();Match(RBRACK);
		Expp *expp1 = FExpp();
		return new LBrackExpp(exp1,expp1);
		}
	case DOT: 
		{Match(DOT);
		switch(look.kind)
		{
		case LENGTH:
			{
			Match(LENGTH);
			Expp *expp2 = FExpp();
			return new DotLenExpp(expp2);
			}
		case ID: 
			{
			Id *id1 = FId();Match(LPAREN);
			ExpList *el = FExpList();Match(RPAREN);
			Expp *expp3 = FExpp();
			return new DotIdExpp(el,expp3);
			}
		default: return NULL;
		}
		}
	case RPAREN:
	case SEMICOLON: return NULL;
	}
}
Exp* Parser::FExp()
{
	switch(look.kind)
	{
	case NUM: 
		{
			Match(NUM);
			Expp *expp = FExpp(); return new NumExp(expp);
		}
	case TRUE: 
		{
		Match(TRUE);
		Expp *expp = FExpp(); return new TrueExp(expp);
		}
	case FALSE: 
		{
		Match(FALSE);
		Expp *expp = FExpp();return new FalseExp(expp);
		}
	case ID: 
		{
		Id *id = FId();Expp *expp = FExpp();
		return new IdExp(id,expp);
		}
	case THIS: 
		{
		Match(THIS);
		Expp *expp = FExpp();return new ThisExp(expp);
		}
	case NEW: 
		{
		Match(NEW);
		switch(look.kind)
		{
		case INT: 
			{
			Match(INT); Match(LBRACK);
			Exp *index = FExp();Match(RBRACK);
			Expp *expp = FExpp();return new NewIntExp(index,expp);
			}
		case ID: 
			{
			Id *id = FId();Match(LPAREN);Match(RPAREN);
			Expp *expp = FExpp();return new NewIdExp(id,expp);
			}
		default: return NULL;
		}
		}
	case NOT: 
		{
		Match(NOT);
		Exp *exp = FExp();Expp *expp = FExpp();
		return new NotExp(exp,expp);
		}
	case LPAREN: 
		{
		Match(LPAREN);
		Exp *exp = FExp();Match(RPAREN);
		Expp *expp = FExpp(); return new LParenExp(exp,expp);
		}
	}
}
Op* Parser::FOp()
{
	switch(look.kind)
	{
	case LT:
		{
			NewToken w = look;
			Match(LT);
			return new Op(w);
		}
	case TIMES:
		{
			NewToken w = look;
			Match(TIMES);
			return new Op(w);
		}
	case PLUS:
		{
			NewToken w = look;
			Match(PLUS);
			return new Op(w);
		}
	case OR:
		{
			NewToken w = look;
			Match(OR);
			return new Op(w);
		}
	case AND:
		{
			NewToken w = look;
			Match(AND);
			return new Op(w);
		}
	case GT:
		{
			NewToken w = look;
			Match(GT);
			return new Op(w);
		}
	case EQ:
		{
			NewToken w = look;
			Match(EQ);
			return new Op(w);
		}
	case MINUS:
		{
			NewToken w = look;
			Match(MINUS);
			return new Op(w);
		}
	case DIV:
		{
			NewToken w = look;
			Match(DIV);
			return new Op(w);
		}
	}
}

ExpList* Parser::FExpList()
{
	if(look.kind == RPAREN)
		return NULL;
	Exp *exp = FExp();
	ExpRests *ers = FExpRests();\
	return new NeExpList(exp,ers);
}
ExpRest* Parser::FExpRest()
{
	Match(COMMA);
	Exp *exp = FExp();
	return new ExpRest(exp);
}
ExpRests* Parser::FExpRests()
{
	if(look.kind == RPAREN)
		return NULL;
	ExpRest *er = FExpRest();
	ExpRests *ers = FExpRests();
	return new ExpRests(er,ers);
}
Id* Parser::FId()
{
	NewToken w = look;
	Match(ID);
	return new Id(w);
}