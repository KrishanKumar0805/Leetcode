class Solution {
public:
    bool isPalindromic(string s) {
        string ans = "";
        for(char ch : s ){
            bitset<8> bin(ch);
            ans += bin.to_string();
        }
        cout << ans << endl ;
        int n = ans.size();
        for(int i=0;i<n/2;i++){
            if(ans[i] != ans[n-i-1]) return false ;
        } return true ;
    }
};