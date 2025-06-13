class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n+1),dp(n);
        for(int i=0;i<n;i++){
            prefix[i+1]=nums[i]+prefix[i];
        }
        long long res=dp[k-1]=prefix[k]-prefix[0];

        for(int i=k;i<n;i++){
            dp[i]=prefix[i+1]-prefix[i-k+1]+max(0LL,dp[i-k]);
            res=max(dp[i],res);
            // cout<<dp[i-k]<<" ";
        }
        return res;
    }
};