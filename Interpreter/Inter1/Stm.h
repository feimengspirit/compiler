#ifndef _STM_H_
#define _STM_H_
class Stm
{
public:
	virtual ~Stm(){}
	virtual int GetPrintMaxargs()=0;
	virtual void Execute()=0;
};

#endif