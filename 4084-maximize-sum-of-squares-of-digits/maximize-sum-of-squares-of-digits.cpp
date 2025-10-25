class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans(num,'0'); 
        if (  num * 9 < sum) return "" ;
        for(int i=0;i<num;i++){
            if(sum > 9) {ans[i] = '9' ;
            sum -= 9 ; }
            else {
                char ch  = '0' + sum ;
                ans[i] = ch ;
                break ;
            }
        
        } return ans ;
    }
};