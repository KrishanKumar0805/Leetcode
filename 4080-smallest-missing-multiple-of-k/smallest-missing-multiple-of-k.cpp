class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
      unordered_map<int,int> mpp ;
      for(int i:nums) mpp[i]++ ;
      sort(nums.begin(),nums.end()) ;
      for(int i=1;i<=100;i++){
            if(mpp[i*k] > 0) continue ;
            return i*k ;
      }
      return 101*k ;
    }
};