class Threefivemultiple {
  public static void main(String[] args) {
    Threefivemultiple m=new Threefivemultiple();
    int tot=m.doStuff();
    System.out.println("The total is :"+tot);
  }

 private int doStuff()
{
 int total_sum = 0;
for(int i=0;i<1000;i++) {
if (i%3 == 0 || i%5 == 0)
{total_sum = total_sum+i;}
  
}   
return total_sum;   
}
}
   
