/**
*You are given two linked lists representing two non-negative numbers. 
*The digits are stored in reverse order and each of their nodes 
*contain a single digit. Add the two numbers and return it as a linked list.

*Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        
        ListNode *l3 = NULL, *l3node = NULL, *l3next = NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        int flag = 0;
        while(p != NULL && q != NULL){
            int sum = p->val + q->val + flag;
            flag = sum / 10;
            sum %= 10;
            l3next = new ListNode(sum);
            
            if(l3 == NULL)
                l3 = l3node = l3next;
            else{
                l3node->next = l3next;
                l3node = l3next;
            }
            p = p->next;
            q = q->next;
            
        }
        
        while(p != NULL){
            int sum = p->val + flag;
            flag = sum / 10;
            sum %= 10;
            l3next = new ListNode(sum);
            l3node->next = l3next;
            
            l3node = l3next;
            
            p = p->next;
        }
        
        while(q != NULL){
            int sum = q->val + flag;
            flag = sum / 10;
            sum %= 10;
            l3next = new ListNode(sum);
            l3node->next = l3next;
            
            l3node = l3next;

            q = q->next;
        }
        
        if(flag){
            l3next = new ListNode(flag);
            l3node->next = l3next;
        }
        return l3;
    }
};
