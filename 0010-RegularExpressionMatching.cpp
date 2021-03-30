#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p == "") return s == "";

        bool firstMatch = s != "" && (s[0] == p[0] || p[0] == '.');
        
        if (p.length() >= 2 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        else
            return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
};

int main()
{
    Solution s;
    cout << (s.isMatch("aa", "a") == false) << endl;
    cout << (s.isMatch("aa", "a*") == true) << endl;
    cout << (s.isMatch("ab", ".*") == true) << endl;
    cout << (s.isMatch("aab", "c*a*b*") == true) << endl;
    cout << (s.isMatch("mississippi", "mis*is*p*.") == false) << endl;
    
}
