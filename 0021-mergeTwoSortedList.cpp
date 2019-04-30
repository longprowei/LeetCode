#include <iostream>
#include <cassert>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    };

    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        } else if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        ListNode* head = l1, *pre = l1;
        while (l1 != NULL && l2 != NULL) {
            if (l2->val < l1->val) {
                if (l1 == head) {
                    head = l2;
                    l2 = l2->next;
                    head->next = l1;
                    pre = head;
                } else {
                    pre->next = l2;
                    pre = l2;
                    l2 = l2->next;
                    pre->next = l1;
                }
            } else {
                pre = l1;
                l1 = l1->next;
            }
        }

        if (l1 == NULL && l2 != NULL) {
            pre->next = l2;
        } else if (l1 != NULL && l2 == NULL) {
            pre->next = l1;
        }

        return head;
    }
};

int main()
{
    ListNode l1(2), l2(1);
    Solution s;
    ListNode* retList;

    retList = s.mergeTwoLists(&l1, &l2);
    assert(retList->val == 1);
    retList = retList->next;
    assert(retList->val == 2);
    assert(retList->next == NULL);
    
    return 0;
}
