class Solution {
    int k;
    int target;
    int count = 0;
    bool isFound = false;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        this->k = k;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        
        target = sum / k;
        vector<int> visited(nums.size(), 0);
        dfs(visited,nums,0,0,0);   
        cout << count << endl;
        return count == k; 
    }
    
    void dfs(vector<int>& visited, vector<int>& nums, int curSum, int depth, int idx) {
        
        if (count == k) {
            return;
        }
        
        if (curSum == target) {
            count++;
            isFound = true;
            return;
        }
        
        if (curSum > target) {
            return;
        }
        
        for (int i = idx; i < nums.size(); i++) {
            
            if (!visited[i]) {
                visited[i] = 1;
                dfs(visited, nums, curSum + nums[i], depth + 1, i + 1);
                if (count == k) {
                    return;
                }
                if (isFound == true && depth > 0) {
                    return;
                }

                //If the program goes back to the depth 0, it would continue to find the next desired set without backtracking
                if (isFound == true && depth == 0) {
                    isFound = false;
                    continue;
                }
                visited[i] = 0;
            }
        }
    }

};