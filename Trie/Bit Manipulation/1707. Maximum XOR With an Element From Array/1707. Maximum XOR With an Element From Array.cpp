class Solution {
    class TrieNode {
    public:
        TrieNode* next[2];
    };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> res(queries.size(), 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(begin(queries), end(queries), [&](vector<int>&a, vector<int>&b) {
           return a[1] < b[1]; 
        });
        
        int idx = 0;
        TrieNode* root = new TrieNode();
        for (auto q : queries) {
            
            int flag = 0;
            while (idx < nums.size() && nums[idx] <= q[1]) {
                TrieNode* node = root;
                for (int k = 31; k >= 0; k--) {
                    if (node->next[(nums[idx]>>k)&1] == nullptr) {
                        node->next[(nums[idx]>>k)&1] = new TrieNode();
                    }
                    node = node->next[(nums[idx]>>k)&1];
                }
                idx++;
            }
            
            if (idx == 0) {
                res[q[2]] = -1;
                continue;
            }
            
            int ans = 0;
            TrieNode* node = root;
            for (int k = 31; k >= 0; k--) {
                if (node->next[1 - (q[0]>>k)&1] != nullptr) {
                    ans = ans*2 + 1;
                    node = node->next[1 - (q[0]>>k)&1];
                } else {
                    ans = ans*2 + 0;
                    node = node->next[(q[0]>>k)&1];
                }
            }
            res[q[2]] = ans;
        }
        return res;
    }
};