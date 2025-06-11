class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       vector<int>indegree(n,0) ; queue<int> q ; 
       vector<vector<int>> adj(n) ; vector<int> ans ;
       if(n==1) return {0};
       for(auto e:edges){
        indegree[e[0]]++ ; indegree[e[1]]++ ;
        adj[e[0]].push_back(e[1]) ; adj[e[1]].push_back(e[0]) ;
       } 

       for(int i=0;i<n;i++) if(indegree[i] == 1) q.push(i) ;
       while(n >  2){
            int sz = q.size(); n -=sz;
            while(sz--){ auto u  = q.front() ; q.pop() ;
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v] == 1)q.push(v) ;
            }}
       }
       while(!q.empty()){ans.push_back(q.front()); q.pop() ;}
       return ans ;
    }
};