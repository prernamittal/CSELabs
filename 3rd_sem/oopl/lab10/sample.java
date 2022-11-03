class Gen<T>
{
    T ob;
    Gen(T o)
    {
        ob=o;
    }
    T getob()
    {
        return ob;
    }
    void display()   
    {
        System.out.println("Type of T is:"+ob.getClass().getName());
    }
}
public class sample
{
    public static void main(String[] args)
    {
        Gen<Integer>iob;
        iob=new Gen<Integer>(99);
        iob.display();
        int val=iob.getob();
        System.out.println("Value is "+val);
        Gen<String>strob=new Gen<String>("Sample Program");
        strob.display();
        String str=strob.getob();
        System.out.println("Value is "+str);
    }
}