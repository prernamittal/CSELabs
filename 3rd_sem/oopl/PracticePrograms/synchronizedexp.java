import java.util.*;
class customer
{
    synchronized void withdraw(int amount,int dep)
    {
        System.out.println("Withdrawing");
        if(amount<dep){
            System.out.println("Failed. Insufficient Balance");
        try
        {
            wait();
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupted");
        }
        }amount-=dep;
        System.out.println("withdraw successful");
    }
    synchronized void deposit(int amount, int wit){
        System.out.println("going to deposit");
        amount+=wit;
        System.out.println("money deposited");
        notify();
    }
}
public class synchronizedexp
{
    public static void main(String[] args){
        customer c = new customer();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter amount in account: ");
        int amount=sc.nextInt();
        System.out.println("Enter amount to be deposited: ");
        int dep= sc.nextInt();
        System.out.println("Enter amount to withdraw: ");
        int wit=sc.nextInt();
        new Thread(){
            public void run(){
                c.deposit(amount,dep);
            }
        }.start();          

        new Thread(){
            public void run(){
                c.withdraw(amount,wit);                
            }
        }.start();
        sc.close();
    }
}