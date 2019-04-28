/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-04-28
 ************************************************************************************/
#include <iostream>
#include <cassert>

class Solution {
public:
	int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            int remainder = x % 10;
            x /= 10;
            
            long long tempResult = (long long)ret * 10 + remainder;
            if (tempResult > INT_MAX || tempResult < INT_MIN) return 0;
            
            ret = tempResult;
        }
        
        return ret;
    }
};

int main()
{
    Solution s;
    assert(s.reverse(1234567) == 7654321);
    assert(s.reverse(3210) == 123);

	return 0;
}
