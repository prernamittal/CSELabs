//incomplete
import java.util.*;
import java.text.*;
class Person{
    private String name;
    GregorianCalendar date;
    public Person(String name, int d, int m, int y)
    {
        this.name=name;
        this.date = new GregorianCalendar(d,m,y);
    }
    Person()
    {
        date = new GregorianCalendar();
        name="";
    }
    Person(Person p)
    {
        this.name=p.name;
        this.date=p.date;
    }
    public String getname()
    {
        return name;
    }
    public GregorianCalendar getdate()
	{
		return date;
	}
    public void input()
    {
        Scanner sc =  new Scanner(System.in);
        System.out.println("Enter name: ");
        name=sc.next();
        System.out.println("Enter date: ");
        date = new GregorianCalendar(sc.nextInt(), sc.nextInt(), sc.nextInt());
    }
    public void display()
    {
		SimpleDateFormat dateFormat = new SimpleDateFormat("MMM,dd,yyyy");
		System.out.println("Name : " + name + "||" + "DOB : " + dateFormat.format(date.getTime()));
    }
}
class CollegeGraduate extends Person{
    private int gpa;
    private int year;
    public int getgpa(){
        return gpa;
    }
    public int getyear(){
        return year;
    }
    public CollegeGraduate(int gpa, int year)
    {
        this.gpa=gpa;
        this.year=year;
    }
    public CollegeGraduate()
    {
        this.gpa=0;
        this.year=0;
    }
    public void input()
    {
        Scanner sc =  new Scanner(System.in);
        System.out.println("Enter gpa: ");
        gpa=sc.nextInt();
        System.out.println("Enter year: ");
        year=sc.nextInt();

    }
    public void display()
    {
        System.out.println("GPA: "+gpa+" year of joining: "+year);
    }
}
public class prog1_alt
{
    public static void main(String[] args)
    {
        int choice;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 1:Person  2:CollegeGraduate");
        choice = sc.nextInt();
        if(choice==1)
        {
            Person p = new Person("Abc",5,6,7);
			p.input();
			p.display();
        }
        else if(choice==2)
        {
            CollegeGraduate clg = new CollegeGraduate();
            clg.input();
            clg.display();
        }
    }
}
