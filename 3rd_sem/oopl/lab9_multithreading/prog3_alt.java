import java.util.*;
class shop
{
    int materials;
    boolean available = false;
    public synchronized int get()
    {
        while (available==false)
        {
            try
            {
                wait();
            }
            catch (InterruptedException e)
            {
                System.out.println("Interrupted");
            }
        }
        available = false;
        notifyAll();
        return materials;
    }
    public synchronized void put(int value)
    {
        while (available==true)
        {
            try
            {
                wait();
            }
            catch (InterruptedException e)
            {
                System.out.println("Interrupted");
            }
        }
        materials = value;
        available = true;
        notifyAll();
    }
}
class cons extends Thread
{
    shop shop;
    int n;
    public cons(shop s)
    {
        shop = s;
    }
    void setn(int n)
    {
        this.n=n;        
    }
    public void run()
    {
        int value = 0;
        for (int i=0; i<n; i++)
        {
            value = shop.get();
            System.out.println("Consumer got: " + value);
        }
    }
}
class prod extends Thread
{
    shop shop;
    int n;
    public prod(shop s)
    {
        shop = s;
    }
    void setn(int n)
    {
        this.n=n;        
    }
    public void run()
    {
        for (int i=0; i<n; i++)
        {
            shop.put(i);
            System.out.println("Producer got: " + i);
            try
            {
                sleep((int)(Math.random()*100));
            }
            catch (InterruptedException e)
            {
                System.out.println("Interrupted");
            }
        }
    }
}
public class prog3_alt
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter n: ");
        int n = sc.nextInt();
        shop s = new shop();
        prod p = new prod(s);
        p.setn(n);
        cons c = new cons(s);
        c.setn(n);
        p.start();
        c.start();
    }
}
