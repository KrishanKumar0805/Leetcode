// #define ll unsigned long long 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size()  ; int sum = 0 ;
        for(int i:nums) sum += i ; if(sum%2 != 0) return false ;
        vector<vector<int>> dp(n,vector<int>(sum+1,0)) ;
        for(int i=0;i<n;i++){dp[i][0] = 1; if(nums[i]<=sum/2)dp[i][nums[i]]=1  ;}
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i]) dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]] ;
            }
        } for(int i=0;i<n;i++) if(dp[i][sum/2]==1) return true ;
        return false ;
    }
};