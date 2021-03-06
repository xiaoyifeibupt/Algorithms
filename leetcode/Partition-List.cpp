/**
*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
*You should preserve the original relative order of the nodes in each of the two partitions.
*For example,
*Given 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;2 and x = 3,
*return 1-&gt;2-&gt;2-&gt;4-&gt;3-&gt;5.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = 0;ListNode* t1 = 0;
        ListNode* h2 = 0;ListNode* t2 = 0;
        for(; head; head = head -> next) {
            if(head -> val < x) {
                if(t1)
                    t1 = t1 -> next = head;
                else
                    t1 = h1 = head;
            }
            else {
                if(t2)
                    t2 = t2 -> next = head;
                else
                    t2 = h2 = head;
            }
        }
        if(t2)
            t2 -> next = 0;
        if(t1)
            t1 -> next = h2;
        return h1?h1:h2;
    }
};