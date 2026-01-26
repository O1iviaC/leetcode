/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <unordered_map>

class Solution {
    unordered_map<Node*, Node*> copy;

    Node* dfs(Node* node) {
        if (!node) return nullptr;

        // If already cloned, return it (prevents cycles)
        if (copy.count(node)) return copy[node];

        // Create clone
        Node* clone = new Node(node->val);
        copy[node] = clone;

        // Clone neighbors
        for (Node* nei : node->neighbors) {
            clone->neighbors.push_back(dfs(nei)); //recursive call on neighbours so they are safely cloned
        }

        return clone;
    }

public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
