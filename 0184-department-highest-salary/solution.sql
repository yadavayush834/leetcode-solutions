-- 184. Department Highest Salary
-- https://leetcode.com/problems/department-highest-salary/
-- Difficulty: Medium | Language: mysql
-- Runtime: 708 ms
-- Memory: 0B
-- Solved: 2026-04-19

select 
  b.name as Department,
  a.name as Employee,
  a.salary as Salary
from Employee a
join Department b
on a.departmentId = b.id
where (a.departmentId, a.salary) in (
  select 
    c.departmentId,
    max(c.salary)
  from Employee c
  group by c.departmentId
);
