class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        letterDict = {}
        left = 0
        right = 0
        maxLen = 0
        for i in range(len(s)):
            if s[i] in letterDict and letterDict[s[i]] >= left:
                curLen = right - left
                if curLen > maxLen:
                    maxLen = curLen
                left = letterDict[s[i]] + 1
            right += 1
            letterDict[s[i]] = i

        curLen = right - left
        if curLen > maxLen:
            maxLen = curLen
        return maxLen

# test code
s = Solution()
print(s.lengthOfLongestSubstring("a") == 1)
print(s.lengthOfLongestSubstring("abba") == 2)
print(s.lengthOfLongestSubstring("abcabcbb") == 3)
print(s.lengthOfLongestSubstring("bbbbb") == 1)
print(s.lengthOfLongestSubstring("pwwkew") == 3)
print(s.lengthOfLongestSubstring("abca") == 3)
print(s.lengthOfLongestSubstring("abcad") == 4)
print(s.lengthOfLongestSubstring("abcbdf") == 4)