#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() < numRows) {
            return s;
        }

        vector<string> rows(numRows);
        
        bool downDirection = false;
        int currRow = 0;
        for(char c : s) {
            rows[currRow] += c;

            if (currRow == 0 || currRow == (numRows - 1)) {
                downDirection = !downDirection;
            }

            currRow += downDirection ? 1 : -1;
        }

        string newStr;
        for(string s : rows) {
            newStr += s;
        }

        return newStr;
    }
};

int main() {
    Solution s;
    cout << (s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR") << endl;
    cout << (s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI") << endl;
    cout << (s.convert("A", 1) == "A") << endl;
    cout << (s.convert("A", 3) == "A") << endl;
    cout << (s.convert("ABC", 2) == "ACB") << endl;
    cout << (s.convert("ABCDE", 3) == "AEBDC") << endl;

    return 0;
}
