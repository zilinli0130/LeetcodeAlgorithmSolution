/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        vector<vector<int>> Graph(501);
        
        while (!q.empty()) {
            
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) {
                Graph[node->val].push_back(node->left->val);
                Graph[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if (node->right) {
                Graph[node->val].push_back(node->right->val);
                Graph[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
        
        queue<int> q2;
        int depth = -1;
        q2.push(target->val);
        vector<int> visited(501, 0);
        while (!q2.empty()) {
            
            depth++;
            if (depth == k) break;
            int len = q2.size();
            while (len--) {
                
                int curNode = q2.front();
                q2.pop();
                
                if (visited[curNode]) continue;
                visited[curNode] = 1;
                
                for (auto& nextNode : Graph[curNode]) {
                    if (visited[nextNode]) continue;
                    q2.push(nextNode);
                }
            }
        }
        
        while (!q2.empty()) {
            res.push_back(q2.front());
            q2.pop();
        }
        return res;
    }
};