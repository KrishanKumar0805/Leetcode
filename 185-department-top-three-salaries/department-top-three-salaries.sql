# Write your MySQL query statement below
with cte as (
select id,dense_rank() 
    over(partition by departmentId order by salary desc)
    as rn from Employee
)

select d.name as Department ,e.name as Employee,e.salary as Salary from 
Employee e join Department d 
on e.departmentId = d.id where e.id in(
    select id from cte where rn <= 3 
)