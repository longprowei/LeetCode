/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-05-06
 ************************************************************************************/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ret = strs[0];

        for (size_t i = 1; i < strs.size(); i++) {
            for (size_t j = 0; j < ret.length(); j++) {
                if (strs[i][j] != ret[j]) {
                    if (j == 0) {
                        return "";
                    } else {
                        ret = string(ret, 0, j);
                        break;
                    }
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> strs1;
    strs1.push_back("fly");
    strs1.push_back("flow");
    strs1.push_back("flower");
    assert(s.longestCommonPrefix(strs1).compare("fl") == 0);

    vector<string> strs2;
    strs2.push_back("cat");
    strs2.push_back("dog");
    strs2.push_back("chicken");
    assert(s.longestCommonPrefix(strs2).compare("") == 0);
    return 0;
}
