class Solution {
public:
    int maxDistinct(string s) {
        int freq[26] = {0}; int ans = 0;
        for(char ch:s) freq[ch-'a']++;
        for(int i=0;i<26;i++) if(freq[i]>0) ans++ ;
        return ans ;
    }
};