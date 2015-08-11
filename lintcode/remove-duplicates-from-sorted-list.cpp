/**
*
Given a sorted linked list, delete all duplicates such that each element appear only once.

*Example*
*Given *1->1->2*, return *1->2*.*
Given *1->1->2->3->3*, return *1->2->3*.
*
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode* p = head;
        while (p) {
            ListNode* q = p -> next;
            while (q && q -> val == p -> val)
                q = q -> next;
            p -> next = q;
            p = q;
        }
        return head;
    }
};
