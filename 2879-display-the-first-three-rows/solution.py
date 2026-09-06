# 2879. Display the First Three Rows
# https://leetcode.com/problems/display-the-first-three-rows/
# Difficulty: Easy | Language: pythondata
# Runtime: 276 ms
# Memory: 66.5 MB
# Solved: 2026-04-18

import pandas as pd

def selectFirstRows(a: pd.DataFrame) -> pd.DataFrame:
    return a.head(3)
