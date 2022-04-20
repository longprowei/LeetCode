class Solution:
    def longestPalindrome(self, s: str) -> str:
        maxLen = 0
        maxStr = ''
        
        if len(s) == 1:
            return s

        for i in range(len(s) - 1):
            j = i
            k = i + 1
            startIndex = j
            currLen = 0
            while j >= 0 and k < len(s) and s[j] == s[k]:
                currLen += 2
                startIndex = j
                j -= 1
                k += 1
            if currLen > maxLen:
                maxLen = currLen
                maxStr = s[startIndex : startIndex + currLen]

        for i in range(1, len(s) - 1):
            j = i - 1
            k = i + 1
            currLen = 1
            startIndex = i
            while j >= 0 and k < len(s) and s[j] == s[k]:
                currLen += 2
                startIndex = j
                j -= 1
                k += 1
            if currLen > maxLen:
                maxLen = currLen
                maxStr = s[startIndex : startIndex + currLen]

        return maxStr if maxLen > 1 else s[0]


################### Test ####################
s = Solution()
assert s.longestPalindrome('a') == 'a'
assert s.longestPalindrome('abccbad') == 'abccba'
assert s.longestPalindrome('dabccba') == 'abccba'
assert s.longestPalindrome('dabccbabdbf') == 'abccba'
assert s.longestPalindrome('babad') == 'bab'
assert s.longestPalindrome('cbbd') == 'bb'
assert s.longestPalindrome('aaaaa') == 'aaaaa'
assert s.longestPalindrome("aacabdkacaa") == "aca"

