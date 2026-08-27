class Solution {
public:
    bool isPalindromic(string s) {string ans = "";
        for(char ch : s ) ans += bitset<8>(ch).to_string();
        int n = ans.size();
        for(int i=0;i<n/2;i++)  if(ans[i] != ans[n-i-1]) return false ;
         return true ;
    }
};