/**
*Reverse a linked list from position m to n.
*Example*
*Given *1->2->3->4->5->NULL*, m = 2 and n = 4, return *1->4->3->2->5->NULL.*

*Note*
*Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.*

*Challenge*
*Reverse it in-place and in one-pass*
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode* dumy = new ListNode(INT_MIN);
        dumy -> next = head;
        ListNode* prev = dumy;
        for (int i = 1; i < m; ++i)
            prev = prev -> next;
        ListNode* head2 = prev;
        prev = prev -> next;
        ListNode* cur = prev -> next;
        for (int i = m; i < n; ++i) {
            prev -> next = cur -> next;
            cur -> next = head2 -> next;
            head2 -> next = cur;
            cur = prev -> next;
        }
        return dumy -> next;
    }
};

