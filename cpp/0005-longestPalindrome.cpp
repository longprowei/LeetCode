#include <iostream>

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
                j--;
                k++;

                if (currLength > maxLength) {
                    maxLength = currLength;
                    palindrome = s.substr(j, maxLength);
                }
            }
        }

        for (int i = 1; i < s.length(); i++) {
            int j = i - 1;
            int k = i + 1;

            while (j >= 0 && k < s.length() && s[j] == s[k]) {

            }
        }
    }
};