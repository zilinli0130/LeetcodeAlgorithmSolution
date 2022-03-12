/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> Map;
public:
    Node* copyRandomList(Node* head) {
        
        return dfs(head);
    }
    
    Node* dfs(Node* head, Node* ptr = nullptr)
    {
        if (head == nullptr)
        {
            return head;
        }
        
        ptr = new Node(head->val);
        Map[head] = ptr;
        ptr->next = dfs(head->next, ptr->next);
        ptr->random = Map[head->random];
        return ptr;
    }
};