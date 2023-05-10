using System;
using CSharpLeetcode;

namespace CSharpLeetcodeTest
{
    public class P0003_LongestSubstringTest
    {
        [Fact]
        public void EmptyString()
        {
            string s = string.Empty;
            int expected = 0;

            P0003_LongestSubstring solution = new();
            int actual = solution.LengthOfLongestSubstring(s);

            Assert.Equal(expected, actual);
        }

        [Fact]
        public void OneLetterString()
        {
            string s = "a";
            int expected = 1;

            P0003_LongestSubstring solution = new();
            int actual = solution.LengthOfLongestSubstring(s);

            Assert.Equal(expected, actual);
        }

        [Fact]
        public void StringAbc()
        {
            string s = "abc";
            int expected = 3;

            P0003_LongestSubstring solution = new();
            int actual = solution.LengthOfLongestSubstring(s);

            Assert.Equal(expected, actual);
        }

        [Fact]
        public void StringSameLetters()
        {
            string s = "aaaaaaa";
            int expected = 1;

            P0003_LongestSubstring solution = new();
            int actual = solution.LengthOfLongestSubstring(s);

            Assert.Equal(expected, actual);
        }

        [Fact]
        public void StringAbcabcbb()
        {
            string s = "abcabcbb";
            int expected = 3;

            P0003_LongestSubstring solution = new();
            int actual = solution.LengthOfLongestSubstring(s);

            Assert.Equal(expected, actual);
        }

        [Fact]
        public void StringPwwkew()
        {
            string s = "pwwkew";
            int expected = 3;

            P0003_LongestSubstring solution = new();
            int actual = solution.LengthOfLongestSubstring(s);

            Assert.Equal(expected, actual);
        }

        [Fact]
        public void StringBbtablud()
        {
            string s = "bbtablud";
            int expected = 6;

            P0003_LongestSubstring solution = new();
            int actual = solution.LengthOfLongestSubstring(s);

            Assert.Equal(expected, actual);
        }
    }
}

