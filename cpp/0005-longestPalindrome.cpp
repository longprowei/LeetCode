#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) {
            return s;
        }

        int maxLength = 0;
        string palindrome;

        for (int i = 0; i < s.length(); i++) {
            int j = i;
            int k = i + 1;
            int currLength = 0;

            while (j >= 0 && k < s.length() && s[j] == s[k]) {
                currLength += 2;
                
                if (currLength > maxLength) {
                    maxLength = currLength;
                    palindrome = s.substr(j, maxLength);
                }

                j--;
                k++;
            }
        }

        for (int i = 1; i < s.length(); i++) {
            int j = i - 1;
            int k = i + 1;
            int currLength = 1;

            while (j >= 0 && k < s.length() && s[j] == s[k]) {
                currLength += 2;

                if (currLength > maxLength) {
                    maxLength = currLength;
                    palindrome = s.substr(j, maxLength);
                }

                j--;
                k++;
            }
        }

        return palindrome.length() > 1 ? palindrome : s.substr(0, 1);
    }
};

int main() {
    Solution s;
    assert(s.longestPalindrome("a") == "a");
    assert(s.longestPalindrome("abccbad") == "abccba");
    assert(s.longestPalindrome("dabccba") == "abccba");
    assert(s.longestPalindrome("dabccbabdbf") == "abccba");
    assert(s.longestPalindrome("babad") == "bab");
    assert(s.longestPalindrome("cbbd") == "bb");
    assert(s.longestPalindrome("aaaaa") == "aaaaa");
    assert(s.longestPalindrome("aacabdkacaa") == "aca");
    assert(s.longestPalindrome("ac") == "a");
    return 0;
}