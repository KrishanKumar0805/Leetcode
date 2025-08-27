class Solution {
public:
    int MOD = 1e9 + 7 ;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int  q = queries.size()  ; int n = nums.size() ;
        for(int i=0;i<q;i++){
            int l = queries[i][0] ; int r = queries[i][1] ;
            int k = queries[i][2] ; int v = queries[i][3];
            for(int idx = l ; idx <=r ; idx += k){
                nums[idx] = (1LL*nums[idx] * v) %MOD ;
            }
        }
        int ans  = 0 ;
        for(int i=0;i<n;i++) ans ^= nums[i] ;  return  ans ;
    }
};