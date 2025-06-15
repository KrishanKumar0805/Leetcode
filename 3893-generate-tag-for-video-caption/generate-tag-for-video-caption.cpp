class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        for(int i=0;i<caption.size();i++){ char ch = caption[i];
            if(ch == ' ' || !isalpha(ch)) continue ;
            if(i > 0 && caption[i-1] == ' ') ch = toupper(ch) ;
            else ch = tolower(ch) ;
            ans += ch ;
            if(ans.size() == 100) break ;
        }if(ans.size()>= 2) ans[1] = tolower(ans[1]) ;return ans ;
    }
};