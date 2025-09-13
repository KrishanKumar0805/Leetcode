WITH t AS (
  SELECT id,
         num,
         id - ROW_NUMBER() OVER (PARTITION BY num ORDER BY id) AS grp
  FROM Logs
)
SELECT distinct num AS ConsecutiveNums
FROM (
  SELECT num, grp, COUNT(*) AS streak_len
  FROM t
  GROUP BY num, grp
) s
WHERE streak_len >= 3;
