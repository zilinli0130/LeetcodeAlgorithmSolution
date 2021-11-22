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
    vector<int> inorder;
    vector<int> postorder;
    int postOrderRootIdx;
    unordered_map<int, int> Map;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        this->inorder = inorder;
        this->postorder = postorder;
        postOrderRootIdx = postorder.size() - 2;
        
        for (int i = 0; i < inorder.size(); i++) {
            Map[inorder[i]] = i;
        }
        
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        root->right = dfs(Map[postorder[postorder.size() - 1]] + 1, postorder.size() - 1);
        root->left = dfs(0, Map[postorder[postorder.size() - 1]] - 1);
        return root;
    }
    
    TreeNode* dfs(int leftBound, int rightBound) {
        
        
        if (leftBound > rightBound || postOrderRootIdx < 0) {
            return nullptr;
        }
        
        int inorderRootIdx = Map[postorder[postOrderRootIdx]];
        TreeNode* node = new TreeNode(postorder[postOrderRootIdx]);
        postOrderRootIdx--;
        node->right = dfs(inorderRootIdx + 1, rightBound);
        node->left = dfs(leftBound, inorderRootIdx - 1);
        return node;
    }
};