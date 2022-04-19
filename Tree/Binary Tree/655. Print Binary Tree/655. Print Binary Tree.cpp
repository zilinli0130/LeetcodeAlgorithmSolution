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
    int height = 0;
    vector<vector<string>> res;
public:
    vector<vector<string>> printTree(TreeNode* root) {
        
        getTreeHeight(root, -1);
        int row = height + 1, col = pow(2, height + 1) - 1;
        res.resize(row, vector<string>(col, ""));
        dfs(root, 0, (col-1)/2);
        return res;
    }
    
    void getTreeHeight(TreeNode* node, int count) {
        
        if (!node) {
            height = max(height, count);
            return;
        }
        
        getTreeHeight(node->left, count + 1);
        getTreeHeight(node->right, count + 1);
    }
    
    void dfs(TreeNode* node, int r, int c) {
        
        if (!node) {
            return;
        }
        
        res[r][c] = to_string(node->val);
        dfs(node->left, r + 1, c - pow(2, height - r - 1));
        dfs(node->right, r + 1, c + pow(2, height - r - 1));
    }
};