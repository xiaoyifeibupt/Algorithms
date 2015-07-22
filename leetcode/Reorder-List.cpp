/**
*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
*reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

*You must do this in-place without altering the nodes' values.

*For example,
*Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if(head == NULL){  
            return;  
        }  
          
        ListNode* p1 = head;  
        ListNode* p2 = splitList(head);  
          
        p2 = reverseList(p2);  
          
        mergeList(p1, p2);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* newList = NULL;
        ListNode* prev = NULL;
        ListNode* pNode = head;
        
        while(pNode) {
            ListNode* pNext = pNode -> next;
            if(pNext == NULL)
                newList = pNode;
            pNode -> next = prev;
            prev = pNode;
            pNode = pNext;
        }
        return newList;
    }
    
    ListNode* splitList(ListNode* head) {
        ListNode* slow = new ListNode(0);
        slow -> next = head;
        ListNode* fast = slow;
        
        while(fast -> next != NULL && fast -> next -> next != NULL){  
            slow = slow -> next;  
            fast = fast -> next;  
            fast = fast -> next;  
        }  
          
        if(fast->next != NULL){  
            slow = slow -> next;  
            fast = fast -> next;  
        }  
          
        ListNode* tmp = slow -> next;  
        slow -> next = NULL;  
        return tmp;  
    }
    
    void mergeList(ListNode* p1, ListNode* p2) {
        while(p2) {
            ListNode* tem = p2;
            p2 = p2 -> next;
            
            tem -> next = p1 -> next;
            p1 -> next = tem;
            p1 = p1 -> next -> next;
        }
    }
};
