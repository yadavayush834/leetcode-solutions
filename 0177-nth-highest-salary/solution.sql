-- 177. Nth Highest Salary
-- https://leetcode.com/problems/nth-highest-salary/
-- Difficulty: Medium | Language: mysql
-- Runtime: 470 ms
-- Memory: 0B
-- Solved: 2026-04-19

create function getNthHighestSalary(n int) returns int
begin
  set n = n - 1;
  return (
    select distinct a.salary
    from Employee a
    order by a.salary desc
    limit 1 offset n
  );
end;
