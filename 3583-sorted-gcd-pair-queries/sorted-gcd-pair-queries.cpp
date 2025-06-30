class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        const int MAXA = *max_element(nums.begin(), nums.end());
        vector<int>freq(MAXA + 1, 0);
        vector<long long>    cntDiv(MAXA + 1, 0),
                             pairsExact(MAXA + 1, 0);

        for (int x : nums) ++freq[x];
        for (int g = 1; g <= MAXA; ++g)
            for (int m = g; m <= MAXA; m += g)
                cntDiv[g] += freq[m];

        for (int g = MAXA; g >= 1; --g) {
            long long tot = cntDiv[g];
            long long cur = tot * (tot - 1) / 2;        
            for (int m = g + g; m <= MAXA; m += g)       
                cur -= pairsExact[m];
            pairsExact[g] = cur;
        }

        vector<int> values;   
        vector<long long>  prefix;   
        for (int g = 1; g <= MAXA; ++g)
            if (pairsExact[g]) {
                values.push_back(g);
                prefix.push_back(pairsExact[g] + (prefix.empty() ? 0 : prefix.back()));
            }

        vector<int> ans;
        ans.reserve(queries.size());
        for (long long k : queries) {
            int idx = static_cast<int>(lower_bound(prefix.begin(), prefix.end(), k + 1) - prefix.begin());
            ans.push_back(values[idx]);
        }
        return ans;
    }
};
