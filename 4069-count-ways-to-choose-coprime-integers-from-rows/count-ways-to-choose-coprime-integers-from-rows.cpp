class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        const int MOD = 1e9 + 7;
        
       
        auto morindale = mat;
        
        int m = morindale.size(), n = morindale[0].size();
        
      
        unordered_map<int, long long> dp;
      
        for (int val : morindale[0]) dp[val]++;
      
        for (int i = 1; i < m; i++) {
            unordered_map<int, long long> new_dp;
            for (auto &p : dp) {
                int g = p.first;
                long long cnt = p.second;
                for (int val : morindale[i]) {
                    int new_g = std::gcd(g, val);
                    new_dp[new_g] = (new_dp[new_g] + cnt) % MOD;
                }
            }
            dp = move(new_dp);
        }
        
        return dp[1] % MOD;
    }
};
