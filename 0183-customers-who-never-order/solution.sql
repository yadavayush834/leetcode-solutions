-- 183. Customers Who Never Order
-- https://leetcode.com/problems/customers-who-never-order/
-- Difficulty: Easy | Language: mysql
-- Runtime: 607 ms
-- Memory: 0B
-- Solved: 2026-04-19

select 
  a.name as Customers
from Customers a
left join Orders b
on a.id = b.customerId
where b.id is null;
