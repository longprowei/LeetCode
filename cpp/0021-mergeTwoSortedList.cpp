/*************************************************************************************
 * Source : https://leetcode.com/problems/reverse-integer/
 * Author : Chenglong Wei
 * Date   : 2019-05-08
 ************************************************************************************/
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
        ListNode head(0);
        ListNode* curNode = &head;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curNode->next = l1;
                l1 = l1->next;
            } else {
                curNode->next = l2;
                l2 = l2->next;
            }
            curNode = curNode->next;
        }

        if (l1 == NULL) {
            curNode->next = l2;
        } else if (l2 == NULL) {
            curNode->next = l1;
        }

        return head.next;
    }
};

int main()
{
    ListNode l1(2), l2(1);
    Solution s;
    ListNode* retList;

    retList = s.mergeTwoLists2(&l1, &l2);
    assert(retList->val == 1);
    retList = retList->next;
    assert(retList->val == 2);
    assert(retList->next == NULL);
    
    return 0;
}
