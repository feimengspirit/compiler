int AomputeFac(struct Fac *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}
int Fac_ComputeFac(struct Fac *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}
int Fac_ComputeFac(struct Fac *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}
int ComputeFac(struct mengfei *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}
int AomputeFac(struct mengfei *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}
int Fac_ComputeFac(struct mengfei *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}
int AomputeFac(struct mengfei *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}
int Fac_ComputeFac(struct mengfei *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}
int Fac_ComputeFac(struct mengfei *this,int num)
{int num_aux;
int aum_aux;
if(num<1)
{
num_aux=1;
}
else
{
num_aux=num*(ComputeFac(this,num-1));
}
return num_aux;
}

struct Fac{
int Fac_i;
int Fac_j;
};
struct mengfei{
int j;
int i;
int mengfei;
int Fac_i;
int Fac_j;
};
int main(char *argv,int argc)
{
printf("%d",ComputeFac((Fac*)malloc(sizeof(Fac)),10))
return 0;
}
