import java.util.Scanner;
class Counter
{
    static int count=0;
    Counter()
    {
        count++;
    }
    public static void display()
    {
        System.out.println("Count= "+count);
    }
}
class prog4
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Number of objects: ");
        int n = sc.nextInt();
        Counter obj[]=new Counter[n];
        for(int i=0; i<n;i++)
        {
            obj[i]=new Counter();
            Counter.display();
        }

    }
}