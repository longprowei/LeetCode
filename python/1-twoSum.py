class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        numDict = {}
        for i in range(len(nums)):
            anotherNum = target - nums[i]
            if anotherNum in numDict:
                return [numDict[anotherNum], i]
            numDict[nums[i]] = i

#test code
s = Solution()
print(s.twoSum([2,7,11,15], 9) == [0, 1])
print(s.twoSum([3,2,4], 6) == [1,2])
print(s.twoSum([3,3], 6) == [0, 1])
print(s.twoSum([0, 0], 0) == [0, 1])
print(s.twoSum([6, 3, -3], 0) == [1, 2])