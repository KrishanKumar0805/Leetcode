select w2.id
from weather w1
join weather w2 
  on w2.recordDate = date_add(w1.recordDate, interval 1 day)
where w2.temperature > w1.temperature;
