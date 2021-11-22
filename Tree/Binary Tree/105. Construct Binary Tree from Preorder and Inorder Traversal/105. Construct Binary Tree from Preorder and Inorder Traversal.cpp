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
    vector<int> preorder;
    int preOrderRootIdx = 1;
    unordered_map<int, int> Map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        this->inorder = inorder;
        this->preorder = preorder;
        TreeNode* root = new TreeNode(preorder[0]);
        
        for (int i = 0; i < inorder.size(); i++) {Map[inorder[i]] = i;}
        
        root->left = dfs(0, Map[preorder[0]] - 1);
        root->right = dfs(Map[preorder[0]] + 1, inorder.size() - 1);
        return root;
    }
    
    TreeNode* dfs(int leftBound, int rightBound) {
        
        if (leftBound > rightBound || preOrderRootIdx == preorder.size()) {
            return nullptr;
        }
        
        int inorderRootIdx = Map[preorder[preOrderRootIdx]];
        TreeNode* node = new TreeNode(preorder[preOrderRootIdx]);
        preOrderRootIdx++;
        node->left = dfs(leftBound, inorderRootIdx - 1);
        node->right = dfs(inorderRootIdx + 1, rightBound);
        return node;
    }
};
