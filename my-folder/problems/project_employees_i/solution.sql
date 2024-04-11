# Write your MySQL query statement below
select project_id, round(sum(experience_years)/count(t2.employee_id),2) average_years
from Project as t1
left join employee as t2
on t1.employee_id = t2.employee_id
where experience_years is not null
group by project_id;