class Solution {
public:  // Best solution
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ; const int NEG_INF = INT_MIN/2;
        vector<vector<int>> curr(k+1,vector<int>(2,NEG_INF)),
        prev(k+1,vector<int>(2,NEG_INF)) ; int ans = 0;
        prev[0][0] = 0 ; prev[1][0] = -prices[0] ;
        prev[0][1] = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){
                curr[j][0] = prev[j][0] ;
                if(j>0 && prev[j-1][1]!= NEG_INF)
                  curr[j][0] = max(curr[j][0],prev[j-1][1]-prices[i]) ;
                curr[j][1] = prev[j][1] ;
                if(j>0 && prev[j-1][0]!= NEG_INF)
                  curr[j][1] = max(curr[j][1],prev[j][0]+prices[i]) ;
            } prev = curr ;
        } for(int i=0;i<=k;i++) ans = max(ans,curr[i][1]) ;
        return ans ;
    }
};