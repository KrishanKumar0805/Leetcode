// static const int _ = []() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     return 0;
// }();

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        multiset<int> zero, one, two;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] % 3 == 0) zero.insert(nums[i]);
            else if(nums[i] % 3 == 1) one.insert(nums[i]);
            else two.insert(nums[i]);

            if(zero.size() > 3) zero.erase(zero.begin());
            if(one.size() > 3) one.erase(one.begin());
            if(two.size() > 3) two.erase(two.begin());
        }

        int p = zero.size(), q = one.size(), r = two.size();
        
        if((p < 3) && (q < 3) && (r < 3) && (p == 0 || q == 0 || r == 0)) return 0;

        int ans = 0;

        if(q == 3) ans = max(ans, accumulate(one.begin(), one.end(), 0));
        if(p == 3) ans = max(ans, accumulate(zero.begin(), zero.end(), 0));
        if(r == 3) ans = max(ans, accumulate(two.begin(), two.end(), 0));

        if(p != 0 && q != 0 && r != 0) {
            ans = max(ans, (*prev(zero.end()) + *prev(two.end()) + *prev(one.end())));
        }
            
        return ans;
    }
};