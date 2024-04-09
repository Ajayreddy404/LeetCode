# Write your MySQL query statement below
select name, bonus
from employee as e
left join Bonus as b
ON e.empId = b.empId
where bonus < 1000 or bonus is null;