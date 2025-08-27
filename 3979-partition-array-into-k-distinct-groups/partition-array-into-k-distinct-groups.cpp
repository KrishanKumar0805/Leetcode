class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int> mpp ;
        for(int i:nums) mpp[i]++ ;
        int n = nums.size() ;
        if(n%k != 0) return false ;
        for(auto &i:nums){if(mpp[i] > n/k) return false ;}
        return true ;
    }
};