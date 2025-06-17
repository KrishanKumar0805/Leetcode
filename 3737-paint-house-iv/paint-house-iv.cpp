class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        const long long INF = 1e18;
        int m = n / 2;
        vector<vector<long long>> prev_dp(3, vector<long long>(3, INF));
        
        // Initialize the first pair (0, n-1)
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                if (a != b) {
                    prev_dp[a][b] = (long long)cost[0][a] + cost[n-1][b];
                }
            }
        }
        
        // Process each subsequent pair
        for (int k = 1; k < m; ++k) {
            vector<vector<long long>> curr_dp(3, vector<long long>(3, INF));
            int i = k;
            int j = n - 1 - k;
            
            for (int a_prev = 0; a_prev < 3; ++a_prev) {
                for (int b_prev = 0; b_prev < 3; ++b_prev) {
                    if (a_prev == b_prev) continue;
                    long long cost_prev = prev_dp[a_prev][b_prev];
                    // if (cost_prev == INF) continue;
                    
                    for (int curr_a = 0; curr_a < 3; ++curr_a) {
                        if (curr_a == a_prev) continue;
                        for (int curr_b = 0; curr_b < 3; ++curr_b) {
                            if (curr_b == b_prev) continue;
                            if (curr_a == curr_b) continue;
                            
                            long long new_cost = cost_prev + cost[i][curr_a] + cost[j][curr_b];
                            if (new_cost < curr_dp[curr_a][curr_b]) {
                                curr_dp[curr_a][curr_b] = new_cost;
                            }
                        }
                    }
                }
            }
            prev_dp.swap(curr_dp);
        }
        
        // Find the minimum cost in the last DP state
        long long ans = INF;
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                if (a != b) {
                    ans = min(ans, prev_dp[a][b]);
                }
            }
        }
        return ans;
    }
};