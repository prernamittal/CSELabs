//incomplete (no input)
import java.util.*;
class Student
{
    int id;
    String name;
    Student()
    {
        name=" ";
        id=0;
    }
    class Sports
    {
        int sgrade;
        Sports()
        {
            sgrade=0;
        }
    }
    class Exam
    {
        int egrade;
        Exam()
        {
            egrade=0;
        }
    }
}
class Result extends Student
{
    Sports ss= new Sports();
    Exam se= new Exam();
    void display()
    {
        System.out.println("Result is:\n name:"+name+"\ns grade:"+ss.sgrade+"\ne grade: "+se.egrade);
    }
}
public class prog4
{
    public static void main(String[] args)
    {
        Result r=new Result();
        r.display();
    }
}