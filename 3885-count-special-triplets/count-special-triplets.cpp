#define ll long long 
class Solution {
public: const int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) { int n = nums.size();
        unordered_map<int,int> total,left; ll ans = 0 ;
        for(int i:nums) total[i]++;
        for(int i=0;i<n;i++){
            int l = left[2*nums[i]] ; int t = total[2*nums[i]] ;   
            if(nums[i] == 0){
                ans += 1LL*l * (t-l-1); 
                ans = (ans %mod);
            }
            else{
                ans += 1LL*l * (t-l) ; ans= ans%mod;;
            } left[nums[i]]++ ;
        } return (int)ans ;
    }
};