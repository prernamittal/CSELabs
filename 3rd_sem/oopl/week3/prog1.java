import java.lang.*;

class Complex
{
    double real=0, img=0;
    public Complex(double real,double img)
    {
        this.real=real;
        this.img=img;
    }
    public void display(Complex temp)
    {
        System.out.println("\nResult is \n" + temp.real+"+" +temp.img+"i");
    }
    public Complex add(Complex n1, Complex n2)
    {
        Complex temp = new Complex(0.0,0.0);
        temp.real=n1.real+n2.real;
        temp.img=n1.img+n2.img;
        return temp;
    }
    public Complex subtract(Complex n1,Complex n2)
    {
        Complex temp=new Complex(0.0,0.0);
        temp.real = Math.abs(n1.real-n2.real);
        temp.img = Math.abs(n1.img-n2.img);
        display(temp);
        return temp;
    }
}
class ComplexDemo
{
    public static void main (String[] args)
    {
        Complex n1 = new Complex(2.3,4.5);
        Complex n2 = new Complex(3.4,5.0);
        Complex temp = new Complex(0,0);
        temp.add(n1,n2);
        temp.subtract(n1,n2);
    }
}




