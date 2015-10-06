/**
*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

*Example*
*Given *1->2->3->3->4->4->5*, return *1->2->5*.*
Given *1->1->1->2->3*, return *2->3*.
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode* dumy = new ListNode(INT_MAX);
        ListNode *pre = dumy;
        while (head) {
            if (head -> next && head -> val == head -> next -> val) {
                int value = head -> val;
                while (head && head -> val == value)
                    head = head -> next;
                pre -> next = head;
            } else {
                pre -> next = head;
                pre = pre -> next;
                head = head -> next;
            }
        }
        return dumy -> next;
    }
};
