class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) {
            return 0;
        }

        map<pair<int, int>, vector<int>> left_dict;
        for (int j = 2; j < n; ++j) {
            for (int i = 0; i < j - 1; ++i) {
                int num_val = nums[i];
                int denom_val = nums[j];
                int g = gcd(num_val, denom_val);
                int a = num_val / g;
                int b = denom_val / g;
                left_dict[{a, b}].push_back(j);
            }
        }

        map<pair<int, int>, vector<int>> right_dict;
        for (int k = 0; k < n - 2; ++k) {
            for (int l = k + 2; l < n; ++l) {
                int num_val = nums[l];
                int denom_val = nums[k];
                int g = gcd(num_val, denom_val);
                int a = num_val / g;
                int b = denom_val / g;
                right_dict[{a, b}].push_back(k);
            }
        }

        long long total_count = 0;
        for (const auto& left_entry : left_dict) {
            auto key = left_entry.first;
            if (right_dict.find(key) != right_dict.end()) {
                const auto& J_list = left_entry.second;
                const auto& K_list = right_dict.at(key);
                vector<int> sorted_J = J_list;
                vector<int> sorted_K = K_list;
                sort(sorted_J.begin(), sorted_J.end());
                sort(sorted_K.begin(), sorted_K.end());
                int idx = 0;
                long long count_jk = 0;
                for (int k_val : sorted_K) {
                    while (idx < sorted_J.size() && sorted_J[idx] <= k_val - 2) {
                        ++idx;
                    }
                    count_jk += idx;
                }
                total_count += count_jk;
            }
        }

        return total_count;
    }
};
