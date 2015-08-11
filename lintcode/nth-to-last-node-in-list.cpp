/**
*Find the nth to last element of a singly linked list. 
*Example*
*Given a List  3->2->1->5->null and n = 2, return node  whose value is 1.*
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
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
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
        return second -> next;
    }
};



