class Solution {
public:
    string lexSmallest(string s) {
        string ans = s ;
        for(int i=1;i<=s.size();i++){
           string s1  = s.substr(0,i); string s1rev = s1 ;
           string s2 = s.substr(i); string s2rev = s2 ;
        //    cout << s1 << "   "  << s2 << endl ;
           reverse(s1rev.begin(),s1rev.end()) ;
           reverse(s2rev.begin(),s2rev.end()) ;
           ans = min({ans,s1+s2rev,s1rev+s2});   
        } 
        return ans ;
    }
};