# 3522. Calculate Score After Performing Instructions
# https://leetcode.com/problems/calculate-score-after-performing-instructions/
# Difficulty: Medium | Language: python3
# Runtime: 23 ms
# Memory: 44.9 MB
# Solved: 2025-04-26

class Solution:
    def calculateScore(self, instructions: List[str], values: List[int]) -> int:
        score = 0
        i = 0
        done = set()

        while 0 <= i < len(values) and i not in done:
            done.add(i)
            if instructions[i] == "jump":
                i += values[i]
            else:
                score += values[i]
                i += 1
        
        return score
