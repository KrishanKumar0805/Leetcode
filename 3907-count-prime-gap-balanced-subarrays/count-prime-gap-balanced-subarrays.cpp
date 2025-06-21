class Solution {
public: const int sz = 5e4+1; vector<bool> is ;
    void solve(){
        for(int i=2;i*i<sz;i++){
            if(is[i]){
                for(int j=i*i;j<sz;j+=i)is[j] = false ;
                } }}
    int primeSubarray(vector<int>& nums, int k) { int n =nums.size();
        is = vector<bool>(sz,true);is[0] = is[1] = false ; solve() ; vector<int> v;
        for(int i=0;i<n;i++) if(is[nums[i]]) v.push_back(i) ;
        set<int> ind ; multiset<int> val ;
        if(v.size() < 2) return false ;
        int left = 0 ; int ans = 0 ; 
        for(int right = 0;right<nums.size();right++){
            if(is[nums[right]]) val.insert(nums[right]), ind.insert(right) ;
            while(val.size() >= 2 && *val.rbegin()-*val.begin() > k){
               if(is[nums[left]]){auto it1 = ind.find(left) ; auto it2  = val.find(nums[left]) ;
                ind.erase(it1) ; val.erase(it2) ;} left++ ;
            } if(val.size() >= 2){
                auto it = ind.end() ; it -- ; it-- ;
                ans += (*it - left+ 1) ;
            }
        } return ans ;
    }
};