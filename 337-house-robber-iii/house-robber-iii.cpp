/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,unordered_map<TreeNode*, unordered_map<int,int>>&dp){
        if(!root) return ;
        dp[root][0] = -1e4 ; dp[root][1] = -1e4;
        dfs(root->left,dp) ; dfs(root->right,dp) ;
        
    }
    int solve(TreeNode* root,
    unordered_map<TreeNode*, unordered_map<int,int>>&dp,int flag){
        if(root == NULL) return 0 ; int taken = 0 ;
        if(dp[root][flag] != -1e4) return dp[root][flag];
        
        int not_taken = solve(root->left,dp,0)+solve(root->right,dp,0);

        if(flag == 0) 
        taken = solve(root->left,dp,1)+solve(root->right,dp,1)+root->val; 
        
        return dp[root][flag] = max(taken,not_taken) ;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, unordered_map<int,int>> dp;
        dfs(root,dp) ;
        int ans = max(solve(root,dp,0),solve(root,dp,1)) ;
        dfs(root,dp) ; return ans ;
    }
};