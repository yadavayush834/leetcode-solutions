-- 1393. Capital Gain/Loss
-- https://leetcode.com/problems/capital-gainloss/
-- Difficulty: Medium | Language: mysql
-- Runtime: 472 ms
-- Memory: 0B
-- Solved: 2026-04-19

SELECT 
    stock_name,
    SUM(
        CASE 
            WHEN operation = 'Buy' THEN -price
            ELSE price
        END
    ) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name;
