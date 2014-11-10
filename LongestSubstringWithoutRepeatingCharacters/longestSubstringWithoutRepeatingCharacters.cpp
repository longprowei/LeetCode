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

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        set<char> myset;        
        queue<char> q;
        int l = 0;
        for (size_t i = 0; i < s.length(); i++) {
            if (myset.find(s[i]) != myset.end()) {
                if (myset.size() > l) {
                    l = myset.size();
                }

                while (q.front() != s[i]) {
                    myset.erase(q.front());
                    q.pop();
                }
                q.pop();
            } else {
                myset.insert(s[i]);
            }
            q.push(s[i]);
        }
        
        if (myset.size() > l) {
            l = myset.size();
        }

        return l;
    }
    
    //refered to Hao Chen's code
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int maxLen = 0;
        int lastRepeatPos = -1;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]]) {
                lastRepeatPos = m[s[i]];
            }

            if (i - lastRepeatPos > maxLen) {
                maxLen = i - lastRepeatPos;
            }
            m[s[i]] = i;
        }

        return maxLen;
    }
};

int main()
{
    Solution s;
    string str = "qopubjguxhxdipfzwswybgfylqvjzhar";
    cout << s.lengthOfLongestSubstring(str) << endl;

    return 0;
}
