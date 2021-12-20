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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int l, int r) {
        
        if (l > r) {
            return vector<TreeNode*>{nullptr};
        }
        
        vector<TreeNode*> res;
        for (int k = l; k <= r; k++) {
            vector<TreeNode*> leftNodes = dfs(l, k - 1);
            vector<TreeNode*> rightNodes = dfs(k + 1, r);
            
            for (auto leftNode : leftNodes) {
                for (auto rightNode : rightNodes) {
                    TreeNode* node = new TreeNode(k, leftNode, rightNode);
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};