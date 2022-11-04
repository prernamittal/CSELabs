//using generic method
import java.util.*;
class prog1
{
    static <T> void display(T arr[])
    {
        for(int i=0;i<arr.length;i++)
        {
            System.out.println(arr[i]);
        }
    }
    static <T> void swap(T arr[], int x, int y)
    {
        T temp;
        temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
    public static void main(String[] args)
    {
        int choice;
        Scanner sc =new Scanner(System.in);
        do
        {
            System.out.println("Enter choice: \n1.Integer\n2.String\n");
            choice=sc.nextInt();
            System.out.println("Enter length: ");
            int len=sc.nextInt();
            System.out.println("exchange this index:");
            int i1=sc.nextInt();
            System.out.println("with this index: ");
            int i2=sc.nextInt();
    
            switch(choice)
            {
                case 1:
                Integer iarr[]=new Integer[len];
                System.out.println("Enter ele: ");
                for(int i=0;i<len;i++)
                {
                    iarr[i]=sc.nextInt();
                }
                swap(iarr,i1,i2);
                System.out.println("New array is: ");
                display(iarr);
                break;

                case 2:
                String sarr[]=new String[len];
                System.out.println("Enter ele: ");
                for(int i=0;i<len;i++)
                {
                    sarr[i]=sc.next();
                }
                swap(sarr,i1,i2);
                System.out.println("New array is: ");
                display(sarr);
                break;

            }
        } while(choice!=3);
        
        //test
        // Integer []iarr ={1,2,3,4};
        // swap(iarr,1,2);
        // for(Integer i:iarr)
        // System.out.println(i+" ");

        // String []sarr={"one","two","three","four"};
        // swap(sarr,3,2);
        // for(String s:sarr)
        // System.out.println(s+" ");
    }
}