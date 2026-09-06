-- 1068. Product Sales Analysis I
-- https://leetcode.com/problems/product-sales-analysis-i/
-- Difficulty: Easy | Language: mysql
-- Runtime: 1243 ms
-- Memory: 0B
-- Solved: 2026-04-18

select b.product_name, a.year, a.price
from Sales a
join Product b
on a.product_id = b.product_id;
