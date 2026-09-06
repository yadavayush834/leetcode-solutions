-- 176. Second Highest Salary
-- https://leetcode.com/problems/second-highest-salary/
-- Difficulty: Medium | Language: mysql
-- Runtime: 308 ms
-- Memory: 0B
-- Solved: 2026-04-19

select (
    select distinct a.salary
    from Employee a
    order by a.salary desc
    limit 1 offset 1
) as SecondHighestSalary;
