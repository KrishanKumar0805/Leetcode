WITH t AS (
  SELECT id,
         num,
         id - ROW_NUMBER() OVER (PARTITION BY num ORDER BY id) AS grp
  FROM Logs
)
, cte as (
    select num from t 
    group by num, grp
    having count(*) >= 3 
)
SELECT distinct num AS ConsecutiveNums
from cte