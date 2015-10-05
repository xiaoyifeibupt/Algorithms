/**
*
*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*Note: Do not modify the linked list.
*Follow up:
*Can you solve it without using extra space?
*
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
               break;
        }
        if(fast != NULL && fast->next != NULL){
            ListNode *detect = head;
            while(fast != detect){
                detect = detect->next;
                fast = fast->next;
            }
                return detect;
        }
    return NULL;
    }
};