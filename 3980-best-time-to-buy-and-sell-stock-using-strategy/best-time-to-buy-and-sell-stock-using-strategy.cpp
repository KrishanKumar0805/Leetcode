#define ll long long 
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size() ;
        vector<ll> sell(n+1,0);
        vector<ll> o(n+1,0) ;
        for(int i=1;i<=n;i++) {
        sell[i] = sell[i-1] + prices[i-1] ;
        o[i] = o[i-1] + (prices[i-1]*strategy[i-1]) ;
        }
        ll ans = o[n] ;
        for(int i=0;i<=n-k;i++){
           ans = max(ans,o[i]+sell[i+k]-sell[i+k/2]+o[n]-o[i+k]);
        } return ans ;
    }
};