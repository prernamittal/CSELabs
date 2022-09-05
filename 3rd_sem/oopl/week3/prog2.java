import java.io.*;
class Time {
    int hr,min,sec;
    public void input (int hr,int min,int sec)
    {
        this.hr=hr;
        this.min=min;
        this.sec=sec;
    }
    public void add (Time obj1,Time obj2)
    {
        Time ob=new Time();
        ob.hr=obj1.hr+obj2.hr;
        ob.min=obj1.min+obj2.min;
        ob.sec=obj1.sec+obj2.sec;
        if (ob.sec>=60)
        {
            ob.min = ob.min+1;
            ob.sec = ob.sec-60;
        }
        if (ob.min>=60)
        {
            ob.hr = ob.hr+1;
            ob.min = ob.min-60;
        }
        if (ob.hr>=24)
        {
            ob.hr = ob.hr-24;
        }
        display(ob);
    }
    public void subtract (Time obj1, Time obj2)
    {
        Time ob = new Time();
        ob.hr=24-Math.abs(obj1.hr-obj2.hr);
        ob.min=Math.abs(obj1.min-obj2.min);
        ob.sec=Math.abs(obj1.sec-obj2.sec);
        if (ob.sec<=0)
        {
            ob.min = ob.min-1;
            ob.sec = ob.sec+60;
        }
        if (ob.min<=0)
        {
            ob.hr = ob.hr-1;
            ob.min = ob.min+60;
        }
        if (ob.hr<=0)
        {
            ob.hr = ob.hr+24;
        }
        display(ob);
    }
    public Time compare (Time obj1, Time obj2)
    {
        if(obj1.hr>obj2.hr)
            return obj1;
        else if(obj2.hr>obj1.hr)
            return obj2;
        else if(obj1.min>obj2.min)
            return obj1;
        else if(obj2.min>obj1.min)
            return obj2;
        else if(obj1.sec>obj2.sec)
            return obj1;       
        else if(obj2.sec>obj1.sec)
            return obj2;
        else 
        {
            if(obj1.min>obj2.min)
                return obj1;
            else if (obj2.min>obj1.min)
                return obj2;
                else{
                if(obj1.sec>obj2.sec)
                    return obj1;
                else 
                   return obj2;}
        }
    display(ob);
    }
    public void display (Time ob)
    {
        System.out.println(ob.hr+":"+ob.min+":"+ob.sec);
    }}
public class prog2
{
    public static void main(String[] args)
    {
        Time obj1=new Time();
        Time obj2 = new Time();
        obj1.input(2,59,59);
        obj2.input(3,5,6);
        obj1.add(obj1,obj2);
        obj2.subtract(obj1,obj2);
    }
}
