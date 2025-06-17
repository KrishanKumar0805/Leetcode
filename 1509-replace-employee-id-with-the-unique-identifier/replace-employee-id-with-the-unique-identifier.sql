
select e.unique_id,es.name from EmployeeUNI e
full outer join Employees es on  es.id = e.id
where es.name is not null 
/* Write your T-SQL query statement below */
