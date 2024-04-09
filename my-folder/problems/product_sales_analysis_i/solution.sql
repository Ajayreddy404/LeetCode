# Write your MySQL query statement below
select t2.product_name, t1.year, t1.price
from Sales as t1
join Product as t2
ON t1.product_id = t2.product_id;