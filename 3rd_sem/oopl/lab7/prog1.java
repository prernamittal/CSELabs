import com.course.structure.*;
public class prog1
{
    public static void main(String[] args)
    {
        Building b = new Building();
        b.Sq(6000);
        b.Story(6);
        System.out.println("Building details: " + b.getSq() + "\n" + b.getStory());

        House h = new House();
        h.Bedroom(3);
        h.Bath(2);
        System.out.println("House details: " + h.getBedroom() + "\n"+ h.getBath());
        School s = new School();
        s.Classroom(508);
        s.Grade("elementary");
        System.out.println("School details: " + s.getClassroom() +"\n"+ s.getGrade());

    }
}