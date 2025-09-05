# Write your MySQL query statement below
select a1.machine_id,
round((sum(a1.timestamp-a2.timestamp)/count(a1.process_id)),3)
as processing_time
from Activity a1 join Activity a2
on a1.machine_id = a2.machine_id 
where a1.activity_type = 'end'  and a2.activity_type = 'start'
group by a1.machine_id