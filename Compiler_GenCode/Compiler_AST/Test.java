class Factorial
{
   public static void main(string[] a)
   {
      System.out.println(new Fac().ComputeFac(10)); /*реб╘╥ж╨е*/
   }
}

class Fac
{
   int j;   
   int i;   
   public int ComputeFac(int num)
   {
      int num_aux;
      int aum_aux;
      if(num < 1)
         num_aux = 1;
      else
         num_aux = num * (this.ComputeFac(num-1));
      return num_aux;
   }

   public int AomputeFac(int num)
   {
      int num_aux;
      int aum_aux;
      if(num < 1)
         num_aux = 1;
      else
         num_aux = num * (this.ComputeFac(num-1));
      return num_aux;
   }
}

class mengfei extends Fac
{
   int mengfei;
   int i;
   int j;
   public int ComputeFac(int num)
   {
      int num_aux;
      int aum_aux;
      if(num < 1)
         num_aux = 1;
      else
         num_aux = num * (this.ComputeFac(num-1));
      return num_aux;
   }
}