class Solution:
    def maxProduct(self, n: int) -> int:
        v = []
        while n  :
            v.append(n%10)
            n //= 10 
        v.sort(reverse = True)
        ans = v[0] * v[1]
        return ans 