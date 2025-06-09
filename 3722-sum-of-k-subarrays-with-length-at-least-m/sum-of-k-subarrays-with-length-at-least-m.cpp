#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MIN_VAL = -10000000000; // -10e9

class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<ll> pref(n+1, 0);
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + nums[i];
        }

        vector<vector<ll>> dp(n+1, vector<ll>(k+1, MIN_VAL));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= k; j++) {
            vector<ll> A(n+1);
            for (int t = 0; t <= n; t++) {
                A[t] = pref[t] + dp[t][j-1];
            }

            vector<ll> suf(n+2, MIN_VAL);
            for (int t = n; t >= 0; t--) {
                suf[t] = max(A[t], suf[t+1]);
            }

            for (int i = n; i >= 0; i--) {
                if (n - i < j * m) {
                    dp[i][j] = MIN_VAL;
                } else {
                    ll skip = (i < n) ? dp[i+1][j] : MIN_VAL;
                    ll take = suf[i+m] - pref[i];
                    dp[i][j] = max(skip, take);
                }
            }
        }

        return (int)dp[0][k];
    }
};