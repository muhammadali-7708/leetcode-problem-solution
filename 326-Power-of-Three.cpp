class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1:
            return True
        pow = 3
        while pow <= n:
            if pow == n:
                return True
            pow = pow * 3
        return False 
        