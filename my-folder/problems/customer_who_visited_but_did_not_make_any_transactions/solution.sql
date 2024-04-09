# Write your MySQL query statement below
select customer_id, count(customer_id) as count_no_trans
from Visits as t1
left join Transactions as t2
ON t1.visit_id = t2.visit_id
where transaction_id is null
group by customer_id;