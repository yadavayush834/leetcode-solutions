-- 182. Duplicate Emails
-- https://leetcode.com/problems/duplicate-emails/
-- Difficulty: Easy | Language: mysql
-- Runtime: 360 ms
-- Memory: 0B
-- Solved: 2026-04-19

select 
  a.email as Email
from Person a
group by a.email
having count(a.email) > 1;
