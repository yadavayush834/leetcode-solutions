-- 577. Employee Bonus
-- https://leetcode.com/problems/employee-bonus/
-- Difficulty: Easy | Language: mysql
-- Runtime: 971 ms
-- Memory: 0B
-- Solved: 2026-04-19

SELECT 
    e.name,
    b.bonus
FROM Employee e
LEFT JOIN Bonus b
ON e.empId = b.empId
WHERE b.bonus < 1000 OR b.bonus IS NULL;
