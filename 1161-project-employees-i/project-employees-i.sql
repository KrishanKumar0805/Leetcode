/* Write your T-SQL query statement below */
select p.project_id, round(avg(0.00 + e.experience_years),2) as average_years
from Project p right join Employee e on e.employee_id = p.employee_id
group by p.project_id having p.project_id is not null 