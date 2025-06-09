class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) { int n = prices.size();
        int prev_buy = -prices[0];  int curr_buy = -1e5 ;
        int prev_sell = 0 ; int curr_sell = -1e5;
        for(int i=1;i<n;i++){
            curr_buy = prev_buy;
            if(prev_sell != -1e5) curr_buy = max(curr_buy,prev_sell-prices[i]) ;
            curr_sell = prev_sell ;
            if(prev_buy != -1e5) curr_sell = max(curr_sell,prev_buy+prices[i]-fee) ;
            prev_buy=curr_buy; prev_sell =curr_sell ;
        } return max(0,curr_sell);
    }
};