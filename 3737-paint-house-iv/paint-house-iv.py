class Solution:
    def minCost(self, n: int, cost: List[List[int]]) -> int:
        k = n // 2
        INF = float('inf')
        dp = [[INF] * 3 for _ in range(3)]
        
        for a in range(3):
            for b in range(3):
                if a != b:
                    dp[a][b] = cost[0][a] + cost[n-1][b]
        
        if k == 1:
            return min(min(row) for row in dp)
        
        for i in range(1, k):
            new_dp = [[INF] * 3 for _ in range(3)]
            for a_prev in range(3):
                for b_prev in range(3):
                    if dp[a_prev][b_prev] == INF:
                        continue
                    for a_curr in range(3):
                        for b_curr in range(3):
                            if a_curr == b_curr:
                                continue
                            if a_curr == a_prev:
                                continue
                            if b_curr == b_prev:
                                continue
                            total = dp[a_prev][b_prev] + cost[i][a_curr] + cost[n-1-i][b_curr]
                            if total < new_dp[a_curr][b_curr]:
                                new_dp[a_curr][b_curr] = total
            dp = new_dp
        
        ans = min(min(row) for row in dp)
        return ans