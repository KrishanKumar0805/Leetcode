class Solution {
public:
    int gcd(int a, int b ){
        if(b == 0) return a ;
        return gcd(b,a%b) ;
    }
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1)) ;
    }
};