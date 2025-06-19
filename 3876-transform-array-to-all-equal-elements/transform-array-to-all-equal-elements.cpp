class Solution {
public:bool check(vector<int>&nums) { for(int i=1;i<nums.size();i++) 
if(nums[i] != nums[i-1] ) return false; return true ;}
    bool canMakeEqual(vector<int>& nums, int k) {
        int cnt1 =0 ,cnt2 = 0 ; int n=  nums.size() ;
        for(int i=0;i<n;i++) if(nums[i] == -1) nums[i] =0 ;
        vector<int> a = nums ;
        for(int i=0;i<n-1;i++) {if(a[i]) {a[i]=!a[i],a[i+1]=!a[i+1];cnt1++;}} 
        if(!check(a)) cnt1 =1e5+1; a= nums; 
        for(int i=0;i<n-1;i++) if(!a[i]) {a[i]=!a[i],a[i+1]=!a[i+1];cnt2++;}
        if(!check(a)) cnt2 = 1e5+1;
        if(min(cnt1,cnt2) <= k) return true ; return false; 
    }
};