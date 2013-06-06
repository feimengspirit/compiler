#include "OpExp.h"

const int OpExp::Plus = 1;
const int OpExp::Minus = 2;
const int OpExp::Times = 3;
const int OpExp::Div = 4;

int OpExp::Compute()
{
	switch(m_iOper){
	case Plus: return m_left->Compute() + m_right->Compute();
	case Minus: return m_left->Compute() - m_right->Compute();
	case Times: return m_left->Compute() * m_right->Compute();
	case Div: return m_left->Compute() / m_right->Compute();
	}
	return 0;
}
