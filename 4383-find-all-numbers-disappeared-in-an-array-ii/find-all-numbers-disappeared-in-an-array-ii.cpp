class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end()); int n = nums.size();
        vector<vector<int>> ans ;
        nums.erase(unique(nums.begin(),nums.end()), nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]< lower) continue;
            else if(nums[i]> upper) break ;

            else if(nums[i] > lower)  ans.push_back({lower,nums[i]-1});
            lower = nums[i]+ 1;
        }
        if(lower <= upper) ans.push_back({lower,upper}) ; return ans;
    }
};