#define ll long long 
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) { int n = nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(2,0));
        dp[n][0] = 1e10+1 ; dp[n][1] = -1e10-1 ;
        for(int i=n-1;i>=0;i--){
            dp[i][0] = min(dp[i+1][0],0LL+nums[i]) ;
            dp[i][1] = max(dp[i+1][1],0LL+nums[i]) ;
            // cout << dp[i+1][0] << '\n';
        }
        ll ans =  -1e10-1;
        for(int i=0;i<n;i++){
            if(i+m-1 >= n) continue ;
            ans = max(1LL*nums[i]*dp[i+m-1][0],ans) ;
            ans = max(1LL*nums[i]*dp[i+m-1][1],ans) ;
        } return ans ;
    }
};