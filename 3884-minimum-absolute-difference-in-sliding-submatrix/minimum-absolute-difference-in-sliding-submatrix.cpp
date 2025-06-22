class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m= grid.size() ;  int n = grid[0].size() ; 
         vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1,0));
         if(k == 1) return ans ;
         for(int i=0;i<=m-k;i++){ vector<int> res ; 
            for(int j=0;j<=n-k;j++){  vector<int> temp ;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        temp.push_back(grid[x][y]) ;
                    }
                } int d =1e6; sort(temp.begin(),temp.end()) ;
                 temp.erase(unique(temp.begin(),temp.end()),temp.end()) ;
                for(int z = 0;z<temp.size()-1;z++) d = min(d,abs(temp[z]-temp[z+1])) ;
                if(temp.size() == 1) d = 0 ;
                ans[i][j] = d ;
         } 
       }  return ans ;
    }
};