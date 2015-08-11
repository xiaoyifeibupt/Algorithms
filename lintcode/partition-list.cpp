/**
*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
*Example*
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode* vir_large = new ListNode(0);
        ListNode* vir_small = new ListNode(0);
        ListNode* large = vir_large;
        ListNode* small = vir_small;
        while (head) {
            if (head -> val < x) {
                small -> next = head;
                small = small -> next;
            } else {
                large -> next = head;
                large = large -> next;
            }
            head = head -> next;
        }
        small -> next = vir_large -> next;
        large -> next = NULL;
        return vir_small -> next;
    }
};



