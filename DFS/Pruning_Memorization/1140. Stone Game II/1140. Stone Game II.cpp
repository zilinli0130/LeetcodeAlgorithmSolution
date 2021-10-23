class Solution {
    int memo[101][101];    
    int suffixSum[101];
public:
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();
        suffixSum[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        return helper(piles, 0, 1);
    }

    int helper(vector<int>& piles, int i, int M)
    {
        if (i == piles.size())  {
            return 0;
        }
        
        if (memo[i][M] != 0) {
            return memo[i][M];
        }
        
        int prefixSum = 0;
        for (int x = 1; x <= 2*M; x++) {
            if (i + x > piles.size()) break;
            prefixSum += piles[i + x - 1];
            memo[i][M] = max(memo[i][M], prefixSum + suffixSum[i + x] - helper(piles, i + x, max(x,M)));
        }
        return memo[i][M];
    }
};