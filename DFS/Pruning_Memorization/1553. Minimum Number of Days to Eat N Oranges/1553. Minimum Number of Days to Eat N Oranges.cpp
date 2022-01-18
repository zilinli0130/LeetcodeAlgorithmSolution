class Solution {
    unordered_map<int, int> Map;
public:
    int minDays(int n) {
        return dfs(n);
    }
    
    int dfs(int num) {
        
        if (num == 1) {
            return 1;
        }
        if (num == 2 || num == 3) {
            return 2;
        }
        
        if (Map.find(num) != Map.end()) {
            return Map[num];
        }
        
        int res = min(num % 2 + 1 + dfs(num/2), num % 3 + 1 + dfs(num/3));
        Map[num] = res;
        return res;
    }
};