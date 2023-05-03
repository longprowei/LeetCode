using System;
using CSharpLeetcode;

namespace CSharpLeetcodeTest
{
    public class P0002_AddTwoNumbersTest
    {
        [Fact]
        public void AddTwoZero()
        {
            ListNode l1 = new();
            ListNode l2 = new();
            ListNode expected = new();

            P0002_AddTwoNumbers solution = new();
            ListNode actual = solution.AddTwoNumbers(l1, l2);

            Assert.NotNull(actual);
            Assert.Equal(expected.val, actual.val);
            Assert.Equal(expected.next, actual.next);
        }

        [Fact]
        public void AddTwoSingleNumber_WithoutCarry()
        {
            ListNode l1 = new(2);
            ListNode l2 = new(3);
            ListNode expected = new(5);

            P0002_AddTwoNumbers solution = new();
            ListNode actual = solution.AddTwoNumbers(l1, l2);

            Assert.NotNull(actual);
            Assert.Equal(expected.val, actual.val);
            Assert.Equal(expected.next, actual.next);
        }

        [Fact]
        public void AddTwoSingleNumber_WithCarry()
        {
            ListNode l1 = new(6);
            ListNode l2 = new(7);
            ListNode expected = new(3, new(1));

            P0002_AddTwoNumbers solution = new();
            ListNode actual = solution.AddTwoNumbers(l1, l2);

            Assert.NotNull(actual);
            Assert.Equal(expected.val, actual.val);
            Assert.NotNull(actual.next);
            Assert.Equal(expected.next!.val, actual.next.val);
        }

        [Fact]
        public void Add1And999()
        {
            ListNode l1 = new(1);
            ListNode l2 = new(9, new(9, new(9)));
            ListNode expected = new(0, new(0, new(0, new(1))));

            P0002_AddTwoNumbers solution = new();
            ListNode actual = solution.AddTwoNumbers(l1, l2);

            Assert.NotNull(actual);
            while(actual != null && expected != null)
            {
                Assert.Equal(expected.val, actual.val);
                expected = expected.next!;
                actual = actual.next!;
            }
            Assert.Null(actual);
            Assert.Null(expected);
        }

        [Fact]
        public void Add342And456()
        {
            ListNode l1 = new(2, new(4, new(3)));
            ListNode l2 = new(5, new(6, new(4)));
            ListNode expected = new(7, new(0, new(8)));

            P0002_AddTwoNumbers solution = new();
            ListNode actual = solution.AddTwoNumbers(l1, l2);

            Assert.NotNull(actual);
            while (actual != null && expected != null)
            {
                Assert.Equal(expected.val, actual.val);
                expected = expected.next!;
                actual = actual.next!;
            }
            Assert.Null(actual);
            Assert.Null(expected);
        }
    }
}

