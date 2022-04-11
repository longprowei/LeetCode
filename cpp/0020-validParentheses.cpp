/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-05-08
 ************************************************************************************/
#include <iostream>
#include <cassert>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';

        size_t len = s.length();
        stack<char> charStack;
        for (size_t i = 0; i < len; i++) {
            char c = s[i];
            if (m.find(c) != m.end()) {
                if (charStack.empty()) return false;

                if (m.at(c) != charStack.top()) return false;
                charStack.pop();
            } else {
                charStack.push(c);
            }
        }
        
        return charStack.empty();
    }
};

int main()
{
    Solution s;
    assert(s.isValid("()") == true);
    assert(s.isValid("(){}[]") == true);
    assert(s.isValid("()[") == false);
    assert(s.isValid("(]") == false);
    assert(s.isValid("({)}") ==  false);
    return 0;
}
