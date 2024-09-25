select 
activity_date as day, 
count(distinct concat(convert(user_id,char),"$",convert(activity_date,char))) active_users
from Activity
group by activity_date
having activity_date <= convert('2019-07-27',DATE)
and activity_date > convert('2019-06-27',DATE)
order by activity_date;