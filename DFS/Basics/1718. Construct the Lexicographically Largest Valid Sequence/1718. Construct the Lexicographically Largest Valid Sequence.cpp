//Time: O(N!), Space: O(N)
class Solution {
    int n;
    int visited[21];
    vector<int> res;
public:
    vector<int> constructDistancedSequence(int n) {
        
        this->n = n;
        res.resize(2*n - 1);
        dfs(0);
        return res;
    }
    
    bool dfs(int idx) {
        
        if (idx == 2*n - 1) {
            return true;
        }
        
        if (res[idx] > 0) {
            return dfs(idx + 1);
        }
        
        
        for (int num = n; num >= 1; num--) {
            
            if (visited[num] == 1) continue;
            if (num > 1 && (idx + num >= 2*n - 1 || res[idx + num] > 0)) continue;
            
            visited[num] = 1;
            res[idx] = num;
            if (num > 1) res[idx + num] = num;
            if (dfs(idx + 1)) {
                return true;
            }
            visited[num] = 0;
            res[idx] = 0;
            if (num > 1) res[idx + num] = 0;
        }
        return false;
    }
};