/**
*A linked list is given such that each node contains an additional 
*random pointer which could point to any node in the list or null.

*Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == 0)
            return 0;
        for(RandomListNode *i = head; i;) {
            RandomListNode *copy = new RandomListNode(i -> label);
            copy -> next = i -> next;
            i -> next = copy;
            i = copy -> next;
        }
        for(RandomListNode *j = head; j; j = j -> next -> next) {
            j -> next -> random = (j -> random == 0)?0:j -> random -> next;
        }
        RandomListNode *h = head -> next;
        RandomListNode *t = h;
        RandomListNode *tail = head;
        while(1) {
            tail = tail -> next = t ->next;
            if(tail == 0) break;
            t = t -> next = tail -> next;
        }
        return h;
    }
};
