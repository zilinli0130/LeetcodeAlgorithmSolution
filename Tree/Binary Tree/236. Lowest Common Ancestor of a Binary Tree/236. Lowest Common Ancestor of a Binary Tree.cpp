/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int visited = 0;
    int pDepth = 0, qDepth = 0;
    unordered_map<int, int> Map;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int pVal = p->val;
        int qVal = q->val;
        dfs(root,p,q,0);
        
        if (pDepth > qDepth) {
            
            while (pDepth != qDepth) {
                pVal = Map[pVal];
                pDepth--;
            }
            
        } else if (pDepth < qDepth) {
            
            while (pDepth != qDepth) {
                qVal = Map[qVal];
                qDepth--;
            } 
        }
        
        while (qVal != pVal) {
            qVal = Map[qVal];
            pVal = Map[pVal];
        }
        
        TreeNode* res = new TreeNode(pVal);
        return res;
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, int depth) {
        
        if (root != nullptr && root->val == p->val) {
            visited++;
            pDepth = depth;
        }
        if (root != nullptr && root->val == q->val) {
            visited++;
            qDepth = depth;
        }
        if (visited == 2) return;
        if (root!= nullptr && root->left == nullptr && root->right == nullptr) return;
        
        
        if (root != nullptr && root->left != nullptr) {
            Map[root->left->val] = root->val;
            dfs(root->left,p,q, depth + 1);
        }
        if (root != nullptr && root->right != nullptr) {
            Map[root->right->val] = root->val;
            dfs(root->right,p,q, depth + 1);
        }
        return;
    }
};