/**
*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*Example*
*Given *-21->10->4->5, tail connects to node index 1*，返回*10*

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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        int sum_circle_nodes = 1;
        ListNode* vir_list = new ListNode(0);
        vir_list -> next = head;
        ListNode* fast = vir_list;
        ListNode* slow = vir_list;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (fast == slow) {
                slow = slow -> next;
                while (slow != fast) {
                    slow = slow -> next;
                    ++sum_circle_nodes;
                }
                fast = vir_list;
                while (sum_circle_nodes > 0) {
                    fast = fast -> next;
                    --sum_circle_nodes;
                }
                slow = vir_list;
                while (fast != slow) {
                    fast = fast -> next;
                    slow = slow -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};



