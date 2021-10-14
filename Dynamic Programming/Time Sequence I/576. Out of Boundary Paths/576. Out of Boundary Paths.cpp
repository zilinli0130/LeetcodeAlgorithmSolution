class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<int>> old_dp(m, vector<int>(n, 0));
        auto new_dp = old_dp;
        int MOD = 1e9 + 7;
        for (int k = 0; k < maxMove; k++) {
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    
                    unsigned long left = j - 1 < 0 ? 1: old_dp[i][j - 1];
                    unsigned long right = j + 1 >= n ? 1: old_dp[i][j + 1];
                    unsigned long up = i - 1 < 0 ? 1: old_dp[i - 1][j];
                    unsigned long down = i + 1 >= m ? 1: old_dp[i + 1][j];
                    new_dp[i][j] = (up + down + left + right) % MOD;
                }
            }
            old_dp = new_dp;
        }
        return old_dp[startRow][startColumn];
    }
};

/*
maxMove = 1
  X X
X 2 2 X
X 2 2 X
  X X

maxMove = 1 or 2

  X X
X 6 6 X
X 6 6 X
  X X

maxMove = 1 or 2 or 3

  X X
X 14 14 X
X 14 14 X
  X X

*/