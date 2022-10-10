package com.course.structure;
public class School
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
