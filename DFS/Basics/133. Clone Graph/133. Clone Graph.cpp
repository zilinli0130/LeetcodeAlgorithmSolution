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

class Solution {
    unordered_map<Node*, Node*> Map; // origin, res
public:
    Node* cloneGraph(Node* head) {
        
        if (!head)
        {
            return nullptr;
        }
        return dfs(nullptr, head, head->neighbors);
    }
    
    Node* dfs(Node* res, Node* origin, vector<Node*> children)
    {
        res = new Node(origin->val);
        Map[origin] = res;
        
        for (const auto& node : children)
        {
            if (Map.find(node) != Map.end())
            {
                continue;
            }
            dfs(nullptr, node, node->neighbors);
        }
        
        for (const auto& node : origin->neighbors)
        {
            res->neighbors.push_back(Map[node]);
        }
        return res;
    }
};