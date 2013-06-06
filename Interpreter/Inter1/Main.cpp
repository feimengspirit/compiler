#include "AssignStm.h"
#include "CompoundStm.h"
#include "Exp.h"
#include "ExpList.h"
#include "IdExp.h"
#include "Inter.h"
#include "LastExpList.h"
#include "NumExp.h"
#include "OpExp.h"
#include "PairExpList.h"
#include "PrintStm.h"
#include "Stm.h"
#include "Table.h"
#include "EseqExp.h"
#include <iostream>


int main(int argc, char* argv[])
{
	Stm *prog = 											//The abstract syntax tree 
			new CompoundStm(new AssignStm("a",				//a := 5 + 3;b := (print(a,a - 1),10 * a);print(b);				
								new OpExp(new NumExp(5),
											OpExp::Plus,
											new NumExp(3))),
			new CompoundStm(new AssignStm("b",
								new EseqExp(new PrintStm(new PairExpList(new IdExp("a"),	
								new LastExpList(new OpExp(new IdExp("a"),
										OpExp::Minus,new NumExp(1))))),
								new OpExp(new NumExp(10),OpExp::Times,new IdExp("a"))					
								)),
							new PrintStm(new LastExpList(new IdExp("b")))));
	//***********************************************************************************************************

	std::cout<<"The interpret result of this AST is: "<<std::endl;
	Inter::InterpStm(prog);							//Call static function of Inter class to interpret this prog

	std::cout<<"The max count of arguments of print statement in this AST is: "
			 <<Inter::maxargs(prog)<<std::endl;		//Call static  function of Inter class to get max count arguments
													//of print statement in the input statement
	delete prog;

	return 0;
}

