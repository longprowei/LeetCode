#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) return 0;

        long long num = 0;
        int statusFlag = 0; // 0 - white space, 1 - sign symbol, 2 - others
        bool negative = false;
        string numStr = "";
        bool leadingZero = true;

        for(int i = 0; i < s.size(); i++) {
            if (statusFlag == 0) {
                if (s[i] >= '0' && s[i] <= '9') {
                    statusFlag = 2;
                    i--;
                } else if(s[i] == '-' || s[i] == '+') {
                    statusFlag = 1;
                    i--;
                } else if (s[i] != ' ') {
                    return 0;
                }
            } else if (statusFlag == 1) {
                if (s[i] == '-') {
                    negative = true;
                }
                statusFlag = 2;
            } else {
                if (s[i] < '0' || s[i] > '9') {
                    break;
                } else {
                    if (leadingZero && s[i] == '0')
                        continue;
                    else
                        leadingZero = false;
                    numStr += s[i];
                }
            }
        }

        if (numStr.size() > 10) {
            if (negative) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }

        if (numStr != "") {
            long long bitBase = 1 * negative ? -1 : 1;
            for (int i = numStr.size() - 1; i >= 0; i--) {
                num += (numStr[i] - 48) * bitBase; 
                bitBase *= 10;

                if (num > INT_MAX) {
                    return INT_MAX;
                }

                if (num < INT_MIN) {
                    return INT_MIN;
                }
            }
        }

        return num;
    }
};


int main() {
    Solution s;
    cout << "42: " << s.myAtoi("42") << endl;
    cout << "-42: " << s.myAtoi("-42") << endl;
    cout << "4193 with words: " << s.myAtoi("4193 with words") << endl;
    cout << "words and 986: " << s.myAtoi("words and 986") << endl;
    cout << "-91283472332: " << s.myAtoi("-91283472332") << endl;

    return 0;
}
