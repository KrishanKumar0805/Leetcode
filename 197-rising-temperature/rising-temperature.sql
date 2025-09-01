# Write your MySQL query statement below
select id from
(select id,recordDate,temperature,
lag(temperature) over(order by recordDate) as prev_temp,
lag(recordDate) over(order by recordDate) as prev_date
from weather) t
where temperature > prev_temp and datediff(recordDate, prev_date) = 1

