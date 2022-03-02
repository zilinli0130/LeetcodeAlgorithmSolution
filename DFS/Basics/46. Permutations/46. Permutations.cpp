class Solution {
    int N;
    vector<int> visited;
    vector<vector<int>> res;
    vector<vector<int>> next;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        N = nums.size();
        next.resize(N);
        visited.resize(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                next[i].push_back(j);
            }
        }
        
        vector<int> temp;
        for (int i = 0; i < N; i++) {
            
            visited[i] = 1;
            temp.push_back(nums[i]);
            dfs(nums, temp, i, 1);
            temp.pop_back();
            visited[i] = 0;
        }
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& temp, int idx, int count) {
        
        if (count == N) {
            res.push_back(temp);
            return;
        }
        
        for (auto nextIdx : next[idx]) {
            
            if (visited[nextIdx]) continue;
            visited[nextIdx] = 1;
            temp.push_back(nums[nextIdx]);
            dfs(nums, temp, nextIdx, count + 1);
            temp.pop_back();
            visited[nextIdx] = 0;
        }
    }
};