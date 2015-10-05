/**
*Write a program to find the node at which the intersection of two singly linked lists begins.
*For example, the following two linked lists: 
*A:          a1 → a2
*                   ↘
*                     c1 → c2 → c3
*                   ↗            
*B:     b1 → b2 → b3
*begin to intersect at node c1.
*Notes:
*If the two linked lists have no intersection at all, return null.
*The linked lists must retain their original structure after the function returns. 
*You may assume there are no cycles anywhere in the entire linked structure.
*Your code should preferably run in O(n) time and use only O(1) memory.
*Credits:Special thanks to @stellari for adding this problem and creating all test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode *ha = headA;
        ListNode *hb = headB;
        int countA = 1,countB = 1;
        while(ha->next != NULL){
            countA++;
            ha = ha->next;
        }
        while(hb->next != NULL){
            countB++;
            hb = hb->next;
        }
        
        if(ha != hb)
            return NULL;
        else{
            int count = countA - countB;
            if(count > 0){
                while(count){
                    headA = headA->next;
                    count--;
                }
            }
            else if(count < 0){
                while(count){
                    headB = headB->next;
                    count++;
                }
            }
            
            while(headA != NULL){
                if(headA == headB)
                    return headA;
                else
                    headA = headA->next,headB = headB->next;
            }
        }
    }
};