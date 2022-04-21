class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or len(s) <= numRows:
            return s

        sLen = len(s)
        strArr = ['' for _ in range(numRows)]
        i = 0
        goingDown = True
        for c in s:
            strArr[i] += c
            i = i + 1 if goingDown else i - 1

            if i == 0 or i == numRows - 1:
                goingDown = not goingDown

        newStr = ''
        for i in range(numRows):
            newStr += strArr[i]
        return newStr

s = Solution()
assert s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR"
assert s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI"
assert s.convert("A", 1) == "A"

