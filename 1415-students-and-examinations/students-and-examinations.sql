/* Write your T-SQL query statement below */
select s.student_id,s.student_name,sb.subject_name,(
select count(*) from Examinations e where 
s.student_id = e.student_id and sb.subject_name = e.subject_name 

) as attended_exams 
from Students s   cross join Subjects sb  
group by s.student_id,s.student_name , sb.subject_name 
order by s.student_id, sb.subject_name 