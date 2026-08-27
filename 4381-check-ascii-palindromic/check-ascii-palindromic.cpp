class Solution {
public:
    bool isPalindromic(string s) {
        string ans = "";
        for(char ch : s ){
            bitset<8> bin(ch);
            ans += bin.to_string();
        }
        string sna = ans ;
        reverse(ans.begin(),ans.end());
        if(ans == sna) return true ;
        return false ;
    }
};