/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if (!root) {
            return {};
        }
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        
        while (!q.empty()) {
            
            int len = q.size();
            bool isFound = false;
            while (len--) {
                
                TreeNode* node = q.front();
                q.pop();
                if (!isFound) {
                    res.push_back(node->val);
                    isFound = true;
                } 
                
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return res;
    }
};