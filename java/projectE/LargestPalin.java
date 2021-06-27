import java.util.*;

class LargestPalin {


public static void main(String args[])
{
int number =0 ,reverse=0;

    Set<Integer> palin=new HashSet<Integer>();      
        for(int i=999;i>=100;i--)
        {
          for(int j=999;j>=100;j--)
          {
            number=i*j;
        reverse=LargestPalin.convertReverse(number); 
            if(number==reverse)
            {
              palin.add(number);
            }
          }
        }
System.out.println(Collections.max(palin));
}

static int convertReverse(int num)
	{
		int digit=0,reverse=0;
        while(num!=0)
		{
			digit = num%10;
            reverse = reverse*10 + digit;
            num /= 10;
		}
		return reverse;
	}


}

    
