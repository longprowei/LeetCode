namespace CSharpLeetcode
{
    public class P0001_TwoSum
    {
        public int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> numsDict = new();
            for (int i = 0; i < nums.Length; i++)
            {
                if (numsDict.ContainsKey(nums[i]))
                {
                    return new int[] { numsDict[nums[i]], i };
                } else
                {
                    numsDict[target - nums[i]] = i;
                }
            }

            return Array.Empty<int>();
        }
    }
}