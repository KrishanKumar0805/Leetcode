class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0 ;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> mpp ;
            int odd = 0 ; int even = 0  ;
            for(int j=i;j<nums.size();j++){
                mpp[nums[j]]++;
                if(mpp[nums[j]] > 1) {
                    if(odd == even) ans  = max(ans,j-i+1) ; 
                 continue ;
                }
                if(nums[j]%2 == 0) even++ ;
                else odd++ ;
                if(odd == even) ans = max(ans,j-i+1) ; 

            }
          } return ans ;
    }
};