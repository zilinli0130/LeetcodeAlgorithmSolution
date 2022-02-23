class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        
        vector<int> courses(n, 0);
        vector<int> statePreq((1<<n), 0);
        vector<int> dp((1<<n), INT_MAX/2);
        
        for (auto& item : relations) {
            courses[item[1] - 1] |=  1<<(item[0] - 1);
        }
        
        for (int state = 0; state < (1<<n); state++) {
            statePreq[state] = 0;
            for (int i = 0; i < n; i++) {
                if ((state>>i) & 1) {
                    statePreq[state] |= courses[i];
                }
            }
        }
        
        dp[0] = 0;
        for (int state = 0; state < (1<<n); state++) {
            for (int subState = state; subState >= 0; subState = (subState - 1) & state) {
                if (__builtin_popcount(state) - __builtin_popcount(subState) <= k && (statePreq[state] & subState) == statePreq[state]) {
                    dp[state] = min(dp[state], dp[subState] + 1);
                }
                if (subState == 0) break;
            }
        }
        return dp[(1<<n) - 1];
    }
};