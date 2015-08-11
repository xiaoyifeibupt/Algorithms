/**
*Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
*Example*
*Given *1->2->3->4*, and node *3*. return *1->2->4*
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
