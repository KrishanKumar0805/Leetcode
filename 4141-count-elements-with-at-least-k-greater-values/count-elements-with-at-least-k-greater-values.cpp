class Solution {
public:
    int countElements(vector<int>& nums, int k) {
       int n  = nums.size() ;
       vector<int>pref(n,0) ;
       sort(nums.begin(),nums.end()) ;
       for(int i=n-2;i>=0;i--){
        if(nums[i] < nums[i+1]) pref[i] = n-1-i;
        else pref[i] = pref[i+1] ;
       }
        int ans= 0 ;
       for(int i=0;i<n;i++) if(pref[i] >= k) ans++ ;
       return ans ;
    }
};