/* Write your T-SQL query statement below */
select e.name  from Employee e  where (
    select count(*) from Employee ee where ee.managerId = e.id
     
) >= 5