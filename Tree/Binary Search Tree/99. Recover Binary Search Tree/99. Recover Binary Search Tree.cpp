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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        
        dfs(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void dfs(TreeNode* node) {
        
        if (!node) {
            return;
        }
        
        dfs(node->left);
        if (node->val < prev->val) {
            if (!first) {
                first = prev;
            }
            second = node;
        }
        prev = node;
        dfs(node->right);
    }
};