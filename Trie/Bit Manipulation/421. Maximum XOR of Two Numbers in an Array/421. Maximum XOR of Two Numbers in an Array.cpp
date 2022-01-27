class Solution {
    class TrieNode {
    public:
        TrieNode* next[2];
        TrieNode () {
            next[0] = nullptr;
            next[1] = nullptr;
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        
        TrieNode* root = new TrieNode();
        for (auto num : nums) {
            TrieNode* node = root;
            for (int k = 31; k >= 0; k--) {
                if (node->next[(num>>k)&1] == nullptr) {
                    node->next[(num>>k)&1] = new TrieNode();
                } 
                node = node->next[(num>>k)&1];
            }
        }
        
        int res = 0;
        for (auto num : nums) {
            
            int temp = 0;
            TrieNode* node = root;
            for (int k = 31; k >= 0; k--) {
                if (node->next[1 - (num>>k)&1] != nullptr) {
                    node = node->next[1 - (num>>k)&1];
                    temp = temp*2 + 1;
                } else {
                    node = node->next[(num>>k)&1];
                    temp = temp*2 + 0;
                }
            }
            res = max(res, temp);
        }
        return res;
    }
};