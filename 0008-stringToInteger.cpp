#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) return 0;
    
        int result = 0;
        int sign = 1;
        int i = 0;

        while(i < s.length() && s[i] == ' ') i++;

        if(i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '+') ? 1 : -1;
        }

        while(i < s.length() && (s[i] >= '0' && s[i] <= '9')) {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[i] - '0' > INT_MAX % 10))) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (s[i++] - '0');
        }

        return result * sign;
    }
};


int main() {
    Solution s;
    cout << "42: " << s.myAtoi("42") << endl;
    cout << "-42: " << s.myAtoi("-42") << endl;
    cout << "4193 with words: " << s.myAtoi("4193 with words") << endl;
    cout << "words and 986: " << s.myAtoi("words and 986") << endl;
    cout << "-91283472332: " << s.myAtoi("-91283472332") << endl;
    cout << "   -42: " << s.myAtoi("   -42") << endl;
    cout << "+-12:" << s.myAtoi("+-12") << endl;

    return 0;
}
