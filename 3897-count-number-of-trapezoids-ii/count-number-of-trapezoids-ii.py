import math
from collections import defaultdict
from typing import List

class Solution:
  def countTrapezoids(self, points: List[List[int]]) -> int:
    n = len(points)
    if n < 4:
        return 0

    memo_line_key = {}
    def get_line_key(i, j):
        # Memoize to avoid re-computation
        if (i, j) in memo_line_key: return memo_line_key[(i, j)]
        if (j, i) in memo_line_key: return memo_line_key[(j, i)]
        
        p1 = points[i]
        p2 = points[j]
        # Handle identical points which don't define a line
        if p1 == p2:
            memo_line_key[(i, j)] = None
            return None

        # Line equation Ax + By + C = 0
        A = p2[1] - p1[1]
        B = p1[0] - p2[0]
        C = -A * p1[0] - B * p1[1]
        
        # Canonical form
        common_divisor = math.gcd(math.gcd(A, B), C)
        A //= common_divisor
        B //= common_divisor
        C //= common_divisor
        
        if A < 0 or (A == 0 and B < 0):
            A, B, C = -A, -B, -C
        
        res = (A, B, C)
        memo_line_key[(i, j)] = res
        return res

    # Part 1: Calculate S
    lines = defaultdict(set)
    for i in range(n):
        for j in range(i + 1, n):
            line_key = get_line_key(i, j)
            if line_key is not None:
                lines[line_key].add(i)
                lines[line_key].add(j)

    slope_groups = defaultdict(list)
    for (A, B, C), pts_on_line in lines.items():
        if B == 0: # Vertical line
            slope_key = (1, 0)
        else:
            dy, dx = A, -B
            common = math.gcd(dy, dx)
            dy //= common
            dx //= common
            if dx < 0:
                dx = -dx
                dy = -dy
            slope_key = (dy, dx)
        slope_groups[slope_key].append(len(pts_on_line))
    
    S = 0
    for slope_key in slope_groups:
        counts = slope_groups[slope_key]
        if len(counts) < 2: continue
        
        num_segments = [c * (c - 1) // 2 for c in counts]
        sum_N = sum(num_segments)
        sum_N_sq = sum(n * n for n in num_segments)
        S_m = (sum_N * sum_N - sum_N_sq) // 2
        S += S_m

    # Part 2: Calculate P and P_degen
    midpoint_groups = defaultdict(lambda: defaultdict(int))
    for i in range(n):
        for j in range(i + 1, n):
            mid_sum = (points[i][0] + points[j][0], points[i][1] + points[j][1])
            line_key = get_line_key(i, j)
            if line_key is not None:
                midpoint_groups[mid_sum][line_key] += 1
    
    P = 0
    P_degen = 0
    for mid_sum in midpoint_groups:
        group = midpoint_groups[mid_sum]
        total_diagonals = sum(group.values())
        P += total_diagonals * (total_diagonals - 1) // 2
        for count in group.values():
            P_degen += count * (count - 1) // 2
    
    # Final Result: T = S - P + P_degen
    return S - P + P_degen