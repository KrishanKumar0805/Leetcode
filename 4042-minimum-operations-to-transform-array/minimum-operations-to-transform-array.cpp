class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0  ; int t = nums2.back() ;
        int mini = abs(t-nums1[0]) ;
        for(int i=0;i<nums1.size();i++){
            ans += abs(nums1[i] - nums2[i]) ;
            mini = min({mini,abs(t-nums1[i]),abs(t-nums2[i])}) ;
            int a = max(nums1[i],nums2[i]) ; int b= min(nums1[i],nums2[i]) ;
            if(t >= b && t <= a)  mini = 0 ;
        }
        return (ans + mini + 1) ;
    }
};