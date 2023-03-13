--ques1-Find courses that ran in Fall 2009 or in Spring 2010
(select course_id from section where semester='Fall' and year=2009)
union
(select course_id from section where semester='Spring' and year=2010);

--ques2- Find courses that ran in Fall 2009 and in spring 2010
(select course_id from section where semester='Fall' and year=2009)
intersect
(select course_id from section where semester='Spring' and year=2010);

--ques3-Find courses that ran in Fall 2009 but not in Spring 2010
(select course_id from section where semester='Fall' and year=2009)
minus
(select course_id from section where semester='Spring' and year=2010);

--ques4-Find the name of the course for which none of the students registered.
select title from course minus select course.title 
from course, takes 
where course.course_id=takes.course_id; 

--ques5-Find courses offered in Fall 2009 and in Spring 2010
select course_id, title from course 
where course_id in
(select course_id from section where semester='Fall' and year=2009) 
and course_id in
(select course_id from section where semester='Spring' and year=2010);

--ques6-Find the total number of students who have taken course taught by the instructor 
with ID 10101
select count(id) from takes
where course_id in
(select course_id from teaches where id=10101);

--ques7-Find courses offered in Fall 2009 but not in Spring 2010
select course_id, title from course where course_id in
(select course_id from section where semester='Fall' and year=2009)
and course_id not in
(select course_id from section where semester='Spring' and year=2010);

--ques8-Find the names of all students whose name is same as the instructor’s name.
select name from student
where name in (select name from instructor);

--ques9-Find names of instructors with salary greater than that of some (at least one) instructor
in the Biology department.
select name from instructor
where salary>some 
(select salary from instructor where dept_name='Biology');

--ques10-Find the names of all instructors whose salary is greater than the salary of all 
instructors in the Biology department.
select name from instructor
where salary>all
(select salary from instructor where dept_name='Biology');

--ques11-Find the departments that have the highest average salary
select dept_name from(select dept_name,avg(salary) avg_salary from instructor group by dept_name) 
where avg_salary = (select max(avg_salary) 
from (select dept_name,avg(salary) avg_salary 
from instructor group by dept_name));

--ques12-Find the names of those departments whose budget is lesser than the average salary 
of all instructors.
select dept_name from department where budget <all (select avg(salary) from instructor);

--ques13-Find all courses taught in both the Fall 2009 semester and in the Spring 2010 semester
select course_id from section s
where semester='Fall' and year=2009 and
exists (select course_id from section t 
where semester='Spring' and year=2010 and
s.course_id=t.course_id);

--ques14-Find all students who have taken all courses offered in the Biology department.
select name from student where exists
(select takes.ID from takes, course where 
takes.course_id = course.course_id and course.dept_name = 'Biology' and student.ID = takes.ID);

--ques15-Find all courses that were offered at most once in 2009.
select title from course where course_id in
(select course_id from section where year = 2009 
group by course_id
having count(course_id)<2);

--ques16-Find all the students who have opted at least two courses offered by CSE department.
select ID from (select ID, count(*) as c from takes 
natural join course where dept_name = 'Comp. Sci.' group by ID) where c >= 2;

--ques17-Find the average instructors salary of those departments where the average salary is 
greater than 42000
select dept_name, avg(salary) from instructor 
group by dept_name
having avg(salary)>42000;

--ques18-Create a view all_courses consisting of course sections offered by Physics 
department in the Fall 2009, with the building and room number of each section
create view all_courses as
select course.course_id, sec_id, building, room_number
from course, section
where course.course_id=section.course_id
and course.dept_name='Physics'
and section.semester='Fall'
and section.year=2009;

--ques19-Select all the courses from all_courses view
select course_id from all_courses;

--ques20-Create a view department_total_salary consisting of department name and total 
salary of that department
create view department_total_salary as 
(select dept_name, sum(salary) as total_salary 
from instructor group by dept_name);
--or
create view department_total_salary(dept_name, total_salary)
as select dept_name, sum(salary)
from instructor
group by dept_name;
