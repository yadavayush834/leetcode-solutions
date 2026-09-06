-- 2356. Number of Unique Subjects Taught by Each Teacher
-- https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/
-- Difficulty: Easy | Language: mysql
-- Runtime: 513 ms
-- Memory: 0B
-- Solved: 2026-04-18

select teacher_id, count(distinct subject_id) as cnt
from Teacher
group by teacher_id;
