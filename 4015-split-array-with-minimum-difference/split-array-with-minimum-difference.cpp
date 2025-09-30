#define ll long long 
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        ll sum= 0  ; for(int i:nums) sum += i ; int n = nums.size() ;
        vector<ll> pref(n+1,0) ;
        for(int i=0;i<n;i++) pref[i+1] = 0LL + pref[i] + nums[i] ;
        for(int i=1;i<n-1;i++){ 
        if(nums[i] <= nums[i+1] && nums[i] <= nums[i-1]) return -1 ;}
        ll ans = 1e10 ;
        for(int i=1;i<n-1;i++){
             if(nums[i] == nums[i+1]) ans = abs(sum-2*pref[i+1]);
             else if (nums[i] == nums[i-1]) ans = abs(sum-2*pref[i]);
            else if (nums[i] >= nums[i-1] && nums[i] >= nums[i+1])
            {
                ans=min(abs(2*pref[i+1]-sum),abs(2*pref[i]-sum)); 
            }   
        }
        if(ans == 1e10){
            if(nums[0] >= nums[1]) ans = abs(sum-2*nums[0]);
            else ans = abs(sum-2*nums[n-1]);
        }
         return ans;
    }
};