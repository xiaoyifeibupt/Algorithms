/**
*Given a list, rotate the list to the right by k places, where k is non-negative.
*For example:
*Given 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL and k = 2,
*return 4-&gt;5-&gt;1-&gt;2-&gt;3-&gt;NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL)
            return NULL;
        ListNode *p = head;
        int length = 1;
        while(p->next){
            p = p->next;
            length++;
        }
        p->next = head;
        
        k = k % length;
        
        for(int i = 0; i < length - k; i++){
            head = head->next;
            p = p->next;
        }
        p->next = NULL;
        return head;
    }
};