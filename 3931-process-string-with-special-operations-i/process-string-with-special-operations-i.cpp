class Solution {
public:
    string processStr(string s) {
        string ans = ""; 
        for(int i=0;i<s.size();i++){ char ch = s[i] ;
            if(ch-'a'>=0 && ch-'a'<=25) ans += ch;
            else if(ch == '*'){
                int t = ans.size() ; ans = ans.substr(0,t-1) ;
            }
            else if (ch == '#'){
                ans = ans + ans ;
            }
            else if(ch == '%'){
                reverse(ans.begin(),ans.end());
            }
        } return ans ;
    } 
};