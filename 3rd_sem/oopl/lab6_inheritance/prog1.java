//incomplete
import java.util.*;
import java.text.*;
import java.io.*;
class Person{
    private String name;
    private int date,  month, year;
    public String getname(){
        return name;
    }
    public int[] getdob(){
        int arr[]={date, month, year};
        return arr;
    }
    Person()
    {
    }
    public Person(String name, int date, int month, int year)
    {
        this.name=name;
        this.date=date;
        this.month=month;
        this.year=year;
    }
    public void input()
    {
        Scanner sc =  new Scanner(System.in);
        System.out.println("Enter name: ");
        name=sc.next();
    }
    public void display()
    {
        System.out.println("Name: "+name);
        System.out.println("DOB: ");
    }
}
class CollegeGraduate extends Person{
    private int gpa;
    private int year;
    public int gpa(){
        return gpa;
    }
    public int year(){
        return year;
    }
    public CollegeGraduate(int gpa, int year)
    {
        this.gpa=gpa;
        this.year=year;
    }



}
