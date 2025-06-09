class Solution {
public:
    int solve(vector<int>& prices, vector<vector<int>>& dp,int ind,int state){
        if(ind == prices.size()) return 0 ;
        if(dp[ind][state] != -1e4) return dp[ind][state] ;
        int profit = -1e4 ;
        if(state == 0) profit = max({profit,solve(prices,dp,ind+1,0),
        -prices[ind]+solve(prices,dp,ind+1,1)});
        if(state == 1) profit = max({solve(prices,dp,ind+1,1),
            profit,prices[ind]+solve(prices,dp,ind+1,2)});
        if(state == 2) profit = max(profit,solve(prices,dp,ind+1,0)) ;
        return dp[ind][state] = profit ;
    }
    int maxProfit(vector<int>& prices) { int n = prices.size() ;
        vector<vector<int>> dp(n,vector<int>(3,-1e4)) ;
        return max(0,solve(prices,dp,0,0)) ;
    }
};