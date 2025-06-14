class Solution {
public:
    bool is(vector<int>&nums,int mid,int p){
        int cnt = 0 ; int n = nums.size();
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1]) <= mid){
                i++; cnt++;
            }
            if(cnt >= p) return true ;
        } return false ;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n  = nums.size(); int lo =0,hi=0;
        sort(nums.begin(),nums.end()) ;
        if(n == 1) return 0 ;
        // for(int i=1;i<n;i++) lo = min(lo,nums[i]-nums[i-1]) ;
        hi = nums[n-1]-nums[0] ; int ans = INT_MAX;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2 ;
            if(is(nums,mid,p)){
                ans= min(ans,mid); hi = mid-1;
            }
            else lo = mid+1 ;
        }
        return ans ;
    }
};