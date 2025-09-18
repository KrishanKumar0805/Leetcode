class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
       return min(t+s for s, t in tasks)