class Solution:
    def reverse(self, x: int) -> int:
        ret = 0
        currNum = x if x > 0 else -x
        maxInt32 = 2 ** 31 - 1
        while currNum != 0:
            if ret > maxInt32 // 10:
                ret = 0
                break

            if ret == maxInt32 // 10:
                if x > 0:
                    if currNum % 10 > maxInt32 % 10:
                        ret = 0
                        break
                else:
                    if currNum % 10 > maxInt32 % 10 + 1:
                        ret = 0
                        break
            
            ret = ret * 10 + currNum % 10
            currNum //= 10

        if x < 0:
            ret = -ret

        return ret

s = Solution()
assert s.reverse(0) == 0
assert s.reverse(123) == 321
assert s.reverse(-123) == -321
assert s.reverse(120) == 21
assert s.reverse(99999999999) == 0
assert s.reverse(-999999999999) == 0
assert s.reverse(1534236496) == 0
assert s.reverse(-2147483412) == -2143847412