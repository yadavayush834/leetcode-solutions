-- 1378. Replace Employee ID With The Unique Identifier
-- https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/
-- Difficulty: Easy | Language: mysql
-- Runtime: 1166 ms
-- Memory: 0B
-- Solved: 2026-04-19

SELECT 
    euni.unique_id,
    e.name
FROM Employees e
LEFT JOIN EmployeeUNI euni
ON e.id = euni.id;
