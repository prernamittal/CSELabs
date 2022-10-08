import java.io.*;
class Time {
    int hr,min,sec;
    public Time (int hr,int min,int sec)
    {
        this.hr=hr;
        this.min=min;
        this.sec=sec;
    }
    public Time ()
    {
        hr=0;
        min=0;
        sec=0;
    }
    public void display ()
    {
        System.out.println(this.hr+":"+this.min+":"+this.sec);
    }}
public class prog2
{
    public static void main(String[] args)
    {
        Time obj1=new Time(2,59,59);
        Time obj2 = new Time(3,5,9);
        obj1.display();
        obj2.display();
    }
}
