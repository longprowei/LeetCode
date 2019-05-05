#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int len = nums.size();
        int cur = 0;
        for (int next = 1; next < len; next++) {
            if (nums[next] != nums[cur]) {
                cur++;
                nums[cur] = nums[next];
            }
        }
        
        return cur + 1;
    }
};

int main()
{
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    Solution s;
    assert(s.removeDuplicates(nums) == 5);
    assert(nums[0] == 0);
    assert(nums[1] == 1);
    assert(nums[2] == 2);
    assert(nums[3] == 3);
    assert(nums[4] == 4);

    return 0;
}
