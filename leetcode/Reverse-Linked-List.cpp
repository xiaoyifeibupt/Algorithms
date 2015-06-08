/*
*Reverse a singly linked list.

*Hint:
*A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverseHead = NULL;
        ListNode* pNode = head;
        ListNode* prev = NULL;
        while(pNode) {
            ListNode* pNext = pNode -> next;
            if(pNext == NULL)
                reverseHead = pNode;
    
            pNode -> next = prev;
    
            prev = pNode;
            pNode = pNext;
        }
    return reverseHead;
    }
};
