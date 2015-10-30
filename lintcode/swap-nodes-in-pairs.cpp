/**
*Given a linked list, swap every two adjacent nodes and return its head.
*Example*
*Given *1->2->3->4*, you should return the list as *2->1->4->3*.*

*Challenge*
*Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*
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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        ListNode* dumy = new ListNode(0);
        dumy -> next = head;
        ListNode* cur = dumy;
        while (cur -> next && cur -> next -> next) {
            ListNode* next_1 = cur -> next;
            ListNode* next_2 = next_1 -> next;
            ListNode* next_3 = next_2 -> next;
            
            cur -> next = next_2;
            next_2 -> next = next_1;
            next_1 -> next = next_3;
            cur = next_1;
        }
        return dumy -> next;
    }
};
