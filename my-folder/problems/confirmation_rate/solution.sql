select t1.user_id, if(t3.count = 0,0, ifnull(round(t3.count/t2.count,2),0)) confirmation_rate
from Signups as t1
left join (select user_id, count(user_id) count from confirmations group by user_id) as t2
on t1.user_id = t2.user_id
left join (select user_id, count(user_id) count from confirmations where action = 'confirmed' group by user_id ) as t3
on t1.user_id = t3.user_id;