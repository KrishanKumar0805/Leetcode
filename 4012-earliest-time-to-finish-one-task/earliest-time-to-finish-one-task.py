class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
        ans = 1e8
        l = len(tasks)
        for i in range(l):
            a = tasks[i][0] 
            b = tasks[i][1]
            ans = min(ans,a+b)   
        return ans