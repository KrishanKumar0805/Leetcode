class Solution {
public:
    int dp[50][50] = {0};

    int solve(vector<int>& values, int i, int j) {
        // Base Case: A polygon with 2 vertices (a line) can't be triangulated. Its score is 0.
        if (j <= i + 1) {
            return 0;
        }
        
        // Your memoization check is correct. If the result is already computed, return it.
        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int min_score = INT_MAX; // Use a temporary variable to find the minimum

        // k is the vertex that forms a triangle with the edge (i, j)
        for (int k = i + 1; k < j; k++) {
            // THE FIX: Sum the cost of the triangle with the costs of BOTH subproblems.
            int current_score = (values[i] * values[k] * values[j]) + 
                                solve(values, i, k) + 
                                solve(values, k, j);
            
            min_score = min(min_score, current_score);
        }
        
        // Store the final minimum score in the dp table before returning.
        return dp[i][j] = min_score;
    }

    int minScoreTriangulation(vector<int>& values) {
        return solve(values, 0, values.size() - 1);
    }
};