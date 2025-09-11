CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
--  set n = n-1;
  RETURN (
      # Write your MySQL query statement below.
      with cte as (
        select id, salary, 
        dense_rank() over(order by salary desc) as rn
        from Employee
      )
    
        select max(case when rn = n then salary end)from cte 
  );
END