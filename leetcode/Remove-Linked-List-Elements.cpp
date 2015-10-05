/**
*Remove all elements from a linked list of integers that have value val.
*Example
*Given: 1 --&gt; 2 --&gt; 6 --&gt; 3 --&gt; 4 --&gt; 5 --&gt; 6,  val = 6
*Return: 1 --&gt; 2 --&gt; 3 --&gt; 4 --&gt; 5
*Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
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