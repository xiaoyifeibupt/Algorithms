/**
*Given a singly linked list, determine if it is a palindrome.

*Follow up:
*Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* mid = getMid(head);
        ListNode* head2 = reverseList(mid);
        while(head && head2)
        {
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* preslow = NULL;
        while(fast && fast -> next) {
            preslow = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        preslow -> next = NULL;
        return slow;
    }
    ListNode* reverseList(ListNode* head)  {
        ListNode *p1, *p2 , *p3;
        if (head == NULL || head->next == NULL) {
            return head;
        }
        p1 = head;
        p2 = head->next;
        while (p2 != NULL) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        head->next = NULL;
        head = p1;
 
        return head;
    }
};