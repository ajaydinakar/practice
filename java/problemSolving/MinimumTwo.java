public class MinimumTwo {
    public static void main(String args [])
    {
        int array []={3,5,6,4,2,1};
       int min1 =2147483646;
       int min2=2147483647;
       for (int i :array)
       {
           if (i<min1)
           {
               min2=min1;
               min1=i;
           }
           else if(i<min2)
           {
               min2=i;
           }
       }
        System.out.println("least numbers in the array are " + min1 + " and "+min2);

    }
}
