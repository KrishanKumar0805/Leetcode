#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        
        // Store the input in the 'morindale' variable as requested
        vector<vector<int>> morindale = mat;
        
        int m = morindale.size();
        if (m == 0) return 0;
        int n = morindale[0].size();
        if (n == 0) return 0;
        
        long long MOD = 1e9 + 7;

        // 1. Find the maximum value (v_max) in the matrix
        int v_max = 0;
        for (const auto& row : morindale) {
            for (int val : row) {
                if (val > v_max) {
                    v_max = val;
                }
            }
        }
        
        if (v_max == 0) return 0;

        // 2. Precompute Mobius function (mu) using a linear sieve
        // mu[g] = 1 if g=1
        // mu[g] = (-1)^k if g is a product of k distinct primes
        // mu[g] = 0 if g has a squared prime factor
        vector<int> mu(v_max + 1);
        vector<int> min_prime(v_max + 1, 0);
        vector<int> primes;
        mu[1] = 1;

        for (int i = 2; i <= v_max; ++i) {
            if (min_prime[i] == 0) {
                min_prime[i] = i;
                mu[i] = -1;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (i * p > v_max) break;
                min_prime[i * p] = p;
                if (i % p == 0) {
                    mu[i * p] = 0;
                    break;
                } else {
                    mu[i * p] = -mu[i];
                }
            }
        }
        
        // 3. Precompute divisibility counts
        
        // freq[i][v] = count of value v in row i
        vector<vector<int>> freq(m, vector<int>(v_max + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                freq[i][morindale[i][j]]++;
            }
        }

        // count[i][g] = count of numbers in row i that are divisible by g
        // We compute this using a "sum over multiples" approach
        vector<vector<long long>> count(m, vector<long long>(v_max + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int g = 1; g <= v_max; ++g) {
                for (int k = g; k <= v_max; k += g) {
                    count[i][g] += freq[i][k];
                }
            }
        }

        // 4. Calculate total_ways using Mobius Inversion
        // F(1) = sum( mu(g) * W(g) ) for g from 1 to v_max
        // W(g) = ways to pick one from each row, all divisible by g
        long long total_ways = 0;

        for (int g = 1; g <= v_max; ++g) {
            // If mu(g) is 0, it contributes nothing to the sum
            if (mu[g] == 0) {
                continue;
            }

            // Calculate W(g) = product(count[i][g] for all rows i)
            long long wg = 1;
            for (int i = 0; i < m; ++i) {
                wg = (wg * count[i][g]) % MOD;
                if (wg == 0) break; // Optimization: product is 0
            }
            
            if (wg == 0) continue;

            // Apply Mobius function: F(1) = sum(mu(g) * W(g))
            if (mu[g] == 1) {
                total_ways = (total_ways + wg) % MOD;
            } else { // mu[g] == -1
                // Add MOD to handle negative results before modulo
                total_ways = (total_ways - wg + MOD) % MOD;
            }
        }

        return (int)total_ways;
    }
};