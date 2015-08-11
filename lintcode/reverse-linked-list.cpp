/**
*Reverse a linked list.
*Example*
*For linked list *1->2->3*, the reversed linked list is *3->2->1*

*Challenge*
*Reverse it in-place and in one-pass*
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode *p1, *p2, *p3;
        if (head == NULL || head -> next == NULL) return head;
        p1 = head;
        p2 = head -> next;
        while (p2) {
            p3 = p2 -> next;
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
        }
        head -> next = NULL;
        head = p1;
        return head;
    }
};

