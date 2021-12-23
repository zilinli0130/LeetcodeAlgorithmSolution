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
    int res = 0;
    int targetSum;
    unordered_map<int, int> Map;
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        this->targetSum = targetSum;
        Map[0] = 1;
        dfs(root,0);
        return res;
    }
    
    void dfs(TreeNode* node, int prefixSum) {
        
        if (!node) return;
        
        prefixSum += node->val;
        if (Map.find(prefixSum - targetSum) != Map.end()) {
            res += Map[prefixSum - targetSum];
        }
        Map[prefixSum]++;
        dfs(node->left, prefixSum);
        dfs(node->right, prefixSum);  
        Map[prefixSum]--;
        prefixSum -= node->val;
    }
};