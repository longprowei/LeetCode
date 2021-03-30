#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.length() + 1][p.length() + 1] = {};

        dp[s.length()][p.length()] = true;

        for(int i = s.length(); i >=0; i--) {
            for(int j = p.length() - 1; j >= 0; j--) {
                bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
                if (j + 1 < p.length() && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || firstMatch && dp[i + 1][j];
                } else {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
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
