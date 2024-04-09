# Write your MySQL query statement below
select t2.id from weather as t1
join (select id,temperature,DATE_SUB(recordDate, INTERVAL 1 DAY) as rdate from weather) as t2
ON t1.recordDate = t2.rdate
where t1.temperature < t2.temperature;
