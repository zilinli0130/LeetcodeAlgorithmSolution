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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string dir1 = "", dir2 = "";
        vector<int> nodeVal1, nodeVal2;
        dfs(root, nodeVal1, dir1, startValue);
        dfs(root, nodeVal2, dir2, destValue);
        
        int idx = 0;
        while (idx < nodeVal1.size() && idx < nodeVal2.size() && nodeVal1[idx] == nodeVal2[idx]) {
            idx++;
        }
        
        for (int i = idx; i < dir1.size(); i++) {
            dir1[i] = 'U';
        }
        return dir1.substr(idx) + dir2.substr(idx);
    }
    
    bool dfs(TreeNode* node, vector<int>& nodeVal, string& dir, int target) {
        
        if (node == nullptr) return false;
        if (node->val == target) return true;
        
        if (node->left) {
            nodeVal.push_back(node->left->val);
            dir += "L";
            if (dfs(node->left, nodeVal, dir, target)) {
                return true;
            }
            nodeVal.pop_back();
            dir.pop_back();
        }
        
        if (node->right) {
            nodeVal.push_back(node->right->val);
            dir += "R";
            if (dfs(node->right, nodeVal, dir, target)) {
                return true;
            }
            nodeVal.pop_back();
            dir.pop_back();
        }
        return false;
    }
};