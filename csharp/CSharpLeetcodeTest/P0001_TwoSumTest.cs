using CSharpLeetcode;

namespace CSharpLeetcodeTest
{
    public class P0001_TwoSumTest
    {
        [Fact]
        public void Test1()
        {
            int[] nums = { 2, 7, 11, 15 };
            int target = 9;
            int[] expected = { 0, 1 };

            P0001_TwoSum solution = new();
            int[] actual = solution.TwoSum(nums, target);

            Assert.Equal(expected.Length, actual.Length);
            Assert.Equal(expected[0], actual[0]);
            Assert.Equal(expected[1], actual[1]);
        }

        [Fact]
        public void Test2()
        {
            int[] nums = { 3, 2, 4 };
            int target = 6;
            int[] expected = { 1, 2 };

            P0001_TwoSum solution = new();
            int[] actual = solution.TwoSum(nums, target);

            Assert.Equal(expected.Length, actual.Length);
            Assert.Equal(expected[0], actual[0]);
            Assert.Equal(expected[1], actual[1]);
        }

        [Fact]
        public void Test3()
        {
            int[] nums = { 3, 3 };
            int target = 6;
            int[] expected = { 0, 1 };

            P0001_TwoSum solution = new();
            int[] actual = solution.TwoSum(nums, target);

            Assert.Equal(expected.Length, actual.Length);
            Assert.Equal(expected[0], actual[0]);
            Assert.Equal(expected[1], actual[1]);
        }
    }
}