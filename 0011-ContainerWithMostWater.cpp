#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int minHeight = min(height[l], height[r]);
            maxArea = max(maxArea, (r - l) * minHeight);

            while(height[l] <= minHeight && l < r) l++;
            while(height[r] <= minHeight && l < r) r--;
        }

        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {1,8,6,2,5,4,8,3,7};
    cout << (s.maxArea(v1) == 49) << endl;

    vector<int> v2 = {1,1};
    cout << (s.maxArea(v2) == 1) << endl;

    vector<int> v3 = {4,3,2,1,4};
    cout << (s.maxArea(v3) == 16) << endl;

    vector<int> v4 = {1,2,1};
    cout << (s.maxArea(v4) == 2) << endl;

    return 0;
}
