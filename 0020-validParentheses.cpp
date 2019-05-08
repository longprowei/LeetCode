/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-05-08
 ************************************************************************************/
#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        size_t len = s.length();
        if (len == 0) return true;
        
        stack<char> charStack;
        for (size_t i = 0; i < len; i++) {
            if (charStack.size() == 0) {
                charStack.push(s[i]);
            } else if ((s[i] == '}' && charStack.top() == '{') ||
                       (s[i] == ')' && charStack.top() == '(') ||
                       (s[i] == ']' && charStack.top() == '[')) {
                charStack.pop();
            } else {
                charStack.push(s[i]);
            }
        }
        
        return charStack.size() == 0 ? true : false;
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
