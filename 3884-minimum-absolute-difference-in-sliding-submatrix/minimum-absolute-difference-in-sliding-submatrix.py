class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m,n= len(grid),len(grid[0])
        ans = [[0]*(n-k+1) for t in range(m-k+1)]
        if k == 1:
            return ans
        for i in range(m-k+1):
            for j in range(n-k+1):
                temp = []
                for x in range(i,i+k):
                    for y in range(j,j+k):
                        temp.append(grid[x][y])

                temp = list(set(temp))
                temp.sort()
                if len(temp) == 1:
                     ans[i][j] =0
                else:
                    d = 1e10
                    for z in range(len(temp)-1):
                        d = min(d,abs(temp[z]-temp[z+1]))
                    ans[i][j] = d 
        return ans 


