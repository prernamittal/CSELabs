--ques1-Find the number of students in each course
select title, count(distinct t.id) as num_students
from takes t, student s, course c
where t.id=s.id and t.course_id=c.course_id and s.dept_name=c.dept_name
group by title;

--ques2-Find those departments where the average number of students are greater than 10.
select dept_name, count(id) from student
group by dept_name
having count(id)>10; --no rows for 10

--ques3-Find the total number of courses in each department.
select dept_name,count(course_id) 
from course 
group by dept_name;

--ques4
select dept_name,avg(salary) as avg_salary
from instructor group by dept_name 
having avg(salary)>42000;

--ques5
select sec_id,count(ID) from takes
where semester='Spring' and year=2009 
group by sec_id;

--ques6
select course_id, prereq_id
from prereq 
order by course_id asc;

--ques7
select * from instructor
order by salary desc;

--ques8
select max(sum(salary)) as max_salary
from instructor group by dept_name;

--ques9
select dept_name, avg_salary 
from(select dept_name,avg(salary) as avg_salary 
from instructor group by dept_name) 
where avg_salary>42000;

--ques10
select sec_id, enrollment from(select sec_id,count(ID) as enrollment
from takes where semester='Spring' and year=2010 group by sec_id) 
where enrollment >=all(select count(ID) as enrollment from takes 
where semester='Spring' and year=2010 group by sec_id);

--ques11
select distinct name from instructor natural join teaches
where course_id in (select course_id from 
student natural join takes where dept_name='Comp. Sci.');

--ques12
select dept_name,total,avg_salary from
(select dept_name,count(id) as total,avg(salary) as avg_salary 
from instructor group by dept_name 
having count(ID)>5 and avg(salary)>5000); --no rows for 5

--ques13
with bud(val) as (select max(budget) from department)
select dept_name,budget from bud,department where bud.val=department.budget;

--ques14
with tot(dept_name,total) as (select dept_name,sum(salary) as tot 
from instructor group by dept_name), aver(val) as (select avg(total) from tot) 
select dept_name, total from tot, aver
where total>val;

--ques17
savepoint ques17;
delete from instructor where dept_name = 'Finance';

--ques18
savepoint ques18;
delete from course where dept_name='Comp. Sci.';