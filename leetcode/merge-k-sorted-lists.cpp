/**
*
*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
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