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
    int numNode = 0;
    int maxDepth = 0;
    TreeNode* res = nullptr;
    unordered_map<int, int> Map;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if (root->left == nullptr && root->right == nullptr) return root;
        
        dfs1(root, 0);
        numNode = Map[maxDepth];
        dfs2(root, 0);
        return res;
    }
    
    void dfs1(TreeNode* root, int depth) {
        
        if (root->left == nullptr && root->right == nullptr) {
            maxDepth = max(maxDepth, depth);
            Map[depth]++;
            return;
        }
        if (root->left != nullptr) dfs1(root->left, depth + 1);
        if (root->right != nullptr) dfs1(root->right, depth + 1);
    }
    
    int dfs2(TreeNode* root, int depth) {
        
        if (root->left == nullptr && root->right == nullptr) {
            if (depth == maxDepth && numNode == 1 && res == nullptr) res = root; 
            if (depth == maxDepth) return 1;
            return 0;
        }
        
        int left = 0;
        if (root->left != nullptr) {
            left = dfs2(root->left, depth + 1);
        }
        
        int right = 0;
        if (root->right != nullptr) {
            right = dfs2(root->right, depth + 1);
        }
        
        int count = left + right;
        if (count == numNode && res == nullptr) {
            res = root;
        }
        return count;
    }
};