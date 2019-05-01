#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0) return false;
        
        vector<int> digits;
        while (x) {
            int digit = 0;
            digit = x % 10;
            x /= 10;
            digits.push_back(digit); 
        }

        for (size_t i = 0, j = digits.size() - 1; i < j; ++i, --j) {
            if (digits[i] != digits[j]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    assert(s.isPalindrome(121) == true);
    assert(s.isPalindrome(0) == true);
    assert(s.isPalindrome(1223) == false);
    assert(s.isPalindrome(12233221) == true);
    assert(s.isPalindrome(-121) == false);
    
    return 0;
}
