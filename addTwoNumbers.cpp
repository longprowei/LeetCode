/*************************************************************************************
 * Source : https://oj.leetcode.com/problems/add-two-numbers/
 * Author : Chenglong Wei
 * Date   : 2018-12-18
 * 
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8 
 *
 ************************************************************************************/
#include <iostream>
#include <stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);;
        ListNode *p = l1, *q = l2, *cur = dummyHead;
        int carry = 0;

        while (p != NULL || q != NULL) {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = x + y + carry;
            cur->next = new ListNode(0);
            cur = cur->next;
            cur->val = sum % 10;
            carry = sum / 10;

            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }

        if (carry != 0) {
            cur->next = new ListNode(1);
        }

        return dummyHead->next;
    }
};

void printLink(ListNode *l) 
{
    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }

    cout << endl;
}

int main()
{
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);

    ListNode *l2 = new ListNode(1);

    Solution s;
    ListNode *ret;
    ret = s.addTwoNumbers(l1, l2);
    printLink(ret);
}
