class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<int> dp(1<<n, INT_MAX/2);
        auto new_dp = dp;
        dp[0] = 0;
        
        for (int j = 0; j < n; j++) {
            for (int state = 0; state < (1<<n); state++) {
                for (int i = 0; i < n; i++) {
                    if ((state>>i) & 1) {
                        new_dp[state] = min(new_dp[state], dp[state - (1<<i)] + (nums1[i]^nums2[j]));
                    }
                }
            }
            dp = new_dp;
        }
        return dp[(1<<n) - 1];
    }
};


/*
dp[state] -> the min XOR sum by making pairs of nums2[0:k-1] to state with k bits,
where state represents the number of positions that have been paired with nums2 in nums1


for j index in nums2
    for state between 0 and (1<<n)
        for i index in state
            if (state>>i) & 1:
                dp[state] = min(dp[state], last_dp[state - (1<<i)] + nums1[i]^nums2[j]);

return dp[(1<<n) - 1];

*/