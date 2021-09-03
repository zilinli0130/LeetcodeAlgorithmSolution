class Solution {
    vector<int> visited;
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        res.push_back(vector<int>{});
        visited.resize(nums.size());
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dfs(nums, temp, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& temp, int idx) {
        
        if (idx == nums.size()) {
            return;
        }
        
        int lastNum = -11;
        for (int i = idx; i < nums.size(); i++) {
            if (!visited[i]) {
                if (lastNum == nums[i]) continue;
                lastNum = nums[i];
                visited[i] = 1;
                temp.push_back(nums[i]);
                res.push_back(temp);
                dfs(nums, temp, i + 1);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
};