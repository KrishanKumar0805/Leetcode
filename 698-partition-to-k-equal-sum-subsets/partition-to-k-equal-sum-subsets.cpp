class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size() ; vector<int> dp(1<<n,-1e8) ;
        dp[0] = 0 ; long long sum = accumulate(nums.begin(),nums.end(),0) ;
        if(sum%k != 0) return false ; sum /= k ;
        for(int i=0;i<(1<<n);i++){if(dp[i] == -1e8) continue ;
            for(int j=0;j<n;j++){
                if((i & (1<<j)) == 0 && (nums[j]+dp[i]) <= sum){
                    dp[i|(1<<j)] = (nums[j]+ dp[i])% sum ;
                }
            }
        } return dp[(1<<n)-1] == 0 ;
    }
};