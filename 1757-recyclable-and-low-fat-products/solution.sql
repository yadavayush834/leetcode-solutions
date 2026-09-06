-- 1757. Recyclable and Low Fat Products
-- https://leetcode.com/problems/recyclable-and-low-fat-products/
-- Difficulty: Easy | Language: mysql
-- Runtime: 488 ms
-- Memory: 0B
-- Solved: 2026-04-18

select product_id
from Products
where low_fats = 'Y' and recyclable = 'Y';
