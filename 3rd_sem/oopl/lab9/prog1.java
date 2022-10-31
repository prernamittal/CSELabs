import java.util.*;
class Tables extends Thread
{
    String table="";
    int n;
    Tables(int x)
    {
        this.n=x;
        this.table="";
        start();

    }
    public void run()
    {
        for( int i=1; i<=10;i++)
        {
            table=table+" "+(i*n);
        }
    }
}
public class prog1
{
    public static void main(String[] args)
    {
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter n: ");
        int n=sc.nextInt();
        Tables obj1 = new Tables(5);
        Tables obj2 = new Tables(7);
        Tables objn = new Tables(n);
        try{
            System.out.println("Sleeping");
            Thread.sleep(1000);
        }
        catch(InterruptedException e) {
            System.out.println("Interrupted..");
        }
        System.out.println("Table of 5: "+obj1.table);
        System.out.println("Table of 7: "+obj2.table);
        System.out.println("Table of"+n +" :" +objn.table);


    }
}