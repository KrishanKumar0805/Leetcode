class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) { int n = nums.size();
        unordered_map<int,int> mpp ; mpp[0] = 1 ; int sum  =0  ; int ans = 0 ;
        for(int i=0;i<n;i++){
            sum += nums[i] ; 
            int res  =  (((sum + k)%k)+k)%k;
            if(mpp.find(res) != mpp.end()) ans += mpp[res] ;
            mpp[res]++;
        } return ans ;
    }
};