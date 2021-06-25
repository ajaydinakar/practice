import java.util.Scanner;
class EvenFebnauci {
int fibonacci(int num)
 {
 int n1=0,n2=1,sum=0;

  if (num < 1)
        return 0 ;
 
    for (int i = 1; i <= num; i++)
    {
    if(n2%2==0)
    {
      System.out.print(n2+" ");
      sum=sum+n2;
    }
        int temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    }
return sum;
} 

 public static void main(String[] args)
  {
  	Scanner in=new Scanner(System.in);
  	System.out.println("Enter a number to get Fibonacci : ");
  	int input =in.nextInt();
    EvenFebnauci object=new EvenFebnauci();
  	System.out.println("Fibonacci series  of "+ input + "is" );
    System.out.println("sum of all the series is"+object.fibonacci(input)) ;

  }	
   
}
    
