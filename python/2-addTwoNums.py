# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ret = ListNode()
        currNode = ret
        carry = 0
        while l1 is not None and l2 is not None:
            sum = l1.val + l2.val + carry
            currNode.val = sum % 10
            carry = sum // 10
            l1 = l1.next
            l2 = l2.next

            if l1 is None and l2 is None and carry == 1:
                currNode.next = ListNode()
                currNode = currNode.next
                currNode.val = carry
                return ret
            elif l1 is None and l2 is None:
                return ret
            
            currNode.next = ListNode()
            currNode = currNode.next

        while l1 is not None:
            sum = l1.val + carry
            currNode.val = sum % 10
            carry = sum // 10
            l1 = l1.next

            if l1 is None and carry == 1:
                currNode.next = ListNode()
                currNode = currNode.next
                currNode.val = carry
                return ret
            elif l1 is None:
                return ret

            currNode.next = ListNode()
            currNode = currNode.next

        while l2 is not None:
            sum = l2.val + carry
            currNode.val = sum % 10
            carry = sum // 10
            l2 = l2.next

            if l2 is None and carry == 1:
                currNode.next = ListNode()
                currNode = currNode.next
                currNode.val = carry
                return ret
            elif l2 is None:
                return ret

            currNode.next = ListNode()
            currNode = currNode.next

        return ret
