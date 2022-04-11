/*********************************************************************
 * Source: https://oj.leetcode.com/problems/two-sum/
 * Author: Chenglong Wei
 * Date  : 2014-10-27
 * 
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. 
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 *********************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        vector<int> indices;
        for (size_t i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[target - nums[i]] = i;
            } else {
                indices.push_back(m[nums[i]]);
                indices.push_back(i);
                break;
            }
        }

        return indices;
    }
};

int main()
{
    Solution s;
    int numbers[] = { 3, 6, 9, 7, 12 };
    vector<int> vec(numbers, numbers + sizeof(numbers) / sizeof(int));
    vector<int> vec1;
    vec1 = s.twoSum(vec, 10);
    cout << vec1[0] << endl; 
    cout << vec1[1] << endl;
}
