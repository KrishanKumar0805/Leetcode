#define ll long long 
class Solution {
public: 
     vector<ll> fact; const int mod = 1e9 + 7 ;
    void solve(int n ){
        for(int i=2;i<n;i++){
            fact[i] = (1LL*i*fact[i-1]) % mod ;
        }
    }
    int countPermutations(vector<int>& c) { int n = c.size() ;
        fact = vector<ll>(n,1) ; solve(n) ; 
        if(*min_element(c.begin()+1,c.end()) <= c[0]) return 0 ;
        return fact[n-1]; 
    }
};