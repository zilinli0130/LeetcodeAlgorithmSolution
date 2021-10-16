class Solution {
    long dp0[1001][1001];
    long dp1[1001][1001];
    long prefixSum0[1001][1001];
    long prefixSum1[1001][1001];
    
    long MOD = 1e9 + 7;
public:
    int numberOfSets(int n, int K) {
        
        for (int i = 0; i < n; i++) {
            dp0[i][0] = 1;
            prefixSum0[i][0] = i + 1;
        }
        
        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= min(i,K); k++) {
                
                dp0[i][k] = prefixSum1[i - 1][k];
                dp1[i][k] = prefixSum0[i - 1][k - 1] + prefixSum1[i - 1][k - 1];

                prefixSum0[i][k - 1] = prefixSum0[i - 1][k - 1] + dp0[i][k - 1];
                prefixSum1[i][k] = prefixSum1[i - 1][k] + dp1[i][k]; 
                prefixSum1[i][k - 1] = prefixSum1[i - 1][k - 1] + dp1[i][k - 1];
                
                prefixSum0[i][k - 1] %= MOD;
                prefixSum1[i][k] %= MOD;
                prefixSum1[i][k - 1] %= MOD;
            }
        }
        return (dp0[n - 1][K] + dp1[n - 1][K]) % MOD;
    }
};

/*
dp0[i][k] -> ways to construct k line segments by using 0:i points and the ith point is not using

dp1[i][k] -> ways to construct k line segments by using 0:i points and the ith point is using

0 1 2 ....          i 
X X X X X X X X X X X

for i = 1:n-1 points can be used to construct n-1 line segments
for k = 1:K
dp0[i][k] = sum{dp1[j][k]} for j = 0,1,2...i - 1
dp1[i][k] = sum{dp0[j][k - 1] + dp1[j][k - 1]} for j = 0,1,2...i - 1

dp0[i][0] = 1;
dp0[0][k] = 0;

dp1[i][0] = 0;
dp1[0][k] = 0;

dp0[i][k] = prefixSum1[i - 1][k];
dp1[i][k] = prefixSum0[i - 1][k - 1] + prefixSum1[i - 1][k - 1];

prefixSum0[i][k - 1] = prefixSum0[i - 1][k - 1] + dp0[i][k - 1];
prefixSum1[i][k] = prefixSum1[i - 1][k] + dp1[i][k]; 
*/
