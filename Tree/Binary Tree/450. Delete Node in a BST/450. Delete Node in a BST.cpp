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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return dfs(root, key);
    }
    
    TreeNode* dfs(TreeNode* root, int key) {
        
        if (root == nullptr) {
            return nullptr;
        }
        
        if (key != root->val) {
            
            if (key < root->val) {
                root->left = dfs(root->left, key);
            } else if (key > root->val) {
                root->right = dfs(root->right, key);
            }
            
            
        } else if (key == root->val) {
            
            //Leaf node
            if (root->left == nullptr &&root->right == nullptr) {
                return nullptr;
            } else if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else {
                
                //Find the 1st node which is greater than the root value
                TreeNode* node = root->right;
                while (node->left != nullptr) {
                    node = node->left;
                }
                
                //Substitute the node value with key value and do recursion again
                int temp = root->val;
                root->val = node->val;
                node->val = temp;
                root->right = dfs(root->right, key);
            }
        }
        return root;
    }
};