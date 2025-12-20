class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() ; unordered_map<int,int> mpp ; int i ;
        for( i = n-1;i>=0; i--) {
            if(mpp[nums[i]]>=1)break ;
            mpp[nums[i]]++ ;
        }
        int ans = (i+1)/3 ;
        // cout<< ans << endl ;
        if((i+1)%3 != 0) ans++ ;
        return ans ;
    }
};