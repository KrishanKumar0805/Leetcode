class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        int target = sum / k;
        vector<int> dp(1 << n, -1); 
        dp[0] = 0;  

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;

            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j)) && dp[mask] + nums[j] <= target) {
                    int new_mask = mask | (1 << j);
                    if(new_mask+1==(1<<n)) return 1;
                    if(dp[new_mask]!=-1) continue;
                    dp[new_mask] = (dp[mask] + nums[j])%target ;
                }
            }
        }

        return dp[(1 << n) - 1] == 0;
    }
};
