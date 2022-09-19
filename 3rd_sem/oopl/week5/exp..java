import java.util.*;
import java.text.*;
class Student 
{
    int reg_no;
    String name;
    GregorianCalendar date;
    short sem;
    float gpa, cgpa;
    Student()
    {
        reg_no=0;
        name = "";
        date = new GregorianCalendar();
        sem = 0;
        gpa = 0.f;
        cgpa = 0.f;
    }
    Student(Student s)
    {
        this.reg_no = s.reg_no;
        this.name = s.name;
        this.date = s.date;
        this.sem = s.sem;
        this.gpa = s.gpa;
        this.cgpa = s.cgpa;
    }
    public void display
    {
        Format = 
    }
}
