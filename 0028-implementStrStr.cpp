/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-05-12
 ************************************************************************************/
#include <iostream>
#include <cassert>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        int m = haystack.length(), n = needle.length();
        
        for (int i = 0; i <= m - n; i++) {
            if (haystack[i] == needle[0]) {
                bool found = true;
                for (int j = 1; j < n; j++) {
                    if (needle[j] != haystack[i + j]) {
                        found = false;
                        break;
                    }
                }
                if (found) return i;
            }
        }
        
        return -1;
    }
};

int main()
{
    Solution s;

    assert(s.strStr("aaa", "") == 0);
    assert(s.strStr("aaa", "aaaa") == -1);
    assert(s.strStr("a", "a") == 0);
    assert(s.strStr("hello", "ll") == 2);

    return 0;
}
