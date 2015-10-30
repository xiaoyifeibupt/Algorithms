/**
*Remove all elements from a linked list of integers that have value val.
*Example*
*Given *1->2->3->3->4->5->3*, val = 3, you should return the list as *1->2->4->5*
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
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode* dumy = new ListNode(0);
        dumy -> next = head;
        ListNode *prev = dumy, *cur = dumy -> next;
        while (cur) {
            if (cur -> val == val) {
                prev -> next = cur -> next;
                delete cur;
            } else
                prev = prev -> next;
            cur = prev -> next;
        }
        return dumy -> next;
    }
};
