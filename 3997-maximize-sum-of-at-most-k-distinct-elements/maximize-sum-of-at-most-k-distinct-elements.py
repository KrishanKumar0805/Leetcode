class Solution:
    def maxKDistinct(self, nums: List[int], k: int) -> List[int]:
      s = set(nums)
      return sorted(s,reverse = True) [:k]