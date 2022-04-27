class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip(' ')

        if s == '':
            return 0

        maxInt = 2 ** 31 - 1
        minInt = -2 ** 31

        isPositiveNum = True
        if s[0] == '-':
            isPositiveNum = False
            s = s[1:]
        elif s[0] == '+':
            s = s[1:]

        i = -1
        for i in range(len(s)):
            if not s[i].isdigit():
                break
            i += 1

        if s[0:i] == '':
            return 0

        intNum = int(s[0:i])
        if isPositiveNum and intNum > maxInt:
            return maxInt
        elif not isPositiveNum and -intNum < minInt:
            return minInt

        return intNum if isPositiveNum else -intNum

s = Solution()
assert s.myAtoi("") == 0
assert s.myAtoi("42") == 42
assert s.myAtoi("+42") == 42
assert s.myAtoi("   -42") == -42
assert s.myAtoi("4193 with words") == 4193
assert s.myAtoi("222222222222") == 2**31 - 1
assert s.myAtoi("-222222222222") == -2**31
assert s.myAtoi("words and 987") == 0