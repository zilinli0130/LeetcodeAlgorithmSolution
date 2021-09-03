class Solution {
    vector<int> visited;
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n = nums.size();
        visited.resize(n);
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(nums, temp, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& temp, int idx) {
        
        if (idx == nums.size()) {
            res.push_back(temp);
            return;
        }
        
        int lastNum = -11;
        for (int i = 0; i < nums.size(); i++) {
            
            if (!visited[i]) {
                if (lastNum == nums[i]) continue;
                lastNum = nums[i];
                visited[i] = 1;
                temp.push_back(nums[i]);
                dfs(nums, temp, idx + 1);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
};