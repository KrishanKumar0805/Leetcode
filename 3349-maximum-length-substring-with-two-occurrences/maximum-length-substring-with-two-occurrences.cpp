class Solution {
public:
    int maximumLengthSubstring(string s) { int ans = 1 ;
    // first approach 
    //    for(int i=0;i<s.size();i++){
    //     for(int j=0;j<s.size();j++){
    //             int freq[26] = {0} ; 
    //             bool is = true ;
    //          for(int k=i;k<=j;k++){
    //             freq[s[k]-'a']++;
    //          }
    //          for(int l =0;l<26;l++){
    //             if(freq[l]>2) is = false ;
    //          }
    //          if(is) ans = max(ans,j-i+1) ;
    //     }
    //    } first approach in o(N^2) coule be better here i guess 

    // 2nd approach (best approach overkill this easy solution)

       
       int left = 0 ; int freq[26] = {0};
        for(int right = 0;right<s.size();right++){
            freq[s[right]-'a']++;
            while(freq[s[right]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans ;
    }
};