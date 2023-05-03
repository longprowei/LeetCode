using System;
namespace CSharpLeetcode
{

    public class ListNode {
        public int val;
        public ListNode? next;
        public ListNode(int val = 0, ListNode? next = null) {
            this.val = val;
            this.next = next;
        }
    }

    public class P0002_AddTwoNumbers
    {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode dummyHead = new();
            ListNode? curr = dummyHead;
            ListNode p = l1, q = l2;
            int carry = 0;
            while (p != null || q != null)
            {
                int x = p != null ? p.val : 0;
                int y = q != null ? q.val : 0;
                curr.next = new ListNode();
                curr = curr.next;
                curr.val = (x + y + carry) % 10;
                carry = (x + y + carry) / 10;

                if (p != null) p = p.next;
                if (q != null) q = q.next;
            }

            if (carry == 1)
            {
                curr.next = new ListNode();
                curr = curr.next;
                curr.val = carry;
            }

            return dummyHead.next;
        }
    }
}

