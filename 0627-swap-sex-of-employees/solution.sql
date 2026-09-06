-- 627. Swap Sex of Employees
-- https://leetcode.com/problems/swap-sex-of-employees/
-- Difficulty: Easy | Language: mysql
-- Runtime: 220 ms
-- Memory: 0B
-- Solved: 2026-04-19

UPDATE Salary
SET sex = CASE
    WHEN sex = 'm' THEN 'f'
    ELSE 'm'
END;
