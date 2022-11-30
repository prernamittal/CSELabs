import java.util.*;
public class extra1
{
    public static <T> void PrintArray(T[] input)
    {
        for (T ele: input)
        {
            System.out.println(ele);
        }
    }
    public static void main(String[] args)
    {
        int choice;
        Scanner sc = new Scanner(System.in);
        do{
        System.out.println("1.Integer\n2.Double\n3.String\nEnter choice: ");
        choice = sc.nextInt();
        System.out.println("Enter length: ");
        int len=sc.nextInt();
        switch(choice){
        case 1:
        Integer iarr[]=new Integer[len];
        System.out.println("Enter ele: ");
        for(int i=0;i<len;i++)
        {
            iarr[i]=sc.nextInt();
        }
        System.out.println("Array is: ");
        PrintArray(iarr);
        break;

        case 2:
        Double darr[]= new Double[len];
        System.out.println("Enter ele: ");
        for(int i=0;i<len;i++)
        {
            darr[i]=sc.nextDouble();
        }
        System.out.println("Array is: ");
        PrintArray(darr);
        break;

        case 3:
        String sarr[]=new String[len];
        System.out.println("Enter ele: ");
        for(int i=0;i<len;i++)
        {
            sarr[i]=sc.next();
        }
        System.out.println("Array is: ");
        PrintArray(sarr);
        break;
        }
    }while(choice!=4);
}
}