# Write your MySQL query statement below
select t1.student_id, t1.student_name, t1.subject_name, ifnull(t2.attended_exams,0) attended_exams from
(select * 
from Students
cross join Subjects) as t1
left join
(select student_id, subject_name, count(*) as attended_exams
from Examinations
group by student_id, subject_name) as t2
ON t1.student_id = t2.student_id and t1.subject_name = t2.subject_name
order by student_id, subject_name;