static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int r0[3] = {INT_MIN, INT_MIN, INT_MIN};
        int r1[3] = {INT_MIN, INT_MIN, INT_MIN};
        int r2[3] = {INT_MIN, INT_MIN, INT_MIN};
        int c0 = 0, c1 = 0, c2 = 0;

        for (int x : nums) {
            int rem = x % 3;
            if (rem < 0) rem += 3;
            int* arr;
            if (rem == 0) { arr = r0; c0++; }
            else if (rem == 1) { arr = r1; c1++; }
            else { arr = r2; c2++; }
            if (x > arr[0]) {
                arr[2] = arr[1];
                arr[1] = arr[0];
                arr[0] = x;
            } else if (x > arr[1]) {
                arr[2] = arr[1];
                arr[1] = x;
            } else if (x > arr[2]) {
                arr[2] = x;
            }
        }
        long long ans = LLONG_MIN;
        bool found = false;
        if (c0 >= 3) {
            ans = max(ans, (long long)r0[0] + r0[1] + r0[2]);
            found = true;
        }
        if (c1 >= 3) {
            ans = max(ans, (long long)r1[0] + r1[1] + r1[2]);
            found = true;
        }

      
        if (c2 >= 3) {
            ans = max(ans, (long long)r2[0] + r2[1] + r2[2]);
            found = true;
        }

        if (c0 >= 1 && c1 >= 1 && c2 >= 1) {
            ans = max(ans, (long long)r0[0] + r1[0] + r2[0]);
            found = true;
        }

        return found ? (int)ans : 0;
    }
};