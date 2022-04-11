/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-05-03
 ************************************************************************************/
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanNumMap;
        romanNumMap['I'] = 1;
        romanNumMap['V'] = 5;
        romanNumMap['X'] = 10;
        romanNumMap['L'] = 50;
        romanNumMap['C'] = 100;
        romanNumMap['D'] = 500;
        romanNumMap['M'] = 1000;

        int ret = romanNumMap[s[s.size() - 1]];
        for (int i = s.size() - 2; i >= 0; i--) {
            if (romanNumMap[s[i]] < romanNumMap[s[i + 1]]) {
                ret -= romanNumMap[s[i]];
            } else {
                ret += romanNumMap[s[i]];
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    assert(s.romanToInt("III") == 3);
    assert(s.romanToInt("IV") == 4);
    assert(s.romanToInt("IX") == 9);
    assert(s.romanToInt("XI") == 11);
    assert(s.romanToInt("LVIII") == 58);
    assert(s.romanToInt("MCMXCIV") == 1994);
    
    return 0;
}
