/**
*Sort a linked list using insertion sort.
*Example*
*Given *1->3->2->0->null*, return *0->1->2->3->null*.*
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode* dumy = new ListNode(INT_MIN);
        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *pos = nullptr;
        while (cur) {
            pos = findInsertPosition(dumy, cur -> val);
            ListNode* temp = cur -> next;
            cur -> next = pos -> next;
            pos -> next = cur;
            cur = temp;
        }
        return dumy -> next;
    }
    
    ListNode *findInsertPosition(ListNode *head, int x) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur && cur -> val <= x) {
                prev = cur;
                cur = cur -> next;
        }
        return prev;
    }
};