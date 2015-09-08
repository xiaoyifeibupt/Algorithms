/**
*Merge k sorted linked lists and return it as one sorted list.
*Example*
*Given lists:*
*[
  2->4->null,
  null,
  -1->null
],
*
*return *-1->2->4->null*.*
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode *dumy = new ListNode(0);
        ListNode *cur = dumy;
        
        priority_queue<ListNode* , vector<ListNode *>, Compare> min_heap;
        for (auto const &a : lists) {
            if (a != nullptr)
                min_heap.emplace(a);
        }
        while (!min_heap.empty()) {
            ListNode* node = min_heap.top();
            min_heap.pop();
            cur -> next = node;
            cur = cur -> next;
            if (node -> next != nullptr) {
                min_heap.emplace(node -> next);
            }
        }
        return dumy -> next;
    }
    
    struct Compare {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
};



