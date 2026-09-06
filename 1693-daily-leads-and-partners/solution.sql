-- 1693. Daily Leads and Partners
-- https://leetcode.com/problems/daily-leads-and-partners/
-- Difficulty: Easy | Language: mysql
-- Runtime: 627 ms
-- Memory: 0B
-- Solved: 2026-04-18

select date_id, make_name,
count(distinct lead_id) as unique_leads,
count(distinct partner_id) as unique_partners
from DailySales
group by date_id, make_name;
