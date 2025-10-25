class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int div = sum / 9 ; string s2 = "" ;
        int rem = sum % 9 ;  if( 9 * num < sum) return "" ;
        string s1 (div,'9') ;
        if(rem>0 ) s2 = to_string(rem); 
        int l = num - div - (rem >0 ? 1 : 0) ;
        string s3(l,'0') ;
        return (s1 + s2 + s3) ;
    }
};