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
    vector<int> preorder;
    vector<int> postorder;
    int postOrderRootIdx;
    unordered_map<int, int> Map;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        if (preorder.size() == 1) {
            TreeNode* node = new TreeNode(preorder[0]);
            return node;
        }
        
        this->preorder = preorder;
        this->postorder = postorder;
        postOrderRootIdx = postorder.size() - 1;
        
        for (int i = 0; i < preorder.size(); i++) {
            Map[preorder[i]] = i;
        }
        
        TreeNode* root = new TreeNode(postorder[postOrderRootIdx]);
        postOrderRootIdx--;
        int preOrderRootIdx = Map[postorder[postOrderRootIdx]];
        root->right = dfs(preOrderRootIdx, postorder.size() - 1);
        root->left = dfs(1, preOrderRootIdx - 1);
        return root;
    }
    
    TreeNode* dfs(int leftBound, int rightBound) {
        
        if (leftBound > rightBound || postOrderRootIdx < 0) {
            return nullptr;
        }
        
        if (leftBound == rightBound) {            
            TreeNode* node = new TreeNode(postorder[postOrderRootIdx]);
            postOrderRootIdx--;
            return node;
        }
        
        TreeNode* node = new TreeNode(postorder[postOrderRootIdx]);
        postOrderRootIdx--;
        int preOrderRootIdx = Map[postorder[postOrderRootIdx]];
        node->right = dfs(preOrderRootIdx, rightBound);
        node->left = dfs(leftBound + 1, preOrderRootIdx - 1);
        return node;
    }
};