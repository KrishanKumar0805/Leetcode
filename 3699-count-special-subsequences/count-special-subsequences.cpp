#define d  double 
#define ll long long 
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<d,int> mpp ; int n = nums.size() ; ll ans = 0 ;
        for(int r=4;r<n-1;r++){
            for(int q = r - 2 ,p = 0;p<q-1;p++) mpp[1.0*nums[p]/nums[q]]++;
            for(int s = r+2; s < n ;s++) ans += mpp[1.0*nums[s]/nums[r]];
        } return ans ;
    }
};