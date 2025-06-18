/* Write your T-SQL query statement below */
with cte as (
    select count(user_id) as cnt  from Users 
)

select r.contest_id , round((count(r.user_id)*100.00)/cte.cnt,2)  as percentage 
from Users u 
right join Register r on r.user_id = u.user_id cross join cte
group by r.contest_id,cte.cnt
order by percentage desc , r.contest_id