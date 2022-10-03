class Building
{
    int sq, story;
    public void Sq(int sq)
	{
	   this.sq = sq;
	}
	public void Story(int story)
	{
	    this.story = story;
	}
	public int getStory()
	{
        return story;
	}
	public int getSq()
	{
        return sq;
	}
}
class House extends Building
{
    int bedroom,bath;

	public void Bedroom(int bedroom)
	{
	   this.bedroom = bedroom;
	}
	public void Bath(int bath)
	{
	    this.bath = bath;
	}
	public int getBedroom()
	{
        return bedroom;
	}
	public int getBath()
	{
        return bath;
	}
}
class School extends Building
{
    int classroom;
    String grade;
    public void Classroom(int classroom)
	{
	   this.classroom = classroom;
	}
	public void Grade(String grade)
	{
	    this.grade = new String(grade);
	}
	public int getClassroom()
	{
        return classroom;
	}
	public String getGrade()
	{
        return grade;
	}
}
public class prog2
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