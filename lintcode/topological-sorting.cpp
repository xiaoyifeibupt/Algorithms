/**
*Given an directed graph, a topological order of the graph nodes is defined as follow:
*Example*
*For graph as follow: *
*
*The topological order can be:*
*[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
...
*

*Note*
*You can assume that there is at least one topological order in the graph.*

*Challenge*
*Can you do it in both BFS and DFS?*
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode *> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode *> output;

        // Find ancestors of each node by DFS
        unordered_set<DirectedGraphNode *> nodes;
        unordered_map<DirectedGraphNode *, vector<DirectedGraphNode *>> ancestors;
        for (auto& node :graph) {
            findDependencyDFS(node, nodes, ancestors);
        }

        // Output topological order by DFS
        unordered_set<DirectedGraphNode *> scheduled;
        for (auto& node : graph) {
            topSortDFS(node, ancestors, scheduled, output);
        }

        return output;
    }
    
private:
    void findDependencyDFS(
                           DirectedGraphNode* node,
                           unordered_set<DirectedGraphNode *> &nodes,
                           unordered_map<DirectedGraphNode *, vector<DirectedGraphNode *>> &ancestors) {
        if (nodes.insert(node).second) {
            for (auto& neighbor : node->neighbors) {
                ancestors[neighbor].emplace_back(node);
                findDependencyDFS(neighbor, nodes, ancestors);
            }
        }
    }

    void topSortDFS(
                    DirectedGraphNode *node,
                    unordered_map<DirectedGraphNode *, vector<DirectedGraphNode *>> &ancestors,
                    unordered_set<DirectedGraphNode *> &scheduled,
                    vector<DirectedGraphNode *> &output) {
        if (scheduled.insert(node).second) {
            for (auto& ancestor: ancestors[node]) {
                topSortDFS(ancestor, ancestors, scheduled, output);
            }
            output.emplace_back(node);
        }
    }
};
