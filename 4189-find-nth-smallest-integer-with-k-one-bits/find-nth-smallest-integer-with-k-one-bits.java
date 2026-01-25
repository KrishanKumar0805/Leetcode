class Solution {
    long[][] nCr;

    long cnt(long val, int k) {
        long res = 0;
        int rem = k;
        for (int i = 50; i >= 0; i--) {
            if (((val >> i) & 1) == 1) {
                if (i >= rem) res += nCr[i][rem];
                rem--;
            }
            if (rem < 0) break;
        }
        if (rem == 0) res++;
        return res;
    }

    public long nthSmallest(long n, int k) {
        nCr = new long[55][55];
        for (int i = 0; i < 55; i++) {
            nCr[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
            }
        }

        long low = 1, hgh = 1L << 50, ans = 0;
        while (low <= hgh) {
            long mid = low + (hgh - low) / 2;
            if (cnt(mid, k) >= n) {
                ans = mid;
                hgh = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
}