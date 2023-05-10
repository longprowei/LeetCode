using System;
namespace CSharpLeetcode
{
    public class P0003_LongestSubstring
    {
        public int LengthOfLongestSubstring(string s)
        {
            int maxLen = 0;
            Dictionary<char, int> charDict = new();

            for (int i = 0, j = 0; j < s.Length; j++)
            {
                if (charDict.ContainsKey(s[j]))
                {
                    i = Math.Max(i, charDict[s[j]]);
                }

                maxLen = Math.Max(maxLen, j - i + 1);
                charDict[s[j]] = j + 1;
            }

            return maxLen;
        }
    }
}

