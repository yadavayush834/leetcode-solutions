-- 1683. Invalid Tweets
-- https://leetcode.com/problems/invalid-tweets/
-- Difficulty: Easy | Language: mysql
-- Runtime: 607 ms
-- Memory: 0B
-- Solved: 2026-04-19

SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;
