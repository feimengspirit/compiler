class Factorial				/*comment/*comment*/comment*/
{
   public static void main(string[] a)
   {
      System.out.println(new Fa/*comment*/c().ComputeFac(10));
   }
}

class Fac
{
   public int ComputeFac(int num)
   {
      int num_aux;
      if(num < 1)
         num_aux = 1;
      else
         num_aux = num * (this.ComputeFac(num-1));
      return num_aux;
   }
}