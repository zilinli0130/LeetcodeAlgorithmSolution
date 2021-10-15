class Solution {
    long dp[1001][1001]; 
    long count[1001][27];
public:
    int numWays(vector<string>& words, string target) {
        
        
        long MOD = 1e9  +7;
        int m = words[0].size();
        int n = target.size();
        target = "*" + target;
        
        
        for (auto word : words) {
            for (int k = 0; k < word.size(); k++) {
                count[k + 1][word[k] - 'a'] += 1;
            }
        }
        
        dp[0][0] = 1;
        for (int k = 1; k <= m; k++) {
            dp[0][k] = 1;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= m; k++) {
                
                //Do not use words[k]
                dp[i][k] = dp[i][k - 1];
                
                //Use words[k]
                if (count[k][target[i] - 'a'] > 0) {
                    dp[i][k] += dp[i - 1][k - 1] * count[k][target[i] - 'a'] % MOD;
                }
                dp[i][k] %= MOD;
            }
        }
        return dp[n][m];
    }
};

/*
dp[i][k] -> ways to form target[0:i] by using words[0:k]

1. Do not use words[k]:
    dp[i][k] = dp[i][k - 1]
2. Use words[k] if target[i] == words[k]:
    dp[i][k] += dp[i - 1][k - 1] * count(words[k])

Boundary Condition : dp[0][k] = 1, dp[i][0] = 0;
*/