#/**
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
    int res = 0;
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return res;
    }
    
    void dfs(TreeNode* node, int minVal, int maxVal) {
        
        if (node->left == nullptr && node->right == nullptr) {
            minVal = min(minVal, node->val);
            maxVal = max(maxVal, node->val);
            res = max(res, abs(minVal - maxVal));
            return;
        }
        
        if (node->left) {
            dfs(node->left, min(minVal,node->left->val), max(maxVal,node->left->val));
        }
        
        if (node->right) {
            dfs(node->right, min(minVal,node->right->val), max(maxVal,node->right->val));  
        }
    }
};