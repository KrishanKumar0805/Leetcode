#define ll long long
#define d double  
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        d p = 1 ; for(int num : nums) p *= num ; ll  k = target ;
        int n = nums.size()  ; int M = 1 << n ; if(sqrt(p) != k) return false;
        for(int i=0;i<M;i++){ ll res  = 1 ;
            for(int j=0;j<n;j++){
                if ((i >> j) & 1)  res *= nums[j] ;
            } if(res == k) return true ;
        } return false;
    }
};