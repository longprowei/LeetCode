# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode()
        p = l1
        q = l2
        curr = dummyHead
        carry = 0

        while p or q:
            v1 = p.val if p else 0
            v2 = q.val if q else 0
            sum = v1 + v2 + carry
            curr.next = ListNode(sum % 10)
            curr = curr.next
            carry = sum // 10
            p = p.next if p else p
            q = q.next if q else q

        if carry == 1:
            curr.next = ListNode(carry)
        
        return dummyHead.next
