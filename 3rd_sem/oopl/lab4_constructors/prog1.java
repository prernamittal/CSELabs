import java.lang.*;

class Complex
{
    double real, img;
    public Complex(double real,double img)
    {
        this.real=real;
        this.img=img;
    }
    public Complex()
    {
        real=0;
        img=0;
    }

    public void display()
    {
        System.out.println("\nResult is \n" + this.real+"+" +this.img+"i");
    }
}
class prog1
{
    public static void main (String[] args)
    {
        Complex n1 = new Complex(2.3,4.5);
        Complex n2 = new Complex(3.4,5.0);
        n1.display();
        n2.display();
    }
}