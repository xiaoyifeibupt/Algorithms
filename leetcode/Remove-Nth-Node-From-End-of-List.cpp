/**
*Given a linked list, remove the nth node from the end of list and return its head.

*For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
*Note:
*Given n will always be valid.
*Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;
        
        ListNode *h1 = head;
        ListNode *h2 = head;
        ListNode *p = NULL;
        while(n-1){
            h2 = h2 -> next;
            n--;
        }
        while(h2->next != NULL){
            p = h1;
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
        
        if(p == NULL){
            head = h1 -> next;
            delete h1;
        }
        else{
            p -> next = h1 -> next;
            delete h1;
        }
        return head;
    }
};
