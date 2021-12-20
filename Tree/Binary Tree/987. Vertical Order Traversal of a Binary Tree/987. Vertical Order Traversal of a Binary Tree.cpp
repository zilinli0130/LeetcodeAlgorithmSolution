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
    priority_queue<int> pq;
    unordered_map<int, vector<pair<int, int>>> Map; //col, <row, node->val>
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs(root, 0,0);
        vector<vector<int>> res;
        while (!pq.empty()) {
            
            int c = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == c) {
                pq.pop();
            }
            
            vector<int> ans;
            vector<pair<int, int>> temp = Map[c];
            sort(temp.begin(), temp.end(), cmp);
            for (auto it : temp) {
                ans.push_back(it.second);
            }
            res.push_back(ans);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(TreeNode* node, int r, int c) {
        
        if (node == nullptr) {
            return;
        }
        
        pq.push(c);
        Map[c].push_back(pair<int, int>{r, node->val});
        if (node->left) dfs(node->left, r + 1, c - 1);
        if (node->right) dfs(node->right, r + 1, c + 1);
        return;
    }
    
    
};