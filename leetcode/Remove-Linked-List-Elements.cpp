/*
*Remove all elements from a linked list of integers that have value val.

*Example
*Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
*Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        
        ListNode* result = head;
        ListNode* p = head;
        
        while(p && p -> val == val) {
            ListNode* tem = p;
            p = p -> next;
            delete tem;
        }
        
        result = p;
        
        while (p) {  
            if (p->next && p->next->val == val) {  
                ListNode *temp = p->next;  
                p->next = p->next->next;  
                delete temp;  
                continue;  
            }  
            p = p->next;  
        }
        
        return result;
    }
};
