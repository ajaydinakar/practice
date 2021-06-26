import java.util.Scanner;
class LargestPF {


public static void main(String args[])
{
  System.out.println("Largest PF is "+ largestPF(600851475143L));
 
}

static long  largestPF(long number)
{
  System.out.println("Prime factors are");
for(long i = 2; i< number; i++) {
         while(number%i == 0) {
     System.out.println(i+" ");
            number = number/i;
         }
     
      }
        if(number>2)
         { System.out.println(number+" ");}
return number;
}


}

    
