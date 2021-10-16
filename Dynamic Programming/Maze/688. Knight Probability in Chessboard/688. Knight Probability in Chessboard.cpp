class Solution {
public:
    double knightProbability(int n, int K, int row, int column) {
        
        if (n == 1 && K == 0) {
            return (double)1;
        }
        
        vector<vector<double>> dp(n, vector<double>(n, 0));
        auto new_dp = dp;
        
        //pre-process the probability that the knight remains on board at K times
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                //Eight directions
                double a1 = i - 2 >= 0 && j - 1 >= 0 ? 1 : 0;
                double a2 = i - 2 >= 0 && j + 1 < n ? 1 : 0;
                
                double a3 = i - 1 >= 0 && j - 2 >= 0 ? 1 : 0;
                double a4 = i - 1 >= 0 && j + 2 < n ? 1 : 0;
                
                double a5 = i + 1 < n && j - 2 >= 0 ? 1 : 0;
                double a6 = i + 1 < n && j + 2 < n ? 1 : 0;
                
                double a7 = i + 2 < n && j - 1 >= 0 ? 1 : 0;
                double a8 = i + 2 < n && j + 1 < n ? 1 : 0;
                
                dp[i][j] = (a1+a2+a3+a4+a5+a6+a7+a8)*1.0 / 8;
            }
        }
        
        
        //Move from k-1th to 1st 
        for (int k = K-1; k >= 1; k--) {
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    
                    double a1 = i - 2 >= 0 && j - 1 >= 0 ? dp[i - 2][j - 1] : 0;
                    double a2 = i - 2 >= 0 && j + 1 < n ? dp[i - 2][j + 1] : 0;

                    double a3 = i - 1 >= 0 && j - 2 >= 0 ? dp[i - 1][j - 2] : 0;
                    double a4 = i - 1 >= 0 && j + 2 < n ? dp[i - 1][j + 2] : 0;

                    double a5 = i + 1 < n && j - 2 >= 0 ? dp[i + 1][j - 2] : 0;
                    double a6 = i + 1 < n && j + 2 < n ? dp[i + 1][j + 2] : 0;

                    double a7 = i + 2 < n && j - 1 >= 0 ? dp[i + 2][j - 1] : 0;
                    double a8 = i + 2 < n && j + 1 < n ? dp[i + 2][j + 1] : 0;
                
                    new_dp[i][j] = (a1+a2+a3+a4+a5+a6+a7+a8)*1.0 / 8;
                    
                }
            }
            dp = new_dp;
        }
        return dp[row][column];
    }
};