class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
       
        vector<long long> dp(k, LLONG_MAX);   dp[0] = 0 ;
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            int rem = (i + 1) % k;
            if (dp[rem] != LLONG_MAX) {
                ans = max(ans, prefix[i + 1] - dp[rem]);
                dp[rem] = min(dp[rem], prefix[i + 1]);
            } else {
                dp[rem] = prefix[i + 1];
            }
        }

        return ans;
    }
};
