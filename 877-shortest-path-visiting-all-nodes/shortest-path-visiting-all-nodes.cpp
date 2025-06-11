class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) { int n=graph.size() ;
        vector<vector<int>> dp(n,vector<int>(1<<n,-1)) ;
        queue<pair<int,int>> q ;
        for(int i=0;i<n;i++) {dp[i][1<<i] = 0 ; q.push({i,1<<i}) ;}
        while(!q.empty()){
            auto[u,mask] = q.front(); q.pop();
            if(mask == (1<<n)-1) return dp[u][mask];
            for(int v:graph[u]){
                int new_mask  = mask | (1<<v);
                if(dp[v][new_mask] == -1){
                    dp[v][new_mask] = 1+dp[u][mask];
                    q.push({v,new_mask}) ;
                }
            }
        } 
        return -1 ;
    }
};