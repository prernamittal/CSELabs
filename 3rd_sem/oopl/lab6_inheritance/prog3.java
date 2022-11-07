import java.util.*;
abstract class figure
{
    int x,y;
    abstract void area();
}
class rectangle extends figure
{
    rectangle(int l, int b)
    {
        x=l; y=b;
    }
    void area()
    {
        System.out.println("Area is "+ x*y);
    }
}
class triangle extends figure
{
    triangle(int b, int h)
    {
        x=b; y=h;
    }
    void area()
    {
        System.out.println("Area is "+ 0.5*x*y);
    }
}
class square extends figure
{
    square(int a)
    {
        x=a;
    }
    void area()
    {
        System.out.println("Area is "+ x*x);
    }
}
public class prog3
{
    public static void main(String[] args)
    {
        int choice;
        Scanner sc = new Scanner(System.in);
        do
        {
            System.out.println("1. Rectangle\t2.Triangle\t3.Square\t4. Exit\nEnter choice:");
            choice=sc.nextInt();
            System.out.println("Enter x: ");
            int x=sc.nextInt();
            System.out.println("Enter y: ");
            int y=sc.nextInt();    
            switch(choice)
            {
                case 1:
                rectangle r=new rectangle(x,y);
                r.area();
                break;

                case 2:
                triangle t=new triangle(x,y);
                t.area();
                break;

                case 3: 
                square s=new square(x);
                s.area();
                break;
            }
        } while(choice !=4);
        sc.close();
    }
}
