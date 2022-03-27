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
    vector<int> res;
    int maxFreq = 0;
    int curFreq = 0;
    int prevNode = INT_MIN;
public:
    vector<int> findMode(TreeNode* root) {
        
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode* node) {
        
        if (!node) {
            return;
        }
        
        dfs(node->left);
        
        if (maxFreq == 0 && curFreq == 0 && prevNode == INT_MIN) {
            maxFreq = 1;
            curFreq = 1;
            prevNode = node->val;
            res.push_back(node->val);
            
        } else {
            
            if (node->val == prevNode) {
                curFreq++;
                
                if (curFreq > maxFreq) {
                    res = {node->val};
                    maxFreq = curFreq;
                    
                } else if (curFreq == maxFreq) {
                    res.push_back(node->val);
                }
                
            } else {
                curFreq = 1;
                if (curFreq == maxFreq) {
                    res.push_back(node->val);
                }
                
            }
            
        }
        prevNode = node->val;
        
        dfs(node->right);
    }
};