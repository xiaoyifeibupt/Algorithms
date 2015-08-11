/**
*Given a list, rotate the list to the right by k places, where k is non-negative.
*Example*
*Given *1->2->3->4->5* and k = *2*, return *4->5->1->2->3*.*
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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        ListNode* help = new ListNode(0);
        help -> next = head;
        int len = 0;
        ListNode* cur = help;
        while (cur -> next) {
            len++;
            cur = cur -> next;
        }
        if (len == 0) return nullptr;
        k %= len;
        if (k == 0) return head;
        ListNode* slow = help;
        ListNode* fast = help;
        while (k) {
            fast = fast -> next;
            k--;
        }
        while (fast && fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
        help -> next = slow -> next;
        slow -> next = nullptr;
        fast -> next = head;
        return help -> next;
    }
};
