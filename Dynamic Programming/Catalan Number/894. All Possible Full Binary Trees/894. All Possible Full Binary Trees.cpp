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
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if (n % 2 == 0) {
            return {};
        }
        return dfs(n);
    }
    
    vector<TreeNode*> dfs(int count) {
        
        // Option 1: no more expansion on both left and right sub tree
        if (count == 1) {
            TreeNode* node = new TreeNode(0);
            node->left = nullptr;
            node->right = nullptr;
            return vector<TreeNode*> {node};
        }
        
        // Option 2: keep expanding the tree on both left and right sub tree
        vector<TreeNode*> res;
        for (int i = 1; i < count - 1; i++) {
            
            if (i % 2 == 0 && (count - 1 - i) % 2 == 0) continue;
            
            vector<TreeNode*> leftSubTreeSet = dfs(i);
            vector<TreeNode*> rightSubTreeSet = dfs(count - i - 1);
            
            for (const auto& leftNode : leftSubTreeSet) {
                for (const auto& rightNode : rightSubTreeSet) {
                    TreeNode* node = new TreeNode(0);
                    node->left = leftNode;
                    node->right = rightNode;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};

