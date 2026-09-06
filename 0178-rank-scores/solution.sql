-- 178. Rank Scores
-- https://leetcode.com/problems/rank-scores/
-- Difficulty: Medium | Language: mysql
-- Runtime: 305 ms
-- Memory: 0B
-- Solved: 2026-04-19

select 
  a.score,
  dense_rank() over (order by a.score desc) as `rank`
from Scores a
order by a.score desc;
