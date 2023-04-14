create table books(
bid number(10) primary key,
bname varchar(20),
publisher varchar(10),
cost number(5));

create table members(
mid number(10) primary key,
mname varchar(20),
address varchar(30),
phone number(10),
birthdate date);

create table issue_return(
bid number(10),
mid number(10),
issue_date date primary key,
return_date date,
foreign key(bid) references books,
foreign key(mid) references members);

insert into books values(1234, 'prerna', 'schand', 250);
insert into books values(2234, 'pre', 'sch', 450);
insert into books values(1334, 'prena', 'and', 450);
insert into books values(4434, 'rna', 'hand', 550);

insert into members values(7890, 'anay', 'pune', 3456, '16-may-23');
insert into members values(8890, 'aay', 'pun', 4456, '18-may-23');
insert into members values(9890, 'nay', 'pue', 5456, '23-may-23');
insert into members values(1890, 'ana', 'pne', 2456, '11-may-23');

insert into issue_return values(1234, 7890, '16-may-23', '18-may-23');
insert into issue_return values(1234, 7890, '18-may-23', '20-may-23');
insert into issue_return values(1234, 7890, '20-may-23', '22-may-23');
insert into issue_return values(2234, 9890, '21-may-23', '23-may-23');
insert into issue_return values(1334, 8890, '19-may-23', '28-may-23');

--ques1
select distinct bname from issue_return i, books b
where b.bid not in(select i.bid from issue_return i);
--or
select distinct bname from books where bid not in (select bid from issue_return);

--ques2
select bname from books
where bid in
(select bid from issue_return 
group by bid
having count(issue_date)>1);

--ques3
select bname, cost from books where cost in(
select max(cost) cost from books 
where cost<(select max(cost) from books));

--new table
create table parts(
partno number(5) primary key,
partname varchar(10),
vehicletype varchar(2) not null check(vehicletype in('v1','v2','v3','v4','v5')),
unitprice number(10) check(unitprice>0),
salesprice number(10) check(salesprice>0));

create table service(
serviceno number(10),
partno number(5),
servicedate date,
customerno varchar(3),
qty number(3),
primary key(serviceno, partno),
foreign key(partno) references parts(partno));

insert into parts values(1,'p1','v1',10,12);
insert into parts values(2,'p2','v2',100,110);
insert into parts values(3,'p3','v3',150,175);
insert into parts values(4,'p4','v4',200,250);
insert into parts values(5,'p5','v5',75,90);

insert into service values(1,1,'01-Jan-17','c1',5);
insert into service values(1,3,'01-Jan-17','c1',4);
insert into service values(2,3,'05-Feb-18','c2',10);
insert into service values(3,1,'15-May-18','c3',9);
insert into service values(4,1,'03-Jun-19','c1',5);

--ques1
select partname, partno from parts where partno not in (select partno from service);

--ques2
select customerno from service
group by customerno 
having 

--PYP-2021
create table tourist(
cust_id number(5),
name varchar(15),
aadhar number(10),
age number(2));

create table transport(
vehicle_id number(10),
driver varchar(15),
type varchar(10) check(type in('car','flight','bus','train')));

create table agent(
id number(10),
rating number(1),
cust_id number(5));

create table booking(
booking varchar(10),
payment number(1) check(payment in(0,1,2)),
cust_id number(5),
scheme varchar(15) check(scheme in('gold','silver','platinum')));

create table travel_details(
cust_id number(5),
days number(2),
source varchar(10),
destination varchar(30));

drop table tourist;
drop table transport;
drop table agent;
drop table booking;
drop table travel_details;

insert into tourist values(1234,'prerna',12,12);
insert into tourist values(1224,'prera',22,09);
insert into tourist values(1214,'prna',13,05);
insert into tourist values(1124,'pena',11,64);
insert into tourist values(2124,'sanath',18,24);

insert into transport values(7980, 56, 'car');
insert into transport values(8980, 46, 'bus');
insert into transport values(9980, 76, 'train');
insert into transport values(9780, 66, 'flight');

insert into agent values(100,5,1234);
insert into agent values(100,5,1224);
insert into agent values(104,5,1224);
insert into agent values(102,4,1214);
insert into agent values(103,3,1124);

insert into booking values('done',0,1124,'gold');
insert into booking values('pending',0,1234,'silver');
insert into booking values('done',1,1224,'gold');
insert into booking values('done',2,1214,null);

insert into travel_details values(1234, 5, 'Bengaluru', 'Himachal Pradesh');
insert into travel_details values(1234, 6, 'Bengaluru', 'Pradesh');
insert into travel_details values(1224, 4, 'Bengaluru', 'Andhra');
insert into travel_details values(1214, 3, 'luru', 'Uttar Pradesh');
insert into travel_details values(1124, 4, 'Bengal', 'Arunachal Pradesh');

--ques1
select name, age from tourist t, travel_details td
where t.cust_id=td.cust_id and source='Bengaluru' and destination='Himachal Pradesh';

--ques2
select distinct id from agent
where rating=(select max(rating) from agent)
group by id 
having count(cust_id)=(select max(count(cust_id)) from agent group by id);

--ques3
select distinct name from tourist, booking
where age>59 and scheme='gold';

--ques4
select distinct name from tourist t, booking b
where t.cust_id not in (select b.cust_id from booking b );
--or
select distinct name from tourist t, booking b
where t.cust_id=b.cust_id and b.scheme is null;

--ques1
select t.name from tourist t, agent a, booking b
where a.id=103 and b.payment=0 and
a.cust_id=b.cust_id and t.cust_id=b.cust_id;

--ques2
select distinct destination from travel_details
where source='Bengaluru'
and days=(select max(days) from travel_details);

--ques3



