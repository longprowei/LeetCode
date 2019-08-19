/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-08-19
 ************************************************************************************/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return nums.size();
    }
};

int main()
{
    Solution s;
    vector<int> v1{1, 3, 5, 6};
    assert(s.searchInsert(v1, 5) == 2);
    assert(s.searchInsert(v1, 2) == 1);
    assert(s.searchInsert(v1, 7) == 4);
    assert(s.searchInsert(v1, 0) == 0);

    return 0;
}
