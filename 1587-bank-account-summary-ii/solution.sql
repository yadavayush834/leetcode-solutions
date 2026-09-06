-- 1587. Bank Account Summary II
-- https://leetcode.com/problems/bank-account-summary-ii/
-- Difficulty: Easy | Language: mysql
-- Runtime: 722 ms
-- Memory: 0B
-- Solved: 2026-04-19

SELECT 
    u.name,
    SUM(t.amount) AS balance
FROM Users u
JOIN Transactions t
ON u.account = t.account
GROUP BY u.account, u.name
HAVING SUM(t.amount) > 10000;
