using LL = long long;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int MOD = 1e9  +7;
        int n = arr.size();
        vector<vector<LL>> dp(n, vector<LL>(2,0));
        dp[0][0] = arr[0] % 2 == 0? 1 : 0; //even
        dp[0][1] = arr[0] % 2 == 0? 0 : 1; //odd
        LL res = dp[0][1];
        
        for (LL i = 1; i < n; i++) {
            
             if (arr[i] % 2 == 0) {
                 dp[i][0] = (dp[i - 1][0] + 1) % MOD;
                 dp[i][1] = dp[i - 1][1]; 
             } else if (arr[i] % 2 != 0) {
                 dp[i][0] = dp[i - 1][1];
                 dp[i][1] = (dp[i - 1][0] + 1) % MOD;
             }
             res = (res + dp[i][1]) % MOD;
        }
        return res;
    }
};
                