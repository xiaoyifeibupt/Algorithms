/**
*Given a linked list, remove the nth node from the end of list and return its head.
*Example*
*Given linked list: 1->2->3->4->5->null, and n = 2.*After removing the second node from the end, the linked list becomes 1->2->3->5->null.*

*Note*
*The minimum number of nodes in list is n.*

*Challenge*
*O(n) time*
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *help = new ListNode(0);
        help -> next = head;
        ListNode *first = help;
        ListNode *second = help;
        
        while (n > 0) {
            --n;
//            if (first -> next)
                first = first -> next;
//            else
//                return NULL;
        }
        while (first -> next) {
            first = first -> next;
            second = second -> next;
        }
        ListNode *node_to_delete = second -> next;
        second -> next = second -> next -> next;
        delete node_to_delete;

        return help -> next;
    }
};



