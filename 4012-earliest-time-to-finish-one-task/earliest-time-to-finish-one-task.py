class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
        ans = 1e8
        l = len(tasks)
        for i in range(l):
            ans= min(ans,tasks[i][0] + tasks[i][1])   
        return ans