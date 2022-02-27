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
typedef long long LL;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        LL res = 1;
        root->val = 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        while (dq.size()) {
            
            int len = dq.size();
            LL ref = dq.front()->val;
            res = max(res, (LL)dq.back()->val - (LL)dq.front()->val + 1);
            while (len--) {
                
                TreeNode* node = dq.front();
                dq.pop_front();
                
                if (node->left) {
                    node->left->val = ((LL)node->val - ref) * 2 + 1;
                    dq.push_back(node->left);
                }
                if (node->right) {
                    node->right->val = ((LL)node->val - ref) * 2 + 2;
                    dq.push_back(node->right);
                }
            }
        }
        return res;
    }
};

