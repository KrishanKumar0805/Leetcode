class Solution {
public:
    int maxProfit(vector<int>& prices) { int n = prices.size() ;
        vector<int> prev(3,-1e5),curr(3,-1e5);
        prev[0] = -prices[0] ; prev[1]= 0  ; prev[2] = 0 ;
        for(int i=1;i<n;i++){
            curr[0] = max(prev[0],prev[2]-prices[i]) ;
            curr[1] = max(prev[0]+prices[i],curr[1]) ;
            curr[2] = max(curr[2],prev[1]) ;
            prev = curr ;
            // cout << curr[0] <<curr[1]<< curr[2]<< "  ";
        } return max({0,curr[1],curr[2]});
    }
};