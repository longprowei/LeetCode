/*************************************************************************************
 * Source : https://oj.leetcode.com/problems/add-two-numbers/
 * Author : Chenglong Wei
 * Date   : 2014-11-05
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int sum = 0, carrybit = 0;
        ListNode *p = NULL, *sumList = NULL;
        while (l1 != NULL || l2 != NULL || carrybit == 1) {
            if (l1 != NULL && l2 != NULL) {
                sum = l1->val + l2->val + carrybit;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != NULL) {
                sum = l1->val + carrybit;
                l1 = l1->next;
            } else if (l2 != NULL) {
                sum = l2->val + carrybit;
                l2 = l2->next;
            } else if (carrybit == 1) {
                p->next = new ListNode(carrybit);
                break;
            }

            ListNode *node = new ListNode(sum % 10);
            carrybit = sum / 10;
            if (NULL == sumList) {
                sumList = p = node;
            } else {
                p->next = node;
                p = node;
            }
        }

        return sumList;
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
