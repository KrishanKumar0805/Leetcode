class Solution {
public:
    int dp[50][50] = {0};

    int solve(vector<int>& values, int i, int j) {
        if(j<= i+1) return 0 ;
        if(dp[i][j]!= 0) return dp[i][j] ;

        for(int k=i+1;k<j;k++){
            dp[i][j] = min({dp[i][j] == 0?INT_MAX:dp[i][j],
                       solve(values,i,k)+solve(values,k,j)+
                       values[i]*values[j]*values[k]});
        }
        return dp[i][j] ;
    }

    int minScoreTriangulation(vector<int>& values) {
        return solve(values, 0, values.size() - 1);
    }
};