class Solution {
public: int t = 0 ; vector<int> dis,low;
    void solve(int u ,int par ,vector<vector<int>> &adj,vector<vector<int>>&ans){
        dis[u]=low[u] = t++ ;
        for(int v:adj[u]){
            if(v == par) continue ;
            if(dis[v] == -1){
                solve(v,u,adj,ans);
                low[u] = min(low[u],low[v]) ;
                if(low[v] > dis[u]) ans.push_back({u,v}) ;
            }
            else{
                low[u] = min(low[u],dis[v]) ;
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dis.resize(n,-1); low.resize(n,-1);
        vector<vector<int>> adj(n) ;
        for(auto c : connections){
            adj[c[0]].push_back(c[1]); 
            adj[c[1]].push_back(c[0]) ;
        } vector<vector<int>> ans ;
        for(int i=0;i<n;i++){
            if(dis[i] == -1) solve(i,-1,adj,ans) ;}
        return ans ;
    }
};