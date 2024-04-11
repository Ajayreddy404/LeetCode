# Write your MySQL query statement below
select t2.product_id, if(sum(units) is null,0,round(sum(price*units)/sum(units),2)) average_price
from UnitsSold as t1
right join Prices as t2
on t1.product_id = t2.product_id and purchase_date >= start_date
and purchase_date <=end_date
group by t2.product_id;