class Solution:
    def reverse(self, x: int) -> int:
        ret = 0
        currNum = x if x > 0 else -x
        while currNum != 0:
            ret = ret * 10 + currNum % 10
            currNum //= 10

        if x < 0:
            ret = -ret

        if ret < -2 ** 31 or ret > 2 ** 31 - 1:
            ret = 0

        return ret

s = Solution()
assert s.reverse(0) == 0
assert s.reverse(123) == 321
assert s.reverse(-123) == -321
assert s.reverse(120) == 21
assert s.reverse(99999999999) == 0
assert s.reverse(-999999999999) == 0