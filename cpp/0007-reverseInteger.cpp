/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-04-28
 ************************************************************************************/
#include <iostream>
#include <cassert>
#include<limits.h>

class Solution {
public:
	int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            int remainder = x % 10;
            x /= 10;
            
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && x > INT_MAX % 10)
                || ret < INT_MIN / 10 || (ret == INT_MIN / 10 && x < INT_MIN % 10)) {
                return 0;
            }

            ret = ret * 10 + remainder;
        }
        
        return ret;
    }
};

int main()
{
    Solution s;
    assert(s.reverse(1234567) == 7654321);
    assert(s.reverse(3210) == 123);
    assert(s.reverse(1534236496) == 0);
    assert(s.reverse(-2147483412) == -2143847412);
    

	return 0;
}
