/**
*Given a linked list, determine if it has a cycle in it.
*Example*
*Given -21->10->4->5, tail connects to node index 1, return true*

*Challenge*
*Follow up:*Can you solve it without using extra space?*
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode *help = new ListNode(0);
        help -> next = head;
        ListNode *fast = help;
        ListNode *slow = help;
        
        while (fast && fast -> next) {
            fast = fast -> next ->next;
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};



