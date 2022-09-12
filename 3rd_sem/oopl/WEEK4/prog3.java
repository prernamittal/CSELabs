import java.util.Scanner;
class BankAccount
{
    String name,type;
    long acc;
    double bal;
    static double rate=5.5;

public BankAccount()
{
    name=null;
    acc=0;
    type=null;
    bal=0.0;
    rate=5.5;
}
public BankAccount (String n, long ac, String t, double b)
{
    name=n;
    acc=ac;
    type=t;
    bal=b;
}
public void dep(double amt)
{
    bal+=amt;
    System.out.println("Adding amount...");
    display();
}
public void withdraw(double amt)
{
    if ((bal-amt)<1000)
    {
        System.out.println("can't be withdrawn");
        System.exit(0);
    }
    else 
    {
        bal-=amt;
        System.out.println("Removing amount");
        display();
    }
}
public void display()
{
    System.out.println("Name: " + name);
    System.out.println("Acc No: " + acc);
    System.out.println("Type of acc: " + type);
    System.out.println("Balance: " + bal);
    System.out.println("ROI: " + rate);
}
public static void displayrate()
{
    System.out.println("Static ROI: "+ rate);
}
}
class prog3
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name: ");
        String n = sc.next();
        System.out.println("Enter Acc no.: ");
        long ac = sc.nextLong();
        System.out.println("Enter Type of acc: ");
        String t = sc.next();
        System.out.println("Enter balance: : ");
        double b = sc.nextDouble();
        System.out.println("Enter amt to deposit : ");
        double amt = sc.nextDouble();
        System.out.println("Enter amt to withdraw : ");
        double am = sc.nextDouble();

        BankAccount ba = new BankAccount();
        BankAccount ba1 = new BankAccount(n,ac,t,b);
        ba1.dep(amt);
        ba1.withdraw(am);
        BankAccount.displayrate();
    }
}
