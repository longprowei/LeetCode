#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() < numRows) {
            return s;
        }

        size_t length = s.length();
        int columns = (length / numRows + 1) * 2;

        char zigArray[numRows][columns];
        memset(zigArray, 0, sizeof(char) * numRows * columns);
        int currRow = 0, currCol = 0;

        bool downDirection = true;
        for (int i = 0; i < length; i++) {
            if (currCol >= columns && currRow >= numRows) {
                cerr << "something wrong" << endl;
                break;
            }
            zigArray[currRow][currCol] = s[i];

            if (currRow == (numRows - 1)) {
                downDirection = false;
                currCol += 1;
            }

            if (currRow == 0) {
                downDirection = true;
            }

            if (currRow == 1 && !downDirection && numRows != 2) {
                currCol += 1;
            }

            if (downDirection) {
                currRow += 1;
            } else {
                currRow -= 1;
            }
        }

        string newStr = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < columns; j++) {
                if (zigArray[i][j] != 0) {
                    newStr += zigArray[i][j];
                }
            }
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
