/**
*Merge two sorted (ascending) linked lists and return it as a new sorted list. The new sorted list should be made by splicing together the nodes of the two lists and sorted in ascending order.
*Example*
*Given *1->3->8->11->15->null*, *2->null* , return *1->2->3->8->11->15->null*.*
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;
        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val <= l2 -> val) {
                l3 -> next = l1;
                l1 = l1 -> next;
            }
            else {
                l3 -> next = l2;
                l2 = l2 -> next;
            }
            l3 = l3 -> next;
        }
        if (l1)
            l3 -> next = l1;
        if (l2)
            l3 -> next = l2;
        return head -> next;
    }
};
