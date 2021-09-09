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
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* node) {
        
        if (node == nullptr) {
            return 0;
        }
        
        int maxLeftStraightPathSum = dfs(node->left);
        int maxRightStraightPathSum = dfs(node->right);
        
        int maxStraightPathSum = max(node->val, max(maxLeftStraightPathSum, maxRightStraightPathSum) + node->val);
        
        res = max(res, max(0,maxLeftStraightPathSum) + max(0,maxRightStraightPathSum) + node->val);
        return maxStraightPathSum;
    }
};