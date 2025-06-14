class Solution {
public:
    const int MOD = 1e9 + 7;
    const long long NEG = -1e18;
    const int M = 1 << 10;
    long long ans;

    vector<long long> solve(int u, int par, vector<vector<int>>& adj, vector<int>& vals) {
        vector<long long> dp(M, NEG);
        dp[0] = 0; int val = vals[u];int msk_u = 0;bool valid = true;
        vector<bool> seen(10, false);
        while (val) {
            int d = val % 10;
            if (seen[d]) {
                valid = false;
                break;}
            seen[d] = true;
            msk_u |= (1 << d);
            val /= 10;
        }
        if (valid)  dp[msk_u] = vals[u];
          for (int v : adj[u]) {
            if (v == par) continue;
            vector<long long> child_dp = solve(v, u, adj, vals);
            vector<long long> new_dp(M, NEG);
            for (int i = 0; i < M; i++) {
                if (dp[i] == NEG) continue;
                for (int j = 0;j < M;j++) {
                    if (child_dp[j] == NEG) continue;
                    if (i & j) continue;
                    new_dp[i|j] = max(new_dp[i|j], dp[i] + child_dp[j]);
                }
            }dp = new_dp;
        }
        long long res = 0;
        for (int i = 0; i < M; ++i) 
            res = max(res, dp[i]);
        ans = (res + ans) % MOD;
        return dp;
    }

    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (par[i] == -1) continue;
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        } ans = 0;
        solve(0, -1, adj, vals);
        return ans % MOD;
    }
};
