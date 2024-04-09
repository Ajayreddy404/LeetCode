select t1.machine_id, round(sum(t2.timestamp-t1.timestamp)/count(t1.machine_id),3) processing_time
from
(select machine_id, process_id, timestamp from Activity where activity_type = 'start') as t1
join
(select machine_id, process_id, timestamp from Activity where activity_type = 'end') as t2
ON t1.process_id = t2.process_id and t1.machine_id = t2.machine_id
group by machine_id;