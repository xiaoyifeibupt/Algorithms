/**
*Reverse a linked list from position m to n. Do it in-place and in one-pass.

*For example:
*Given 1->2->3->4->5->NULL, m = 2 and n = 4,

*return 1->4->3->2->5->NULL.

*Note:
*Given m, n satisfy the following condition:
*1 ≤ m ≤ n ≤ length of list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL) return NULL;
        ListNode *p = head;
        ListNode *q = NULL;
        for(int i = 0; i< m - 1; ++i) {
            q = p;
            p = p -> next;
        }
        ListNode *pre = p;
        ListNode *end = p;
        p = p -> next;
        for(int i = m + 1; i <= n; ++i) {
            ListNode *pnext = p -> next;
            p -> next = pre;
            pre = p;
            p = pnext;
        }
        end -> next = p;
        if(q)
            q -> next = pre;
        else
            head = pre;
        
        return head;
    }
};
