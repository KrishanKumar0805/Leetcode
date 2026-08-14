class Solution {
public:
    int maximumLengthSubstring(string s) { int ans = 1 ;
       for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
                int freq[26] = {0} ; 
                bool is = true ;
             for(int k=i;k<=j;k++){
                freq[s[k]-'a']++;
             }
             for(int l =0;l<26;l++){
                if(freq[l]>2) is = false ;
             }
             if(is) ans = max(ans,j-i+1) ;
        }
       }
       return ans ;
    }
};