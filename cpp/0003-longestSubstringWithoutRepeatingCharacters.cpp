/*************************************************************************************
 * Source : https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
 * Author : Chenglong Wei
 * Date   : 2014-11-04
 *
 * Given a string, find the length of the longest substring without repeating characters.
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 ************************************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int maxLen = 0;
        int lastRepeatPos = -1;
        for (int i = 0, j = 0; j < s.size(); j++) {
            if (m.find(s[j]) != m.end()) {
                i = max(i, m[s[j]]);
            }

            maxLen = max(maxLen, j - i + 1);
            m[s[j]] = j + 1;
        }

        return maxLen;
    }
};

int main()
{
    Solution s;
    string str = "qopubjguxhxdipfzwswybgfylqvjzhar";
    cout << s.lengthOfLongestSubstring(str) << endl; // should be 12

    return 0;
}
