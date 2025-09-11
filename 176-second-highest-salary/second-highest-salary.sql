# Write your MySQL query statement below
with cte as 
(select salary,Dense_rank() over(order by salary desc ) as rn from 
Employee) 

select max(case when rn = 2 then salary end) 
as SecondHighestSalary from cte 