/**
*
*Given a sorted linked list, delete all duplicates such that each element appear only once.
*For example,
*Given 1-&gt;1-&gt;2, return 1-&gt;2.
*Given 1-&gt;1-&gt;2-&gt;3-&gt;3, return 1-&gt;2-&gt;3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        if(p == NULL)
            return NULL;
        while(p->next != NULL){
            ListNode *q = p->next;
            if(p -> val == q -> val){
                p->next = q->next;
                delete q;
            }
            else
                p = q;
        }
    return head;
    }
};