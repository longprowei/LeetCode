class Solution:
    def myAtoi(self, s: str) -> int:
        sign = 1
        result = 0
        INT_MAX, INT_MIN = 2 ** 31 - 1, -2 ** 31

        i = 0
        for i in range(len(s)):
            if s[i] != ' ':
                break

        s = s[i:]

        if len(s) == 0:
            return 0

        if s[0] == '-' or s[0] == '+':
            sign = -1 if s[0] == '-' else 1
            s = s[1:]

        for c in s:
            if not c.isdigit():
                break
            if result > INT_MAX // 10 or (result == INT_MAX // 10 and int(c) > INT_MAX % 10):
                return INT_MAX if sign == 1 else INT_MIN
            result = result * 10 + int(c)

        return sign * result

s = Solution()
assert s.myAtoi("") == 0
assert s.myAtoi("42") == 42
assert s.myAtoi("+42") == 42
assert s.myAtoi("   -42") == -42
assert s.myAtoi("4193 with words") == 4193
assert s.myAtoi("222222222222") == 2**31 - 1
assert s.myAtoi("-222222222222") == -2**31
assert s.myAtoi("words and 987") == 0