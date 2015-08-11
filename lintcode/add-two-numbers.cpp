/**
*You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
*Example*
*Given *7->1->6 + 5->9->2*. That is, *617 + 295*.*
*Return *2->1->9*. That is *912*.*
*Given *3->1->5* and *5->9->2*, return *8->0->8*.*
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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        int flag = 0;
        ListNode *l3 = nullptr, *l3node = nullptr, *l3next = nullptr;
        while (l1 && l2) {
            int sum = l1 -> val + l2 -> val + flag;
            flag = sum / 10;
            sum %= 10;
            l3next = new ListNode(sum);
            if (l3 == nullptr) {
                l3 = l3node = l3next;
            } else {
                l3node -> next = l3next;
                l3node = l3node -> next;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1) {
            int sum = l1 -> val + flag;
            flag = sum / 10;
            sum %= 10;
            l3next = new ListNode(sum);
            l3node -> next = l3next;
            l3node = l3node -> next;
            l1 = l1 -> next;
        }
        while (l2) {
            int sum = l2 -> val + flag;
            flag = sum / 10;
            sum %= 10;
            l3next = new ListNode(sum);
            l3node -> next = l3next;
            l3node = l3node -> next;
            l2 = l2 -> next;
        }
        if (flag) {
            l3next = new ListNode(flag);
            l3node -> next = l3next;
        }
        return l3;
    }
};
