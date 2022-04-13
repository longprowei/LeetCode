# This solution hasn't been finished, it is a hard problem, leave this for now
class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        if m == 0:
            if n % 2 == 1:
                return nums2[(n - 1) // 2]
            else:
                return (nums2[n // 2] + nums2[(n - 1) // 2]) / 2

        if n == 0:
            if m % 2 == 1:
                return nums1[(m - 1) // 2]
            else:
                return (nums1[m // 2] + nums1[(m - 1) // 2]) / 2

s = Solution()
print(s.findMedianSortedArrays([], [1, 2, 3, 4]) == 2.5)
print(s.findMedianSortedArrays([1, 2, 3], []) == 2.0)