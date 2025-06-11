class Solution {
public:
    void solve(int i, int j , vector<vector<bool>>&vis,vector<vector<char>>& grid){ 
        int m = grid.size() ; int n = grid[0].size();
        vis[i][j] = true ;
        int dx[] = {-1,1,0,0} ; int dy[] = {0,0,-1,1}; 
        for(int k=0;k<=3;k++){
            int x = i+dx[k]; int y = j+dy[k];
            if(x>=0 && x < m && y >=0 && y< n && grid[x][y] == '1'&&!vis[x][y]){
                solve(x,y,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {int m =grid.size(); int n = grid[0].size();
        int ans = 0 ; vector<vector<bool>> vis(m,vector<bool>(n,false)) ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    solve(i,j,vis,grid);ans++;
                }
            }
        } return ans ;
    }
};