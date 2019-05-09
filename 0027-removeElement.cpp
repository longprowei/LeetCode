/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-05-09
 ************************************************************************************/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] == val) {
                nums[i] = nums[j];
                j--;
            } else {
                i++;
            }
        }
        
        return i;
    }
};

int main()
{
	Solution s;
    vector<int> v1{3, 2, 2, 3};
    int count = s.removeElement(v1, 3);
    assert(count == 2);
    assert(v1[0] == 2);
    assert(v1[1] == 2);

	return 0;
}
